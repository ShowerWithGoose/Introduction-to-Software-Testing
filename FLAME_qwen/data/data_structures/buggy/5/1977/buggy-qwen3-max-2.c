#include <stdio.h>
struct unit
{
    int factor;
    int pow;
};
int main()
{
    struct unit expression1[100];
    struct unit expression2[100];
    struct unit ans[100]; // @@ [The size of 'ans' is too small. Multiplying two polynomials with up to 100 terms each can produce up to 10,000 terms, but 'ans' only has space for 100. This leads to buffer overflow and undefined behavior.]
    int flag1 = 0;
    int flag2 = 0;
    char line[1000];

    fgets(line, sizeof(line), stdin);
    char *token = strtok(line, " ");
    while (token != NULL) {
        sscanf(token, "%d", &expression1[flag1].factor);
        token = strtok(NULL, " ");
        if (token != NULL) {
            sscanf(token, "%d", &expression1[flag1].pow);
            token = strtok(NULL, " ");
            flag1++;
        }
    }

    fgets(line, sizeof(line), stdin);
    token = strtok(line, " ");
    while (token != NULL ) {
        sscanf(token, "%d", &expression2[flag2].factor);
        token = strtok(NULL, " ");
        if (token != NULL) {
            sscanf(token, "%d", &expression2[flag2].pow);
            token = strtok(NULL, " ");
            flag2++;
        }
    }

    int flag=0;
    for(int i=0;i<flag1;++i)
    {
        for(int j=0;j<flag2;++j)
        {
            ans[flag].factor=expression1[i].factor*expression2[j].factor;
            ans[flag++].pow=expression1[i].pow+expression2[j].pow;
        }
    }
    for(int i=0;i<flag1*flag2;++i) // @@ [This loop assumes exactly flag1*flag2 terms exist in 'ans', but if 'ans' overflows due to insufficient size, this accesses invalid memory. Also, after combining like terms, zero-coefficient terms should be excluded from output, but they are still processed here.]
    {
        for(int j=i+1;j<flag1*flag2;++j)
        {
            if(ans[i].pow==ans[j].pow)
            {
                ans[i].factor+=ans[j].factor;
                ans[j].factor=0; // @@ [Only the coefficient is zeroed; the exponent remains. Later sorting and printing may still process this term unless explicitly skipped. However, the bigger issue is that duplicate terms might not be fully merged if more than two terms share the same exponent.]
            }
        }
    }
    for(int i=0;i<flag1*flag2-1;i++) // @@ [Sorting range assumes all flag1*flag2 terms are valid, but some may have been zeroed out. Also, bubble sort is inefficient but logically acceptable if bounds are correct. However, due to small 'ans' array, this may access uninitialized or overflowed memory.]
    {
        for(int j=0;j<flag1*flag2-1-i;++j)
        {
            if(ans[j].pow<ans[j+1].pow)
            {
                struct unit temp;
                temp=ans[j];
                ans[j]=ans[j+1];
                ans[j+1]=temp;
            }
        }
    }
    for(int i=0;i<flag1*flag2;++i) // @@ [This prints all terms including those with zero coefficients that were not marked as invalid. Although there's a check for factor!=0, if merging was incomplete (e.g., three terms with same exponent), some zero terms might remain and be skipped correctly—but the main issue is potential buffer overflow from undersized 'ans'.]
    {
        if(ans[i].factor!=0)
        {
        printf("%d ",ans[i].factor);
        printf("%d ",ans[i].pow);
        }
    }
    return 0;   
}