#include<stdio.h>
#include<string.h>
int main(void)
{
    char i;
    char *c=NULL;
    c=(char *)malloc(sizeof(char));
    scanf("%s",c);
    int a;
    for (a=0;*(c+a)!='\0';a++){
        if (*(c+a)=='-'){
            if (((*(c+a-1)>='0'&&*(c+a-1)<='9')&&(*(c+a+1)>='0'&&*(c+a+1)<='9'))||((*(c+a-1)>='A'&&*(c+a-1)<='Z')&&(*(c+a+1)>='A'&&*(c+a+1)<='Z'))||((*(c+a-1)>='a'&&*(c+a-1)<='z')&&(*(c+a+1)>='a'&&*(c+a+1)<='z'))){
                for (i=*(c+a-1)+1;i<*(c+a+1);i++) printf("%c",i);
            }
            else printf("-");
        }
        else printf("%c",*(c+a));
    }
    free(c);
    c=NULL;
    return 0;
}

