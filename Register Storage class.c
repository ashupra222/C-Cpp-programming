#include <stdio.h>
int main(){
  register int i;
  for (i=0; i<=100000000; i++){
    printf("%d\n", i);
  }
  return 0;
}
