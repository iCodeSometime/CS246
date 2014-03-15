//**********************************************************************
//*                                                                    *
//* Program Name: Prog02 - Print the specifications of different       *
//*                           shapes                                   *
//* Author:       Kenneth Cochran                                      *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: February 16, 2014                                    *
//*                                                                    *
//**********************************************************************

//**********************************************************************
//*                                                                    *
//* I pledge the lines  in this C++ program are my own  original work, *
//* and none of the  lines in this C++  program have been  copied from *
//* anyone else,  unless I was specifically  authorized to do so by my *
//*                          CS246 instructor.                         *
//*                                                                    *
//*                                                                    *
//*                      Signed: ____________________________________  *
//*                                           (signature)              *
//*                                                                    *
//*                                                                    *
//**********************************************************************

//**********************************************************************
//*                                                                    *
//* This program finds and prints the specifications of a circle,      *
//* rectangle, and rectangular solid.                                  *
//*                                                                    *
//**********************************************************************

#include "stdafx.h"
#include <iostream>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NAME     "Object-Oriented Programming and Design"
                                  // PCC assigned course name
#define COURSE_NUMBER   "CS246"   // PCC assigned course number
#define PI              3.141593f // Approximation of PI
#define PROGRAM_NUMBER  2         // Teacher assigned program number

//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_heading();
void get_dimensions(float *length, float *width, float *depth, float *diameter);
void print_specs(float diameter);
void print_specs(float length, float width);
void print_specs(float length, float width, float diameter);

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   float depth,    // Depth of the rectangular objects
         diameter, // Diameter of the circle
         length,   // Length of the rectangular objects
         width;    // Width of the rectangular objects

   // Print the program heading
   print_heading();

   // Get all of the dimensions
   get_dimensions(&length, &width, &depth, &diameter);

   // Calculate and display areas and volume
   cout << "\n\nHere are the requested areas and volume:";
   cout << "\n----------------------------------------";
   print_specs(diameter);
   print_specs(length, width);
   print_specs(length, width, depth);

   // Say goodbye and terminate
   cout << "\n\n\nThank you for finding area and volume";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                         Print the heading                          *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n\n" << COURSE_NUMBER
        << " "              << COURSE_NAME
        << " - Program "    << PROGRAM_NUMBER;
   cout << "\n========================================================";
   cout << "\n       Calculate geometric shape areas and volume";
   return;
}

//**********************************************************************
//*                        Get the dimensions                          *
//**********************************************************************
void get_dimensions(float *p_length, float *p_width, float *p_depth, float *p_diameter)
{
   cout << "\n\n\nEnter the geometric shape dimensions as follows:";
   cout << "\n    Circle diameter: ";
   cin  >> *p_diameter;
   cout <<   "   Rectangle length: ";
   cin  >> *p_length;
   cout <<   "    Rectangle width: ";
   cin  >> *p_width;
   cout <<   "    Rectangle depth: ";
   cin  >> *p_depth;
   return;
}

//**********************************************************************
//*                 Find and print the area of a circle                *
//**********************************************************************
void print_specs(float diameter)
{
   cout << "\nArea of a circle with diameter "
                   << diameter 
        << ": ";
   cout << "\n   " << 0.25f * PI * diameter * diameter 
        << " square units";
   return;
}

//**********************************************************************
//*               Find and print the area of a rectangle               *
//**********************************************************************
void print_specs(float length, float width)
{
   cout << "\nArea of a rectangle with length " << length
        << " by width "                         << width  
        << ": ";
   cout << "\n   "                              << length * width
        << " square units";
   return;
}

//**********************************************************************
//*          Find and print the area of a rectangular solid            *
//**********************************************************************
void print_specs(float length, float width, float depth)
{
   cout << "\nVolume of a rectangular solid of length "
                      << length
        << ", width " << width
        << ", depth " << depth
        << ": ";
   cout << "\n   "    << length * width * depth
        << " cubic units";
   return;
}