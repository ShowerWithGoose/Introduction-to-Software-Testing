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
      out[j]='e'; // @@ Missing 'e' is written, but the exponent sign and digits are printed separately with printf, causing missing 'e' in some cases (like when l-i<=1). Also, in the case of "0.9", this block is skipped, so 'e' is never added to out[].
    }
      else
          out[1]='e'; 
         for(k=0;k<j+1;k++)
         printf("%c",out[k]);
         printf("%d",-t); // @@ This prints the exponent as a decimal number directly, but it should be prefixed with '-' only if negative, and more critically, the 'e' may not have been printed if the else branch was taken and j is uninitialized or incorrect. In "0.9", l-i = 1 (since i=2, l=3), so else branch runs: out[1]='e', then loop prints out[0] and out[1] ('9' and 'e'), then printf prints "-1" → "9e-1". But wait: j is uninitialized in the else branch! So k<j+1 uses garbage j → undefined behavior. Also, even if j were set, the output format mixes array printing and direct printf, which breaks consistency.
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
      printf("%d",t-1); // @@ Similar issue: exponent is printed via printf after printing out[], but if there are no fractional digits, trailing '.' might remain, and also for numbers like "5.0" (though problem says no trailing zeros), but more importantly, the exponent should be printed as part of the string, not separately. However, main bug is in the '0.' branch.
    }
     return 0;
}