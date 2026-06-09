#include<stdio.h>
#include<string.h>//#include<stdlib.h>
int main(){
char str[200];
int i,n_before=0,flag=0,n_after=-1,len,flag_2=0;
gets(str);
len = strlen(str);
for(i=0;i<len;i++){
	if(str[i] == '.')
	flag = 1;
	if(i>0&&str[i]!='0'){
		flag_2=1;//非整整数
		//printf("%d\n",i);
	} 
}
//printf("%d\n",flag_2);
if(flag == 0){
	if(flag_2 == 0){
	    printf("%c",str[0]);
		for(i = 0;i<len;i++){
			n_before++;
		}			
	}
	else{
		printf("%c.",str[0]);
		for(i = 0;i<len;i++){
			n_before++;
			if(i>=1&&i<len){
				printf("%c",str[i]);
			}
		}		
	}
	printf("e%d",n_before-1);
	return 0;
}//整数 
if(str[0] == '0'){
	for(i = 2;str[i] == '0';i++){
		n_after--;
	}
	//printf("%d",i);
	if(str[i+1]<='9'&&str[i+1]>='0'){
	printf("%c.",str[i]);	
	}
	else{
	printf("%c",str[i]);	
	}
	for(i++;i<len;i++){
		printf("%c",str[i]);
	}
	printf("e%d",n_after);
	return 0;
}//小数 
for(i = 0;str[i] != '.';i++){
	n_before++;
}
printf("%c.",str[0]);
for(i = 1;i<len;i++){
	if(str[i] == '.') continue;
	printf("%c",str[i]);
}
printf("e%d",n_before-1);
return 0;
}

