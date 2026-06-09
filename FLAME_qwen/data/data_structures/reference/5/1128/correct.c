#include<stdio.h>
int main()
{
    int i=0,j,k,m,n,mid,z1=0,z2=0,z3=0,z4=0,z5=1;
    char c;
    int xishu1[100],zhishu1[100];
    int xishu2[100],zhishu2[100];
    int xishu3[100],zhishu3[100];
    int xishu4[100],zhishu4[100];
    scanf("%d%d%c",&xishu1[0],&zhishu1[0],&c);
    for(i=1;c!='\n';i++)
	{
		scanf("%d%d%c",&xishu1[i],&zhishu1[i],&c);
	} 
	scanf("%d%d%c",&xishu2[0],&zhishu2[0],&c);
	for(j=1;c!='\n';j++)
	{
		scanf("%d%d%c",&xishu2[j],&zhishu2[j],&c);
	} 
	//printf("%d %d %d %d",xishu1[i-1],zhishu1[i-1],xishu2[j-1],zhishu2[j-1]);
    for(m=0;m<i;m++)
    {
        for(n=0;n<j;n++)
        {
            xishu3[z1]=xishu1[m]*xishu2[n];
            zhishu3[z1]=zhishu1[m]+zhishu2[n];
            z1++;
        }
    }
   // printf("%d",zhishu3[0]);
    for(z2=0;z2<z1-1;z2++)
    {
        for(z3=z2;z3<z1;z3++)
        {
            if(zhishu3[z2]<zhishu3[z3])
            {
                mid=zhishu3[z2];
                zhishu3[z2]=zhishu3[z3];
                zhishu3[z3]=mid;
                mid=xishu3[z2];
                xishu3[z2]=xishu3[z3];
                xishu3[z3]=mid;
            }
        }
    }
    //printf("%d",zhishu3[3]);
    zhishu4[0]=zhishu3[0];
    xishu4[0]=xishu3[0];
    for(z4=1;z4<z1;z4++)
    {
        if(zhishu3[z4]!=zhishu3[z4-1])
        {
            zhishu4[z5]=zhishu3[z4];
            xishu4[z5]=xishu3[z4];
			z5++;
        }
        else
        {
            xishu4[z5-1]=xishu4[z5-1]+xishu3[z4];
        }
        
    }
    for(i=0;i<z5;i++)
    {
        printf("%d %d ",xishu4[i],zhishu4[i]);
    }
}

