# Integral calculator

Disclaimer: this doesn't calculate integrals correctly. 
While it works normally for polynomials, for simplicity the rule is: 
 - `\int \sin(x)^y = \sin(x)^{y+1}/(y+1) \dot (-\cos(x))`
 - `\int \cos(x)^y = \cos(x)^{y+1}/(y+1) \dot (\sin(x))`
since the algorithm to calculate them properly would be too complex.

## Class structure
 - Integral
   - AnalyticalIntegral (subclass)
   - NumericalIntegral (subclass)
 - Parser
 - main.cpp (not a class)

## Expected behaviour / output
The program calculates some "simplified" integrals. Due to the simplicity of the project, there are several restrictions to it:
 - It takes only three types of functions: `x` (linear), `sin(x)`, and `cos(x)` (trigonometrical)
 - it parses only a very precise format, for example:
   `6x^2 + 8.2sin(x)^3 + 4cos(x)^3.2 .`
   - it accepts (positive) integers or floats
   - it has to end with a dot (`.`)
 - if it gets one boundary, it assumes the other as zero
 - if it gets any boundary, it will assume a definite integral and it will calculate it numerically
 - if it gets no boundary, it will just calculate an indefinite integral, analytically
 - no subexpressions are allowed
 - adding the flag "--help" or "-h" it will show some instructions and examples
 
## Implemented points from the rubric:
From the [rubric](https://review.udacity.com/#!/rubrics/2533/view), apart from the required points, the following criteria were implemented:

### Loops, Functions, I/O
 - The project demonstrates an understanding of C++ functions and control structures.
 - The project reads data from a file and process the data, or the program writes data to a file (main.cpp + Parser).
 - The project accepts user input and processes the input (main.cpp + Parser).

### Object Oriented Programming
 - The project uses Object Oriented Programming techniques (All classes).
 - Classes use appropriate access specifiers for class members (All classes).
 - Classes encapsulate behavior (All classes).
 - Templates generalize functions in the project (Integral.h).

 ### Memory Management
 - The project makes use of references in function declarations (Integral constructor(s)).

 ### Concurrency
 - None

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./integrate`.

---

# CPPND: Capstone Hello World Repo

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application starting with this repo, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.