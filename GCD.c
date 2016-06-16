/****
An iterative approach to find out GCD of  multiple numbers using Dynamic Programming
-
Dewang Lahariya
****/


#include<stdio.h>
#include<stdlib.h>


int gcd(int,int);

int main()
{
  
  
  printf("How many numbers would you like to find GCD for ?");
  int n;
  scanf("%d",&n);
  int *num=(int *)malloc(n*sizeof(int));
  int i;
  for(i=0;i<n;i++)
  {
  	scanf("%d",&num[i]);
  
  }

int temp = num[0];

for(i=0;i<n-1;i++)
{
  	temp = gcd(temp,num[i+1]);
	
}
printf("GCD is %d\n",temp);
 
return 0;
}

int gcd(int x,int y)
{
    int i;
    for(i=x;i>=1;i--){
         if(x%i==0&&y%i==0){
             break;
         }
    }
    return i;
}
