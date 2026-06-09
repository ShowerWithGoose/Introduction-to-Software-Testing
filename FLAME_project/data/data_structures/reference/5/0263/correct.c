#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct node 
{
	int coe;
	int pow;
 }a[500],b[500],ans[500],tem;
 
int main(){
 	int coe,pow;
 	char c;
 	int i=0,j=0,k=0,n,len1,len2,len=0,judge,coeans,powans;
	while(scanf("%d%d%c",&coe,&pow,&c)!=EOF){
 		if (c!='\n'){
 			a[i].coe=coe;
 			a[i].pow=pow;
 			i++;
		}
		else{
		 	a[i].coe=coe;
 			a[i].pow=pow;
 			i++;
 			break;
		}
		len1=i;	
	}
	while(scanf("%d%d%c",&coe,&pow,&c)!=EOF){
 		if (c!='\n'){
 			b[j].coe=coe;
 			b[j].pow=pow;
 			j++;
		}
		else{
		 	b[j].coe=coe;
 			b[j].pow=pow;
 			j++;
 			break;
		}
		len2=j;	
	}
	
	for(i=0;i<=len1;i++){
		for(j=0;j<=len2;j++){
			judge=0;
			coeans=a[i].coe*b[j].coe;
			powans=a[i].pow+b[j].pow;
			for(k=0;k<len;k++){	
				if(ans[k].pow==powans){
					judge=1;
					if (ans[k].coe+coeans==0){
						for(n=k;n<len;n++){
							ans[n]=ans[n+1];
						}
						len--;
					}
					else {
						ans[k].coe=ans[k].coe+coeans;
					}
					break;
				}	
			}
			if(judge==0){
				ans[len].coe=coeans;
				ans[len].pow=powans;
				len++;
			}	
		}
	}
	for(i=0;i<len-1;i++){
		for(j=0;j<len-i-1;j++){
			if(ans[j].pow>ans[j+1].pow){
				tem=ans[j+1];
				ans[j+1]=ans[j];
				ans[j]=tem;
			}
		}	
	}
	
	for(i=len-1;i>=0;i--)
	printf("%d %d ",ans[i].coe,ans[i].pow);
	return 0;
}

