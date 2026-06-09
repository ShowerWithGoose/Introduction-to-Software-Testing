#include<stdio.h>

struct team
{
    int d;
    int m;
};
int main()
{
    struct team t1[1000];
    struct team t2[1000];
    struct team t[1000];
    int i=0;
    char c;
    while(1)
    {
        scanf("%d",&t1[i].d);
        scanf("%d",&t1[i].m);
        scanf("%c",&c);
        if(c=='\n')
        {
            break;
        }
        i++; // @@ [The increment happens after checking for newline, so the last valid term is not counted. This causes `num1 = i` to be one less than the actual number of terms.]
    }
    int j=0;
    while(1)
    {
        scanf("%d",&t2[j].d);
        scanf("%d",&t2[j].m);
        scanf("%c",&c);
        if(c=='\n')
        {
            break;
        }
        j++; // @@ [Same issue as above: `j` is incremented only when the character is not '\n', so the last term index is undercounted.]
    }
    
//    for(;i>=0;i--)
//    {
//        printf("%d %d\n",t1[i].d,t1[i].m);
//    }
//    for(;j>=0;j--)
//    {
//        printf("%d %d\n",t2[j].d,t2[j].m);
//    }
    int k=0;
    int num1=i; // @@ [`i` is the index of the last successfully read term, but because of the loop logic, it's actually one less than the count of terms. Should be `num1 = i + 1`.]
    int num2=j; // @@ [Same as above: should be `num2 = j + 1`.]
    for(i=0;i<num1+1;i++) // @@ [Because `num1` is already too small by 1, `num1+1` accidentally compensates, but this is fragile and relies on the earlier off-by-one. However, combined with the input logic error, it may still miss the last term if input parsing fails to capture it correctly.]
    {
        for(j=0;j<num2+1;j++) // @@ [Same issue as above.]
        {
            t[k].d=t1[i].d*t2[j].d;
            t[k].m=t1[i].m+t2[j].m;
            k++;
        }
    }
    for(i=0;i<k-1;i++)
    {
        for(j=i+1;j<k;j++)
        {
            if(t[i].m==t[j].m)
            {
                t[i].d=t[i].d+t[j].d;
                t[j].d=0; // @@ [This sets duplicate terms to zero but doesn't remove them or prevent printing zeros later. However, the print loop skips zero coefficients, so this may be acceptable, but inefficient and error-prone if multiple merges occur.]
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(t[i].d==0)
        {
            continue;
        }
        printf("%d %d ",t[i].d,t[i].m); // @@ [Output is not sorted in descending order of exponents as required by the problem statement. The merging step does not sort the terms, leading to incorrect output order.]
    }
    return 0;
}