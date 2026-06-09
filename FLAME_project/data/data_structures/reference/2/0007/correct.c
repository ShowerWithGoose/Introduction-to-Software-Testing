#include<stdio.h> 
#include<math.h>
#include<stdlib.h> 
#include<string.h> 
#include<stdbool.h> 
char s[1666],s2[1666],symbol[1032];
int num[1027],ans=0;
void aoti(char c[],int,int );
int caculate(int);
int main(){ 
gets(s);
int i,j=0;
int len;
for(i=0;i<strlen(s);i++){
	if(s[i]!=' '){
	 s2[j]=s[i];
	 j++;	
	}	
}
len=j;
int k=0;
for(i=0;i<len;i++){
	if(s2[i]>'9'||s2[i]<'0'){
		symbol[k]=s2[i];
		k++;
	}	
}
int num_symbol=k;
aoti(s2,len,k);
ans=caculate(k);
printf("%d",ans);
return 0;
}
void aoti(char c[],int len_all,int len_symbol){
	int i,j=0;
for(i=0;i<len_symbol;i++){
for(num[i]=0; c[j]>='0' && c[j] <= '9'; j++){
	num[i] = 10*num[i] + c[j] - '0';
                }
j++;	
        }	
}
int caculate(int slen ){
	int i;
	int Ans=0;
for(i=0;i<slen;i++){
	if(symbol[i]=='-'){
		num[i+1]=-num[i+1];
	}
}
for(i=0;i<slen-1;i++){
	if(symbol[i]=='*'){
		num[i+1]=num[i+1]*num[i];
		num[i]=0;
	}else if(symbol[i]=='/'){
		num[i+1]=num[i]/num[i+1];
		num[i]=0;
	}
}	
for(i=0;i<slen;i++){
	Ans=Ans+num[i];
}	
return Ans;
}
	
	

