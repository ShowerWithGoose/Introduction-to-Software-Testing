#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//qsort顺序为数组名，元素数量，元素大小，cmp 
struct locate{
	int x1;
	int y1;
	int x2;	
	int y2;
	int from;
};
int lian(struct locate l1,struct locate l2){
	if(l1.x2==l2.x1&&l1.y2==l2.y1||l1.x1==l2.x2&&l1.y1==l2.y2)
	return 1;
	return 0;
}
int main(){
	int n,i,j,a[101]={0},k1=0,k;
	scanf("%d",&n); 
	
	struct locate line[101];
	for(i=0;i<n;i++)
	scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	for(i=0;i<n;i++){
		int op=0,qlink1,qlink2;
		for(j=0;j<i;j++){
			if(lian(line[i],line[j])&&op==0){
				qlink1=line[j].from;
				a[line[j].from]++;
				op++;
				continue;
			}
			if(lian(line[i],line[j])&&op==1){
				qlink2=line[j].from;
				op++;
				break;
			}
		}
		if(op==0){
			k1++;
			a[k1]=1;
			line[i].from=k1;
		}
		else if(op==1)
		line[i].from=qlink1;
		else if(op==2){
			a[qlink1]+=a[qlink2];
			a[qlink2]=0;
			for(k=0;k<i;k++)
			if(line[k].from==qlink2)
			line[k].from=qlink1;
		} 
	}
	int maxi=0,fin,firstx,firsty,jud=0;
	for(i=1;i<=k1;i++)
	if(a[i]>maxi){
		maxi=a[i];
		fin=i;
	}
	for(i=0;i<n;i++){
		if(line[i].from==fin&&jud==0){
			firstx=line[i].x1;
			firsty=line[i].y1;
			jud=1;
			continue;
		}
		else if(line[i].from==fin&&jud==1){
			if(firstx>line[i].x1){
				firstx=line[i].x1;
				firsty=line[i].y1;
			}
		}
		
	}	
	printf("%d %d %d",maxi,firstx,firsty);
    return 0;
} 


