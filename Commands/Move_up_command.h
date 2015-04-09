#ifndef _MOVE_UP_H
#define _MOVE_UP_H

class Move_up_command : public Command
{
  public:
    Move_up_command() :
      Command() {}
    Move_up_command(Command* prev, Command* next) :
      Command(prev, next) {} 
    Move_up_command(
        Command*,
        Command*,
        int val,
        int x_coord,
        int y_coord) {}

    void execute(int, int, int);
    Command* undo( void );

  protected:

    int val_;
    int x_;
    int y_;
}

#endif
