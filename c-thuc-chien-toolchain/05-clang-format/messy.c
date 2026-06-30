#include <stdio.h>
int  add(int a,int b){return a+b;}
int main(void){
int* p;
int x=5;
    p=&x;
  if(x>0){
printf("%d\n",add(x,*p));
}
        return 0;
}
