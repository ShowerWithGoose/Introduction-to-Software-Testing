#include <stdio.h>
#include <string.h>

int main()
{
    char str[2000],s[1000];
    int num[1000]={0},j=0,sum=0,len;
    gets(str);
    len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]>='0'&&str[i]<='9'){
            num[j]=num[j]*10+str[i]-'0';
        }
        else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='='){
            s[j++]=str[i];
        }
    }
    for(int i=0;i<j;i++){
        if(s[i]=='*'){
            num[i+1]=num[i]*num[i+1];
            num[i]=0;
            if(s[i-1]=='-'){
                s[i]='-';
            }
            else{
                s[i]='+';
            }
        }
        else if(s[i]=='/'){
            num[i+1]=num[i]/num[i+1];
            num[i]=0;
            if(s[i-1]=='-'){
                s[i]='-';
            }
            else{
                s[i]='+';
            }
        }
    }
    sum+=num[0];
    for(int i=0;i<j-1;i++){
        if(s[i]=='-'){
            sum-=num[i+1];
        }
        else{
            sum+=num[i+1];
        }
    }
    printf("%d",sum);
    return 0;
}



