#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i,j,k,l,m,n;
    gets(str); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the logic below does not correctly handle general cases of scientific notation conversion]
    if(str[0]=='0')
    {
        for(i=2;str[i]=='0';i++); // @@ [Assumes input always starts with "0."; fails if input like "0.0..." has more than one zero after decimal before first non-zero]
        //printf("%d",i);
        for(j=i;str[j]!='\0';j++)
        {
            j==i+1 ? printf(".%c",str[j]):printf("%c",str[j]); // @@ [Incorrectly formats mantissa: should always print first digit, then '.', then rest; this skips first digit when j==i]
        }
        //printf("%d",j);
        //printf("%c",str[j]);
        printf("e-%d",i-1); // @@ [Exponent calculation is wrong: for "0.00123", first non-zero at index 3 (0-based), exponent should be -3, but i-1 = 2 → e-2]
    }
    else if(str[strlen(str)-1]=='0') // @@ [This condition checks if last character is '0', but problem states there are no trailing zeros after decimal point, so this branch is logically flawed]
    {
        for(k=0;str[k]!='0';k++) // @@ [This loop breaks at first '0', which may appear in middle of number (e.g., "102.34"), causing incorrect truncation]
        {
            k==1?printf(".%c",str[k]):printf("%c",str[k]); // @@ [Incorrect mantissa formatting: assumes second digit should follow decimal, but ignores digits after '.']
        }
        for(l=k;str[l]!='\0';l++); // @@ [This loop does nothing useful; l ends up as strlen(str), but used incorrectly in exponent]
        
        printf("e%d",l-1);    // @@ [Exponent l-1 is wrong; for "123.45", l = 6, prints e5, but correct exponent is 2]
    }
    else
    {
        if(str[1]=='.') // @@ [Only handles case where number is like "d.dddd"; fails for single-digit integer part without decimal, or multi-digit before '.']
        {
            printf("%s",str);
            printf("e0"); // @@ [Correct only if input is already normalized like "5.123"; but problem says if one digit before '.', it can be 0, but here assumes non-zero]
        }
        else{
        
        for(m=0;str[m]!='.';m++)
        {
            if(m==1) printf(".%c",str[m]); // @@ [Wrong: should print first digit, then '.', then subsequent digits; this prints first digit (m=0), then at m=1 prints ".digit", skipping proper structure]
            else printf("%c",str[m]);        
        }
        for(n=m+1;str[n]!='\0';n++)
        {
            printf("%c",str[n]);
        }
        printf("e%d",2*m-n+1); // @@ [Exponent formula 2*m - n + 1 is incorrect; for "87899.99...", m=5 (index of '.'), n goes to end (~20), gives negative exponent instead of +4]
            }
    }
    return 0;
}