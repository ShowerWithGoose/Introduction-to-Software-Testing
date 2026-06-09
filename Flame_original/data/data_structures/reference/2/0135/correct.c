#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

int temp[1000],ans,n[1000],len;    //³Ë³ýÎª1 
char in[1000];

void del(){
	int i,j;
	for(i=0,j=0;in[i]!='\0';i++){
		if(in[i]!=' ') in[j++] = in[i];
	}
	in[j] = '\0';
}

void list(int len){
	int i,j,k;
	
	for(i=0,j=0,k=0;i<len;i++){
		if(isdigit(in[i])){
			temp[k] = temp[k] * 10 + in[i] - 48;
		} 
		else if(in[i]=='='){
			n[j] = 4;
			j++;
			k++;	
		} 
		else if(in[i]=='*'){
			n[j] = 2;
			j++;
			k++;
		}
		else if(in[i]=='/'){
			n[j] = 3;
			j++;
			k++;
		}
		else if(in[i]=='+'){
			n[j] = 0;
			j++;
			k++;
		}
		else if(in[i]=='-'){
			n[j] = 1;
			j++;
			k++;
		}
	}
	
	return;
}

void count(){
	int i=0,flag=-1;
	
	for(i=0;n[i]!=4;i++){
		if(n[i]==2){
			temp[i+1] = temp[i] * temp[i+1];
		}
		else if(n[i]==3){
			temp[i+1] = temp[i] / temp[i+1];
		}  
	}
	
	for(i=0;n[i]!=4;i++){
		if(n[i]==0){
			if(flag==-1) ans = temp[i];
			else{
				if(flag == 1) ans += temp[i];
				else ans -= temp[i];
			} 
			flag = 1;
		}
		else if(n[i]==1){
			if(flag==-1) ans = temp[i];
			else{
				if(flag == 1) ans += temp[i];
				else ans -= temp[i];
			}
			flag = 0; 
		}  
	}
	if(flag == 1) ans += temp[i];
	else if(flag == 0) ans -= temp[i];
	else ans = temp[i];
}


int main(){
	gets(in);
	del();
	
	len = strlen(in);
	list(len);
	count();
	
	printf("%d",ans);
	return 0;
} 

