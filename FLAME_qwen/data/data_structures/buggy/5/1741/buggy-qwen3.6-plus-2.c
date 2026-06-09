#include <stdio.h>
struct duoxiangshi
{
    int xishu;
    int zhishu;
}duoxiangshi1[1000],duoxiangshi2[1000],duoxiangshi[1000000];
int main()
{
    int len1,len2,len3,temp;
    for(int i=1;;i++) // @@ The loop starts at index 1, causing an off-by-one error. Additionally, declaring variables inside the for-loop initialization may cause a compilation error in C89/C90 standards.
    {
        scanf("%d%d",&duoxiangshi1[i].xishu,&duoxiangshi1[i].zhishu);
        len1=i;
        if(getchar()=='\n')
            break;
    }
    for(int i=1;;i++) // @@ Same off-by-one error and potential C89 compilation issue for the second polynomial input.
    {
        scanf("%d%d",&duoxiangshi2[i].xishu,&duoxiangshi2[i].zhishu);
        len2=i;
        if(getchar()=='\n')
            break;
    }
    int k=0;
    for(int i=0;i<len1;i++) // @@ Since input data is stored starting from index 1, this loop should start from 1 and use i<=len1 to correctly access all terms.
    {
        for(int j=0;j<len2;j++,k++) // @@ Same index mismatch for the second polynomial, should start from 1 and use j<=len2.
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