#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv)
{
int massive[20][20];

FILE* fp=fopen("teks.txt","r");
int j=0;
while(!feof(fp))
{
  int i;
  for(i=0;i<20;i++)
  {
        fscanf(fp,"%d ",&massive[j][i]);
  }
  j++;
}

int LeftRightMax=0,Sum=0,UpDownMax=0,MainDiagonal=0,SecondDiagonal=0;

for(int j=0;j<20;j++)
{
  for(int i=0;i<17;i++)
  {
    Sum=massive[j][i]*massive[j][i+1]*massive[j][i+2]*massive[j][i+3];
    if(Sum>LeftRightMax)
    {
      LeftRightMax=Sum;
    }
  }
}

for(int j=0;j<17;j++)
{
  for(int i=0;i<20;i++)
  {
    Sum=massive[j][i]*massive[j+1][i]*massive[j+2][i]*massive[j+3][i];
    if(Sum>UpDownMax)
    {
        UpDownMax=Sum;
    }
  }
}

for(int j=0;j<17;j++)
{
  for(int i=0;i<17;i++)
  {
    Sum=massive[j][i]*massive[j+1][i+1]*massive[j+2][i+2]*massive[j+3][i+3];
    if(Sum>MainDiagonal)
    {
        MainDiagonal=Sum;
    }
  }
}

int k,f;

for(int j=0;j<17;j++)
{
  for(int i=3;i<20;i++)
  {
    Sum=massive[j][i]*massive[j+1][i-1]*massive[j+2][i-2]*massive[j+3][i-3];
    if(Sum>SecondDiagonal)
    {
        SecondDiagonal=Sum;
        k=j;
        f=i;
    }
  }
}


int biggestMassive[4]={UpDownMax,LeftRightMax,MainDiagonal,SecondDiagonal};
int biggestNumber=0;
for(int i=0;i<4;i++)
{
  if(biggestNumber<biggestMassive[i])
  biggestNumber=biggestMassive[i];
}

printf("\n%d\n",biggestNumber);
    return 0;
}
