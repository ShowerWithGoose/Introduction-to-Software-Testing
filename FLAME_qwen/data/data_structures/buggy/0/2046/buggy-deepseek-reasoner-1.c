#include <stdio.h>
#include <string.h>
char s[100000];
void func(char a,char b)
{
    char i;
    if(a>='a'&&a<='z'&&b>='a'&&b<='z')
    {
        if(a>b){ // @@ Should be if(a>=b) to handle a==b case, where no expansion should occur and '-' should be printed.
            printf("-");
            return;
        }
        else{ // @@ When a==b, this else executes but prints nothing, missing '-'. Should be else if(a<b) { ... } else printf("-");
            for(i=a+1;i<b;i++)
            printf("%c",i);
        }
    }
    else if(a>='A'&&a<='Z'&&b>='A'&&b<='Z'){
        if(a>b){ // @@ Same issue: should be if(a>=b)
            printf("-");
            return;
        }
        else{ // @@ Same issue: a==b case not handled.
            for(i=a+1;i<b;i++)
            printf("%c",i);
        }
    }
    else if(a>='0'&&a<='9'&&b>='0'&&b<='9'){
        if(a>b){ // @@ Same issue: should be if(a>=b)
            printf("-");
            return;
        }
        else{ // @@ Same issue: a==b case not handled.
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
    printf("len=%d\n",strlen(s)); // @@ Extra output not required by problem; should be removed.
    //len-=1;
    for(i=0;i<len;i++) // @@ len is uninitialized; loop condition causes undefined behavior. Should be i<strlen(s) or len=strlen(s) assigned.
    {
        if(s[i]!='-')
        printf("%c",s[i]);
        else{
            func(s[i-1],s[i+1]); // @@ When i is at boundaries (0 or len-1), s[i-1] and s[i+1] are out-of-bounds accesses. Also no check that both sides exist.
        }
    }
    return 0;
}