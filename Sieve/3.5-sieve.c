#include <stdio.h>

#define N 10000

int main(void) 
{
  int i, j, a[N+1];

  // mark every one as not eliminated at the start
  for (i = 2; i <= N; i++)
  {
    a[i] = 1;
  }


  for(i = 2; i <= N; i++)  // outer loop
  {
    if (a[i])
	{
	  // Sieving process starts
      for (j = i; i*j <= N; j++)
	  {
	    a[i*j] = 0; // not a prime
	  }
    }
  }
  
  for (i = 2; i <= N; i++)
  {
    if (a[i])
	{
      printf("%4d ", i);
	}
  }
  printf("\n");
  printf("Michael has done the work!! \n\n");
  
  return 0;
}
