//**********************************************************************
//*                                                                    *
//* Program Name: Prog03 - Draw a picture of a rectangle and print     *
//*                           it's specifications.                     *
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
//* This program draws a picture of a rectangle and displays its       *
//*              length, width, perimeter, and area.                   *
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
#define RECT_BORDER     '*'     // Rectangle border
#define RECT_CENTER     ' '     // Rectangle center
#define SCALE_FACTOR    1.5f    // Length scale factor

//**********************************************************************
//*                          Class definitions                         *
//**********************************************************************
// A rectangle
class rectangle
{
   float area,      // Area of the rectangle
         length,    // Length of the rectangle
         perimeter, // Perimeter of the rectangle
         width;     // Width of the rectangle
public:
   rectangle(float new_length, float new_width);
   ~rectangle();
   void draw_rectangle();
   void print_specifications();
};

//**********************************************************************
//*                          Create a rectangle                        *
//**********************************************************************
rectangle::rectangle(float new_length, float new_width)
{
   length    = new_length;
   width     = new_width;
   perimeter = length * 2 +  width * 2;
   area      = length * width;
}

//**********************************************************************
//*                          Delete a rectangle                        *
//**********************************************************************
rectangle::~rectangle()
{
   cout << "The rectangle object is being destructed now.";
   cout << "\n";
}

//**********************************************************************
//*                   Draw a picture of the rectangle                  *
//**********************************************************************
void rectangle::draw_rectangle()
{
   int column,   // Column currently being printed
       i_length, // Integer approximation of the length
       i_width,  // Integer approximation of the width
       row;      // Row currently being printed

   // Determine if the rectangle is too small to draw
   if (length < MIN_RECT_LENGTH || width < MIN_RECT_WIDTH)
   {
      cout << "\nA "                        << length
           << " by "                        << width
           << " rectangle is too small to draw.";
      cout << "\nIt must be at least size " << MIN_RECT_LENGTH
           << " by "                        << MIN_RECT_WIDTH
           << " (length by width).";
   }
   else
   {
      // Scale the length and convert dimensions to integers
      i_length = (int)(length * SCALE_FACTOR);
      i_width  = (int)width;

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
void rectangle::print_specifications()
{
   cout << "\n\n\nThe rectangle specifications are:";
   cout << "\n        Length = " << length    << " units";
   cout << "\n         Width = " << width     << " units";
   cout << "\n          Area = " << area      << " sq. units";
   cout << "\n     Perimeter = " << perimeter << " units";
   return;
}
//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_heading();
   // Print the program heading
void get_dimensions(float *p_length, float *p_width);
   // Get the rectangle's dimensions

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   float start_length,
         start_width;

   // Print heading
   print_heading();

   // Get the rectangle's specifications and make a rectangle
   get_dimensions(&start_length, &start_width);
   rectangle rectangle_object(start_length, start_width);

   // Draw rectangle and prints its specifications
   rectangle_object.draw_rectangle();
   rectangle_object.print_specifications();

   // Say goodbye and terminate
   cout << "\n\nThank you for drawing a rectangle";
   cout << "\n\n\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                         Print the heading                          *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n\n        " << COURSE_NUMBER
        << " "                      << COURSE_NAME
        << " - Program "            << PROGRAM_NUMBER;
   cout << "\n\n                    This program draws a rectangle";
   cout <<   "\n                    ==============================";
   return;
}

//**********************************************************************
//*   Get the rectangle's dimensions and find its area and perimeter   *
//**********************************************************************
void get_dimensions(float *p_length, float *p_width)
{
   cout << "\n\n\nEnter the rectangle length now: ";
   cin  >> *p_length;
   cout << "Enter the rectangle width here: ";
   cin  >> *p_width;
   return;
}