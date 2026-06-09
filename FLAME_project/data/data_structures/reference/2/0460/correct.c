#include<stdio.h>
int chengchu(int res,char c){
	int tmp;
	scanf("%d ",&tmp);
	if(c=='*'){
		return(res*tmp);
	}
	else if(c=='/'){
		return(res/tmp);
	}
	
}
int main(){
	// 1+2*3*4+6/4=?
	int res=0,num=0,jia=0,jian=0,count=0;
	char c;
	scanf("%d ",&res); //count为偶数时读入符号，为奇数时读入数字
l:	while(1){
		if(count%2==0){
			scanf("%c ",&c);
			count++;
			
			if(c=='+'){
				if(jia){
					jia--;
					res+=num;
				}
				else if(jian){
					jian--;
					res-=num;
				}
				jia++;
			}
			else if(c=='-'){
				if(jia){
					jia--;
					res+=num;
				}
				else if(jian){
					jian--;
					res-=num;
				}
				jian++;
			}
			else if(c=='*'||c=='/'){
				if(count==1){
					int a;
					scanf("%d ",&a);
					if(c=='*')
						res=res*a;
					else
						res=res/a;
					count--;
					goto l;
				}
				else{
					num=chengchu(num,c);
					count++;
				}
			}
			else if(c=='='){
				if(jia)
					printf("%d",num+res);
				else if(jian)
					printf("%d",res-num);
				else
					printf("%d",res);
				return 0;
			}  
		}
		else if(count%2==1){
			scanf("%d ",&num);
			count++;
		}
	}
}

