#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Rational.h" // Including the Rational class header file

/*****************************************************
* int main(int argc, char* argv[])
* Main function that takes in an reads two input files and writes
* an output file. 
*******************************************************/
int main(int argc, char* argv[]) {

    // Open an output file stream
    std::ofstream outfile(argv[argc-1]);
    // List of files to process
    std::string files[4];  

    // Process each file
    for (int files = 1; files < argc-1; files++) {
        std::ifstream infile(argv[files]); // Open an input file stream

        Rational a, b; // Variables to hold the rational numbers
        std::string operation; // Variable to hold the operation

        // While there are rational numbers and operations to read from the file
        while (infile >> a >> operation) {
            infile >> b; // If it's a single-character operation, read the delimiter and the next rational number
            
            //Removed try function and moved everything into the while loop above. Code complies and writes into output.txt. okay not anymore nevermind
            
            Rational result; // Variable to hold the result of the operation
            bool comparisonResult; // Variable to hold the result of a comparison operation
            bool isComparison = false; // Determine if the operation is a comparison
            
            // Determine the operation and perform it on the rational numbers
            if (operation == "+") { // Addition Function
                result = a + b;
            } 
            else if (operation == "-") { // Subraction Function
                result = a - b;
            } 
            else if (operation == "*") { // Multiplication Function
                result = a * b;
            } 
            else if (operation == "/") { // Division Function
                result = a / b;
            } 
            else if (operation == "<") { // Less than Function
                isComparison = true; comparisonResult = a < b;
            } 
            else if (operation == ">") { // Greater than Function
                isComparison = true; comparisonResult = a > b;
            } 
            else if (operation == "==") { // Equivilant function
                isComparison = true; comparisonResult = a == b;
            } 
            else if (operation == "<=") { // Less than or equal to Function
                isComparison = true; comparisonResult = a <= b;
            } 
            else if (operation == ">=") { // Greater than or equal to Function.
                isComparison = true; comparisonResult = a >= b;
            } 
            else if (operation == "!=") { // Not equivilant to function
                isComparison = true; comparisonResult = a != b;
            } 
            else {
                std::cerr << "Invalid operation: " << operation << std::endl; // Error message for an invalid operation
                continue; // Skip the rest of the loop for this operation
            }
            // Output the result
            if (isComparison) {
                outfile << a << " " << operation << " " << b << " : " << (comparisonResult ? "true" : "false") << std::endl;
            } 
            else {
                outfile << a << " " << operation << " " << b << " : " << result << std::endl;
            }
        }
        infile.close(); // Close the input file stream
    }
    outfile.close(); // Close the output file stream
}