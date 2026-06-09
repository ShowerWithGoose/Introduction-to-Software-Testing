#include<stdio.h>
#include<string.h>
struct way{
	int num;
	int meth;
}w[1000];
int main()
{
	int len=0;//整数栈的长度
	int n[1000];
	int i=0;
	while(scanf("%d",&w[i].meth)!=-1){
		if(w[i].meth==1){
			if(len==100){
				printf("error ");
				i++;
			}
			else{
				scanf("%d",&w[i].num);
				n[len]=w[i].num;
				len++; 
			}
		}
		else if(w[i].meth==0){
			if(len==0) printf("error ");
			else{
				printf("%d ",n[len-1]);
				len--;
			}
		}
		i++;
	} 
	
return 0; 
	
	
}










