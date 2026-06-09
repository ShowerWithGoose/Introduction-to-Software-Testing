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
    struct unit ans[100]; // @@ [The size of 'ans' is too small. Multiplying two polynomials with up to 100 terms each can produce up to 100*100 = 10,000 terms before combining like terms, but 'ans' only has space for 100 elements, leading to buffer overflow.]
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
    for(int i=0;i<flag1*flag2;++i) // @@ [This loop assumes exactly flag1*flag2 terms exist in 'ans', but 'flag' may be less if input parsing failed or was incomplete. More critically, it accesses beyond the actual number of stored terms if flag < flag1*flag2, but the real issue is that 'ans' array is too small as noted earlier.]
    {
        for(int j=i+1;j<flag1*flag2;++j)
        {
            if(ans[i].pow==ans[j].pow)
            {
                ans[i].factor+=ans[j].factor;
                ans[j].factor=0;
            }
        }
    }
    for(int i=0;i<flag1*flag2-1;i++) // @@ [Same issue: assumes flag1*flag2 terms, but also performs bubble sort on possibly uninitialized or zeroed entries, and doesn't handle zero-coefficient terms properly before sorting. Additionally, sorting after combining like terms is inefficient but not incorrect per se; however, the fixed array size remains the critical flaw.]
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
    for(int i=0;i<flag1*flag2;++i) // @@ [Again iterates over flag1*flag2 terms, but many may be zero or uninitialized due to insufficient array size and incorrect term count handling. Also, zero-coefficient terms are skipped, which is correct, but the loop bound is wrong because actual valid terms are only 'flag' (which equals flag1*flag2 only if parsing succeeded fully), yet 'ans' array is too small to hold them safely.]
    {
        if(ans[i].factor!=0)
        {
        printf("%d ",ans[i].factor);
        printf("%d ",ans[i].pow);
        }
    }
    return 0;   
}