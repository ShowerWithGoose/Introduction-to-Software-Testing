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
    for(int i=0;i<flag1*flag2;++i) // @@ [This loop assumes exactly flag1*flag2 terms exist in 'ans', but if 'ans' overflows due to insufficient size, this accesses invalid memory. Also, after merging like terms, zero-coefficient terms are not removed from consideration in sorting.]
    {
        for(int j=i+1;j<flag1*flag2;++j)
        {
            if(ans[i].pow==ans[j].pow)
            {
                ans[i].factor+=ans[j].factor;
                ans[j].factor=0; // @@ [Only the coefficient is zeroed; the exponent remains. Later, during sorting and output, these zero-coefficient terms may still be printed if not properly skipped, or interfere with ordering. However, the bigger issue is that duplicate exponents might not all be merged due to incomplete collapsing (only pairwise from i onward).]
            }
        }
    }
    for(int i=0;i<flag1*flag2-1;i++) // @@ [Sorting range assumes all flag1*flag2 terms are valid, but some may have been zeroed. More critically, if flag1 or flag2 is zero (empty polynomial), this loop runs with negative bound, causing undefined behavior. Also, bubble sort is inefficient but not incorrect per se.]
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
    for(int i=0;i<flag1*flag2;++i) // @@ [Iterates over all possible product terms, including those set to zero. While it checks 'factor!=0' before printing, if the array 'ans' was too small (as noted earlier), this loop reads beyond valid data, causing undefined behavior.]
    {
        if(ans[i].factor!=0)
        {
        printf("%d ",ans[i].factor);
        printf("%d ",ans[i].pow);
        }
    }
    return 0;   
}