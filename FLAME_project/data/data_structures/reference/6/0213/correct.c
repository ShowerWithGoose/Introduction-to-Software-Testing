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
	char input[500];
	stack room[100];
	number NUM[500];
	gets(input);
	int i=0,j=0,k=0,mark=0;
	for(i=0;input[i]!='\0';i++){
		if(j==0){
			if(input[i]=='1'){
				NUM[k].flag=1;
				NUM[k].num=0;
				j=1;
			}else if(input[i]=='0'){
				NUM[k].flag=0;
				NUM[k].num=0;
				k++;
			}else if(input[i]=='-'&&input[i+1]=='1'){
				break;
			}
		}else{
			if(input[i]!=' '){
				j=0;
				if(input[i]=='-'){
					i++;
					mark=1;
				}
				for(;input[i]!=' ';i++){
					NUM[k].num=NUM[k].num*10+input[i]-'0';
				}
				if(mark==1){
					NUM[k].num=0-NUM[k].num;
					mark=0;
				}
				k++;
			}
		}
	}
	for(i=0,j=0;i<k;i++){
		if(NUM[i].flag==1){
			if(j==100){
				printf("error ");
			} else{
				room[j].num=NUM[i].num;
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

