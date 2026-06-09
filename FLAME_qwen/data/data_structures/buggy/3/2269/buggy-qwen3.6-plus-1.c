#include<stdio.h>
#include<string.h>
char s[101];
int main(){
    int j=0;
    char t;
    gets(s); // @@ [gets() has been removed from the C11 standard and causes a compilation error in modern compilers; use fgets() or scanf() instead]
    if(s[0]!='0'){

    for(int i=0;i<strlen(s);i++){ // @@ [Declaring loop variable 'i' inside the for statement is not allowed in C89/C90 standards, causing a compilation error; declare 'i' before the loop]

        if(s[i]=='.')
        {
        j=i;break;}

    }
        for(int i=0;i<j;i++)
    {
        if(i==1)
        printf(".");
        printf("%c",s[i]);
    }

        if(j==1)
        printf(".");
        for(int i=j+1;i<strlen(s);i++)
    {
        printf("%c",s[i]);
    }
        printf("e%d",j-1);

}
    else
    {
        for(int i=0;i<strlen(s);i++){

        if(s[i]!='0'&&s[i]!='.')
        {
        j=i;break;}

    }

    for(int i=j;i<strlen(s);i++)
    {
        printf("%c",s[i]);
        if(i==j+1)
        printf(".");

    }
    printf("e-%d",j-1);
    }
    return 0;}