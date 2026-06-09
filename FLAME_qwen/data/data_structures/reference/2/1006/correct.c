#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#define LL long long
#define ULL unsigned long long

int main(void)
{
    char str[10000];
    int num[10000],i=0,j=0,ans=0,tem,tran,flag=1;
    gets(str);

    for(i=j=0;str[i]!='\0';i++){
        if(str[i]!=' ')
        str[j++]=str[i];
    }
    str[j]='\0';

    i=0;
    j=0;

    while(str[i]!='='){
        if(str[i]>='0'&&str[i]<='9'){
            int n=atoi(&str[i]);
            num[j]=flag*n;
            i++;
            tem=num[j];
            while(tem/10!=0){
                tem/=10;
                i++;
            }
        }
        while(str[i]=='*'||str[i]=='/'){
            while(str[i]=='*'){
                i++;
                tran=atoi(&str[i]);
                num[j]*=tran;
                i++;
                while(tran/10!=0){
                    tran/=10;
                    i++;
                }
            }

            while(str[i]=='/'){
                i++;
                tran=atoi(&str[i]);
                num[j]/=tran;
                i++;
                while(tran/10!=0){
                    tran/=10;
                    i++;
                }
            }
        }

        if(str[i]=='+'){
            flag=1;
        }else if(str[i]=='-'){
            flag=-1;
        }else{
            break;
        }

        i++;
        j++;    
    }

    j++;
    while(j--){
        ans+=num[j];
    }

    printf("%d",ans);

    return 0;
}
