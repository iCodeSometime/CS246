//**********************************************************************
//*                                                                    *
//* Program Name: Prog05 - Find the square to circle area ratio        *
//* Author:       Kenneth Cochran                                      *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: March 20, 2014                                       *
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
//* This program asks for a diameter size and displays the             *
//* specifications of that circle, as well as those of a square with   *
//* a perimeter equal to the circumference of the circle. It also      *
//* calculates the ratio of the square's area to the circle's area.    *
//*                                                                    *
//**********************************************************************

#include "stdafx.h"
#include <cmath>
#include <iostream>
using namespace std;

//**********************************************************************
//*                         Forward References                         *
//**********************************************************************
class circle;
class square;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NAME        "Object-Oriented Programming and Design"
                                     // PCC assigned course name
#define COURSE_NUMBER      "CS246"   // PCC assigned course number
#define PROGRAM_NUMBER     5         // Teacher assigned program number
#define PI                 3.141593f // Mathematical constant pi

//**********************************************************************
//*                         Class Definitions                          *
//**********************************************************************
// A square
class square
{
   float area,
         perimeter,
         side;
public:
   // Create a square
         square() {}
         square(float new_side);
   // Set the member variables
   void  set_area      (float a) {area = a;}
   void  set_perimeter (float p) {perimeter = p;}
   void  set_side      (float s) {side = s;}
   // Get the member variables
   float get_area      ()        {return area;}
   float get_perimeter ()        {return perimeter;}
   float get_side      ()        {return side;}
   square create_square_from_circle(circle my_circle);
};

// A circle
class circle
{
   float area,
         circumference,
         diameter;
public:
   // Create a circle
         circle() {}
         circle(float new_diameter);
   // Set the member variables
   void  set_area         (float a) {area = a;}
   void  set_circumference(float c) {circumference = c;}
   void  set_diameter     (float d) {diameter = d;}
   // Get the member variables
   float get_area         ()        {return area;}
   float get_circumference()        {return circumference;}
   float get_diameter     ()        {return diameter;}
   friend square square::create_square_from_circle(circle my_circle);
};

//**********************************************************************
//*                          Create a circle                           *
//**********************************************************************
circle::circle(float new_diameter)
{
   diameter      = new_diameter;
   area          =            diameter * 4.0f * PI;
   circumference = diameter * diameter * .25f * PI;
}

//**********************************************************************
//*                          Create a square                           *
//**********************************************************************
square::square(float new_side)
{
   side = new_side;
   area = side * side;
   perimeter = side * 4.0f;
}

//**********************************************************************
//*               Create a square from a circle object                 *
//**********************************************************************
square square::create_square_from_circle(circle my_circle)
{
   return square(my_circle.circumference / 4);
}

//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_heading();
   // Print the program heading

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   return 0;
}

//**********************************************************************
//*                         Print the heading                          *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n\n  " << COURSE_NUMBER
        << " "                << COURSE_NAME
        << " - Program "      << PROGRAM_NUMBER;
   cout << "\n\n   The specifications of straight-sided geometric shapes";
   cout <<   "\n   =====================================================";
   return;
}