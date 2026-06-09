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
                t[j] = '\0'; // @@ [Missing null terminator for string t, leading to garbage output like '`']
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
        t[j] = '\0'; // @@ [Missing null terminator for string t after copying digits, may cause undefined behavior or garbage output]
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
            printf("%c.%se%d",s[0],t,sum-1);        
        return 0;    
    }
}