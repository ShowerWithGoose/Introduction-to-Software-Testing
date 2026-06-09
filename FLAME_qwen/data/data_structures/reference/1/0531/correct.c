#include<stdio.h>
#include<string.h>
int a[11];
char b[11];	int n;
void arrange(int x,int y)
{

	
	if( y==0){ 
		a[x]='\0';puts(b);
		return;
	}
	for(int i=1;i<=n;i++)
		if(a[i]==0)
		{
			a[i]=1; 
			b[x+1]=' ';	b[x]='0'+i;  	
			arrange(x+2,y-1); 	
			a[i]=0;	
		}
}
int main()
{
	
    memset(a,0,sizeof(a));
	scanf("%d",&n);
	int sum=1;
	for(int i=1;i<=n;i++)
	sum+=i;
	arrange(0,n);
	return 0;
	
 } 

