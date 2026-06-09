#include<stdio.h>              
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h> 
int max = 0,x,y;
struct line1{
	int sx;
	int sy;
	int ex;
	int ey;
}line[103];
void quicksort(struct line1 line[],int left,int right)//从小到大排ex 
{
	if(left < right)  
	{
		int j = left - 1,i;
		struct line1 tmp,p = line[right];
		for(i = left;i <= right - 1;i ++){
			if(line[i].sx <= p.sx){
				j ++;
				tmp = line[i];
				line[i] = line[j];
				line[j] = tmp;
			}
		}
	line[right] = line[j + 1];
	line[j + 1] = p;
   	quicksort(line,j + 2,right);
  	quicksort(line,left,j);
	}
	
}
void solve(int head,int n)//head为起点下标 
{
	int standard = head;
	int count = 1,i;
	while(standard <= n){
		for(i = standard + 1;i <= n;i ++){
			if(line[i].sx==line[standard].ex&&line[i].sy==line[standard].ey){
				count ++;
				standard = i;
				break;//此时i <= n找到了后继 
			}
		}
		if(i == n + 1)	break;
	}
	if(count > max){
		max = count;
		x = line[head].sx;
		y = line[head].sy;
	}
}
int main(void)
{
	int n,i;
	scanf("%d",&n);
	for(i = 1;i <= n;i ++){
		scanf("%d%d%d%d",&line[i].sx,&line[i].sy,&line[i].ex,&line[i].ey);
	}
	quicksort(line,1,n);
	for(i = 1;i <= n - 1;i ++){//以i为开头 
		solve(i,n);
	}
	printf("%d %d %d",max,x,y);
	return 0;
}



