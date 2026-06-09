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
    printf("len=%d\n",strlen(s));
    //len-=1;
    for(i=0;i<len;i++) @@ [The variable 'len' is uninitialized. It is declared but never assigned the length of the string, so the loop condition uses an indeterminate value, leading to undefined behavior.]
    {
        if(s[i]!='-')
        printf("%c",s[i]);
        else{
            func(s[i-1],s[i+1]); @@ [When i=0, s[i-1] accesses s[-1], which is out-of-bounds. Similarly, when i is the last index, s[i+1] may access beyond the string. The code does not check bounds before accessing adjacent characters.]
        }
    }
    return 0;
}