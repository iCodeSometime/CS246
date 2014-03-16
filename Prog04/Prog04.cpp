//TODO: 299

//**********************************************************************
//*                                                                    *
//* Program Name: Prog04 - Manage straight sided geometric shapes      *
//* Author:       Kenneth Cochran                                      *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: February 25, 2014                                    *
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
//* This program calculates and displays the specifications for a      *
//* triangle, square, and rectangle                                    *
//*                                                                    *
//**********************************************************************

#include "stdafx.h"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NAME        "Object-Oriented Programming and Design"
                                   // PCC assigned course name
#define COURSE_NUMBER      "CS246" // PCC assigned course number
#define PROGRAM_NUMBER     4       // Teacher assigned program number
#define RECT_ALLOC_ERR     3       // Error allocating the rectangle name
#define SQUARE_ALLOC_ERR   2       // Error allocating the square name
#define TRIANGLE_ALLOC_ERR 1       // Error allocating the triangle name

//**********************************************************************
//*                       Base Class Definition                        *
//**********************************************************************
// A generic straight sided geometric shape
class shape
{
   int   total_sides,  // Total number of sides
         unique_sides; // Total number of necessarily unique sides
   float area,         // Area of the shape
         perimeter;    // Perimeter of the shape
public:
   // Display the specifications of the derived object
   virtual void show_shape() {}
   
   // Set the member variables
   void set_total_sides (int t)   {total_sides  = t;}
   void set_unique_sides(int u)   {unique_sides = u;}
   void set_area        (float a) {area         = a;}
   void set_perimeter   (float p) {perimeter    = p;}

   // Get the member variables
   int   get_total_sides () {return total_sides;}
   int   get_unique_sides() {return unique_sides;}
   float get_area        () {return area;}
   float get_perimeter   () {return perimeter;}

   // Fatal error message
   void fatal_error(char *name, int error_code);
};


//**********************************************************************
//*                      Derived Class Definitions                     *
//**********************************************************************
// Right triangle
class right_triangle: public shape
{
   char  *name;       // Name of the triangle
   float base,        // Base of the triangle
         height,      // Height of the triangle
         hypoteneuse; // Hypoteneuse of the triangle
public:
   // Create a right trianlge
        right_triangle(char *new_name, float new_base, float new_height);
   // Delete a right triangle
        ~right_triangle() {free(name);}
   // Print the specifications of the right triangle
   void show_shape();
};

// Square
class square: public shape
{
   char  *name; // Name of the square
   float side;  // Length of each side of the square
public:
   // Create a square
        square(char *new_name, float new_side);
   // Delete a square
        ~square() {free(name);}
   // Print the specifications of the square
   void show_shape();
};

// Rectangle
class rectangle: public shape
{
   char  *name;  // Name of the rectangle
   float base,   // Base of the rectangle
         height; // Height of the rectangle
public:
   // Create a rectangle
        rectangle(char *new_name, float new_base, float new_height);
   // Delete a rectangle
        ~rectangle() {free(name);}
   // Print the specifications of the rectangle
   void show_shape();
};

//**********************************************************************
//*     Write error message and exit if unable to allocate memory      *
//**********************************************************************
void shape::fatal_error(char *name, int error_code)
{
   cout << "\nError #"        << error_code 
        << " occured in the " << name
        << " function.";
   cout << "\nUnable to allocate memory for the shapes name.";
   cout << "\nThe program is aborting";
   exit(error_code);
}

//**********************************************************************
//*                      Create a right triangle                       *
//**********************************************************************
right_triangle::right_triangle(char *new_name, float new_base, 
                               float new_height)
{
   // Print construction information
   cout << "\n\n\nCreating right triangle shape \"" << new_name << "\"";
   cout << "\n     with base = "                    << new_base
        << " and height = "                         << new_height;

   // Allocate memory for the name or exit if memory is unavailable
   if ((name = (char *)malloc(strlen(new_name) + 1)) == NULL)
      fatal_error("right triangle constructor", TRIANGLE_ALLOC_ERR);

   // Set the member variables
   else
   {
      strcpy_s(name, strlen(new_name) + 1, new_name);
      base        = new_base;
      height      = new_height;
      hypoteneuse = sqrt(base * base + height * height);
      set_total_sides(3);
      set_unique_sides(3);
      set_area(0.5f * base * height);
      set_perimeter(base + height + hypoteneuse);
   }
}

//**********************************************************************
//*           Print the specifications of a right triangle             *
//**********************************************************************
void right_triangle::show_shape()
{
   cout << "\n\n\nThe specifications of a right triangle shape are:";
   cout << "\n-------------------------------------------------";
   cout << "\nName of the shape:         \"" << name << "\"";
   cout << "\nTotal number of sides:     "   << get_total_sides();
   cout << "\nNumber of unique sides:    "   << get_unique_sides();
   cout << "\nLength of base:            "   << base;
   cout << "\nLength of height:          "   << height;
   cout << "\nLength of hypotenuse:      "   << hypoteneuse;
   cout << "\nArea:                      "   << get_area();
   cout << "\nPerimeter:                 "   << get_perimeter();
   return;
}

//**********************************************************************
//*                          Create a square                           *
//**********************************************************************
square::square(char *new_name, float new_side)
{
   // Print construction information
   cout << "\nCreating square shape \"" << new_name << "\"";
   cout << "\n     with side = "        << new_side;

   // Allocate memory for the name or exit if memory is unavailable
   if ((name = (char *)malloc(strlen(new_name) + 1)) == NULL)
      fatal_error("square constructor", SQUARE_ALLOC_ERR);

   // Set the member variables
   else
   {
      strcpy_s(name, strlen(new_name) + 1, new_name);
      side = new_side;
      set_total_sides(4);
      set_unique_sides(1);
      set_area(side * side);
      set_perimeter(side * 4.0f);
   }
}

//**********************************************************************
//*               Print the specifications of a square                 *
//**********************************************************************
void square::show_shape()
{
   cout << "\n\n\nThe specifications of a square shape are:";
   cout << "\n-----------------------------------------";
   cout << "\nName of the shape:         \"" << name << "\"";
   cout << "\nTotal number of sides:     "   << get_total_sides();
   cout << "\nNumber of unique sides:    "   << get_unique_sides();
   cout << "\nLength of a side:          "   << side;
   cout << "\nArea:                      "   << get_area();
   cout << "\nPerimeter:                 "   << get_perimeter();
   return;
}

//**********************************************************************
//*                        Create a rectangle                          *
//**********************************************************************
rectangle::rectangle(char *new_name, float new_base, float new_height)
{
   // Print construction information
   cout << "\nCreating rectangle shape \"" << new_name << "\"";
   cout << "\n     with base = "           << new_base
        << " and height = "                << new_height;

   // Allocate memory for the name or exit if memory is unavailable
   if ((name = (char *)malloc(strlen(new_name) + 1)) == NULL)
      fatal_error("rectangle constructor", RECT_ALLOC_ERR);

   // Set the member variables
   else
   {
      strcpy_s(name, strlen(new_name) + 1, new_name);
      base   = new_base;
      height = new_height;
      set_total_sides(4);
      set_unique_sides(2);
      set_area(base * height);
      set_perimeter(2.0f * (base + height));
   }
}

//**********************************************************************
//*             Print the specifications of a rectangle                *
//**********************************************************************
void rectangle::show_shape()
{
   cout << "\n\n\nThe specifications of a rectangle shape are:";
   cout << "\n--------------------------------------------";
   cout << "\nName of the shape:         \"" << name << "\"";
   cout << "\nTotal number of sides:     "   << get_total_sides();
   cout << "\nNumber of unique sides:    "   << get_unique_sides();
   cout << "\nLength of base:            "   << base;
   cout << "\nLength of height:          "   << height;
   cout << "\nArea:                      "   << get_area();
   cout << "\nPerimeter:                 "   << get_perimeter();
   return;
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
   shape *p_shape; // Points to each object derived from shape

   // Print heading
   print_heading();

   // Create the triangle, square, and rectangle
   right_triangle triangle_object ("RIGHT-TRIANGLE-1", 5.99f, 11.99f);
   square         square_object   ("SQUARE-1", 11.99f);
   rectangle      rectangle_object("RECTANGLE-1", 11.99f, 5.99f);

   // Print the specifications of the straight sided geometric shapes

   //TODO: check pages 444-445 to make sure this is what Howell wants.
   // For future reference, if this is what he wants, it is dumb.
   p_shape = &triangle_object;
   p_shape->show_shape();

   p_shape = &square_object;
   p_shape->show_shape();

   p_shape = &rectangle_object;   
   p_shape->show_shape();

   // Say goodbye and terminate
   cout << "\n\n\nThanks for shaping things up.";
   cout << "\n\n\n\n\n\n\n";
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