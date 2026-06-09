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
        else{ // @@ missing handling for a==b: when a==b, this branch is taken but does not output '-', causing dash to be omitted. Should print '-' if a>=b.
            for(i=a+1;i<b;i++)
            printf("%c",i);
        }
    }
    else if(a>='A'&&a<='Z'&&b>='A'&&b<='Z'){
        if(a>b){
            printf("-");
            return;
        }
        else{ // @@ missing handling for a==b: same issue as above.
            for(i=a+1;i<b;i++)
            printf("%c",i);
        }
    }
    else if(a>='0'&&a<='9'&&b>='0'&&b<='9'){
        if(a>b){
            printf("-");
            return;
        }
        else{ // @@ missing handling for a==b: same issue.
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
    printf("len=%d\n",strlen(s)); // @@ extra debugging output not allowed; should be removed.
    //len-=1;
    for(i=0;i<len;i++) // @@ using uninitialized variable 'len' leads to undefined behavior; should use strlen(s) instead.
    {
        if(s[i]!='-')
        printf("%c",s[i]);
        else{
            func(s[i-1],s[i+1]);
        }
    }
    return 0;
}