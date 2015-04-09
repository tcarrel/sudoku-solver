#ifndef _COMMAND_LIST
#define _COMMAND_LIST

#include"all_commands.h"

class Command_list
{
  public:
    Command_list( void ) :
      curr_(NULL) {}

    void undo();
    void execute(int, int, int, Command_base*, Command_base*);

  private:
      Command_base* curr_;

      Command_base
}

#endif /*_COMMAND_LIST*/
