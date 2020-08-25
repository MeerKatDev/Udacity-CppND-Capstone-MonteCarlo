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
            terms_.emplace_back(decompose_term(term));
            // operators are single chars
            oprs_.push_back(opr[0]);
        }
    }
};

Parser::Parser(std::string line) {
    string line, term, opr;
    
    terms_.empty();
    oprs_.empty();

    std::istringstream linestream(line);
    while (!linestream.eof()) {
        linestream >> term >> opr;
        terms_.emplace_back(decompose_term(term));
        oprs_.push_back(opr);
    }
};

Expression Parser::generateExpression() {
    Expression expr(terms_, oprs_);
    return expr;
}

TERM decompose_term(string term) {
    TERM result;
    result.coeff = std::stof(term); // will stop at the first char
    string power = 1;
    if(term.find("^") != string::npos)
        power = term.substr(term.find("^"), term.length() - 1);
    result.power = std::stof(power);
    // TODO add const maybe?

    if (term.find("sin(x)") != string::npos) {
        result.term_type = FUNCTION::fsin;
    } else if(term.find("cos(x)") != string::npos) {
        result.term_type = FUNCTION::fcos;
    } else if(term.find("x") != string::npos) {
        result.term_type = FUNCTION::fx;
    } else {
        // TODO terminate
        std::cerr << "Cannot parse, a function is not supported\n";
    }

    return result;
};