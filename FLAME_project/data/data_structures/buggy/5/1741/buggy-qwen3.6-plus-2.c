#include <stdio.h>
struct duoxiangshi
{
    int xishu;
    int zhishu;
}duoxiangshi1[1000],duoxiangshi2[1000],duoxiangshi[1000000];
int main()
{
    int len1,len2,len3,temp;
    for(int i=1;;i++) // @@ The loop starts at i=1, but the multiplication loop later uses indices starting from 0. This causes the first element (index 0) of duoxiangshi1/2 to be uninitialized (garbage) and used in calculation, while the last read element is stored at index len1. Also, if input has only one term, len1 becomes 1, but the multiplication loop runs for i=0 to <1, accessing index 0 which was never written to by scanf.
    {
        scanf("%d%d",&duoxiangshi1[i].xishu,&duoxiangshi1[i].zhishu);
        len1=i;
        if(getchar()=='\n')
            break;
    }
    for(int i=1;;i++) // @@ Same error as above for the second polynomial. Indices are shifted by 1 compared to the multiplication logic.
    {
        scanf("%d%d",&duoxiangshi2[i].xishu,&duoxiangshi2[i].zhishu);
        len2=i;
        if(getchar()=='\n')
            break;
    }
    int k=0;
    for(int i=0;i<len1;i++) // @@ This loop accesses duoxiangshi1[0] to duoxiangshi1[len1-1]. However, the input loop stored data in duoxiangshi1[1] to duoxiangshi1[len1]. Thus, it reads uninitialized memory for index 0 and misses the last valid term stored at index len1.
    {
        for(int j=0;j<len2;j++,k++) // @@ Similarly, this accesses duoxiangshi2[0] to duoxiangshi2[len2-1], missing the valid data at indices 1 to len2.
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
    for(k=0;duoxiangshi[k].xishu!=0;k++)
    {
        printf("%d %d ",duoxiangshi[k].xishu,duoxiangshi[k].zhishu);
    }
}