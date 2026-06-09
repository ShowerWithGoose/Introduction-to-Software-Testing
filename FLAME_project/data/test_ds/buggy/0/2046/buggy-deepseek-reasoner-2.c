#include <stdio.h>
#include <string.h>
char s[100000];
void func(char a,char b)
{
    char i;
    if(a>='a'&&a<='z'&&b>='a'&&b<='z')
    {
        if(a>b){
            printf("-");
            return;
        }
        else{ // @@ Missing case when a == b; should print '-' instead of entering loop.
            for(i=a+1;i<b;i++)
            printf("%c",i);
        }
    }
    else if(a>='A'&&a<='Z'&&b>='A'&&b<='Z'){
        if(a>b){
            printf("-");
            return;
        }
        else{ // @@ Missing case when a == b; should print '-' instead of entering loop.
            for(i=a+1;i<b;i++)
            printf("%c",i);
        }
    }
    else if(a>='0'&&a<='9'&&b>='0'&&b<='9'){
        if(a>b){
            printf("-");
            return;
        }
        else{ // @@ Missing case when a == b; should print '-' instead of entering loop.
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
    //len=strlen(s);
    printf("len=%d\n",strlen(s)); // @@ Debug output not required, causing extra output.
    //len-=1;
    for(i=0;i<len;i++) // @@ Variable 'len' is uninitialized, leading to undefined loop behavior.
    {
        if(s[i]!='-')
        printf("%c",s[i]);
        else{
            func(s[i-1],s[i+1]); // @@ Potential out-of-bounds access when i=0 or i=len-1; also, func does not properly handle expansion when characters are equal.
        }
    }
    return 0;
}