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
    printf("len=%d\n",strlen(s)); @@ [The program prints debug output "len=..." which is not part of the expected output, causing Wrong Answer.]
    //len-=1;
    for(i=0;i<len;i++) @@ [Variable 'len' is uninitialized; it should be set to strlen(s). Using uninitialized 'len' leads to undefined behavior and incorrect loop bounds.]
    {
        if(s[i]!='-')
        printf("%c",s[i]);
        else{
            func(s[i-1],s[i+1]); @@ [When '-' appears at position 0 (i=0), s[i-1] accesses s[-1], which is out-of-bounds. Also, expansion logic is flawed: it only prints characters between a and b, not including a and b themselves, and does not handle cases where expansion should not occur correctly. Additionally, the function prints '-' when expansion conditions aren't met, but according to requirements, the original substring (e.g., "a-R") should be output unchanged, not replaced by a single '-'.]
        }
    }
    return 0;
}