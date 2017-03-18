#include <stdio.h>
#include <stdlib.h>
int main()
{
  int size=0;
  char* masivcho=(char*)malloc(2);
  printf("enter string: ");
  while(1)
  {
    scanf("%c",&masivcho[size]);
    if(masivcho[size]=='a')
    break;
    size++;
    masivcho=(char*)realloc(masivcho,size+2);

  }

printf("%s",masivcho);
free(masivcho);
   return(0);
}
