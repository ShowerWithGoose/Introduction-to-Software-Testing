#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	int result=0,tmp=1,num;
	char a;
	while(1){
		scanf("%d %c ",&num,&a);
		tmp*=num;
		while(a=='*'||a=='/'){
			scanf("%d ",&num);
			if(a=='*'){
				tmp*=num;
			}else{
				tmp/=num;
			}
			scanf("%c ",&a);
		}
		result+=tmp;
		if(a=='+'){
			tmp=1;
		}else if(a=='-'){
			tmp=-1;
		}else{
			printf("%d",result);
			break;
		}
	}
return 0;
}


