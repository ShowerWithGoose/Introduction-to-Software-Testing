#include<stdio.h>
#include<stdlib.h>
struct line {
	int x1,x2;
	int y1,y2;
	int count;
	int first; 
	int flag;
};
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main(){
	int n,i,j,middle;
	int temp;
	int max=0,max_tik;
	struct line s[101];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
		s[i].count=1;
		s[i].flag=0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if(s[i].x1<s[j].x1){
				swap(&s[i].x1,&s[j].x1);
				swap(&s[i].y1,&s[j].y1);
				swap(&s[i].x2,&s[j].x2);
				swap(&s[i].y2,&s[j].y2);
			}
			else if(s[i].x1==s[j].x1&&s[i].y1<s[j].y1){
				swap(&s[i].y1,&s[j].y1);
				swap(&s[i].x2,&s[j].x2);
				swap(&s[i].y2,&s[j].y2);
			}
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)continue;
			
			if(s[i].x2==s[j].x1&&s[i].y2==s[j].y1){
				if(s[i].flag==0){
					s[j].first=i;
					s[i].flag=s[j].flag=1;
					s[i].count++;
				}
				else {
					s[j].first=s[i].first;
					s[j].flag=1;
					middle=s[i].first;
					s[middle].count++;
				}
			}
		}
	}
	for(i=0;i<n;i++){
		if(max<s[i].count){
			max=s[i].count;
			max_tik=i;
		}
	}
	
	printf("%d %d %d",s[max_tik].count,s[max_tik].x1,s[max_tik].y1);
	return 0;
}

