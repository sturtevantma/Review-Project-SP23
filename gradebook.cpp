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

void Course::read_file(std::string f_name) {

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