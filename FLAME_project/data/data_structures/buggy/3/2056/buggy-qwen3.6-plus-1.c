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
      out[j]='e'; // @@ The 'e' character is missing from the output because the subsequent printf loop only prints up to index j-1 (condition k<j+1), and the exponent is printed separately without the 'e'. The 'e' should be included in the printed string or the loop bound adjusted. Specifically, for input 0.9, l-i is not > 1, so it goes to else.
    }
      else
          out[1]='e'; 
         for(k=0;k<j+1;k++) // @@ In the case of 0.9, j is uninitialized because the if block (where j is assigned) was skipped. The else block sets out[1]='e' but does not set j. Thus j contains garbage, leading to undefined behavior in the loop condition and potentially missing output or crash. Even if j were correctly set to 2 (index after 'e'), the loop prints characters from out[0] to out[j]. For 0.9, out[0]='9', out[1]='e'. If j=2, it prints out[0], out[1]. Then printf("%d",-t) prints -1. Result: "9e-1". Wait, let's re-evaluate. If j is uninitialized, it's a bug. In the else branch, j is not assigned. So k<j+1 uses uninitialized j. This is the primary error for the test case 0.9.
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