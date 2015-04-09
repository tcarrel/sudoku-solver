#include<iostream>

using namespace std;

#include"Colors.h"
#include"Game.h"

int main( )
{

  Color_Handler color( LIGHT_CYAN, LIGHT_BLUE, NORMAL, GREEN );

  Game game(color);
  
  if( game.set_givens() )
  {

  }

  return 0;
}
