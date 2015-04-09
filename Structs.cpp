//Structs.cpp
//

#include<iostream>

using namespace std;

#include"Structs.h"

ostream& operator<< (ostream& os, Pen_mark& pm)
{
  os << UP_1 << LEFT_1 << flush;

  if( pm.num )
  {
    if( pm.type == GIVEN )
    {
      os << string(3, 'G') << RETURN << flush;
      os << "G" << pm.num << "G" << RETURN << flush;
      os << string(3, 'G') << flush;
    }
    else
    {
      os << string(3, 'S') << RETURN << flush;
      os << "S" << pm.num << "S" << RETURN << flush;
      os << string(3, 'S')<< flush;
    }
  }
  else
  {
    os << string(3, ' ') << RETURN << flush;
    os << " ? " << RETURN << flush;
    os << string(3, ' ') << flush;
  } 

  os << UP_1 << LEFT_1 << flush;
  return os;
}

ostream& operator<< (ostream& os, Pencil_mark& pm)
{
  os << "\033[42C" << flush; //Prints offset buy 43 columns
  os << UP_1 << flush;

  if ( pm.is_done )
  {
    os << "\033[0;31m" << flush;
    os << "\\|/" << RETURN << flush;
    os << "-X-" << RETURN << flush;
    os << "/|\\" << flush;
    os << "\033[0m" << UP_1 << flush;
  }
  else
  {
    for( int i = 0; i < 9; i++ )
    {
      if ( ( i == 3) || ( i == 6 ) )
        os << RETURN << flush;

      if ( pm.num[i] )
        os << i + 1;
      else
        os << ' ';
    }
  }

  os << "\033[44D" << flush;
  return os;
}

void Pencil_mark::solve( void )
{
  is_done = true;
  num_poss = 0;

  for( int i = 0; i < 9; i++ )
    num[i] = false;
}

void Pencil_mark::eliminate( int N )
{
  N--;

  if( is_done && !num[N] )
    return;

  num[N] = false;
  num_poss--;

  if( !num_poss )
    is_done = true;
}

void Pencil_mark::reset( int N )
{
  num[N - 1] = true;
  num_poss++;
}

bool Pencil_mark::is_set( int N )
{
  return !num[ N - 1 ];
}
