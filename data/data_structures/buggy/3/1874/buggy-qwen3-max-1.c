#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i,j,k,l,m,n;
    gets(str); // @@ [Use of unsafe and deprecated function 'gets' which can cause buffer overflow; also, the reference program uses 'scanf' instead]
    if(str[0]=='0')
    {
        for(i=2;str[i]=='0';i++); // @@ [If input is "0.0", this loop runs past the null terminator causing undefined behavior; also assumes at least two characters exist before digits]
        //printf("%d",i);
        for(j=i;str[j]!='\0';j++)
        {
            j==i+1 ? printf(".%c",str[j]):printf("%c",str[j]); // @@ [Incorrect formatting: when j==i (first non-zero digit), it should print without a decimal point unless there are more digits]
        }
        //printf("%d",j);
        //printf("%c",str[j]);
        printf("e-%d",i-1); // @@ [Exponent calculation is off by one in some cases; e.g., "0.001" should be "1e-3", but i=4 → i-1=3 → prints "e-3" correctly, but logic fragile]
    }
    else if(str[strlen(str)-1]=='0') // @@ [This condition checks if last character is '0', but problem states there are no trailing zeros after decimal point, so this branch may never trigger as intended]
    {
        for(k=0;str[k]!='0';k++) // @@ [Loop condition wrong: it stops at first '0', but number like "102.3" would break at '0' prematurely]
        {
            k==1?printf(".%c",str[k]):printf("%c",str[k]); // @@ [Assumes second digit is always after decimal or part of integer; doesn't handle numbers like "123.45"]
        }
        for(l=k;str[l]!='\0';l++); // @@ [This loop does nothing useful; l ends up as strlen(str), but used in exponent below incorrectly]
        
        printf("e%d",l-1);    // @@ [Exponent formula incorrect; e.g., "123.45" should be "1.2345e2", but this logic doesn't normalize properly]
    }
    else
    {
        if(str[1]=='.') // @@ [Only handles single-digit before decimal like "5.67"; fails for multi-digit like "12.34"]
        {
            printf("%s",str); // @@ [Prints original string, but scientific notation requires normalized form like "1.234e1", not "12.34"]
            printf("e0"); // @@ [Only correct if number is already in normalized form like "5.6", but even then should be "5.6e0", which is acceptable, but logic incomplete]
        }
        else{
        
        for(m=0;str[m]!='.';m++)
        {
            if(m==1) printf(".%c",str[m]); // @@ [Assumes normalization starts at m=1, but for "123.45", should print "1.2345", not "1.2" then rest]
            else printf("%c",str[m]);        
        }
        for(n=m+1;str[n]!='\0';n++)
        {
            printf("%c",str[n]);
        }
        printf("e%d",2*m-n+1); // @@ [Exponent formula is mathematically incorrect; correct exponent for "123.45" is 2, but 2*m - n +1 = 2*3 - 6 +1 = 1, which is wrong]
            }
    }
    return 0;
}