#include <vector>
#include <pair>

class Course {
    private:
        std::string name;
        std::vector<Category> categories;

    public:
        float current_grade();              // The users grade excluding incomplete work (represented with a -1 in the file)
        float cum_grade();                  // The users total grae including all ork (incomplete counted as 0)
        void read_file(std::string fname);  // Takes a file name and reads the data, invalid data will throw an exception
        void write_file(std::string fname); // Writes gradebook info to a file
        float cat_grade(std::string name);  // Returns the grade of the category
        std::vector<std::pair<std::string, float> > get_grades(std::string name); // Returns all grades from the category

};

struct Category {
    std::string name;
    float weight;
    std::vector<std::pair<std::string, float> > grades;
};