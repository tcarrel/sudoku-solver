//Thomas C.
//
//Environment initialization class and
//other useful global functions and
//variables
//

#ifndef INIT_H
#define INIT_H

#include<iostream>
#include"Colors.h"

#include"Debug.h"

class Init
{
  public:
    Init( Color_Handler& ch );
    void horizontal( bool );
    void vertical( int );

  private:
    Color_Handler* m_ch;
};

#endif
