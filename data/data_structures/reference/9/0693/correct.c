#include <stdio.h>
struct place{
	int startx;
	int starty;
	int endx;
	int endy;
};
int jishu(struct place line[],int n,int i);
int main(){
	int n,i,j,num[105],max=0;
	struct place line[105];
	struct place temp;
	struct place line2[105];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&line[i].startx,&line[i].starty,&line[i].endx,&line[i].endy);
	}
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(line[i].startx>line[j].startx){
			temp=line[i];
			line[i]=line[j];
			line[j]=temp;	
			}
		}
	}
	
	for(i=0;i<n;i++){
		num[i]=jishu (line,n,i);
	}
	
	for(i=0;i<n;i++){
		if(num[i]>=num[max]){
			max=i;
		}	
	}
	printf("%d %d %d",num[max],line[max].startx,line[max].starty);
	return 0;
}
int jishu(struct place line[],int n,int i){
	int a=i,j,num=1;
	

		for(j=a+1;j<n;j++){
			if(line[i].endx==line[j].startx&&line[i].endy==line[j].starty){
				num=num+1;
				line[i].endx=line[j].endx;
				line[i].endy=line[j].endy;
			}
		}
	
	return num;
} 

