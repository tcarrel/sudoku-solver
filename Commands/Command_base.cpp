#include"Command.h"

Command::~Command( void )
{
  if( next_ )
    delete next_;
  // Recursively deletes all commands after current.
}
