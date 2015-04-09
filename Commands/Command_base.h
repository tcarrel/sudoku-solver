#ifndef _COMMANDS_H
#define _COMMANDS_H

#include<cstdlib>

class Command
{
  public:
    ~Command_base( void );

    virtual void execute(int, int, int) = 0;
    virtual Command_base* undo( void ) = 0;

  protected:
    Command_base() : 
      prev_(NULL), next_(NULL) {}
    Command_base(Command_base* previous, Command_base* next) :
      prev_(previous), next_(next) {}

    Command_base* next_;
    Command_base* prev_;
};

#endif // _COMMANDS_H
