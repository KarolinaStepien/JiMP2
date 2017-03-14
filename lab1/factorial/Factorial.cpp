#include "Factorial.h"

int factorial(int value)
{
  if(value==0||value==1){
    return 1;
  }
  if(value>1){
    return factorial(value-1)*value;
  }
  if(value<0){
    return factorial(value+1)*value;
  }
}
