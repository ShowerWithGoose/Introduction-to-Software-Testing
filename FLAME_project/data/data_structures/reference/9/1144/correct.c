#include<stdio.h>
int a,t,m,n,e,f,l=1;
struct mmm{
	int x1;
	int y1;
	int x2;
	int y2;
};
int main()
{

	struct mmm p[1005],q;
	scanf("%d",&a);
	for(int i=0;i<a;i++)
	{
		scanf("%d%d%d%d",&p[i].x1,&p[i].y1,&p[i].x2,&p[i].y2);
	}

	for(int i=0;i<a;i++)
	{
		t=0;
		for(int j=i+1;j<a;j++)
		{
			if(p[j].x1<p[i].x1)
            {
                q=p[j];
                p[j]=p[i];
                p[i]=q;
                t=1;
            }
		}
		if(t==0)
		break;
	}

	for(int i=0;i<a;i++)
	{
		m=1;
		n=i;
		for(int j=i+1;j<a;j++)
		{
			if(p[j].x1==p[n].x2&&p[j].y1==p[n].y2)
            {
                m++;
                n=j;
            }
		}
		if(m>l)
        {
            l=m;
            e=p[i].x1;
            f=p[i].y1;
        }
	}
	printf("%d %d %d",l,e,f);
	
}

