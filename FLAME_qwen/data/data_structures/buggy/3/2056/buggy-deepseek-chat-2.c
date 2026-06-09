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
      out[j]='e'; // @@ Error: Variable j is not properly initialized or updated before this assignment. The loop condition uses i+1<l, but after the loop, j may not be correctly set for the next assignment. Also, the loop increments i, which changes the index used in out[j]=in[i+1], potentially causing out-of-bounds or incorrect copying.
    }
      else
          out[1]='e'; 
         for(k=0;k<j+1;k++) // @@ Error: Variable j may be uninitialized or have an incorrect value when the else branch is taken, leading to undefined behavior in the loop.
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
      for(i=t+1;i+1<=l;i++,j++) // @@ Error: The condition i+1<=l may cause out-of-bounds access when i equals l-1, as in[i+1] would access in[l] which is the null terminator. Also, the loop copies the decimal part incorrectly, potentially missing the last digit.
        out[j]=in[i];
        out[j]='e'; // @@ Error: After the second for loop, j is incremented one extra time, so out[j] may overwrite a valid character or be out of bounds.
      for(k=0;k<=j;k++)
      printf("%c",out[k]);
      printf("%d",t-1);
    }
     return 0;
}