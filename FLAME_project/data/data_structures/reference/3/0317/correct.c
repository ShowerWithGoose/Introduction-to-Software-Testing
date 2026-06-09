#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int main()
{
	int i,k=0,point,zero_num=0,num_e,flag=0;
	char num[100],prinum[100];
	
	gets(num);
	
	for(i=0;num[i]!='\0';i++){
		if(num[i]=='.')
			point=i;
		else{
			if(num[i]!='0' || flag==1){
				prinum[k++]=num[i];
				flag=1;
			}
			else
				zero_num++;
		}
	}
	prinum[k]='\0';
	printf("%c",prinum[0]);
	if(k!=1)
		printf(".");
	for(i=1;prinum[i]!='\0';i++)
		printf("%c",prinum[i]);
	if(zero_num==0){
		num_e=point-1;
		printf("e%d",num_e);
	}
	if(zero_num!=0){
		num_e=zero_num;
		printf("e-%d",num_e);
	}

	return 0;
}


