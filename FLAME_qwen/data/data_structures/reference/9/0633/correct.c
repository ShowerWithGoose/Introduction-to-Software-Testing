/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int n,count[105],max=0,k;
int main(){
	int a1,a2,b1,b2;
	struct LINE{
	int x1;
	int y1;
	int x2;
	int y2;
	}line[105],temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(line[i].x1>line[j].x1){
				temp=line[i];
				line[i]=line[j];
				line[j]=temp;
			}
		}
	}//按从小到大排序(没毛病)
	for(int i=0;i<n;i++){
		a1=line[i].x1;b1=line[i].y1;a2=line[i].x2;b2=line[i].y2;
		for(int j=i+1;j<n;j++){//找组合线段的头尾 
			if(a1==line[j].x1&&b1==line[j].y1){
				count[i]++;
				a1=line[j].x2;b1=line[j].y2;
			}
			else if(a1==line[j].x2&&b1==line[j].y2){
				count[i]++;
				a1=line[j].x1;b1=line[j].y1;
			}
			else if(a2==line[j].x1&&b2==line[j].y1){
				count[i]++;
				a2=line[j].x2;b2=line[j].y2;
			}
			else if(a2==line[j].x2&&b2==line[j].y2){
				count[i]++;
				a2=line[j].x1;b2=line[j].y1;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(count[i]>=max){
			max=count[i];
			k=i;
		}
	}
	printf("%d %d %d",max+1,line[k].x1,line[k].y1);
	return 0;
}

