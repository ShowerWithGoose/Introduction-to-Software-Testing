#include <stdio.h>
struct duoxiangshi
{
    int xishu;
    int zhishu;
}duoxiangshi1[1000],duoxiangshi2[1000],duoxiangshi[1000000];
int main()
{
    int len1,len2,len3,temp;
    for(int i=1;;i++) // @@ The loop starts from i=1, but array indices in C start from 0. This causes the first term to be stored at index 1, leaving index 0 uninitialized. Later, when accessing duoxiangshi1[0] in the multiplication loop, it will use garbage values.
    {
        scanf("%d%d",&duoxiangshi1[i].xishu,&duoxiangshi1[i].zhishu);
        len1=i;
        if(getchar()=='\n')
            break;
    }
    for(int i=1;;i++) // @@ Same issue as above: loop starts from i=1, causing the first term of the second polynomial to be stored at index 1 instead of 0.
    {
        scanf("%d%d",&duoxiangshi2[i].xishu,&duoxiangshi2[i].zhishu);
        len2=i;
        if(getchar()=='\n')
            break;
    }
    int k=0;
    for(int i=0;i<len1;i++) // @@ The loop starts from i=0, but duoxiangshi1[0] was never assigned a valid value (since input started at index 1). This will use uninitialized data.
    {
        for(int j=0;j<len2;j++,k++) // @@ Similarly, duoxiangshi2[0] is uninitialized, leading to incorrect multiplication results.
        {
            duoxiangshi[k].xishu=duoxiangshi1[i].xishu*duoxiangshi2[j].xishu;
            duoxiangshi[k].zhishu=duoxiangshi1[i].zhishu+duoxiangshi2[j].zhishu;
        }
    }
    len3=k;
    for(k=0;k<len3;k++)
    {
        for(int j=k+1;j<len3;j++)
        {
            if(duoxiangshi[k].zhishu<duoxiangshi[j].zhishu)
            {                
                temp=duoxiangshi[k].zhishu;
                duoxiangshi[k].zhishu=duoxiangshi[j].zhishu;
                duoxiangshi[j].zhishu=temp;
                
                temp=duoxiangshi[k].xishu;
                duoxiangshi[k].xishu=duoxiangshi[j].xishu;
                duoxiangshi[j].xishu=temp;

            }
            else if(duoxiangshi[k].zhishu==duoxiangshi[j].zhishu)
            {
                duoxiangshi[k].xishu+=duoxiangshi[j].xishu;
                duoxiangshi[j].xishu=0;
                duoxiangshi[j].zhishu=0;
            }
        }
    }
    for(k=0;duoxiangshi[k].xishu!=0;k++) // @@ This loop assumes that all zero-coefficient terms are at the end after sorting, but due to the earlier errors, the array may contain uninitialized or incorrect data. Also, if the result polynomial has a term with coefficient 0 in the middle, the loop will stop prematurely.
    {
        printf("%d %d ",duoxiangshi[k].xishu,duoxiangshi[k].zhishu);
    }
}