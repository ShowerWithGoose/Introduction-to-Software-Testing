#include<stdio.h>
struct point{
	int x1;
	int y1;
	int x2;
	int y2;
};
struct connect{
	int left;
	int right;
};
int search(int x,int m,struct connect cot[]);

int main()
{
	int n,i,j,k=0,num[105],max=0,score=0;
	struct point line[105];
	struct connect cont[105];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j==i)
			continue;
			else{
				if(line[j].x1==line[i].x2&&line[j].y1==line[i].y2){
					cont[k].left=i;
					cont[k].right=j;
					k++;
				}
			}
		}
	}
	for(i=0;i<k;i++){
		num[i]=search(i,k,cont);
		if(num[i]>max){
		max=num[i];
		score=i;
		}
	}
	printf("%d %d %d",max+1,line[cont[score].left].x1,line[cont[score].left].y1);
	return 0;
}
int search(int x,int m,struct connect cot[]){
	int j,next=0,flag=0;
	for(j=0;j<m;j++){
		if(cot[x].right==cot[j].left){
		flag++;
		next=j;
		}
	}
	if(flag==0)
	return 1;
	else 
	return search(next,m,cot)+1;
}

