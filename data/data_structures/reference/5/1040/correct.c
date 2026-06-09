#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Duo
{
    int numx;
    int numz;
};

int main()
{
    struct Duo x[200],y[200],z[200],zz[200];
    int a,b,i,j,sumx=0,sumy=0;
    for(i=0;a!='\n';i++)
    {
        scanf("%d%d",&x[i].numx,&x[i].numz);
        sumx++;
        a=getchar();
    }
    for(i=0;b!='\n';i++)
    {
        scanf("%d%d",&y[i].numx,&y[i].numz);
        sumy++;
        b=getchar();
    }   //输入

    int k=0;
    for(i=0;i<sumx;i++)
    {
        for(j=0;j<sumy;j++)
        {
            z[k].numx=x[i].numx*y[j].numx;
            z[k].numz=x[i].numz+y[j].numz;
            k++;
        }
    }   //相乘

    struct Duo emp={-1,-1};
    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k;j++)
        {
            if(z[i].numz==z[j].numz)
            {
                z[i].numx+=z[j].numx;
                z[j]=emp;
            }
        }
    }
    int m=0;
    for(i=0;i<k;i++)
    {
        if(z[i].numx!=-1&&z[i].numz!=-1)
        {
            zz[m]=z[i];
            m++;
        }
    }   //合并同类项

    struct Duo temp;
    for(i=0;i<m;i++)
	{	
		for(j=i+1;j<m;j++)
		{
			if(zz[i].numz<zz[j].numz)
            {
                temp=zz[i];
                zz[i]=zz[j];
                zz[j]=temp;
            }
		}
	}

    for(i=0;i<m;i++)
    {
        printf("%d %d ",zz[i].numx,zz[i].numz);
    }
}
