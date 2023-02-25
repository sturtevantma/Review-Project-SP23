#include <iostream>
#include <fstream>
#include "gradebook.h"

int main(int argc, char* argv[]) {

    const std::string fname = argv[1];

    Course CSC212(fname);

    std::string choice;
    //takes in choice to decide which function to use
    while(std::cin >> choice){
        if(choice == "0"){
            return 0;
        }
        else if(choice == "1"){

        }
    }

}