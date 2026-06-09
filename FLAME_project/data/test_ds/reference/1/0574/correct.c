#include<stdio.h>
#include<string.h>
void kuozhan(char a,char b)
{
    char i;
    if((a<='Z'&&a>='A'&&b<='Z'&&b>='A')||(a<='z'&&a>='a'&&b<='z'&&b>='a')||(a<='9'&&a>='0'&&b<='9'&&b>='0')){
        for(i=a+1;i<b;i++)printf("%c",i);
    }
    else printf("-");
}
int main()
{
    char a[200];
    gets(a);
    for(int i=0;a[i]!='\0';i++){
        if(a[i]=='-'){
            kuozhan(a[i-1],a[i+1]);
        }
        else {
            printf("%c",a[i]);
        }
    }
    return 0;
}



