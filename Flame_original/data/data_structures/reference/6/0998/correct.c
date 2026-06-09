#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
int num;//weishu
int s[105];
 
int main(){
	int tmp;//caozuo
	while(scanf("%d",&tmp)!=EOF){
		if(tmp == -1) break;
		else if((num==0&&tmp==0)||(num==100&&tmp==1)){
			printf("error ");
		} 
		
		else if(1==tmp){
			scanf("%d",&s[num++]);
		}
		else if(0==tmp){
			printf("%d ",s[--num]);
		}
	}	
	return 0;
}

