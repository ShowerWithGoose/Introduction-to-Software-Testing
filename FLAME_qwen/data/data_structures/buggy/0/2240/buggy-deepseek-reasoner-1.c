#include<stdio.h>

char s[1025] = {'\0'};

void fk(int i);

int main(){
    gets(s);
    for(int i=0;s[i]!='\0';i++) // @@ [C99 style for loop declaration may cause compilation error in C89; also, when i==0, s[i-1] access later is out-of-bounds]
    {
        if(s[i]!='-') printf("%c",s[i]);
        else fk(i);
    }
    return 0;
}

void fk(int i)
{
    int k=1;
    if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a') // @@ [s[i-1] may be out-of-bounds when i==0; no bounds check]
    k=0;
    else if(s[i-1]<='9'&&s[i+1]<='9'&&s[i-1]>='0'&&s[i+1]>='0') // @@ [s[i-1] may be out-of-bounds when i==0; no bounds check]
    k=0;
    else if(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A') // @@ [s[i-1] may be out-of-bounds when i==0; no bounds check]
    k=0;
    
    if(s[i+1]-s[i-1]<=0) // @@ [s[i-1] may be out-of-bounds when i==0; no bounds check]
    k=1;
    if(k==1)
    return; // @@ [returns without printing the dash when expansion conditions are not met; should print s[i] instead]
    else{
        for(int j=1;s[i+1]-s[i-1]>j;j++) // @@ [C99 style for loop declaration; also s[i-1] may be out-of-bounds when i==0]
        printf("%c",s[i-1]+j);
    }
}