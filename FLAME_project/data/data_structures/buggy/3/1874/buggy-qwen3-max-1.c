#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i,j,k,l,m,n;
    gets(str); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the logic below fails to correctly handle general cases of scientific notation conversion]
    if(str[0]=='0')
    {
        for(i=2;str[i]=='0';i++); // @@ [Assumes input always starts with "0." but doesn't verify presence of decimal point; also skips non-zero digit detection properly]
        //printf("%d",i);
        for(j=i;str[j]!='\0';j++)
        {
            j==i+1 ? printf(".%c",str[j]):printf("%c",str[j]); // @@ [Incorrect formatting: should print first non-zero digit, then '.', then rest; this prints '.' before second digit only]
        }
        //printf("%d",j);
        //printf("%c",str[j]);
        printf("e-%d",i-1); // @@ [Exponent calculation is wrong: for "0.00...x...", exponent should be -(number of leading zeros after decimal + 1), not i-1]
    }
    else if(str[strlen(str)-1]=='0') // @@ [This condition checks if last character is '0', but problem states there are no trailing zeros after decimal point, so this branch is based on a false assumption]
    {
        for(k=0;str[k]!='0';k++) // @@ [This loop stops at first '0', which may be in the middle (e.g., "102.3"), causing incorrect output]
        {
            k==1?printf(".%c",str[k]):printf("%c",str[k]); // @@ [Incorrect base formatting: should only have one digit before decimal, but this prints multiple digits until first '0']
        }
        for(l=k;str[l]!='\0';l++); // @@ [This loop does nothing useful; l ends up being strlen(str), but used incorrectly in exponent]
        
        printf("e%d",l-1);    // @@ [Exponent is miscalculated; should be (position of decimal point - 1), not l-1]
    }
    else
    {
        if(str[1]=='.') // @@ [Only handles case where number is like "d.xxxx" (one digit before decimal), but fails if more digits exist and last digit isn't '0']
        {
            printf("%s",str);
            printf("e0");
        }
        else{
        
        for(m=0;str[m]!='.';m++) // @@ [Loop finds position of decimal point, stored in m]
        {
            if(m==1) printf(".%c",str[m]); // @@ [Wrong: should print first digit, then '.', then subsequent digits; this prints digit[0], then at m=1 prints ".digit[1]", skipping proper base format]
            else printf("%c",str[m]);        
        }
        for(n=m+1;str[n]!='\0';n++)
        {
            printf("%c",str[n]);
        }
        printf("e%d",2*m-n+1); // @@ [Exponent formula is completely incorrect; correct exponent is (m - 1), since m is index of '.', and we move decimal to after first digit]
            }
    }
    return 0;
}