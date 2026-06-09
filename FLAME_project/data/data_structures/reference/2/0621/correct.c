#include<stdio.h>
#include<string.h>
int main(){
	char string[1001]; 
	int i,num[1001],count=0,temp=0,special=0;//由于乘除法优先，出现乘或除special =1 || 2; 
	int all=0;
	gets(string);
	
	for (i=0;string[i]!='=';i++){
		if (string[i]==' ')
			continue;
		else if (string[i]>='0'&&string[i]<='9')
			temp=temp*10+string[i]-'0';
		else if (string[i]=='-'||string[i]=='+'){
			
			if (special!=0){
				if (special==1){
					num[count-1]=num[count-1]*temp;
					temp=0;
					special=0;
				}
				else{
					num[count-1]=num[count-1]/temp;
					temp=0;
					special=0;
				}
			}
			else{
				//保存数字 
				num[count]=temp;
				temp=0;
				count++;				
			}
		
		} 
		else if (string[i]=='*'||string[i]=='/'){
			
			if (special!=0){
				if (special==1){
					num[count-1]=num[count-1]*temp;
					temp=0;
					special=0;
				}
				else{
					num[count-1]=num[count-1]/temp;
					temp=0;
					special=0;
				}
			}
			else{
				//保存数字 
				num[count]=temp;
				temp=0;
				count++;				
			}
			
			//进入紧急状态 
			if(string[i]=='*')special=1;
			if(string[i]=='/')special=2;
		}
	}	
	if (special!=0){
		if (special==1){
			num[count-1]=num[count-1]*temp;
			temp=0;
			special=0;
		}
		else{
			num[count-1]=num[count-1]/temp;
			temp=0;
			special=0;
		}
	}
	else {
		num[count]=temp;
	}
	int cnt2=1;
	temp=num[0];
	for(i=0;string[i]!='=';i++){
		if(string[i]=='+'){
			temp+=num[cnt2];
			cnt2++;
		}
		if(string[i]=='-'){
			temp-=num[cnt2];
			cnt2++;
		}
	}
	printf("%d",temp);
	return 0;}



