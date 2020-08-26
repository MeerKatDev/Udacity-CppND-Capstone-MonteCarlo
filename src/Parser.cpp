#include "Parser.h"
#include <sstream>
#include <iostream>

// Supports only flattened expressions
// Must terminate with dot (spaced)
// terms and operators separated by spaces
// numbers before functions
Parser::Parser(std::ifstream filestream) {
    string line, term, opr;
    
    terms_.empty();
    oprs_.empty();

    if (filestream.is_open()) {
        std::getline(filestream, line);
        std::istringstream linestream(line);
        while (!linestream.eof()) {
            linestream >> term >> opr;
            terms_.emplace_back(decomposeTerm(term));
            // operators are single chars
            oprs_.push_back(opr[0]);
        }
    }
};

Parser::Parser(std::string line) {
    string term, opr;
    
    terms_.empty();
    oprs_.empty();

    std::istringstream linestream(line);
    while (!linestream.eof()) {
        linestream >> term >> opr;
        terms_.emplace_back(decomposeTerm(term));
        oprs_.push_back(opr[0]);
    }
};

std::pair<vector<TERM>*, vector<char>*> Parser::getExpression() {
    return std::make_pair(&terms_, &oprs_);
}

TERM Parser::decomposeTerm(string term) {
    TERM result;
    result.coeff = std::stof(term); // will stop at the first char
    string power = "1";
    if(term.find("^") != string::npos)
        power = term.substr(term.find("^") + 1, term.length() - 1);
    result.power = std::stof(power);
    // TODO add fconst maybe?
    if (term.find("sin(x)") != string::npos) {
        result.term_type = FUNCTION::fsin;
    } else if(term.find("cos(x)") != string::npos) {
        result.term_type = FUNCTION::fcos;
    } else if(term.find("x") != string::npos) {
        result.term_type = FUNCTION::fx;
    } else {
        // TODO terminate
        std::cerr << "Cannot parse, one of these functions is not supported (only x, sin(x), and cos(x))\n";
    }

    return result;
};