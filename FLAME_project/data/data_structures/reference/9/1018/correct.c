#include<stdio.h>
#include<string.h> 
#include <stdlib.h>
typedef struct line{
	int x1;
	int y1;
	int x2;
	int y2;
}line;

void sort_x1(line *num,int *pi,int n);

int main(){
int n, *pi, *link, *time, max=0, max_i=0;
line *num;
scanf("%d",&n);
num = (line*)malloc((n+1)*sizeof(line));
pi = (int*)malloc((n+1)*sizeof(int));
link = (int*)malloc((n+1)*sizeof(int));
time = (int*)malloc((n+1)*sizeof(int));
for(int i=0;i<n;i++){
	scanf("%d %d %d %d",&((num+i)->x1),&((num+i)->y1),&((num+i)->x2),&((num+i)->y2));
	pi[i] = i;
	link[i] = i;
	time[i] = 0;
}
sort_x1(num,pi,n);
for(int i=0;i<n;i++){
	for(int t=i+1;t<n;t++){
		if(((num+pi[t])->x1)==((num+pi[i])->x2)&&((num+pi[t])->y1)==((num+pi[i])->y2)){
			link[pi[t]] = link[pi[i]];
		}
	}
}
for(int i=0;i<n;i++){
	time[link[pi[i]]]++;
}
for(int i=0;i<n;i++){
	if(time[pi[i]] > max){
		max_i = link[pi[i]];
	    max = time[pi[i]];
	}
	
}
printf("%d %d %d\n",max,(num+max_i)->x1,(num+max_i)->y1);


free(num);
free(pi);
free(link);
free(time);
return 0;
} 

void sort_x1(line *num,int *pi,int n){
	for(int i=0;i<n;i++){
		for(int t=i+1;t<n;t++){
			if((num+pi[i])->x1 > (num+pi[t])->x1){
				pi[i] ^= pi[t];
				pi[t] ^= pi[i];
				pi[i] ^= pi[t];
			}
		}
	}
}

