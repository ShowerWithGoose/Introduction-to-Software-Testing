#include <stdio.h>
#include <string.h>
struct stu{
	int x1;
	int y1;
	int x2;
	int y2;
}stu[101];
void chongpai(int n,struct stu stu[101]){
	int a,b,c,d;
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(stu[i].x1>stu[j].x1){
				a=stu[i].x1;
				stu[i].x1=stu[j].x1;
				stu[j].x1=a;
				b=stu[i].y1;
				stu[i].y1=stu[j].y1;
				stu[j].y1=b;
				c=stu[i].x2;
				stu[i].x2=stu[j].x2;
				stu[j].x2=c;
				d=stu[i].y2;
				stu[i].y2=stu[j].y2;
				stu[j].y2=d;
			}
		}
	}
}
int main()
    {
    	int n,i,j,max=0,num=0,m=0,ans;
    	struct stu stu[101];
    	scanf("%d",&n);
    	for(i=0;i<n;i++){
    		scanf("%d%d%d%d",&stu[i].x1,&stu[i].y1,&stu[i].x2,&stu[i].y2);
		}
		chongpai(n,stu);
		for(i=0;i<n;i++){
			m=i;
			num=1;
			for(j=i+1;j<n;j++){
				if(stu[m].x2==stu[j].x1){
					if(stu[m].y2==stu[j].y1){
						num++;
						m=j;
					}
				}
			}
			if(num>max){
				max=num;
				ans=i;
			}
		}
		printf("%d %d %d",max,stu[ans].x1,stu[ans].y1);
		return 0;
	 } 

