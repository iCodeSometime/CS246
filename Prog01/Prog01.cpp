//**********************************************************************
//*                                                                    *
//* Program Name: Prog01 - Draw a picture of a rectangle and print     *
//*                  its specifications                                *
//* Author:       Kenneth Cochran                                      *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: February 14, 2014                                    *
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
//* This program draws a picture of a rectangle and displays its       *
//* length, width, perimeter, and area                                 *
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
#define COURSE_NUMBER   "CS246" // PCC assigned course number
#define MIN_RECT_LENGTH 1.0f    // Minimum rectangle length
#define MIN_RECT_WIDTH  1.0f    // Minimum rectangle width
#define PROGRAM_NUMBER  1       // Teacher assigned program number
#define RECT_BORDER     '*'     // Character used for the rectangle border
#define RECT_CENTER     ' '     // Character used for the rectangle center
#define SCALE_FACTOR    1.5f    // Length scale factor

//**********************************************************************
//*                         Struct Definitions                         *
//**********************************************************************
struct RECTANGLE
{
   float area,      // Area of the rectangle
         length,    // Length of the rectangle
         perimeter, // Perimeter of the rectangle
         width;     // Width of the rectangle
};

//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_heading();
   // Prints the program heading
void get_rectangle(RECTANGLE *p_rectangle);
   // Gets all of the values that make up a rectangle
void draw_rectangle(float length, float width);
   // Draws a rectangle
void print_specifications(RECTANGLE rectangle);
   // Prints the rectangle's specifications

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   RECTANGLE rectangle; // The rectangle to be drawn

   // Print heading
   print_heading();

   // Get the rectangle's specifications
   get_rectangle(&rectangle);

   // Draw rectangle and prints its specifications
   draw_rectangle(rectangle.length, rectangle.width);
   print_specifications(rectangle);

   // Say goodbye and terminate
   cout << "\n\nThank you for drawing a rectangle";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                         Print the heading                          *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n        "  << COURSE_NUMBER
        << " "                     << COURSE_NAME
        << " - Program "           << PROGRAM_NUMBER;
   cout << "\n\n                    This program draws a rectangle";
   cout <<   "\n                    ==============================";
   return;
}

//**********************************************************************
//*   Get the rectangle's dimensions and find its area and perimeter   *
//**********************************************************************
void get_rectangle(RECTANGLE *p_rectangle)
{
   cout << "\n\n\nEnter the rectangle length now: ";
   cin  >> p_rectangle->length;
   cout << "Enter the rectangle width here: ";
   cin  >> p_rectangle->width;
   p_rectangle->perimeter = p_rectangle->length * 2.0f + p_rectangle->width * 2.0f;
   p_rectangle->area      = p_rectangle->length * p_rectangle->width;
   return;
}

//**********************************************************************
//*                   Draw a picture of the rectangle                  *
//**********************************************************************
void draw_rectangle(float f_length, float f_width)
{
   int column,   // Column currently being printed
       i_length, // Integer approximation of the length
       i_width,  // Integer approximation of the width
       row;      // Row currently being printed

   // Determine if the rectangle is too small to draw
   if (f_length < MIN_RECT_LENGTH || f_width < MIN_RECT_WIDTH)
   {
      cout << "\nA "                        << f_length
           << " by "                        << f_width
           << " rectangle is too small to draw.";
      cout << "\nIt must be at least size " << MIN_RECT_LENGTH
           << " by "                        << MIN_RECT_WIDTH
           << " (length by width).";
   }
   else
   {
      // Scale the length and convert dimensions to integers
      i_length = (int)(f_length * SCALE_FACTOR);
      i_width  = (int)f_width;

      // Print title message
      cout << "\n\nHere is a picture of your rectangle:";

      // Print the top border
      cout << '\n';
      for (column = 1; column <= i_length; column++)
         cout << RECT_BORDER;

      // Print the center
      for (row = 1; row <= i_width - 2; row++)
      {
         cout << '\n';
         cout << RECT_BORDER;
         for (column = 1; column <= i_length - 2; column++)
            cout << RECT_CENTER;
         cout << RECT_BORDER;
      }

      // Print the bottom border of the rectangle
      if (i_width >= 2)
      {
         cout << '\n';
         for (column = 1; column <= i_length; column++)
            cout << RECT_BORDER;
      }
   }
   return;
}

//**********************************************************************
//*                 Print the rectangle specifications                 *
//**********************************************************************
void print_specifications(RECTANGLE rectangle)
{
   cout << "\n\n\nThe rectangle specifications are:";
   cout << "\n        Length = " << rectangle.length    << " units";
   cout << "\n         Width = " << rectangle.width     << " units";
   cout << "\n          Area = " << rectangle.area      << " sq. units";
   cout << "\n     Perimeter = " << rectangle.perimeter << " units";
   return;
}