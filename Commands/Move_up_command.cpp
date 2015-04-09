#include"Move_up_command.h"

void execute(int val, int x, int y, Command* prev, Command* next)
{
  row--;
  if( row < 0 )
    row += 9;

  print_coordinate();
  set_cursor();

}
