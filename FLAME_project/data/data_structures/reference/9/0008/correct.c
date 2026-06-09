#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int sort(int a[],int len);
struct node{
	int x0;
	int y0;
	int x1;
	int y1;
	int len;	
}p[200]; 
int mark[200];

main(){
	
	int n;
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&p[i].x0,&p[i].y0,&p[i].x1,&p[i].y1);
		p[i].len=1;
	}
	
	int t;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(p[i].x0>p[j].x0)
			{
				t=p[i].x0;     
				p[i].x0=p[j].x0;
				p[j].x0=t;
				t=p[i].y0;     
				p[i].y0=p[j].y0;
				p[j].y0=t;
				t=p[i].x1;    
				p[i].x1=p[j].x1;
				p[j].x1=t;
				t=p[i].y1;     
				p[i].y1=p[j].y1;
				p[j].y1=t;
			}
		 	
				 
		 			
		}
		
	}
 	
			
	/*printf("\n");
	for(i=0;i<n;i++){
		printf("%d %d %d %d %d\n",p[i].x0,p[i].y0,p[i].x1,p[i].y1,p[i].len);
	}*/	
	int f;
	int flag=0,pt,max=0;
	int k;
	for(k=0;k<n;k++){
		for(i=k;i<n;i++){
			for(j=i+1;j<n;j++){
				if(p[i].x1==p[j].x0&&p[i].y1==p[j].y0)
				{	
				
					if(flag==0)
					{
						flag=1;
						pt=i;
					//	printf("%daz\n",pt);
					}
					p[pt].len++;
					i=j-1;
					//printf("iiii%d\n",i);
					//printf("%d==%d\n",i,j);
				//	printf("%dthis\n",p[pt].len);
					break; 
				}
				
			}
			if(j==n) break;
			if(p[pt].len>max)
			{
				
				max=p[pt].len;
				f=pt;
			}
		
		}	
	flag=0;
	}
	/*printf("\n");
	for(i=0;i<n;i++){
		printf("%d %d %d %d %d\n",p[i].x0,p[i].y0,p[i].x1,p[i].y1,p[i].len);
	}*/	
	printf("%d %d %d",p[f].len,p[f].x0,p[f].y0);
	
}

 




