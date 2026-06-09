#include<stdio.h>
struct Line{
		int a;
		int b;
		int c;
		int d;
		int flag;

	};

int main(){
int i,j,n,p;
int td,tc,i1,k=1;
int hash[100]={0};
scanf("%d",&n);

	struct Line line[100];
	
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&line[i].a,&line[i].b,&line[i].c,&line[i].d);
		line[i].flag=0;
	}

	for(i=0;i<n;i++){

		tc=line[i].c;
		td=line[i].d;
		for(j=0;j<n;j++){
			if(i==j)continue;
			if(tc==line[j].a&&td==line[j].b){
				
				if(line[i].flag==0&&line[j].flag==0){
				hash[k]+=2;
				line[i].flag=k;
				line[j].flag=k;k++;
				}
				else if(line[i].flag!=0&&line[j].flag==0){
					line[j].flag=line[i].flag;
					hash[line[j].flag]++;
				}
				else if(line[i].flag==0&&line[j].flag!=0){
					line[i].flag=line[j].flag;
					hash[line[j].flag]++;
				}
        else if(line[i].flag!=0&&line[j].flag!=0){
				hash[line[j].flag]=0; p=line[j].flag;
					for(i1=0;i1<n;i1++){
					 
						if(line[i1].flag==p){
							
							line[i1].flag=line[i].flag;hash[line[i].flag]++;
						}
					}
				}
				/*for(p=0;p<n;p++){
					printf("%d\n",hash[p]);
				}*/
			}
		}//printf("\n");
	}
	int max=0,maxi=0;
	int maxa=1000,maxb=1000;
	for(i=0;i<n;i++){
		if(hash[i]>=max){
		max=hash[i];
		maxi=i+1;
		}
		
	}
	for(i=0;i<n;i++){
		if(line[i].flag==maxi-1){
			if(line[i].a<=maxa){
				maxa=line[i].a;
				maxb=line[i].b;
			}
		}
	} 
	printf("%d %d %d",max,maxa,maxb);
}

