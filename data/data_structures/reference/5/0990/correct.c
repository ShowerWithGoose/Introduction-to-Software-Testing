#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct line{
	int x1,x2;
};
struct line num1[1024];
struct line num2[1024];
struct line num[1024];
int main(){
	int i=0,j,n,m,k=0,hold;
	char a=' ';
	for(i=0;a!='\n';i++){
		scanf("%d%d%c",&num1[i].x1,&num1[i].x2,&a);
	}	
	n=i;
	a=' ';
	for(i=0;a!='\n';i++){
		scanf("%d%d%c",&num2[i].x1,&num2[i].x2,&a);
		}
	m=i;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			num[k].x1=num1[i].x1*num2[j].x1;
			num[k].x2=num1[i].x2+num2[j].x2;
			k++;
		}
	}
	for(i=0;i<k;i++){
		for(j=i+1;j<k;j++){
			if(num[i].x2==num[j].x2){
				num[i].x1=num[i].x1+num[j].x1;
			    for(n=j;n<k-1;n++){
				    num[n]=num[n+1];
				    }
			    k--;
			    j--;
			}
		}
	}
	for(i=0;i<k-1;i++){
		for(j=0;j<k-1-i;j++){
			if(num[j].x2<num[j+1].x2){
				hold=num[j].x1;
				num[j].x1=num[j+1].x1;
				num[j+1].x1=hold;
				hold=num[j].x2;
				num[j].x2=num[j+1].x2;
				num[j+1].x2=hold;				
			}
		}
	}
	for(i=0;i<k;i++) printf("%d %d ",num[i].x1,num[i].x2);
	return 0;
}

