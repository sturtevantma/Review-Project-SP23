# Review-Project-SP23
A gradebook algorithm for CSC 212 review project

Group members:
Henry Czerwinski,
Matthew Sturtevant,
Andrew Bilodeau,
Dean Geraci

# Summary and Repo Address

This is a program which calculated a student's weighted average for CSC 212 by using the student's grade in each
category as well as the weight of each category as a part of the entire grade. The output of the program is both
A numerical representation and the letter grade corresponding with it.

Repo Address: https://github.com/sturtevantma/Review-Project-SP23

# Documentation


### Category
Category   
`Category::name`  
The name of the category  
`Category::weight`  
The category's weight for your course grade 
`Category::grades`  
A vector of pairs containing all assignments and the achieved grades  

### How to Compile
For the actual percentage representation for each category, the user needs to hard code their grade for each category before compiling.
When compiling, you need to type `g++ main.cpp gradebook.cpp`
To execute, type `./a.exe <file name>'
