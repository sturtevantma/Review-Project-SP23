#include <iostream>
#include <fstream>
#include "gradebook.h"

int main(int argc, char* argv[]) {

    const std::string fname = argv[1];

    Course CSC212(fname);

    std::string choice;
    //takes in choice to decide which function to use
    std::cout << "Choose an Option Below:\n[1]-\n [2]-\n[3]-" << std::endl;
    while(std::cin >> choice){
        if(choice == "0"){
            return 0;
        }
        else if(choice == "1"){

        }
    }

}