#include <stdio.h>
#include <string.h>
char s[100000];
void func(char a,char b)
{
    char i;
    if(a>='a'&&a<='z'&&b>='a'&&b<='z')
    {
        if(a>b){ // @@ [Should be a>=b to also treat a==b as invalid; currently a==b causes no output and dash is lost]
            printf("-");
            return;
        }
        else{
            for(i=a+1;i<b;i++)
            printf("%c",i);
        }
    }
    else if(a>='A'&&a<='Z'&&b>='A'&&b<='Z'){
        if(a>b){ // @@ [Same issue: should be a>=b]
            printf("-");
            return;
        }
        else{
            for(i=a+1;i<b;i++)
            printf("%c",i);
        }
    }
    else if(a>='0'&&a<='9'&&b>='0'&&b<='9'){
        if(a>b){ // @@ [Same issue: should be a>=b]
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
    int i,len; // @@ [len is uninitialized; must be set to strlen(s)]
    scanf("%s",s);
    //len=strlen(s); // @@ [This line should be uncommented to initialize len]
    printf("len=%d\n",strlen(s)); // @@ [This debug output is not part of the expected output and should be removed]
    //len-=1;
    for(i=0;i<len;i++) // @@ [len is uninitialized, causing undefined behavior in loop termination]
    {
        if(s[i]!='-')
        printf("%c",s[i]);
        else{
            func(s[i-1],s[i+1]);
        }
    }
    return 0;
}