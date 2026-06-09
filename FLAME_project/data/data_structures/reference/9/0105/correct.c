#include<stdio.h>
struct line {
	struct dot {
		int x;
		int y;
	} dot1,dot2;
} lines[100],temp,re;
int main() {
	int n,i,m,count,max=0;
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d%d%d%d",&lines[i].dot1.x,&lines[i].dot1.y,&lines[i].dot2.x,&lines[i].dot2.y);
	}
	for(i=0;i<n;i++){
		for(m=0;m<n-i-1;m++){
			if(lines[m].dot1.x>lines[m+1].dot1.x){
				temp=lines[m];
				lines[m]=lines[m+1];
				lines[m+1]=temp;
			}
		}
	}
	for(i=0; i<n; i++) {
		temp=lines[i];
		count=1;
		for(m=i+1; m<n; m++) {
			if(temp.dot2.x==lines[m].dot1.x&&temp.dot2.y==lines[m].dot1.y) {
				temp=lines[m];
				count++;
			}
		}
		if(count>max) {
			max=count;
			re=lines[i];
		}
	}
	printf("%d %d %d",max,re.dot1.x,re.dot1.y);
	getchar();
	getchar();
}



