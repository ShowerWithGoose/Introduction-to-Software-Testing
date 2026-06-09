#include<stdio.h>
#include<stdlib.h>//申请内存malloc(例如 ：int*a；a=（int*）malloc（number*sizeof（int））；接下来就拿a当数组来用就可以了,最后要还内存free（a）a指的是最开始的原地址)
#include<math.h> // 开方sqrt(x)  x的y次方pow(x,y)
#include<stdbool.h> //C99 bool : true or false 布尔量本质还是整数,故输出还是1或0
#include<string.h>
#include<time.h>

typedef struct node
{
	int x1,y1,x2,y2;
}node;

int main()
{
	int n;
	scanf ("%d",&n);
	int i=0;
	node *a;
	a=(node*)malloc(n*sizeof(node));
	while (i<n)
	{
		scanf ("%d%d%d%d",&a[i].x1 ,&a[i].y1 ,&a[i].x2 ,&a[i].y2 );
		i++;
	}
	int j;
	int max=0;
	int x;
	int y;
	node *p;
	for (i=0;i<n;i++)
	{
		int cnt=1;
		p=&a[i];
		for (j=0;j<n;j++)
		{
		
			if (p->x2 == a[j].x1 && p->y2 == a[j].y1 )
			{
				p=&a[j];
				cnt++;
				j=-1;
			}
			
		}
		if (cnt > max)
		{
			max=cnt;
			x=a[i].x1 ;
			y=a[i].y1 ;
			//printf ("p->x1=%d,p->y1=%d,count=%d\n",p->x1 ,p->y1,cnt );
		}
	}
	printf ("%d %d %d\n",max,x,y);
	//printf ("p->x1=%d,p->y1=%d\n",p->x1 ,p->y1 );
	free(a);
	return 0;
}

/*{
	80 75 125 75

60 40 80 55

80 55 90 20

140 120 195 205

10 111 70 165

22 35 43 43

22 175 80 205

43 43 60 40

90 20 125 60

125 60 80 75
}*/


