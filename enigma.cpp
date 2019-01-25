#include<stdio.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int rotor[5][26]={{9,3,14,6,23,24,17,1,11,18,7,8,21,16,19,12,0,5,4,2,10,20,13,22,15,25},{23,3,9,16,19,6,22,13,0,12,11,24,18,10,1,17,2,21,15,8,5,20,4,14,7,25},{11,18,21,10,1,19,20,7,16,3,17,6,23,25,15,24,8,13,0,9,2,5,22,14,12,4},{25,2,23,0,6,1,21,8,9,3,20,22,7,16,24,5,19,4,10,14,18,12,15,13,17,11},{24,8,15,12,1,19,9,7,10,4,0,22,5,13,25,23,21,11,16,18,14,3,17,2,6,20}};

void rotate(int a)//for the rotation of the rotor
{
  int i;
  int temp;
  temp=rotor[a][0];
  for(i=1;i<26;i++)
    rotor[a][i-1]=rotor[a][i];
  rotor[a][25]=temp;
}

void print_rotor(int a)//just to verify if rotation is working
{
  int i;
  for(i=0;i<26;i++)
    cout<<rotor[a][i]<<"\t";
  cout<<"\n";
}

int reflecter(int a)//for symmetry
{
  return(25-a);
}

int plugboard(int a, int* pb)//to increase possibilities
{
  int flag=0;
  int i;
  for(i=0;i<10;i++)
    {
      if(pb[i]==a)
	{
	  flag=1;
	  break;
	}
    }
    if(flag==1)
      return(pb[9-i]);
    else
      return(a);
}

int find(int a, int num)//for returning back after reflecting
{
  int i;
  for(i=0;i<25;i++)
    if(rotor[num][i]==a)
      break;
  return(i);
}
int main()
{
  int i;
  i=0;
  
  int pb[10];
  char ch1,ch2;
  cout<<"enter the plugboard combinations \n";
  for(i=0;i<5;i++)
    {
      cout<<"enter the "<<i<<" combination \n";
      cin>>ch1>>ch2;
      ch1=toupper(ch1);
      ch2=toupper(ch2);
      pb[i]=int(ch1)-65;
      pb[9-i]=int(ch2)-65;
    }
  
  /*print_rotor(0);
  rotate(0);
  print_rotor(0);
  cout<<"\n";*/
  
  /*int ret=plugboard(0,pb);
    cout<<char(ret+65);*/

  cout<<"enter the rotor numbers 1-5 select 3 out of them \n";
  i=0;
  int ar[3];
  for(i=0;i<3;i++)
    {
      cin>>ar[i];
      ar[i]=ar[i]-1;
    }

  cout<<"select the number of initial turns for each rotor (inital setting) \n";//initial number of turns must be same during encryption and decryption
  int r[3];
  cin>>r[0]>>r[1]>>r[2];
  int j;
  for(i=0;i<3;i++)
    {
      for(j=0;j<(r[i])%26;j++)
	rotate(ar[i]);
    }

  string str;
  cout<<"enter the string"<<"\n";//can be upper of lower case without spaces
  cin>>str;
  cout<<"entered string \n";
  cout<<str<<"\n";
  
  int enc;
  i=0;
  int rotor2;
  rotor2=0;
  int s0,s1,s2,s3;
  char ch;
  cout<<"encoded string \n";
  while(str[i]!='\0')//till it encounters a null charecter
    {
      ch=toupper(str[i]);
      s0=plugboard(int(ch)-65,pb);//commented part was used to verify the working of the code
      //cout<<"s0="<<s0<<"\n";
      // cout<<"plugboard 1="<<s0<<"\n";
      s1=rotor[ar[2]][rotor[ar[1]][rotor[ar[0]][s0]]];
      //cout<<"s1="<<s1<<"\n";
      //cout<<"rotor 1 1="<<rotor[ar[0]][s0]<<"\n";
      //cout<<"rotor 2 1="<<rotor[ar[1]][rotor[ar[0]][s0]]<<"\n";
      //cout<<"rotor 3 1="<<rotor[ar[2]][rotor[ar[1]][rotor[ar[0]][s0]]]<<"\n";
      s2=reflecter(s1);
      //cout<<"reflecter="<<s2<<"\n";
      //s3=rotor[0][rotor[1][rotor[2][s2]]];
      //cout<<"s3="<<s3<<"\n";
      //cout<<"rotor 3 2="<<find(s2,ar[2])<<"\n";
      //cout<<"rotor 2 2="<<find(find(s2,ar[2]),ar[1])<<"\n";
      //cout<<"rotor 1 2="<<find(find(find(s2,ar[2]),ar[1]),ar[0])<<"\n";
      s3=find(find(find(s2,ar[2]),ar[1]),ar[0]);
      enc=plugboard(s3,pb);
      //cout<<"plugboard 2="<<enc<<"\n";
      //cout<<"enc="<<enc<<"\n";
      cout<<char(enc+65);
      i++;
      rotate(ar[0]);
      if(i%26==0 && i!=0)
	{
	  rotate(ar[1]);
	  rotor2++;
	}
      if(rotor2%26==0 && rotor2!=0)
	rotate(ar[2]);
     }
  cout<<"\n";
  return(0);
}
