#include <stdio.h>
#include <unistd.h>
int n;
int num=1;
int line_max=1;
struct place
{
	int x;
	int y;
}start[110],final[110];
int x_f,y_f;
void sort(struct place a[],struct place b[])
{
	int i,j,flag;
	struct place hold_x,hold_y;
	for (i=0; i<n-1; i++)
		{
			flag=0;
			for (j=0; j<n-1-i; j++)
				{
					if(a[j].x-a[j+1].x>0)
						{
							hold_x=a[j];
							a[j]=a[j+1];
							a[j+1]=hold_x;
							hold_y=b[j];
							b[j]=b[j+1];
							b[j+1]=hold_y;
							flag=1;
						}
				}
			if(0==flag)
				break;
		}
}
int lin(struct place a[],struct place b[],int i)
{
	for (int m=i; m<n; m++)
	{
		if(b[i].x==a[m].x&&b[i].y==a[m].y)
		{
			num++;
			lin(a,b,m);
		}
	}
	return num;
}
int main(int argc, char *argv[]) {
	scanf("%d",&n);
	for (int i=0; i<n; i++)
		scanf("%d %d %d %d",&start[i].x,&start[i].y,&final[i].x,&final[i].y);
	sort(start, final);
	for (int i=0; i<n; i++)
	{
		num=1;
		int c=lin(start,final,i);
		if(c>line_max)
			{
				line_max=c;
				x_f=start[i].x;
				y_f=start[i].y;
			}
	}
	printf("%d %d %d",line_max,x_f,y_f);
	return 0;
}
