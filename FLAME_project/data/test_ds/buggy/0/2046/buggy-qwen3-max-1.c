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
    printf("len=%d\n",strlen(s)); // @@ [The program prints "len=..." which is not part of expected output; also, 'len' is uninitialized and used in loop]
    //len-=1;
    for(i=0;i<len;i++) // @@ ['len' is uninitialized; should be set to strlen(s). This causes undefined behavior and incorrect loop bounds.]
    {
        if(s[i]!='-')
        printf("%c",s[i]);
        else{
            func(s[i-1],s[i+1]); // @@ [When '-' is at position 0, s[i-1] accesses invalid memory (s[-1]). Also, expansion logic is wrong: it prints characters between a and b but excludes endpoints, while problem requires including both ends (e.g., a-d → abcd). Additionally, the function prints '-' on invalid cases, but original '-' should be preserved along with surrounding chars, not replaced by just '-'.]
        }
    }
    return 0;
}