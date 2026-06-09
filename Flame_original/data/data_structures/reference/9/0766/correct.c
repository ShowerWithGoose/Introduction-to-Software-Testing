#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct point {
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
}scan[100]; 
int main()
{
	int n,max=1;
	scanf("%d",&n);
	scanf("%d%d%d%d",&scan[0].x1,&scan[0].y1,&scan[0].x2,&scan[0].y2);
	scan[0].num=1;
	for(int i=1;i<n;i++){
		scanf("%d%d%d%d",&scan[i].x1,&scan[i].y1,&scan[i].x2,&scan[i].y2);
		scan[i].num=1; 
	}
	
	for(int j=0;j<n;j++){
		for(int i=j+1;i<n;i++){
			if(scan[i].x1==scan[j].x1&&scan[i].y1==scan[j].y1){   //  1==1 
				scan[j].x1=scan[i].x2;
				scan[j].y1=scan[i].y2;
				scan[j].num++;
				for(int k=i;k<n-1;k++){
					scan[k]=scan[k+1];
				}
				j=-1;
				n--;
				break;
			}
			else if(scan[i].x2==scan[j].x1&&scan[i].y2==scan[j].y1){  // shuru  2  ==  1
				scan[j].x1=scan[i].x1;
				scan[j].y1=scan[i].y1;
				scan[j].num++;
				for(int k=i;k<n-1;k++){
					scan[k]=scan[k+1];
				}
				j=-1;
				n--;
				break;
			}
			else if(scan[i].x1==scan[j].x2&&scan[i].y1==scan[j].y2){  // shuru  1  ==  2
				scan[j].x2=scan[i].x2;
				scan[j].y2=scan[i].y2;
				scan[j].num++;
				for(int k=i;k<n-1;k++){
					scan[k]=scan[k+1];
				}
				j=-1;
				n--;
				break;
			}
			else if(scan[i].x2==scan[j].x2&&scan[i].y2==scan[j].y2){  // shuru  2  ==  2
				scan[j].x2=scan[i].x1;
				scan[j].y2=scan[i].y1;
				scan[j].num++;
				for(int k=i;k<n-1;k++){
					scan[k]=scan[k+1];
				}
				j=-1;
				n--;
				break;
			}
		}
//		for(int i=0;i<n;i++){
//			printf("%d %d %d %d num=%d\n",scan[i].x1,scan[i].y1,scan[i].x2,scan[i].y2,scan[i].num);
//		}
//		printf("\n");
	}
	
	
	for(int i=0;i<n;i++){
		if(scan[i].num>max){
			max=scan[i].num;
		}
	}
	
//	printf("max==%d\n",max);
	for(int i=0;i<n;i++){
		if(scan[i].num==max){
			printf("%d %d %d\n",scan[i].num,scan[i].x1<scan[i].x2?scan[i].x1:scan[i].x2 ,scan[i].x1<scan[i].x2?scan[i].y1:scan[i].y2 );
		}
	}
	return 0;
}

