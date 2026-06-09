#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int m[1005][2],n[1005][2];
struct ans
{
	int a;
	int b;	
};
struct ans x[1000005];
int cmp(const void *a,const void *b)
{
	struct ans s1,s2;
	s1=*(struct ans*)a;
	s2=*(struct ans*)b;
	if(s2.b>s1.b) return 1;
	if(s2.b<s1.b) return -1;
	if(s2.b==s1.b) return 0;
}
int flag;
int read() {
    int x = 0, f = 1, c = getchar();flag=0;
    while ((c < '0' || c > '9')) (c == '-') ? (f = -1) : 0, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();if (c=='\n') flag= -1;
    return x * f;
}
int main()
{
	int i,j,mm=0,nn=0,k=0,l,h;
	/*while((l=read()),(h=read())) 
	{
		m[mm][0]=l;m[mm][1]=h;
		mm++;
		if(flag==-1) break;
	}
	m[mm][0]=l;m[mm][1]=h;
	while((l=read()),(h=read()))
	{
		n[nn][0]=l;n[nn][1]=h;
		nn++;
		if(flag==-1) break;
	}
	n[nn][0]=l;n[nn][1]=h;*/
	scanf("%d %d", &m[mm][0], &m[mm][1]);
	while(getchar()!='\n') 
	{
		mm++;
		scanf("%d %d", &m[mm][0], &m[mm][1]);
	}
	scanf("%d %d", &n[nn][0], &n[nn][1]);
	while(getchar()!='\n')
	{
		nn++;
		scanf("%d %d", &n[nn][0], &n[nn][1]);
	}
	for(i=0;i<=mm;i++)
	{
		for(j=0;j<=nn;j++)
		{
			x[k].a=m[i][0]*n[j][0];
			x[k].b=m[i][1]+n[j][1];
			k++;
		}
	}
	qsort(x,k,sizeof(x[0]),cmp);
	for(i=1;i<k;i++)
	{
		if(x[i].b==x[i-1].b)
		{
			x[i-1].b=-1;
			x[i].a+=x[i-1].a;
		}
	}
	qsort(x,k,sizeof(x[0]),cmp);
	for(i=0;i<k;i++)
		if(x[i].b!=-1&&x[i].a!=0)
			printf("%d %d ", x[i].a, x[i].b);
	return 0;
} 

