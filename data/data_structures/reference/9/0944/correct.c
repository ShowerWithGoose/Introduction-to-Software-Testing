#include<stdio.h>


struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int sum;
}mmu[110];

void read(int message[][4],struct line mmu[]);

void count(int message[][4],struct line mmu[],int num);

int message[110][4];
int num=0,flag;
int i,j,n;
int max=0;

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			scanf("%d",&message[i][j]);
		}
	}
	read(message,mmu);
	count(message,mmu,num);
	for(i=0;i<num;i++){
		if(mmu[i].sum>max){
			max=mmu[i].sum;
			flag=i;
		}
	}
	printf("%d %d %d",mmu[flag].sum,mmu[flag].x1,mmu[flag].y1);
	return 0;
} 
 
void read(int message[][4],struct line mmu[])
{
	int type=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j==i) continue;
			if(message[i][0]==message[j][2]&&message[i][1]==message[j][3]){
				type=1;
				break;
			}
		}
		if(type==0){
			mmu[num].x1=message[i][0];
			mmu[num].y1=message[i][1];
			mmu[num].x2=message[i][2];
			mmu[num].y2=message[i][3];
			num++;
		} 
		type=0;
	}
}

void count(int message[][4],struct line mmu[],int num)
{
	for(i=0;i<num;i++){
		mmu[i].sum=1;
		for(j=0;j<n;j++){
			if(mmu[i].x2==message[j][0]&&mmu[i].y2==message[j][1]){
				mmu[i].sum++;
				mmu[i].x2=message[j][2];
				mmu[i].y2=message[j][3];
				j=-1;
			}
		}
	}
}


