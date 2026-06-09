#include<stdio.h>
#include<string.h>
int book[11],a[11];
void fullArray(int step, int n)
{
	int i,j;
    //收尾情况的代码：
	if(step==n)
    //盒子放满之后，逐一打印数字卡片
	{
		for(j=0;j<n;j++)
			printf("%d ",a[j]);
		printf("\n");	
	}
    //递归部分的代码：
    for (i = 1; i <= n; i++) //每一步都从最小的开始尝试放数字
    {
        if (book[i] == 0) //如果还没有被用
        {
            a[step] = i;      //用一个数组装卡片，放下数字卡片
            book[i] = 1;      //表明放下的数字卡片被占用
            fullArray(step + 1, n); //开始下一步
            book[i] = 0;      //取回数字卡片
        }
    }
}
/*不用考虑顺序的输出 
void swap(int list[],int first,int last)
{
	int tmp;
	tmp=list[first];
	list[first]=list[last];
	list[last]=tmp;
}
void digui(int list[],int first,int last)
{
	int i;
	if(first==last)
	{
		for(i=0;i<=last;i++)
			printf("%d ",list[i]);
		printf("\n");
	}
	else 
	{
		for(i=first;i<=last;i++)
		{
			swap(list,first,i);
			digui(list,first+1,last);
			swap(list,first,i);
		}
	}	
}
*/
int main()
{
	int n,i;
	scanf("%d",&n);
	fullArray(0,n);
	return 0;
}




