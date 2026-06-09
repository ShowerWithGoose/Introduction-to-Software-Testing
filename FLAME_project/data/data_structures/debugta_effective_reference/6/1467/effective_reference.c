#include<stdio.h>
#include<string.h>
typedef struct _number{
	int num;
	int flag;
}number,*Pnumber;
typedef struct _stack{
	int num;
}stack;
int main(){
	char op[500];
	stack room[100];
	number num[500];
	gets(op);
	int flag=0,j=0,k=0,mark=0;
	for(flag=0;op[flag]!='\0';flag++){
		if(j==0){
			if(op[flag]=='1'){
				num[k].flag=1;
				num[k].num=0;
				j=1;
			}else if(op[flag]=='0'){
				num[k].flag=0;
				num[k].num=0;
				k++;
			}else if(op[flag]=='-'&&op[flag+1]=='1'){
				break;
			}
		}else{
			if(op[flag]!=' '){
				j=0;
				if(op[flag]=='-'){
					flag++;
					mark=1;
				}
				for(;op[flag]!=' ';flag++){
					num[k].num=num[k].num*10+op[flag]-'0';
				}
				if(mark==1){
					num[k].num=0-num[k].num;
					mark=0;
				}
				k++;
			}
		}
	}
	for(flag=0,j=0;flag<k;flag++){
		if(num[flag].flag==1){
			if(j==100){
				printf("error ");
			} else{
				room[j].num=num[flag].num;
				j++;
			}
		}else{
			if(j==0){
				printf("error ");
			}else{
				printf("%d ",room[j-1].num);
				room[--j].num='\0';
			}
		}
	}
	return 0;
} 

