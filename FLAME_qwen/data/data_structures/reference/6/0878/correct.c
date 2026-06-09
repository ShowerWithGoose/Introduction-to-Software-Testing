#include<stdio.h>
int s[110],flag=1,op,tmp,tt=-1,ans[500],idx=-1,i;
int main(){
	while(flag){
		scanf("%d",&op);
		
		if(op==1){
			scanf("%d",&tmp);
			s[++tt]=tmp;
		}
		
		if(op==0){
			if(tt==-1){
				ans[++idx]=-1;
			}
			else{
				ans[++idx]=s[tt];
				tt--;
			}
		}
		
		if(op==-1) 
		break;
	}
	
	for(i=0;i<=idx;i++){
		if(ans[i]==-1) printf("error ");
		else printf("%d ",ans[i]);
	}
	
	return 0;
}

