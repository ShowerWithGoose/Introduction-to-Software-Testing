#include<stdio.h>
struct multi
{
    int xs;
    int zs; 
}multi1[10010],multi2[10010],multi[10010];
int main()
{
    int i,j,len1,len2,len3,k,temp;
    for(i=0;;i++)
    {
        scanf("%d%d",&multi1[i].xs,&multi1[i].zs);
        len1=i+1;
        if(getchar()=='\n')
            break;
    }
    for(i=0;;i++)
    {
        scanf("%d%d",&multi2[i].xs,&multi2[i].zs);
        len2=i+1;
        if(getchar()=='\n')
            break;
    }
    for(i=0,k=0;i<len1;i++)
    {
        for(j=0;j<len2;j++,k++)
        {
            multi[k].xs=multi[i].xs*multi[j].xs; // @@ Error: should use multi1[i].xs and multi2[j].xs, not multi[].
            multi[k].zs=multi[i].zs+multi[j].zs; // @@ Error: should use multi1[i].zs and multi2[j].zs.
         } 
    }
    len3=k;
    for(k=0;k<len3;k++)
    {
        for(j=k+1;j<len3;j++)
        {
            if(multi[k].zs<multi[j].zs)
            {
                temp=multi[k].xs;
                multi[k].xs=multi[j].xs;
                multi[j].xs=temp;
                temp=multi[k].zs;
                multi[k].zs=multi[j].zs;
                multi[j].zs=temp;
            }
            else if(multi[k].zs==multi[j].zs)
            {
                multi[k].xs+=multi[j].xs;
                multi[j].xs=0;
                multi[j].zs=0;
            }
        }
    }
    for(k=0;multi[k].xs!=0;k++) // @@ Error: condition should be k < len3 and print only if coefficient != 0; current loop stops at first zero coefficient, missing later non-zero terms.
    {
        printf("%d %d ",multi[k].xs,multi[k].zs);
    }
    return 0;
}