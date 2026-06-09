#include <stdio.h>
typedef struct node{
	int x1;
	int x2;
	int y1;
	int y2;
	int valid;
	int count;
}line;
line l[105];
void bubblesort(line a[],int n);
void culmulate(int i,int n);
int main()
{
	int n,i;//线段数 
	line temp;//记录线段数最高 
	temp.count=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
		l[i].valid=1;
		l[i].count=1;
	}
	bubblesort(l,n);
	/*for(i=1;i<=n;i++)
	{
		printf("%d %d %d %d\n",l[i].x1,l[i].y1,l[i].x2,l[i].y2);
	}*/
	for(i=1;i<=n;i++)
	{
		if(l[i].valid==1)//只对有权利的线段操作 
		{
			culmulate(i,n);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(l[i].valid==1)
		{
			temp=(temp.count>l[i].count)?temp:l[i]; 
		}
	}
	printf("%d %d %d",temp.count,temp.x1,temp.y1);
	return 0;
 } 
void bubblesort(line a[],int n)
{
    int i,j;
    line hold;
    for(i=1;i<n;i++){
        for(j=1;j<n-i+1;j++){
            if(a[j].x1>a[j+1].x1){
                hold=a[j];
                a[j]=a[j+1];
                a[j+1]=hold;
            }

       }
       }
}
void culmulate(int i,int n)
{
	int temp;
	for(temp=i+1;temp<=n;temp++)
	{
		if(l[i].x2==l[temp].x1&&l[i].y2==l[temp].y1)//如果没有后续线段，不进行任何操作 
		{
			culmulate(temp,n);//统计后序线段的count
			l[i].count=l[temp].count+1;//加上自己 
			l[temp].valid=0;//有前序线段的线段被剥夺权利 
			break;
		}
	}
	return; 
}

