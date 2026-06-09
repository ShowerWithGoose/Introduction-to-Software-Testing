#include<stdio.h>
int js=0,c[4000000][10]={0},num;
void pailie(int n,int a[])
{
	int i,y=1;
	for(i=n-1;i>=1;i--)
	  y=y*i;                             //½×³Ë 
	for(i=0;i<n;i++){
		c[js][num-n]=a[i];
		if(n>1)
		{
			int b[10],j,k;
			for(j=0,k=0;k<n;k++){
				if(k!=i)
				  {
				  	b[j]=a[k];
				  	j++;
				  }	  
			}
			pailie(n-1,b);
		}
		else
		  js++;
	}
}
int main()
{
	int a[10],i,y=1,l;
	scanf("%d",&num);
	for(i=0;i<num;i++){
		a[i]=i+1;
	}
	pailie(num,a);
	for(i=num;i>=1;i--)
	  y=y*i;
	for(l=0;l<num;l++)
	{
		int jicun=0;
		for(i=0;i<y;i++)
		  {
		  	if(c[i][l]!=0)
		  	  jicun=c[i][l];
		  	else
		  	  c[i][l]=jicun;
		  }
	}
	for(i=0;i<y;i++)
	{
		for(l=0;l<num;l++)
		  {
		  	printf("%d ",c[i][l]);
		  }
		printf("\n");
	}
	/*printf("%d",a[1]);*/
	return 0;
}



