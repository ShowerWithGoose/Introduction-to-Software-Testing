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
        i++;
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
        j++;
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
    int num1=i;
    int num2=j;
    for(i=0;i<num1+1;i++) // @@ Error: The loop condition should be i<num1, not i<num1+1, because num1 is the index of the last element (after the break, i is not incremented for the last term), so the number of terms is num1+1, but the loop starts from 0, so it should iterate num1+1 times, which is correct. However, the issue is that when reading input, i is incremented only after storing a term, but the break occurs before incrementing i for the last term. So after the loop, i is the index of the last term (e.g., if there are 3 terms, i=2 after the loop). Then num1=i, so num1+1=3, which is correct. But the loop uses i<num1+1, which iterates 3 times (i=0,1,2), which is correct. The actual error is that the input reading logic is flawed: when the first term is read, i=0, then i is incremented to 1 after the scanf, but if the next character is newline, the loop breaks, leaving i=1, but only one term was stored at index 0. So num1=1, but there is only 1 term. The loop then iterates i=0,1, accessing t1[1] which is uninitialized. This causes undefined behavior. The correct fix is to not increment i before the break, or to adjust the loop bounds.
    {
        for(j=0;j<num2+1;j++) // @@ Error: Same issue as above; the loop should be j<num2, not j<num2+1, because num2 is the index of the last term, so the number of terms is num2+1, but the loop starts from 0, so it should iterate num2+1 times. However, due to the input reading bug, num2 may be incorrect. The core problem is the input reading logic.
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
                t[j].d=0;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(t[i].d==0)
        {
            continue;
        }
        printf("%d %d ",t[i].d,t[i].m);
    }
    return 0;
}