#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 int m111=0;
int n, m, a[105][105];
int vis[105], ok, q[105];
void dfs(int x)
{
	if (!ok)
		printf("%d", x*m111/m111), ok = 1;
	else
		printf(" %d", x*m111/m111);
	vis[x] = 1;
	int i;
	for (i = 1; i <= n; i++)
		if (a[x][i])
		{
			if (!vis[i])
			{
				//			printf("&&%d %d\n",x,i);
				dfs(i);
			}
		}
}
void bfs(int t)
{
	q[1] = t;

	int l = 1, r = 1, i;
	while (l <= r)
	{
		int x = q[l];
		l++;
		if (vis[x])
			continue;
		if (!ok)
			printf("%d", x*m111/m111), ok = 1;
		else
			printf(" %d", x*m111/m111);

		vis[x] = 1;
		for (i = 1; i <= n; i++)
			if (a[x][i])
			{
				if (!vis[i])
					q[++r] = i;
			}
	}
	memset(vis, 0, sizeof(vis));
}

int s1[100];
int s2[100];
 
void J(int a2) 
{ int i,j;
	for(i=0;i<=a2-1;i++)
	{ if(s1[i]>=s2[i])
		s1[i]=s1[i]-s2[i];
		else
			{ if(i<a2-1)//借位 
			{
			s1[i]=s1[i]-s2[i]+10;
					if(s1[i+1]==0)//下一位是零 
					{
					j=i;
					while(s1[j+1]==0)//循环借位 
						{ s1[j+1]=9;
							j++;
						}
					s1[j+1]=s1[j+1]-1;
					}
					else//下一位不是零，直接借 
					s1[i+1]=s1[i+1]-1;
			}
			  else
			  s1[i]=s1[i]-s2[i];		
			}
	 } 
}
 int cmp(const void *p1,const void *p2)
{ int c=*((int *)p1);
 int b=*((int *)p2);
 if(c<b)
 {
 return 1;}
 else if(c>b)
 {
 return -1;} 
 else
 {
 return 0;}
}

int main()
{	int i111;
  for(i111=1;i111<=10;i111++)
  m111=m111+i111;
	scanf("%d%d", &n, &m);
	int i;
	for (i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	ok = 0;
	dfs(0);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	ok = 0;
	bfs(0);
	printf("\n");
	scanf("%d", &i);
	vis[i] = 1;
	ok = 0;
	dfs(0);
	printf("\n");
	memset(vis, 0, sizeof(vis));
	vis[i] = 1;
	ok = 0;
	bfs(0);
	printf("\n");
	



char c11[96],d11[96];

char a11[40]="abcdfe";
int b11[95]={0};
int i1,k11=1,n11=95,m11,j1=0,x11=0,z11;



 
 //
 for(i1=0;a11[i1]!='\0';i1++)
 { if(b11[a11[i1]-' ']==0)
 	{ b11[a11[i1]-' ']=k11;
 	k11++;
	 }
}
for(i1=1;i1<=k11-1;i1++)
{ for(j1=0;j1<=94;j1++)
	{ if(b11[j1]==i1)
		{ c11[i1-1]=j1+' ';
		}
	}
}
c11[95]='\0';
k11=k11-1;

for(i1=0;i1<=94;i1++)
{ if(b11[i1]==0)
c11[k11++]=i1+' ';
 } 
 
int *p11;
p11=b11;

 for(j1=0;j1<=94;j1++)
 { b11[j1]=1;
 }
 //
 i1=0;
 m11=c11[i1];
 b11[i1]=0;
 k11=0;
 i1=1;
while(x11<n11-1)                      
        { 
            if(*(p11+i1)!=0)  
			k11++;             
            if(k11==m11)
            {
                *(p11+i1)=0;                   
                k11=0;                        
                x11++;								 
				d11[m11-' ']=c11[i1];
				m11=c11[i1];
				if(x11==n11-1)
				z11=i1;                             
            }
            i1++;
            if(i1==n11)
			{   
			i1=0;     
			}
			                
        }
         
		d11[c11[z11]-' ']=c11[0];
		            
  	d11[95]='\0'  ; 
  
	return 0;
}



