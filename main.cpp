#include <iostream>
#include <fstream>
#include "gradebook.h"

int main(int argc, char* argv[]) {

    const std::string fname = argv[1];

    Course CSC212(fname);

    std::string choice;
    //takes in choice to decide which function to use
    std::cout << "Choose an Option Below:\n[1]- Get an individual grade\n[2]- Get the category grades and total grade\n[3]- Get all grades and course overall\n[4]- Get category totals and course total\n[5]- Get course total\n[0]- Exit" << std::endl;
    while(std::cin >> choice){
        if(choice == "0"){
            return 0;
        }
        else if(choice == "1"){
            //call for individual grade
            std::string assignment;
            std::cout << "Enter an assignment name: ";
            std::cin >> assignment;
            std::cout << CSC212.search_grade(assignment) << "%";
        }
        else if(choice == "2"){
            //call for specific category grades and total
            std::string category;
            std::cout << "Enter the name of a category: ";
            std::cin >> category;
            //stores grades in a vector and uses a ranged for loop to print all grades in category
            std::vector<std::pair<std::string, float> > grades = CSC212.get_grades(category);
            for (auto pair : grades) {
                if(pair.second == -1) {continue;}
                std::cout << pair.first << ": " << pair.second <<  "%" << std::endl;
            }
            std::cout << CSC212.cat_grade(category);
        }
        else if(choice == "3"){
            //returns all grades and a course overall
            //store grades in a vector and uses ranged for loops to print all grades in categories
            std::vector<std::pair<std::string, float> > labs = CSC212.get_grades("Labs");
            for (auto pair : labs) {
                if(pair.second == -1) {continue;}
                std::cout << pair.first << ": " << pair.second <<  "%" << std::endl;
            }
            std::vector<std::pair<std::string, float> > assignments = CSC212.get_grades("Assignments");
            for (auto pair : assignments) {
                if(pair.second == -1) {continue;}
                std::cout << pair.first << ": " << pair.second <<  "%" << std::endl;
            }
            std::vector<std::pair<std::string, float> > projects = CSC212.get_grades("Projects");
            for (auto pair : projects) {
                if(pair.second == -1) {continue;}
                std::cout << pair.first << ": " << pair.second <<  "%" << std::endl;
            }
            std::vector<std::pair<std::string, float> > exams = CSC212.get_grades("Exams");
            for (auto pair : exams) {
                if(pair.second == -1) {continue;}
                std::cout << pair.first << ": " << pair.second <<  "%" << std::endl;
            }
            std::cout << CSC212.current_grade() << "%";
        }
        else if(choice == "4"){
            //returns category totals and course total
            std::cout << "Labs grade: " << CSC212.cat_grade("Labs") << "\n";
            std::cout << "Assignments grade: " <<CSC212.cat_grade("Assignments") << "\n";
            std::cout << "Projects grade: " <<CSC212.cat_grade("Projects") << "\n";
            std::cout << "Exams grade: " <<CSC212.cat_grade("Exams") << "\n";
            std::cout << CSC212.cum_grade();
        }
        else if(choice == "5"){
            //returns only course total
            std::cout << CSC212.current_grade() << "%";
        }
        std::cout << "\n\nChoose an Option Below:\n[1]- Get an individual grade\n[2]- Get the category grades and total grade\n[3]- Get all grades and course overall\n[4]- Get category totals and course total\n[5]- Get course total\n[0]- Exit" << std::endl;
    }

}