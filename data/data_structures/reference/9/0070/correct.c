#include<stdio.h>
typedef struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
}ln;

int a[105][4];

int main(){
	ln b[105];
	int i,j,k=0,n,m=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int t=0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j){
				continue;
			}
			if (a[i][0] == a[j][2] && a[i][1] == a[j][3])
			{
				t=1;
				break;
			}
			}
		if(t==0){
			b[k].x1=a[i][0];
			b[k].y1=a[i][1];
			b[k].x2=a[i][2];
			b[k].y2=a[i][3];
			k++;
			}
		
		t=0;
		
}
//printf("\n%d\n",k);
/*for(i=0;i<k;i++){
		
			printf("%d %d %d %d\n",b[i].x1,b[i].y1,b[i].x2,b[i].y2);
		
	
	}*/
for (i=0;i<k;i++)
	{
		b[i].num=1;
		for (j=0;j<n;j++)
		{
			if (b[i].x2==a[j][0]&&b[i].y2==a[j][1])
			{
				b[i].x2=a[j][2];
				b[i].y2=a[j][3];
				b[i].num++;
				j=-1;
			}
		}
	}
	/*for(i=0;i<k;i++){
		printf("\n%d\n",b[i].num);
	}*/
	int c=0;
	for(i=0;i<k;i++)
	{
		if(m<=b[i].num)
		{
			m=b[i].num;
			c=i;
		}
	}
	//printf("\n%d\n",m);
	printf("%d %d %d\n", b[c].num, b[c].x1, b[c].y1);
    return 0;
}



