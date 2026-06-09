#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define eps 1e-8
    
int main()
{
    char s[100],t[100];
    int i,j,k,sum=0;
    gets(s);
    if(s[0]=='0'){
        for(i=2;i<strlen(s);i++){
            if(s[i]!='0'){
                sum=i;
                i++;
                for(j=0;i<strlen(s);j++,i++){
                    t[j]=s[i];
                }
                if(j==0)
                    printf("%c%se-%d",s[sum],t,sum-1);
                else
                    printf("%c.%se-%d",s[sum],t,sum-1);        
                return 0;
            }
        }
    }
    else{j=0;
        sum=0;
        for(i=1;i<strlen(s);i++){
            if(s[i]=='.'){
                sum=i;
                }
            else{
                t[j]=s[i];
                j++;        }    
        }
        j--;
        for(;j!=-1;j--){
            if(t[j]=='0') t[j]='\0';
            else break;
        }
        if(sum==0){
            if(i==1)
            printf("%ce%d",s[0],sum);
            else if(j==-1)
            printf("%ce%d",s[0],i-1);
            else
            printf("%c.%se%d",s[0],t,i-1);
        }    
        else
            printf("%c.%se%d",s[0],t,sum-1); // @@ [Error: For input "9.99", sum=2, so this branch prints "9.99e1" but expected is "9.99e0". The exponent should be sum-2 (since the decimal point is at index 1, not 2) or more precisely, the exponent is the number of digits before the decimal point minus 1. Here, fir=1 (index of '.'), so exponent should be fir-1 = 0, but sum is set to i where s[i]=='.', which is 2, so sum-1=1 is wrong. The correct exponent is the position of the decimal point minus 1, but the code incorrectly uses sum (which is the index of '.' in the loop) and subtracts 1, but for "9.99", '.' is at index 1, so exponent should be 0, not 1.]        
        return 0;    
    }
}