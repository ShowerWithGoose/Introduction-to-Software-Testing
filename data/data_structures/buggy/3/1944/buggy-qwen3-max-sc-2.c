#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define eps 1e-8
    
int main()
{
    char s[100],t[100];
    int i,j,k,sum=0;
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors with modern compilers.]
    if(s[0]=='0'){
        for(i=2;i<strlen(s);i++){
            if(s[i]!='0'){
                sum=i;
                i++;
                for(j=0;i<strlen(s);j++,i++){
                    t[j]=s[i];
                }
                if(j==0)
                    printf("%c%se-%d",s[sum],t,sum-1); // @@ [When j==0, the array 't' is uninitialized or empty, leading to undefined behavior when printed as a string. Also, format expects a string for %s but t may not be null-terminated.]
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
            printf("%ce%d",s[0],sum); // @@ [If there's no decimal point (sum==0), the exponent should be the number of digits after the first minus one, but 'sum' is 0 here which is incorrect. Also, 'i' after loop is strlen(s), so exponent should be i-1, not sum.]
            else if(j==-1)
            printf("%ce%d",s[0],i-1);
            else
            printf("%c.%se%d",s[0],t,i-1);
        }    
        else
            printf("%c.%se%d",s[0],t,sum-1);        
        return 0;    
    }
}