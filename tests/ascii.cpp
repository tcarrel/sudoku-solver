#include<iostream>

using namespace std;


int main()
{

  cout << "\1Bh)0" << flush;

  cout << string(50, '\n') << flush;

  cout << "\1Bh[0;0H" << flush;

  char out = 29;
  for( int i = 30; i < 256; out = ++i )
  {
    cout << "  " << i << "___. " << out << endl;
  }

  return 0;
}
