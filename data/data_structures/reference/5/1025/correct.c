#include<stdio.h>
#include<stdlib.h>
struct linknode
{long long number;
int fir;
};
struct linknode link1[100],link2[100],link3[500];
int n1=0,n2=0,n3=0,i,j,k,m,op=0;
char a;
int cmp(const void* ,const void*);
int main()
{
for(i=0;;i++)
	{scanf("%lld%d",&link1[i].number,&link1[i].fir);
	scanf("%c",&a);
	if(a=='\n')
		break;
	}
n1=i+1;
for(i=0;;i++)
	{scanf("%lld%d",&link2[i].number,&link2[i].fir);
	scanf("%c",&a);
	if(a=='\n')
		break;
	}
n2=i+1;
for(i=0;i<n2;i++)
	{link3[i].number=link2[i].number*link1[0].number;
	link3[i].fir=link2[i].fir+link1[0].fir;
	}
n3=n2;
for(i=1;i<n1;i++)
	{for(j=0;j<n2;j++)
		{m=link1[i].fir+link2[j].fir;
		op=0;
		for(k=0;k<n3;k++)
			{if(link3[k].fir==m)
				{link3[k].number+=link2[j].number*link1[i].number;
				op=1;
				break;
				}
			}
		if(op==0)
			{link3[n3].number=link2[j].number*link1[i].number;
			link3[n3].fir=m;
			n3++;
			}
		}
	}
qsort(link3,n3,sizeof(link3[0]),cmp);
for(i=0;i<n3;i++)
	printf("%lld %d ",link3[i].number,link3[i].fir);
return 0;
}
int cmp(const void *p1,const void *p2)
{struct linknode *a=(struct linknode*)p1;
struct linknode *b=(struct linknode*)p2;
return (b->fir-a->fir);
}

