#include<stdio.h>
int x[100][200], y[100][200];
void insert(int j,int a,int b);
void bubbleSort(int a[], int b[], int n);
int main()
{
	int n, x1, x2, y1, y2;	
	int i, j, k, l, m, line=0, flag, max=0, mm, head;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		flag=0;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(j=0;j<line;j++)
		{
			if(x[j][0]==x2&&y[j][0]==y2)
			{
				insert(j,x1,y1);
					flag=1;break;
				
			}
			else
			{
				for(k=0;x[j][k]!=x[j][k+1];k++);
				if(x[j][k-1]==x1&&y[j][k-1]==y1)
				{
					x[j][k]=x2;
					y[j][k]=y2;
					flag=1;break;	
				}
			}
		}
		if(flag==0)
		{
			x[line][0]=x1;
			x[line][1]=x2;
			y[line][0]=y1;
			y[line++][1]=y2;
		}	
	}
	for(i=0;i<line;i++)
	{
		for(k=0;x[i][k]!=x[i][k+1];k++);
		for(j=i+1;j<line;j++)
		{
			for(l=0;x[j][l]!=x[j][l+1];l++);
			if(x[i][0]==x[j][l-1]&&y[i][0]==y[j][l-1])
			{
				for(m=1;m<k;m++)
				{
					x[j][l]=x[i][m];
					y[j][l++]=y[i][m];
				}
				bubbleSort(x[j],y[j],l);
				for(m=0;m<k;m++)
					x[i][m]=y[i][m]=0;
				break;
			}
			if(x[i][k-1]==x[j][0]&&y[i][k-1]==y[j][0])
			{
				for(m=0;m<k-1;m++)
				{
					x[j][l]=x[i][m];
					y[j][l++]=y[i][m];
				}
				bubbleSort(x[j],y[j],l);
				for(m=0;m<k;m++)
					x[i][m]=y[i][m]=0;
				break;
			}
		}
	}
	for(i=0;i<line;i++)
	{
		for(k=0;x[i][k]!=x[i][k+1];k++);
		if(k>max)
		{
			max=k;mm=i;
		}	
	}
	printf("%d %d %d",max-1,x[mm][0],y[mm][0]);
}
void insert(int j,int a,int b)
{
	int i, k, hold, hhold;			
	for(k=0;x[j][k]!=x[j][k+1];k++);
	for(i=0;i<k;i++)
	{
		hold=x[j][i];
		x[j][i]=a;
		a=hold;
		hhold=y[j][i];
		y[j][i]=b;
		b=hhold;		
	}
	x[j][i]=a;y[j][i]=b;
}
void bubbleSort(int a[], int b[], int n)    //Ã°ÅÝËã·¨ 
{
	int i, j, hold,hhold, flag;
	for( i = 0; i < n-1; i++)
	{
		flag=0;	
		for(j = 0; j < n-1-i; j++)
		{	
			if(a[j] > a[j+1])
			{
			hold = a[j];
			a[j] = a[j+1];
			a[j+1] = hold;
			hhold = b[j];
			b[j] = b[j+1];
			b[j+1] = hhold;
			flag=1;
			}
		}
		if(flag==0)
		break;
	}
}


