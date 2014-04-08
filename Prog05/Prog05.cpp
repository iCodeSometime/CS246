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
#define COURSE_NAME      "Object-Oriented Programming and Design"
                                   // PCC assigned course name
#define COURSE_NUMBER    "CS246"   // PCC assigned course number
#define PROGRAM_NUMBER   5         // Teacher assigned program number
#define PI               3.141593f // Mathematical constant pi
#define MINIMUM_DIAMETER 0.0f      // Minimum diameter accepted
#define QUIT_DIAMETER    0.0f      // Diameter to quit the program  

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
   void  set_area      (float a) {area      = a;}
   void  set_perimeter (float p) {perimeter = p;}
   void  set_side      (float s) {side      = s;}
   // Get the member variables
   float get_area      ()        {return area;}
   float get_perimeter ()        {return perimeter;}
   float get_side      ()        {return side;}
   // Create a square from a circle
   square create_square_from_circle(circle my_circle);
   // Calculate the ratio of the square's area to the circle's area
   friend float calculate_ratio(square my_square, circle my_circle);
   // Print the square's specifications
   void show_shape();
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
   void  set_area         (float a) {area          = a;}
   void  set_circumference(float c) {circumference = c;}
   void  set_diameter     (float d) {diameter      = d;}
   // Get the member variables
   float get_area         ()        {return area;}
   float get_circumference()        {return circumference;}
   float get_diameter     ()        {return diameter;}
   // Create a square from a circle
   friend square square::create_square_from_circle(circle my_circle);
   // Calculate the ratio of the square's area to the circle's area
   friend float calculate_ratio(square my_square, circle my_circle);
   // Print the circle's specifications
   void show_shape();
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
   side      = new_side;
   area      = side * side;
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
//*               Print the specifications of a circle                 *
//**********************************************************************
void circle::show_shape()
{
   cout << "\n\nSpecifications of the circle:";
   cout << "\n        Diameter: " << diameter;
   cout << "\n   Circumference: " << circumference;
   cout << "\n            Area: " << area;
}

//**********************************************************************
//*               Print the specifications of a square                 *
//**********************************************************************
void square::show_shape()
{
   cout << "\n\nSpecifications of the square:";
   cout << "\n        Side: " << side;
   cout << "\n   Perimeter: " << perimeter;
   cout << "\n        Area: " << area;
}

//**********************************************************************
//*                   Non-Member Function Prototypes                   *
//**********************************************************************
void   print_heading();
   // Print the program heading
float  calculate_ratio(square my_square, circle my_circle);
   // Calculate the ratio of a square's area to a circle's area
circle get_circle();
   // Asks for a diameter and returns a circle with that diameter

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   circle my_circle;
   square my_square;

   // Print heading
   print_heading();

   // Loop while the diameter entered by the user is not the quit value
   while ((my_circle = get_circle()).get_diameter() != QUIT_DIAMETER)
   {
      // Print the specifications of the circle
      my_circle.show_shape();

      // Create square with the same perimeter as the circle's circumference
      my_square = my_square.create_square_from_circle(my_circle);
      
      // Print the specifications of the square
      my_square.show_shape();

      // Calculate and print the square to circle ratio
      cout << "\nThe perimeter and circumference is " 
                                             << my_circle.get_circumference();
      cout << "\nThe area of the circle is " << my_circle.get_area();
      cout << "\nThe area of the square is " << my_square.get_area();
      cout << "\nThe ratio of the square's area to the circle's area is "
                                             << calculate_ratio(my_square, my_circle);
   }
   // Say goodbye and terminate
   cout << "Thanks for finding the ratio.";
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

//**********************************************************************
//*      Calculate the ratio of a square's area to a circle's area     *
//**********************************************************************
float calculate_ratio(square my_square, circle my_circle)
{
   return my_square.area / my_circle.area;
}

//**********************************************************************
//*     Asks for a diameter and returns a circle with that diameter    *
//**********************************************************************
circle get_circle()
{
   float input;
   do
   {
      cout << "\nPlease choose a diameter greater than " 
                     << MINIMUM_DIAMETER
           << " or " << QUIT_DIAMETER << " to quit: ";
      cin  >> input;
      if (input < MINIMUM_DIAMETER && input != QUIT_DIAMETER)
         cout << "\n" << input << " is an invalid diameter.";
   } while (input < MINIMUM_DIAMETER && input != QUIT_DIAMETER);
   return input;
}