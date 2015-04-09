#ifndef _INSERT_COMMAND
#define _INSERT_COMMAND

#include"Command_base.h"

struct Changes
{
  int x;
  int y;
  int val;
};

class Insert_command : public Command_base
{
  public:
    ~Insert_command( void );

    void execute(int, int, int);
    Command_base* undo( void );

  private:
    
};

#endif
