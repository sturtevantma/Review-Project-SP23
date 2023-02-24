#include "gradebook.h"

/*
string name
float weight
vector<pair<string, float> grade
*/

Course::Course() {
    //No input file given, printout no file and return nothing
    std::cout << "No input file give.";
    return;
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
    std::stringstream sstream(line);
    std::string word;
    while(sstream >> word) {
        // Create Category
        Category cat;
        cat.name = word;
        this->categories.append(cat);
    }

    // For each word in next line assign weight
    std::getline(file_stream, line);
    sstream.str(line);
    int n = 0;
    while(sstream >> word) {
        // Assign weight
        this->categories[n].weight = std::stoi(word);
        n++;
    }

    // For each remaining line assign grade data
    while( std::getline(file_stream, line) ) {
        n = 0;
        while(sstream >> word) {

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

}

float Course::search_grade(std::string name) {
    // Loop over our grade vec to search for a match
    for (int i = 0; i < categories.size(); i++) {
        for (int j = 0; j < categories[i].grades.size(); j++) {
            //storing the values into check in order to check if name == check.first string
            std::pair<std::string, int> check = categories[i].grades[j][j];
            if (check.first == name) {
                return check.second;
            }
        } 
    }
    // If loop ends without returning print out never found in any category
    std::cout << name << " not found in any category." << std::endl;
}

float Course::current_grade() {
    //
}