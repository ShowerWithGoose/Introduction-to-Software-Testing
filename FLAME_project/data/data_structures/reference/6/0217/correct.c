#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
int s[MAXSIZE],temp[MAXSIZE];
int main(){
	memset(s,0,sizeof(s));
	int i,j,k,item;
	while(1){
		scanf("%d",&item);
		if(item==-1)
		break;
		else if(item==1){
		scanf("%d",&j);
		    if(s[99]!=0){
	        printf("error ");
	        }
	        else{
	        for(i=0,k=1;i<MAXSIZE-1;i++,k++){
		    temp[k]=s[i];
	        }
	        temp[0]=j;
	        for(i=0;i<MAXSIZE;i++){
		    s[i]=temp[i];
	        }
	        }
		}
		else if(item==0){
			if(s[0]==0){
			printf("error ");
			}
			else{
			printf("%d ", s[0]);
			for(i=0;i<99;i++){
				s[i]=s[i+1];
			}
			s[99]=0;
			}
		}
		}
		return 0;	
	}
	




