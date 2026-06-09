#include <stdio.h>
#include <string.h>
char s[100000];
void func(char a,char b)
{
    char i;
    if(a>='a'&&a<='z'&&b>='a'&&b<='z')
    {
        if(a>b){ @@ Condition should be a>=b to correctly handle cases where characters are equal, otherwise the '-' is omitted.
            printf("-");
            return;
        }
        else{
            for(i=a+1;i<b;i++)
            printf("%c",i);
        }
    }
    else if(a>='A'&&a<='Z'&&b>='A'&&b<='Z'){
        if(a>b){
            printf("-");
            return;
        }
        else{
            for(i=a+1;i<b;i++)
            printf("%c",i);
        }
    }
    else if(a>='0'&&a<='9'&&b>='0'&&b<='9'){
        if(a>b){
            printf("-");
            return;
        }
        else{
            for(i=a+1;i<b;i++)
            printf("%c",i);
        }
    }
    else{
        printf("-");
        return;
    }
}
int main()
{
    int i,len;
    scanf("%s",s);
    //len=strlen(s); @@ This assignment is commented out, leaving 'len' uninitialized, which causes undefined behavior in the loop.
    printf("len=%d\n",strlen(s)); @@ This debug print statement is not required by the problem and will cause output mismatch.
    //len-=1;
    for(i=0;i<len;i++) @@ Loop condition uses uninitialized 'len', leading to unpredictable iteration count or runtime error.
    {
        if(s[i]!='-')
        printf("%c",s[i]);
        else{
            func(s[i-1],s[i+1]);
        }
    }
    return 0;
}