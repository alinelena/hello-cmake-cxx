//    Copyright (c) 2015 Alin Marin Elena <alin@elena.space>
//    The MIT License http://opensource.org/licenses/MIT
#include <iostream>
#include <cstdlib>
#include "hello.h"
#ifdef WITH_MYMATH
#include "mymath.h"
#else
#include<cmath>
#endif

using namespace std;

int main(int argc, char **argv){

  cout<< "Hello World!!!\n";
  cout <<"Running hello version: "<<Hello_VERSION_MAJOR<<"."
    << Hello_VERSION_MINOR<<"."<<Hello_VERSION_PATCH<<"."
    << Hello_VERSION_TWEAK<<endl;

  double a=42.0;
  if (argc>1) a=atof(argv[1]);
#ifdef WITH_MYMATH
  cout << "mySqrt("<<a<<") is "<<0.1*mySqrt(a)<<endl;
#else
  cout << "sqrt("<<a<<") is "<<0.1*sqrt(a)<<endl;
#endif
  return 0;
}
