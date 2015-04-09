//Colors.h
//
//Set up text color environment
//

#ifndef COLORS_H
#define COLORS_H

using namespace std;

#include"Debug.h"

enum Colors_Enum
{ 
  NORMAL       = -1, 
  BLACK        =  0,
  BLUE         =  1,
  GREEN        =  2,
  CYAN         =  3,
  RED          =  4,
  PURPLE       =  5,
  BROWN        =  6,
  LIGHT_GRAY   =  7,
  LIGHT_GREY   =  7,
  DARK_GRAY    =  8,
  DARK_GREY    =  8,
  LIGHT_BLUE   =  9,
  LIGHT_GREEN  = 10,
  LIGHT_CYAN   = 11,
  LIGHT_RED    = 12,
  LIGHT_PURPLE = 13,
  YELLOW       = 14,
  WHITE        = 15,
};

static const bool DARK = false;
static const bool LIGHT = true;

class Color_Handler
{
  public:
    Color_Handler( void );
    Color_Handler( int, int, int, int );
    ~Color_Handler( void );
 
    void set_dark( int );
    void set_light( int );

    void to_default( void );
    void to_current( void );
    void to_dark( void );
    void to_light( void );
    void to_text( void );
    void to_highlight( void );

    string get_special( int );

    void color_test( void );

    void reset( void );
    void change( void );

  private:
    string color_string( int );
//    string color_string( void );
    
    string m_light;
    string m_dark;
    string m_text;
    string m_highlight;
    bool m_cur;
};
#endif
