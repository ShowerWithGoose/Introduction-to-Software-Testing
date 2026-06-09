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
    for(int i=0;i<flag1*flag2;++i) // @@ [This loop assumes exactly flag1*flag2 terms, but 'flag' may be less if input parsing failed or was incomplete. Also, after combining like terms, zero-coefficient terms are not removed from consideration in sorting, which may cause incorrect output order or extra zeros.]
    {
        for(int j=i+1;j<flag1*flag2;++j)
        {
            if(ans[i].pow==ans[j].pow)
            {
                ans[i].factor+=ans[j].factor;
                ans[j].factor=0; // @@ [Only the coefficient is zeroed; the exponent remains. Later, during sorting and printing, this term may still appear if not properly skipped, but more critically, it interferes with correct combination if multiple same exponents exist beyond pairs.]
            }
        }
    }
    for(int i=0;i<flag1*flag2-1;i++) // @@ [Sorting range assumes all flag1*flag2 entries are valid, but some may be zeroed-out terms that should be excluded. Also, bubble sort is inefficient but acceptable; however, it sorts even zero terms, which are later skipped—but this is logically okay if printing skips zeros. The real issue is array size and incomplete combination of like terms.]
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
    for(int i=0;i<flag1*flag2;++i) // @@ [Loop iterates over all possible product terms, including those set to zero. While it checks 'factor!=0', if array 'ans' overflows due to insufficient size (as noted earlier), this loop accesses uninitialized or out-of-bound memory, causing undefined behavior.]
    {
        if(ans[i].factor!=0)
        {
        printf("%d ",ans[i].factor);
        printf("%d ",ans[i].pow);
        }
    }
    return 0;   
}