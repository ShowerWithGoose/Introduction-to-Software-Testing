#include<stdio.h>

char s[1025] = {'\0'};

void fk(int i);

int main(){
    gets(s); // @@ [gets is removed in the C11 standard, which causes a compilation error in modern environments; use fgets instead.]
    for(int i=0;s[i]!='\0';i++) // @@ [Declaring the loop variable 'i' inside the for statement is a C99 feature and may cause a compilation error in older C89/C90 compilers.]
    {
        if(s[i]!='-') printf("%c",s[i]);
        else fk(i); // @@ [When fk() determines no expansion is needed, it returns without printing '-', causing the '-' character to be missing from the output.]
    }
    return 0;
}

void fk(int i)
{
    int k=1;
    if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a')
    k=0;
    else if(s[i-1]<='9'&&s[i+1]<='9'&&s[i-1]>='0'&&s[i+1]>='0')
    k=0;
    else if(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A')
    k=0;

    if(s[i+1]-s[i-1]<=0)
    k=1;
    if(k==1)
    return; // @@ [When k==1, the function returns without printing the '-' character, violating the requirement to output the original string unchanged for invalid expansion cases.]
    else{
        for(int j=1;s[i+1]-s[i-1]>j;j++)
        printf("%c",s[i-1]+j);
    }
}