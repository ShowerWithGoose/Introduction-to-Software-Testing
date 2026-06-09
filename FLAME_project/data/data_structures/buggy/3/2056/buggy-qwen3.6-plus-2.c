#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char in[500];
char out[500];
int main()
{   gets(in);
    int l;
    l=strlen(in);
    if(in[0]=='0'){
    int i,j,k,t;
      for(i=2;i<l;i++){
        if(in[i]!='0')
        break;
      }
      t=i-1;
      out[0]=in[i];
      if(l-i>1){
      out[1]='.';
        for(j=2;i+1<l;j++,i++)
          out[j]=in[i+1];
      out[j]='e'; // @@ [The variable j is not initialized or updated correctly in the else branch, leading to undefined behavior or incorrect index when accessing out[j] later. Also, the logic for constructing the output string is fragmented between printf and out array.]
    }
      else
          out[1]='e'; 
         for(k=0;k<j+1;k++) // @@ [Variable j is uninitialized in the else branch (when l-i <= 1), causing undefined behavior. In the if branch, j might also be incorrect depending on loop termination.]
         printf("%c",out[k]);
         printf("%d",-t);
    }
    else{
      int i,j,k,t;
      for(i=0;i<l;i++){
          if(in[i]=='.')
          break;
      }
      t=i;
      out[0]=in[0];
      out[1]='.';
      for(j=2,i=1;i<t;j++,i++)
          out[j]=in[i];
      for(i=t+1;i+1<=l;i++,j++)
        out[j]=in[i];
        out[j]='e';
      for(k=0;k<=j;k++)
      printf("%c",out[k]);
      printf("%d",t-1);
    }
     return 0;
}