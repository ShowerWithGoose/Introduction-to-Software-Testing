#include<stdio.h>
struct num{
	int x;
	int y;
	int n;	
};

int main()
{
	struct num left[1001],right[1001];
	int i,j,t,h,sum=0;
	for(i=0;i<1001;i++){
		left[i].n+=1;
		right[i].n+=1;
	}
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d%d",&left[i].x,&left[i].y);
		scanf("%d%d",&right[i].x,&right[i].y);		
		for(j=0;j<i;j++){
			if(left[j].x==right[i].x&&left[j].y==right[i].y){
				right[i].n=right[j].n+right[i].n;
				left[i].n=right[i].n;
				right[i].x=right[j].x;
				right[i].y=right[j].y;
				left[j].x=left[j].y=left[j].n=0;
				right[j].x=right[j].y=right[j].n=0;								
				for(h=0;h<i;h++){
					if(right[h].x==left[i].x&&right[h].y==left[i].y){
						left[i].n=left[h].n+left[i].n;
						right[i].n=left[i].n;
						left[i].x=left[h].x;
						left[i].y=left[h].y;
						right[h].x=right[h].y=right[h].n=0;
						left[h].x=left[h].y=left[h].n=0;
					}
					//printf("%d.%d.%d.%d.%d\n",left[i].n,left[i].x,left[i].y,right[h].x,right[h].y);
				}
				
			}
			else if(right[j].x==left[i].x&&right[j].y==left[i].y){
				left[i].n=left[j].n+left[i].n;
				right[i].n=left[i].n;
				left[i].x=left[j].x;
				left[i].y=left[j].y;
				right[j].x=right[j].y=right[j].n=0;
				left[j].x=left[j].y=left[j].n=0;
			}
			else{
				;	
			}
			//printf("%d %d %d %d %d\n",left[i].n,left[i].x,left[i].y,left[j].x,left[j].y);
		}
	}
	int max=0;
	for(i=0;i<t;i++){
		if(max<left[i].n){
			max=left[i].n;
		}
	}
	i=0;
	int s=t;
	while(s>=0){
		if(max==left[i].n){
			s=-1;
		}
		i++;
	}
	
	printf("%d %d %d",max,left[i-1].x,left[i-1].y);
	/*for(j=0;j<t;j++){
		printf("%d %d %d %d %d\n",left[j].x,left[j].y,left[j].n,max,i);
	}
	/*int n;
	int num=1;	
	scanf("%d\n",&n);
	int i,x,y,x1,y1;
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&x,&y,&x1,&y1);
		s[i][i]=i+1;
		a[x][y]+=1;
		a[x1][y1]+=1;
		if(a[x][y]>1){
			a[x1][y1]=a[x][y];
			a[x][y]=0;
		}
		else if(a[x1][y1]!=0){
			
		}
		else{
			a[x1][y1]+=1;
		}
	}
	int j=0;
	int max=0;
	for(i=0;i<200;i++){
		for(j=0;j<200;j++){
			if(a[i][j]>max){
				max=a[i][j];
			}
		}
	}
	printf("%d",max);*/
	return 0;
}



