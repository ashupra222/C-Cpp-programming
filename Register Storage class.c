#include <stdio.h>
int main(){
  register long int i;
  register int b;
  printf("task started\n");
  for (i=0; i<=10000000000; i++){
    b=0;
  }
  printf("task completed\n");
  return 0;
}
