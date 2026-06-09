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
    for(i=0;i<len;i++) // @@ [Using uninitialized variable 'len'; 'len' is declared but never assigned a value, leading to undefined behavior in the loop condition.]
    {
        if(s[i]!='-')
        printf("%c",s[i]);
        else{
            func(s[i-1],s[i+1]); // @@ [Potential out-of-bounds access: when i=0, s[i-1] accesses s[-1]; when i is the last index, s[i+1] may be out of bounds. Also, no check ensures that '-' is not at the start or end of the string.]
        }
    }
    return 0;
}