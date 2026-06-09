#include<stdio.h>
#include<string.h>
struct node{
	long long int x;
	long long int n;
}num1[55],num2[55],end[105];
int i,j;
int len1,len2; 
char c;
main(){
	long long int x,n;
	i=0;
	do{
			
		scanf("%lld%lld",&num1[i].x,&num1[i].n);
		i++;
		len1=i;
		c = getchar();
	}while(c!='\n');
//	len1=i;
//  printf("%d\n",len1);
	i=0;
	do{
			
		scanf("%lld%lld",&num2[i].x,&num2[i].n);
		i++;
		len2=i;
		c = getchar();
	}while(c!='\n');
//	len2=i;
//	printf("%d\n",len2);
/*	for(i=0;i<len1;i++){
		printf("%lld %lld ha",num1[i].x,num1[i].n);
	}
	printf("\n");
	for(i=0;i<len2;i++){
		printf("%lld %lld ha",num2[i].x,num2[i].n);
	}
	printf("\n");
	*/
	int len=1;
//	len=len1*len2;
	for(i=0;i<len1;i++){
		for(j=0;j<len2;j++){
			end[len].x=num1[i].x*num2[j].x;
			end[len].n=num1[i].n+num2[j].n;
			len++;
		}
	}
/*	for(i=0;i<len;i++){
		printf("%lld %lld +",end[i].x,end[i].n);
	}
*/	
	long long int trs;
	for(i=0;i<len;i++){
		for(j=i;j<len;j++){
			if(end[i].n==end[j].n){
				end[i].x=end[i].x+end[j].x;
				end[j].n=-1;
			}
			else if(end[i].n<end[j].n){
				trs=end[i].x;
				end[i].x=end[j].x;
				end[j].x=trs;
				trs=end[i].n;
				end[i].n=end[j].n;
				end[j].n=trs;
			}
		}
	}
/*	for(i=0;i<len;i++){
		for(j=i;j<len;j++){
			if(end[i].n==end[j].n){
				end[i].x=end[i].x+end[j].x;
				end[j].n=-1;
			}
				
			
		}
	}
	*/
//	printf("%lld",end[0].x);
	for(i=0;i<len;i++){
		if(end[i].n!=-1)
		printf("%lld %lld ",end[i].x,end[i].n);
	}
} 

