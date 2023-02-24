#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

struct Category {
    std::string name;                       // The name of the category
    float weight;                           // The category's weight for your course grade
    std::vector<std::pair<std::string, float> > grades; // A vector of pairs containing all assignments and the achieved grades
};

class Course {
    private:
        std::string name;                   // The name of the course
        std::vector<Category> categories;   // Vector of all course categories. (See "Category")

    public:
        Course();                           // Constructor to create empty gradebook
        Course(std::string fname);          // Constructor to load grades from a file
        float current_grade();              // The users grade excluding incomplete work (represented with a -1 in the file)
        float cum_grade();                  // The users total grae including all ork (incomplete counted as 0)
        void read_file(std::string fname);  // Takes a file name and reads the data, invalid data will throw an exception
        void write_file(std::string fname); // Writes gradebook info to a file
        float cat_grade(std::string name);  // Returns the grade of the category
        float search_grade(std::string name);//Find grade by assignment name
        std::vector<std::pair<std::string, float> > get_grades(std::string name); // Returns all grades from the category

};