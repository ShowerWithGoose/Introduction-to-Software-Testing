#include <stdio.h>
#include<stdlib.h>
struct dxs
{
    int xishu;
    int zhishu;
}dxs1[1000],dxs2[1000],dxs[10000];
int i,j,len1,len2,k,temp,len3;
void shuru(void){
	for(i=0;;i++)
    {
        scanf("%d%d",&dxs1[i].xishu,&dxs1[i].zhishu);
        len1=i+1;
        if(getchar()=='\n')
            break;
    }
    for(i=0;;i++)
    {
        scanf("%d%d",&dxs2[i].xishu,&dxs2[i].zhishu);
        len2=i+1;
        if(getchar()=='\n')
            break;
    }
}
int main()
{
	shuru();
    for(i=0,k=0;i<len1;i++)
    {
        for(j=0;j<len2;j++,k++)
        {
            dxs[k].xishu=dxs1[i].xishu*dxs2[j].xishu;
            dxs[k].zhishu=dxs1[i].zhishu+dxs2[j].zhishu;
        }
    }
    len3=k;
    for(k=0;k<len3;k++)
    {
        for(j=k+1;j<len3;j++)
        {
            if(dxs[k].zhishu<dxs[j].zhishu)
            {
                temp=dxs[k].xishu;
                dxs[k].xishu=dxs[j].xishu;
                dxs[j].xishu=temp;
                temp=dxs[k].zhishu;
                dxs[k].zhishu=dxs[j].zhishu;
                dxs[j].zhishu=temp;
            }
            else if(dxs[k].zhishu==dxs[j].zhishu)
            {
                dxs[k].xishu+=dxs[j].xishu;
                dxs[j].xishu=0;
                dxs[j].zhishu=0;
            }
        }
    }
    for(k=0;dxs[k].xishu!=0;k++)
    {
        printf("%d %d ",dxs[k].xishu,dxs[k].zhishu);
    }
    return 0;
}

