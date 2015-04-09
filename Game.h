//Game.h
//Carrel, Thomas R.

#ifndef GAME_H
#define GAME_H

#include<vector>
#include"Structs.h"
#include"Colors.h"

#include"Debug.h"

static const char BELL = 7;

class Game
{
  public:
    Game( Color_Handler& );    
    
    bool set_givens( void );
    void solve( void );
    
    ~Game();

  private:

    // array coordinates are (row,col) format

    Pencil_mark m_work[9][9];
    Pen_mark m_solved[9][9];

    int cursor_r;
    int cursor_c;
    int row;
    int col;

    int sol_origin_r;
    int sol_origin_c;
    int wrk_origin_r; 
    int wrk_origin_c;

    Color_Handler* m_ch;

    void set_cursor( void );
    void Update_Pencil_Marks( void );
    void Update_Pencil_Marks( int, int );
    bool is_valid( int&, char );
    void given( int );
    bool is_good( int );
    void minor_grid( int& );

    //Movement
    void move_up( void );
    void move_down( void );
    void move_left( void );
    void move_right( void );
    void print_coordinate( void );
};

#endif
