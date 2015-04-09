//sudoku_structs.h
//Carrel, Thomas R.

#ifndef SUDOKU_STRUCTS_H
#define SUDOKU_STRUCTS_H

#include"Debug.h"
#include<iostream>

using namespace std;

static const bool GIVEN = true;
static const bool FOUND = false;

static const string UP_1    = "\033[1A";
static const string RIGHT_1 = "\033[1C";
static const string DOWN_1  = "\033[1B";
static const string LEFT_1  = "\033[1D";

static const string RETURN  = DOWN_1 + LEFT_1 + LEFT_1 + LEFT_1;

class Pen_mark
{
  public:
    int num = 0; // is set to 0 (zero) if BLANK
    int type = GIVEN;

    friend ostream& operator<< (ostream&, Pen_mark& );
};

class Pencil_mark
{
  private:
    bool num[9] = { true, true, true, true, true,
      true, true, true, true };

  public:
    bool is_done = false;
    int num_poss = 9;
    
    bool is_set( int );
    void solve( void );
    void eliminate( int );
    void reset( int );

    friend ostream& operator<< (ostream&, Pencil_mark& );
};

#endif
