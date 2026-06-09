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
      out[j]='e'; // @@ Missing 'e' is printed but the exponent sign and value are printed separately with printf, causing missing 'e' in some cases (e.g., when l-i<=1)
    }
      else
          out[1]='e'; 
         for(k=0;k<j+1;k++)
         printf("%c",out[k]);
         printf("%d",-t); // @@ This prints the exponent without ensuring it's prefixed with '-' in the string; also, when l-i<=1, j is uninitialized leading to undefined behavior
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
      printf("%d",t-1); // @@ Exponent is printed directly with printf instead of being formatted into out[], which breaks output format consistency and may omit 'e' if logic fails
    }
     return 0;
}