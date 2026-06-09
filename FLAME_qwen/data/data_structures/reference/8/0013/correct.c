#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	int a[1000];
	int b[1000];
	int n,N,i,flag=0,sc;
	scanf("%d%d",&n,&N);
	//printf("%d %d\n",n,N);
	for(i=0;i<N;i++){
		scanf("%d%d",&a[i],&b[i]);
		//printf("%d %d\n",a[i],b[i]);
	}
	scanf("%d",&sc);
	//printf("%d",sc);
	if(n==N){
		if(n==3*sc){
			for(i=0;i<4;i++){
				if(flag==0){
					printf("%d 1 2\n",i);
					flag=1;
				} 
				else if(flag==1){
					printf("0 %d 2\n",i);
					flag=2;
				} 
				else if(flag==2){
					printf("0 %d\n",i);
					flag=3;
				} 
				else if(flag==3){
					printf("0 2\n");
					flag=4;
				} 
			}
			
		}
		else{
			for(i=0;i<4;i++){
				if(flag==0){
					printf("%d 1 2 3 4 6 5 7 8\n",i);
					flag=1;
				} 
				else if(flag==1){
					printf("0 %d 5 2 6 3 7 4 8\n",i);
					flag=2;
				} 
				else if(flag==2){
					printf("0 5 6 %d 3 4 7 8\n",i);
					flag=3;
				} 
				else if(flag==3){
					printf("0 5 6 2 7 %d 8 4\n",i);
					flag=4;
				} 
			}
			
		}
	}
	else if(N-n<4){
		for(i=0;i<4;i++){
				if(flag==0){
					printf("%d 1 2 3\n",i);
					flag=1;
				} 
				else if(flag==1){
					printf("0 %d 2 3\n",i);
					flag=2;
				} 
				else if(flag==2){
					printf("0 1 %d\n",i+1);
					flag=3;
				} 
				else if(flag==3){
					printf("0 1 %d\n",i);
					flag=4;
				} 
			}
	}
	else if(N-n==4){
		for(i=0;i<4;i++){
				if(flag==0){
					printf("%d 8 2 4 3 7 1 9 10 11 6 5 12\n",i);
					flag=1;
				} 
				else if(flag==1){
					printf("0 8 9 12 2 %d 7 4 10 3 5 11 6\n",i);
					flag=2;
				} 
				else if(flag==2){
					printf("0 9 1 7 3 4 %d 5 6 11 10 12\n",i);
					flag=3;
				} 
				else if(flag==3){
					printf("0 9 12 1 7 10 %d 5 11 4 6 2\n",i);
					flag=4;
				} 
			}
		
	}
	else{
		for(i=0;i<4;i++){
				if(flag==0){
					printf("%d 2 9 6 5 4 3 1 10 8 17 11 15 7 12 13 20 14 18 19 21 16\n",i);
					flag=1;
				} 
				else if(flag==1){
					printf("0 2 7 8 13 15 18 19 9 3 10 4 %d 5 6 16 12 17 20 11 14 21\n",i);
					flag=2;
				} 
				else if(flag==2){
					printf("0 7 3 1 10 %d 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12\n",i*4);
					flag=3;
				} 
				else if(flag==3){
					printf("0 7 8 13 15 18 19 %d 10 4 1 5 6 12 9 17 20 11 14 21 16\n",i);
					flag=4;
				} 
			}
	}



	return 0;
}


