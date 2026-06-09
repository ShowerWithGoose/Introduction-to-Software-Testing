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
    //len=strlen(s);
    printf("len=%d\n",strlen(s)); // @@ This line prints debug output, which is not part of the required output format and will cause mismatch with expected output.
    //len-=1;
    for(i=0;i<len;i++) // @@ Variable 'len' is uninitialized; it should be assigned strlen(s) instead of being commented out. This causes undefined behavior.
    {
        if(s[i]!='-')
        printf("%c",s[i]);
        else{
            func(s[i-1],s[i+1]); // @@ When i=0, s[i-1] accesses out-of-bounds memory (s[-1]), causing undefined behavior.
        }
    }
    return 0;
}