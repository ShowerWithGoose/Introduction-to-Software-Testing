#include<stdio.h>
#include<string.h>
char str[101];

int main()
{
    gets(str);
    int len,k,flag=0;
    len=strlen(str);
    if(str[0]!='0')
        {
        printf("%c.",str[0]);
        for(k=1;k<len;k++)
        {
            if(str[k]!='.')
            {
                printf("%c",str[k]);
            }
            else flag=k;
        }
        printf("e%d",flag-1); // @@ [When there's no decimal point in the input (e.g., "123"), flag remains 0, leading to incorrect exponent calculation. Also, this branch assumes there is always a decimal point, which may not be true per problem constraints.]
        
        }
    else{
        for(k=2;k<len;k++)
        {
            if(str[k]!='0')
            {
                printf("%c",str[k]);    
                break;
            }
        }
        if(k!=len-1)
        {
            printf(".");
            for(int i=k+1;i<len;i++)
            {
                printf("%c",str[k]); // @@ [This should print str[i], not str[k]. Using str[k] repeats the first non-zero digit instead of printing subsequent digits.]
            }
        }
        printf("e-%d",k-1); // @@ [The exponent should be -(k - 1), but since k starts at 2 (after "0."), the number of leading zeros is (k - 2), so exponent should be -(k - 1) only if counting from decimal point. However, the real issue is that the logic doesn't correctly count leading zeros; it should be (k - 1) zeros after decimal before first non-zero, so exponent is -(k - 1). But due to off-by-one and the digit printing error above, this fails.]
    }
    return 0;
    
}