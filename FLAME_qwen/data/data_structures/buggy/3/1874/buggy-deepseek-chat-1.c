#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i,j,k,l,m,n;
    gets(str); // @@ gets() is unsafe and may cause buffer overflow; also not standard in modern C
    if(str[0]=='0')
    {
        for(i=2;str[i]=='0';i++);
        //printf("%d",i);
        for(j=i;str[j]!='\0';j++)
        {
            j==i+1 ? printf(".%c",str[j]):printf("%c",str[j]); // @@ logic error: when j==i+1, it prints a dot before the digit, but the first digit after zeros should be printed without a dot if it's the only digit; also the ternary condition is incorrect for handling the first non-zero digit
        }
        //printf("%d",j);
        //printf("%c",str[j]);
        printf("e-%d",i-1); // @@ exponent calculation error: should be -(i-2) because i starts from 2, so number of zeros before first non-zero is i-2, not i-1
    }
    else if(str[strlen(str)-1]=='0') // @@ condition is incorrect: this checks if last character is '0', but the problem says no trailing zeros after decimal point, so this case should not occur; also logic for this branch is flawed
    {
        for(k=0;str[k]!='0';k++) // @@ loop condition is wrong: it stops at first '0' which may be before decimal point, not handling the number correctly
        {
            k==1?printf(".%c",str[k]):printf("%c",str[k]); // @@ incorrect formatting: prints dot at wrong position
        }
        for(l=k;str[l]!='\0';l++); // @@ empty loop just to find length, but l is not used correctly
        
        printf("e%d",l-1); // @@ exponent calculation is incorrect
    }
    else
    {
        if(str[1]=='.')
        {
            printf("%s",str);
            printf("e0"); // @@ this is correct for numbers like 0.5, but the condition str[1]=='.' only works if first char is digit and second is dot, which is not general
        }
        else{
        
        for(m=0;str[m]!='.';m++)
        {
            if(m==1) printf(".%c",str[m]); // @@ incorrect: prints dot after first digit, but should print the first digit then dot for all subsequent digits
            else printf("%c",str[m]);        
        }
        for(n=m+1;str[n]!='\0';n++)
        {
            printf("%c",str[n]);
        }
        printf("e%d",2*m-n+1); // @@ exponent calculation is completely wrong; should be m-1 (number of digits before decimal point minus one)
            }
    }
    return 0;
}