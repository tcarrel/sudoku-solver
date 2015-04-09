#include<iostream>

using namespace std;

#include"Colors.h"

Color_Handler::Color_Handler( void )
{
  m_dark = color_string(NORMAL);
  m_highlight = m_text = m_light = m_dark;
  m_cur = DARK;
}

Color_Handler::Color_Handler( int lt = NORMAL, int dk = NORMAL, int txt = NORMAL, int hlt = NORMAL )
{ 
  m_light     = color_string( lt );
  m_dark      = color_string( dk );
  m_text      = color_string( txt );
  m_highlight = color_string( hlt );

  m_cur = DARK;
}

void Color_Handler::set_light( int to )
{
  m_light = color_string(to);
}

void Color_Handler::set_dark( int to )
{
  m_dark = color_string(to);
}

void Color_Handler::reset( void )
{
  m_light = m_dark = color_string(NORMAL);
  cout << m_light << flush;
}

void Color_Handler::change( void )
{
  m_cur = !m_cur;
  to_current();
}

void Color_Handler::to_default( void )
{
  cout << color_string(NORMAL) << flush;
}

void Color_Handler::to_dark( void )
{
  m_cur = DARK;
  cout << m_dark << flush;
}

void Color_Handler::to_light( void )
{
  m_cur = LIGHT;
  cout << m_light << flush;
}

void Color_Handler::to_text( void )
{
  cout << m_text << flush;
}

void Color_Handler::to_highlight( void )
{
  cout << m_highlight << flush;
}

string Color_Handler::get_special( int color_id )
{
  return color_string( color_id );
} 

void Color_Handler::to_current( void )
{
  if( m_cur == DARK )
    cout << m_dark;
  else
    cout << m_light;

  cout << flush;
}

void Color_Handler::color_test( void )
{
  for( int i = 0; i < 32; i++ )
    cout << color_string( i ) << "TEST TEST TEST" << endl;

  to_current();
}

/*
string Color_Handler::color_string( void )
{
  return color_string(NORMAL);
}
*/

string Color_Handler::color_string( int val = NORMAL )
{
  switch( (val < 0) ? -1 : val % 16 )
  {
    case BLACK:
      return "\033[0;30m";
    case BLUE:
      return "\033[0;34m";
    case GREEN:
      return "\033[0;32m";
    case CYAN:
      return "\033[0;36m";
    case RED:
      return "\033[0;31m";
    case PURPLE:
      return "\033[0;35m";
    case BROWN:
      return "\033[0;33m";
    case LIGHT_GRAY:
      return "\033[0;37m";
    case DARK_GRAY:
      return "\033[1;30m";
    case LIGHT_BLUE:
      return "\033[1;34m";
    case LIGHT_GREEN:
      return "\033[1,32m";
    case LIGHT_CYAN:
      return "\033[1;36m";
    case LIGHT_RED:
      return "\033[1;31m";
    case LIGHT_PURPLE:
      return "\033[1;35m";
    case YELLOW:
      return "\033[1;33m";
    case WHITE:
      return "\033[1;37m";
    case NORMAL:
    default:
      return "\033[0m";
  }
}

Color_Handler::~Color_Handler( void )
{
  cout << color_string(NORMAL) << endl;
}
