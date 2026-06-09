#include<stdio.h>
#include<string.h>
int wgt[200][200],vst[200]={0},s[200];
int n;
void deep(int x);
void broad(int x);

int main()
{	
	int m,p,q,y;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&p,&q);
		wgt[p][q]=1;
		wgt[q][p]=1;
	}
	deep(0);puts("");
	
	memset(vst,0,sizeof(vst));
	broad(0);puts("");
	
	scanf("%d",&y);
	memset(vst,0,sizeof(vst));
	vst[y]=1;	 
	deep(0);puts("");
	
	memset(vst,0,sizeof(vst));memset(s,0,sizeof(s));
	vst[y]=1;
	broad(0);puts("");
	return 0;
}

void deep(int x)
{
	int i;
	printf("%d ",x);
	vst[x]=1;
	for(i = 0; i < n; i++)
		if (wgt[x][i] && !vst[i])
		{
			deep(i);
		}
}

void broad(int x)
{
	int i,h=0,t=1,tmp;
	s[h]=x;
	while(h<=t)
	{
		tmp=s[h++];
		if(vst[tmp])	continue;
		else
		{
			printf("%d ",tmp);
			vst[tmp]=1;	
			for(i=0;i<n;i++)
				if (wgt[tmp][i] && !vst[i])
					s[t++]=i;
		}
	}
}

