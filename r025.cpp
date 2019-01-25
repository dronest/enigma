#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
  srand(time(0));
  int ar[26];
  int i,flag,num,j;
  flag=0;
  for(i=0;i<26;i++)
    {
      while(1)
	{
	  num=(rand()%26);
	  flag=0;
	  for(j=0;j<i;j++)
	    {
	      if(ar[j]==num)
		{
		  flag=1;
		  break;
		}
	    }
	  if(flag==0)
	    break;
	}
      cout<<i<<"-";
      ar[i]=num;
      cout<<ar[i]<<"\n";
    }
  for(i=0;i<26;i++)
    cout<<ar[i]<<",";
  cout<<"\n";
  return(0);
}
