#include<stdio.h>

char s[1025] = {'\0'};

void fk(int i);

int main(){
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!='-') printf("%c",s[i]);
        else fk(i);
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
    
    if(s[i+1]-s[i-1]<=0) // @@ [This condition incorrectly treats equal characters (e.g., B-e) as invalid for expansion, but the problem requires no expansion only when the character after '-' is less than or equal to the one before. For B-e, 'B' and 'e' are different types, so the expansion should not occur anyway, but the logic here is flawed because it sets k=1 for all non-positive differences, including cases where types differ. The correct check should ensure both characters are of the same type and the second is greater than the first.]
    k=1;
    if(k==1)
    return;
    else{
        for(int j=1;s[i+1]-s[i-1]>j;j++)
        printf("%c",s[i-1]+j);
    }
}