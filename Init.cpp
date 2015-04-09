#include<iostream>

using namespace std;

#include"Init.h"

void Init::horizontal(bool is_bold = DARK )
{
  string l = "";
  if( is_bold == DARK )
  {
    l = "===";
    m_ch->to_dark();
  }
  else
  {
    l = "---";
    m_ch->to_light();
  }

  for( int k = 0; k < 2; k++ )
  {
    for( int j = 0; j < 9; j++ )
    {
      if( is_bold == LIGHT && !(j % 3) )
      {
        m_ch->to_dark();
        cout << "+";
        m_ch->to_light();
      }
      else
      {
        cout << "+";
      }
      cout << l << flush;
    }

    m_ch->to_dark();
    cout << "+      ";
    m_ch->to_current();
  }
  cout << endl;
}

void Init::vertical( int qty = 1 )
{
  for( int j = 0; j < qty; j++ )
  {
    for( int k = 0; k < 2; k++ )
    {
      for( int i = 0; i < 10; i++ )
      {
        if( i % 3 )
          m_ch->to_light();
        else
          m_ch->to_dark();

        cout << "|   " << flush;
      }
      cout << "   ";
    }
    cout << endl;
  }
}

Init::Init( Color_Handler& ch ) : m_ch( &ch )
{
  string wh = m_ch->get_special(WHITE);
  string norm = m_ch->get_special(NORMAL);

  cout <<  "\033[2J" << flush;
  if( DRAW_DOTS )
  {
    cout << m_ch->get_special(YELLOW) << string(100, '.') << endl;
    for( int i = 0; i <= 42; i++ )
      cout << m_ch->get_special(YELLOW) << "." << m_ch->get_special(GREEN) << string(98, '.') << m_ch->get_special(YELLOW) << "." << endl;
    cout << m_ch->get_special(YELLOW) << string(100, '.') << flush;
  }
  else
  {
    for( int i = 0; i <= 42; i++ )
      cout << string(100, ' ') << endl;
  }
  cout << "\033[1;1H" << flush;

  cout << m_ch->get_special(LIGHT_RED) << "Solution" << flush;
  cout << "\033[1;44H" << "Pencil Marks" << endl;
  m_ch->to_default();

  if( SHOW_COORDINATES )
  {
    for( int i = 1; i < 91; i++ ) //for dev/debug purposes.
    {
      if( !(i % 10 ) )
      {
        cout << m_ch->get_special(LIGHT_RED) << flush;
        cout << i / 10;
      }
      else
      {
        m_ch->to_default();
        cout << i % 10;
      }
    }

    m_ch->to_current();
    cout << endl;
  }
  else
  {
    horizontal(DARK);
  }
  for( int i = 1; i < 10; i++ )
  {
    vertical(3);
    horizontal( i % 3 );
  }
  m_ch->to_default();

  string comma = norm + ", " + wh;
  cout << endl << " Use the " << wh << "[w]" << comma << "[a]" << comma << "[s]" << comma << "[d] keys" << norm << " to navigate.";
  cout << "  " << wh << "Numbers 1 " << norm << "to " << wh << 9 << norm << " to enter a given." << endl;
  //  cout << wh << "[ZERO]" << norm << " to delete a given. " << flush;
  cout << " Press " << wh << "[v]" << norm << " to " << "sol" << wh << "v" << norm << "e,";
  cout << "or " << wh << "[q]" << norm << " to " << wh << "q" << norm << "uit." << endl;

  if( SHOW_COORDINATES )
  {
    cout << "\033[3;1H" << flush;

    for( int i = 3; i < 43; cout << i++ << endl );
  }
  cout << "\033[4;3H" << flush;
}

