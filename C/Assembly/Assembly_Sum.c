#include<stdio.h>

int main(){
   int a = 3, b = 3, c;

   asm{
      mov ax,a
      mov bx,b
      add ax,bx
      mov c,ax
   }

   printf("%d", c);
}
