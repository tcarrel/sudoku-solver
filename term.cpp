/*
This code is very procedural in nature.  It's leave it to you to figure out how
to turn it into a useful class...

A phrase often used for non-buffered input is "Hot Keys".
You can get additional information through the following two commands:
man 2 termios (this has most of the useful information)
man 7 termio  (this has some flag settings that termios uses)
...by the way, if you want to save these man pages in files to review them
in your editor, try:
man 7 termio | col -b >filename

This is a quick program to switch to raw mode and then back to canonical mode.
Make note of the following:
-the program has echoing turned off.  Try commenting out the line with
~ECHO to leave echoing turned on.
-the VMIN line sets the number of characters to accept before beginning
 processing.
-you can also create a line like
  term_hot.c_cc[VTIME]=3;
This will wait a maximum of 3/10 of a second before going on without taking
input.

Let me know if you have any questions regarding this.
-TAG

*/

#include <termios.h>
#include <unistd.h>
#include <iostream>

using namespace std;

void set_hot(struct termios* term_save)
{
  struct termios term_hot;
  tcgetattr(0, term_save);
  term_hot=*term_save;
  term_hot.c_lflag &= ~ICANON;
  term_hot.c_lflag &= ~ECHO;
  term_hot.c_cc[VMIN]=1;
//  comment above and uncomment below to get non-blocking input
//  term_hot.c_cc[VTIME]=0;
//  term_hot.c_cc[VMIN]=0;
  tcsetattr(0, TCSANOW, &term_hot);
}

void set_canonical(struct termios* term_save)
{
  tcsetattr(0, TCSANOW, term_save);
}


int main()
{
  struct termios term_save;
  char c;

  set_hot(&term_save);

  cout << "Hot keys are now enabled.  Type 'q' to re-enable\n";
  cout << "canonical processing and quit" << endl;

  do
  {
    cin.clear();
    cin >> c;
    cout << "You hit " << c << endl;
  } while (c!='q');

  set_canonical(&term_save);
}
