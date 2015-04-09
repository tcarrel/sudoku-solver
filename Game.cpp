//Game.cpp
//Carrel, Thomas R.

#include<termios.h>
#include<unistd.h>
#include<iostream>
#include<cctype>

using namespace std;

#include"Game.h"
#include"Init.h"
#include"Structs.h"

////////////////////////////////////////////////////////////
//HELPER FUNCTIONS//////////////////////////////////////////
////////////////////////////////////////////////////////////

//Code for termios.h use originally from Todd Gibson

void set_hot(struct termios* term_save)
{
  struct termios term_hot;
  tcgetattr(0, term_save);
  term_hot=*term_save;
  term_hot.c_lflag &= ~ICANON;
  term_hot.c_lflag &= ~ECHO;
  term_hot.c_cc[VMIN]=1;
  //  comment above and uncomment below to get non-blocking input
  //  term_hot.c_cc[VTIME]=0;
  //  term_hot.c_cc[VMIN]=0;
  tcsetattr(0, TCSANOW, &term_hot);
}

void set_canonical(struct termios* term_save)
{
  tcsetattr(0, TCSANOW, term_save);
}

void lower( char& ch )
{
  if( !isdigit(ch) )
    if( (64 < ch) && (ch < 91) )
      ch += 32;
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

Game::Game( Color_Handler& ch ) : m_ch(&ch)
{
  Init ting(ch);

  cursor_r = 4;
  cursor_c = 3;

  for( row = 0; row < 9; row++ )
    for( col = 0; col < 9; col++ )
    {
      set_cursor();
      cout << m_work[row][col];
    }

  Update_Pencil_Marks();

  row = col = 0;

  sol_origin_r = 4;
  sol_origin_c = 3;
  wrk_origin_r = 4;
  wrk_origin_c = 46;

  m_ch->to_text();
  print_coordinate();
  set_cursor();
}

Game::~Game()
{
  cout << "\033[43;1H" << flush; //return cursor to bottom of screen
}

bool Game::set_givens( void )
{

  struct termios term_save;
  char c;

  set_hot(&term_save);

  int number = 0;

  do
  {
    cin.clear();
    cin >> c;
    lower(c);

    switch( c )
    {
      case 'w':
      case 'k':
        move_up();
        break;
      case 'a':
      case 'h':
        move_left();
        break;
      case 's':
      case 'j':
        move_down();
        break;
      case 'd':
      case 'l':
        move_right();
        break;
      case 'v': //solve
      case '=':
        set_canonical(&term_save); //
        //load solver
        return true;
      case 'q': //quit
        set_canonical(&term_save); //
        return false;
      default:
        if( is_valid(number, c) )
        {
          given(number);
        }
        else
          cout << BELL << flush;
    }

  } while (true);
}

bool Game::is_valid( int& n, char l )
{
  if( !isdigit(l) )
    return false;

  n = l - 48;
  return true;
}

void Game::set_cursor(void)
{
  cursor_r = 4 + (4 * row);
  cursor_c = 3 + (4 * col);

  cout << "\033[" << cursor_r << ";" << cursor_c << "H" << flush;
}

void Game::Update_Pencil_Marks( void )
{
  int c_coord = col;
  int r_coord = row;

  for( col = 0; col < 9; col++ )
  {
    for( row = 0; row < 9; row++ )
    {
      set_cursor(); 
      cout << m_work[row][col];
    }
  }

  col = c_coord;
  row = r_coord;
  set_cursor();
  //  cout << "\033[" << cursor_r << ";" << cursor_c << "H" << flush;
}

void Game::Update_Pencil_Marks( int r, int c ) //updates one box and returns cursor afterwards
{
  int r_ = (4 * r) + wrk_origin_r;
  int c_ = (4 * c) + wrk_origin_c;

  cout << "\033[" << r_ << ";" << c_ << "H" << flush;
  cout << m_work[r][c];
  set_cursor();
}

void Game::given( int n )
{
  if( !is_good( n ) || (n < 1) || (9 < n) )
  { 
    cout << BELL << flush;
  }
  else
  {
    m_solved[row][col].num = n;
    m_solved[row][col].type = GIVEN;

    m_work[row][col].solve();

    cout << m_solved[row][col];

    for( int ro_ = 0; ro_ < 9; ro_++ )
    {
      m_work[ro_][col].eliminate( n );
    }
    for( int co_ = 0; co_ < 9; co_++ )
    {
      m_work[row][co_].eliminate( n );
    }

    int temp_r = row;
    int temp_c = col;

    minor_grid(row);
    minor_grid(col);

    row--; col--;

    for( int r = 0; r < 3; r++ )
    {
      row++;
      for( int c = 0; c < 3; c++ )
      {
        col++;
        m_work[row][col].eliminate( n );
      }
      col -= 3;      
    }

    row = temp_r;
    col = temp_c;

    Update_Pencil_Marks();
  }
}

bool Game::is_good( int test_val )
{
  return !m_work[row][col].is_set( test_val );
}

void Game::minor_grid( int& val )
{
  val = val - (val % 3);
}

////////////////////////////////////////////////////////////
//CURSOR MOVEMENT///////////////////////////////////////////
////////////////////////////////////////////////////////////

void Game::move_down( void )
{
  row++;
  if( row >= 9 )
    row -= 9;

  print_coordinate();
  set_cursor();
}

void Game::move_left( void )
{
  col--;
  if( col < 0 )
    col += 9;

  print_coordinate();
  set_cursor();
}

void Game::move_right( void )
{
  col++;
  if( col >= 9 )
    col -= 9;

  print_coordinate();
  set_cursor();
}

void Game::print_coordinate( void )
{
  // 7 chars
  m_ch->to_highlight();

  cout << "\033[39;33H" << flush;
  cout << "(" << col + 1 << "," << row + 1 << ")" << flush;

  m_ch->to_text();
}
