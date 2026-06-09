#include <stdio.h>
int tmpx1,tmpy1,tmpx2,tmpy2,num=0,exi,win,max=0,tmd,t,m;
struct xd{
	int bgx;
	int bgy;
	int edx;
	int edy;
	int len;
}xd[110];
int main()
{
	int n,i;
	scanf("%d",&n);
	while(n--)
	{
		exi=0;
		scanf("%d%d%d%d",&tmpx1,&tmpy1,&tmpx2,&tmpy2);
	for(i=0;i<num;i++)
	{
		if(xd[i].edx==tmpx1&&xd[i].edy==tmpy1)
		{
			(xd[i].len)++;
			xd[i].edx=tmpx2;
			xd[i].edy=tmpy2;
			exi=1;
			break;
		}
		else if(xd[i].bgx==tmpx2&&xd[i].bgy==tmpy2)
		{
			(xd[i].len)++;
			xd[i].bgx=tmpx1;
			xd[i].bgy=tmpy1;
			exi=1;
			break;
		}
	}
	if(exi==0)
	{
		xd[num].bgx=tmpx1;
		xd[num].bgy=tmpy1;
		xd[num].edx=tmpx2;
		xd[num].edy=tmpy2;
		xd[num].len=1;
		num++;
		
	}
	}
	while(1)
	{
		tmd=0;
	for(i=0;i<num;i++)
	{
		exi=0;
		for(t=0;t<num;t++)
		{
			if(xd[i].edx==xd[t].bgx&&xd[i].edy==xd[t].bgy)
		{
			(xd[i].len)+=xd[t].len;
			xd[i].edx=xd[t].edx;
			xd[i].edy=xd[t].edy;
			exi=1;
			tmd=1;
			break;
		}
		else if(xd[i].bgx==xd[t].edx&&xd[i].bgy==xd[t].edy)
		{
			(xd[i].len)+=xd[t].len;
			xd[i].bgx=xd[t].bgx;
			xd[i].bgy=xd[t].bgy;
			exi=1;
			tmd=1;
			break;
		}
		}
		if(exi==1)
		{
			for(m=t;m<num-1;m++)
			{
				xd[m].bgx=xd[m+1].bgx;
				xd[m].bgy=xd[m+1].bgy;
				xd[m].edx=xd[m+1].edx;
				xd[m].edy=xd[m+1].edy;
				xd[m].len=xd[m+1].len;
			}
			num--;
		}
		
	}
	if(tmd==0)
	break;
    }
	for(i=0;i<num;i++)
	{
		if(xd[i].len>max)
		{
			max=xd[i].len;
			win=i;
		}
	}
	printf("%d %d %d",xd[win].len,xd[win].bgx,xd[win].bgy);
	return 0;
}

