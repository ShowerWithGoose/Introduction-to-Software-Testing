#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct lines{
	int st[2];
	int nd[2];
};
void sortbyx(struct lines array[],int n);
int search(struct lines array[],int N,int m);
int main(){
	int N,i=0,j=0,count=0,bx=0,by=0,s,all[100],max[2]={0};
	struct lines l[100]={0};
	struct lines tmp;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d%d%d%d",&l[i].st[0],&l[i].st[1],&l[i].nd[0],&l[i].nd[1]);
	}
	sortbyx(l,N);
	for(i=0;i<N;i++){
		bx=l[i].st[0];
		by=l[i].st[1];
		s=i;
		count=1;
		for(j=s;j<N;j++){
			s=search(l,N,s);
			if(s==-1){
				all[i]=count;
				if(count>max[0]){
					max[0]=count;
					max[1]=i;
				}
				break;
			}
			else{
				count++;
			}
		}
		
	}
	printf("%d %d %d",max[0],l[max[1]].st[0],l[max[1]].st[1]);
	return 0;
}
void sortbyx(struct lines array[],int n){
	int i,j;
	struct lines tmp;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(array[i].st[0]>array[j].st[0]){
				tmp=array[i];
				array[i]=array[j];
				array[j]=tmp;
			}
		}
	}
}
int search(struct lines array[],int N,int m){
	int i,j,s=-1;
	for(i=m+1;i<N;i++){
		if(array[i].st[0]==array[m].nd[0]&&array[i].st[1]==array[m].nd[1]){
			s=i;
			return s;
		}
	}
	return s;
}


