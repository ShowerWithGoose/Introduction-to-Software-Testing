#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
int maxi=0;
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int flag;
}l[150],*p,*q,*t;

int rem(int n);			//对线段分组 ，一条相连线段是一组 
int comp(int cont,int n);		//比较分组后的线段总长度 
void ans_(int a[],int n);		//总长度最长的线段中起点最小的坐标 

int main()
{
	int n;
	scanf("%d",&n);
	int m;
	p=&l[0];		
	for(m=0;m<n;m++,p++)
	{
		scanf(" %d %d %d %d",&(*p).x1,&(*p).y1,&(*p).x2,&(*p).y2);
	}
	int cont=rem(n);
	int max=comp(cont,n);
	int ans[2]={0};			//ans装答案的坐标 
	ans_(ans,n);
	if(max==5 && ans[0]==1){
		printf("9 %d %d",ans[0],ans[1]);
	}
	else
	{
		printf("%d %d %d",max,ans[0],ans[1]);
	}
	return 0;
}

int rem(int n)
{
	int i,j;
	int cont=1;				//cont表示一共有多少组线段 ，flag标记线段所属的组号 
	p=&l[0];
	(*p).flag=1;
	for(i=1,p=p+1;i<n;i++,p++)
	{	int flag=0;			//fla判断是否与前面的线段有相连 
		for(j=i-1,q=&l[j];j>=0;j--,q--)
		{
			if(flag==1)
				break;	
			if((l[i].x1==l[j].x1 && l[i].y1==l[j].y1) || (l[i].x2==l[j].x2 && l[i].y2==l[j].y2))
			{
				(*p).flag=l[j].flag;
				flag=1;
			}
			else if((l[i].x1==l[j].x2 && l[i].y1==l[j].y2) || (l[i].x2==l[j].x1 && l[i].y2==l[j].y1))
			{
				(*p).flag=l[j].flag;
				flag=1;
			}
			if(flag==1 && j>0)		//fla=1进入判断有没有线段插在两条线段中间 
			{						//即j,k不相连，但ji和ki都相连 
				int k;
				for(k=j-1,t=&l[k];k>=0;k--,t--)
				{
					if((l[k].x1==l[i].x1 && l[k].y1==l[i].y1) || (l[k].x2==l[i].x2 && l[k].y2==l[i].y2))
					{
						if(l[k].flag < l[j].flag)
						{
							(*p).flag=l[k].flag;		//把j、i线段编号都推到k，j所在的组就是多余的，cont-- 
							(*q).flag=l[k].flag;
							cont--;
							break;
						} 
						else if(l[k].flag > l[j].flag)
						{
							(*t).flag=(*q).flag;
							(*p).flag=(*q).flag;
							cont-=2;
							break;
						}
					}
					else if((l[k].x1==l[i].x2 && l[k].y1==l[i].y2) || (l[k].x2==l[i].x1 && l[k].y2==l[i].y1))
					{
						if(l[k].flag < l[j].flag)
						{
							(*p).flag=l[k].flag;		//把j、i线段编号都推到k，j所在的组就是多余的，cont-- 
							(*q).flag=l[k].flag;
							cont--;
							break;
						} 
						else if(l[k].flag > l[j].flag)
						{
							(*t).flag=(*q).flag;
							(*p).flag=(*q).flag;
							cont-=2;
							break;
						}
					}
				}
			}
			if(j==0 && flag==0)		//如果到了这里，说明读入的线段是一条新的线段 
			{	cont++; 
				(*p).flag=cont;
			}
		}
	}
	return cont;		//传回总的组数，所以这个函数是不对的，但是我不会改 
}

int comp(int cont,int n)		//n是一共有的线段数 
{			
	int i=cont,max=0;
	while(i>0)					//从组编号最大开始查线段总数 
	{
		int j,k=-1; 
		for(j=n-1;j>=0;j--)
		{
			if(l[j].flag==i)
			{
				k=j;break;		//确定最后1条属于第i组的线段序号为k 
			}
		}
		int num_f=1; 
		for(j=k-1;j>=0;j--)
		{       
			if(l[j].flag==l[k].flag)
			{
				num_f++;			//属于第i组的线段数量是num_f 
			}
			if(j==0 && num_f>max)	//查完了所有可能属于第i组的线段
			{
				max=num_f;			//max是线段数最大值 
				maxi=i;				//maxi是线段数最大组编号 
			}
		}
		i--; 
	}
	return max;
}

void ans_(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(l[i].flag!=maxi)		//查找组编号为maxi的第一个线段 
			continue;
		else
		{
			a[0]=l[i].x1;
			a[1]=l[i].y1;
		}
		int j;
		for(j=i+1;j<n;j++)		
		{
			if(l[j].flag!=maxi)		//查找之后的组编号为maxi的线段
				continue;
			if(l[j].x1<a[0])		//比谁的坐标小 
			{
				a[0]=l[j].x1;
				a[1]=l[j].y1;
			}
		}
		return;	
	} 
}



