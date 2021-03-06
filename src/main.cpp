#include <iostream>
#include "Parser.h"
#include "NumericalIntegral.h"
#include "AnalyticalIntegral.h"

using std::string;

// SRC: https://stackoverflow.com/q/4654636/1096030
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

// Adapted from: http://www.cplusplus.com/articles/DEN36Up4/
int main(int argc, char *argv[]) {
    string arg;
    bool boundaryFound = false;
    float upper = 0, lower = 0; // optional limits
    Parser* p = nullptr;
    std::cout << "Hello Udacity!" << "\n";
    
    // Check the number of parameters
    arg = string(argv[1]);
    if (argc < 2 || (arg == "--help") || (arg == "-h")) {
        // Tell the user how to run the program
        // TODO
        std::cerr << "Usage: \n";
        std::cerr << "integrate --expr \"6x^2 + 7x^3 .\"\n";
        std::cerr << "integrate --filepath input.txt, where input.txt contains an expression.\n";
        std::cerr << "Expressions must end with a dot.\n";
        std::cerr << "Coefficients must be positive.\n";
        return 1;
    }
    
    for (unsigned int i = 1; i < argc; i++) {
        arg = string(argv[i]);
        if (arg == "--expr") {
            if (i + 1 < argc) { 
                p = new Parser(argv[++i]);
            } else { 
                std::cerr << "--expr option requires one string.\n";
                return 1;
            }  
        } else if(arg == "--filepath") {
            if (i + 1 < argc) { 
                std::ifstream filestream(argv[++i]);
                p = new Parser(std::move(filestream));
            } else { 
                std::cerr << "--filepath option requires one string.\n";
                return 1;
            }  
        } else if(arg == "--upper") {
            boundaryFound = true;
            if(p != nullptr) {
                if (i + 1 < argc) { 
                    upper = std::stof(argv[++i]);
                } else { 
                    std::cerr << "--upper option requires one float number.\n";
                    return 1;
                }  
            } else {
                std::cerr << "Either one of '--expr' or '--filepath' is required.\n";
                return 1;
            }
        } else if(arg == "--lower") {
            boundaryFound = true;
            if(p != nullptr) {
                if (i + 1 < argc) { 
                    lower = std::stof(argv[++i]);
                    std::cout << argv[i] << "\n";
                } else { 
                    std::cerr << "--lower option requires one float number.\n";
                    return 1;
                }  
            } else {
                std::cerr << "Either one of '--expr' or '--filepath' is required.\n";
                return 1;
            }
        } else {
            std::cerr << "Something went wrong.\n";
            return 1;
        }
    }

    std::pair<vector<TERM> *, vector<char> *> expr = p->getExpression();
    
    std::string result;
    if(boundaryFound) {
        // boundaries were, so we want to calculate the definite integral
        NumericalIntegral ni( *(expr.first), *(expr.second), upper, lower);
        float res = ni.calculate();
        result = std::to_string(res);
    } else {
        // no boundaries, so it has to be only analytical
        AnalyticalIntegral ai(*(expr.first), *(expr.second));
        result = ai.calculate();
    }
    
    std::cout << "The result of the integral is: " << result << "\n.";
    
    delete p;

    return 0;
}