#include<stdio.h>
#include<string.h>
char c[100000000];
int main()
{
    int o=0,i=0,t=0,l;
    while(scanf("%c",&c[i])!=EOF) // @@ This reads the newline character and does not stop at it; should use scanf("%s") or break on '\n' to match expected input.
    {
        if(c[i]=='.')
        t=i;
        else
        i++;
    }
    i--;
    if(c[0]=='0')
    {
        for(l=1;c[l]=='0';l++); // @@ Starts from index 1 which is '.' for numbers like "0.xxx"; should start from index 2 (after decimal) or correctly skip the dot.
        if(i==(l+1))
        printf("%ce-%d",c[l],l); // @@ Uses c[l] which is the decimal point '.' instead of the actual first non-zero digit; base is wrong.
        else
        {
            int k=l;
            printf("%c.",c[l]); // @@ c[l] is again the decimal point; should print the first non-zero digit.
            for(l++;l<i;l++)
            printf("%c",c[l]);
            printf("e-%d",k); // @@ Exponent k is incorrect because l was not correctly set; should be number of zeros after decimal.
        }
    }
    else
    {
        printf("%c.",c[0]);
        for(l=1;l<i;l++) // @@ This loop prints all characters from index 1 to i-1, including the decimal point '.'; should skip the dot.
        printf("%c",c[l]);
        printf("e%d",t-1);
    }
    return 0;
}