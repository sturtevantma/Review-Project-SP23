#include "gradebook.h"

/*
string name
float weight
vector<pair<string, float> grade
*/

Course::Course() {

}

Course::Course(std::string f_name) {
    // read in file name into read_file method call
    read_file(f_name);
}

void Course::read_file(std::string fname) {
    std::ifstream file_stream;
    file_stream.open(fname);

    // Throw exception if file is not opened
    if (!file_stream.is_open()) {
        std::cout << "Failed to open file" << std::endl;
        throw;
    }

    // For each word in line
    std::string line;
    std::getline(file_stream, line);
    std::stringstream* sstream = new std::stringstream(line);
    std::string word;
    while(*sstream >> word) {
        // Create Category
        Category cat;
        cat.name = word;
        this->categories.push_back(cat);
    }

    // For each word in next line assign weight
    std::getline(file_stream, line);
    sstream = new std::stringstream(line);
    int n = 0;
    while(*sstream >> word) {
        // Assign weight
        this->categories[n].weight = std::stoi(word);
        n++;
    }

    // For each remaining line assign grade data
    while( std::getline(file_stream, line) ) {
        n = 0;
        sstream = new std::stringstream(line);
        while(*sstream >> word) {

            // Separate name,grade
            int comma = word.find(',');
            std::string name = word.substr(0,comma);
            std::string grade = word.substr(comma+1, std::string::npos);
            std::pair<std::string,float> new_pair(name, std::stof(grade));

            // Add pair to vec
            this->categories[n].grades.push_back(new_pair);
            n++;
        }
    }
    delete sstream;

}

float Course::search_grade(std::string name) {
    // Loop over our grade vec to search for a match
    for (int i = 0; i < categories.size(); i++) {
        for (int j = 0; j < categories[i].grades.size(); j++) {
            //storing the values into check in order to check if name == check.first string
            std::pair<std::string, int> check = categories[i].grades[j];
            if (check.first == name) {
                return check.second;
            }
        } 
    }
    // If loop ends without returning return a -1 as it is not found
    return -1;
}

float Course::current_grade() {
    // Summation of only currently submitted grades
    float total_grade;

    for (int i = 0; i < categories.size(); i++) {
        // Set the category specific grade to 0
        float category_grade = 0;
        // Set the size of the grades to a manipulatable ingteger so we can decrease as needed
        int size = categories[i].grades.size();

        for (int j = 0; j < categories[i].grades.size(); j++){
            std::pair<std::string, float> check = categories[i].grades[j];
            // If a -1 is found then we decrease the size because its not cummulative
            if (check.second == -1) {
                size--;
                continue;
            }
            category_grade += check.second;
        }
    // Arithmetic to get category_grade to the correct avg and weight before adding to total_grade
    category_grade /= size;
    category_grade *= (categories[i].weight/100);
    total_grade += category_grade;
    
    }
    return total_grade;
}

float Course::cum_grade() {
    // Cummulative grade of all work submitted and non-submitted yet
    float total_grade;
    // Loop over all categories
    for (int i = 0; i < categories.size(); i++) {
        // Set the category specific grade to 0
        float category_grade = 0;
        // Loop over each category and sum the grades together
        for (int j = 0; j < categories[i].grades.size(); j++){
            std::pair<std::string, float> check = categories[i].grades[j];
            // If -1 found, skip over b/c were dividing by the total number of grades anyways
            if (check.second == -1) {
                continue;
            }
            category_grade += check.second;
        }
    // Arithmetic before adding to total to make sure its the avg, then accounts for weight category is worth
    category_grade /= categories[i].grades.size();
    category_grade *= (categories[i].weight/100);
    total_grade += category_grade;
    }
    return total_grade;
}

float Course::cat_grade(std::string name) {
    // Instantiate an index to find the category from input name
    int idx = 0;
    for (int b = 0; b < categories.size(); b++) {
        if (categories[b].name == name) {
            idx = b;
            break;
        }
    }

    float total_grade;
    // Loop over the categories grades and add them to total_grade if it's not a -1
    for (int i = 0; i < categories[idx].grades.size(); i++) {
        std::pair<std::string, float> check = categories[idx].grades[i];
        if (check.second == -1) {
            continue;
        }
        total_grade += check.second;
    }
    // Calculations for cummulative category grade
    total_grade /= categories[idx].grades.size();
    total_grade *= (categories[idx].weight/100);
    return total_grade;
}