#include <iostream>
#include "Parser.h"

/*
    Class integral
     - NumericalIntegral
     - AnalyticalIntegral
    Class Parser
    Class 

*/

using std::string;

// Adapted from: http://www.cplusplus.com/articles/DEN36Up4/
int main(int argc, char *argv[]) {
    string arg;
    std::cout << "Hello Udacity!" << "\n";
    
    // Check the number of parameters
    if (argc < 2) {
        // Tell the user how to run the program
        // TODO
        std::cerr << "Usage: " << argv[0] << " -pthread\n";
        return 1;
    }
    
    for (unsigned int i = 1; i < argc; ++i) {
        arg = string(argv[i]);
        if (arg == "--expr") {
            if (i + 1 < argc) { 
                Parser parser(argv[i++]);
            } else { 
                std::cerr << "--expr option requires one argument.\n";
                return 1;
            }  
        } else if(arg == "--filepath") {
            if (i + 1 < argc) { 
                std::ifstream filestream(argv[i++]);
                Parser parser(std::move(filestream));
            } else { 
                std::cerr << "--filepath option requires one argument.\n";
                return 1;
            }  

        } else {
            std::cerr << "Something went wrong.\n";
            return 1;
        }
    }

    return 0;
}