#include <stdio.h>
#include <string.h>
int suan(int a,int b,char c){
	int t;
	if(c=='+') t= a+b;
	else if(c=='-') t= a-b;
	else if(c=='*') t= a*b;
	else if(c=='/') t= a/b;
	return t;
}
int main(){
	char s[500],t[500],op[100],o1,o2;
	int i ,j=0 ,k=0,num[100],change;
	gets(s);
	for(i=0;i<strlen(s);i++){
		if(s[i]!=' '){
			t[j]=s[i];
			j++;
		}
	}
	j=0;memset(num,0,sizeof(num));
	for(i=0;i<strlen(t);i++){
		if(t[i]=='+'||t[i]=='-'||t[i]=='*'||t[i]=='/'||t[i]=='='){
			op[j]=t[i];
			for(;k<i;k++){
				change=t[k]-'0'+0;
				num[j]=num[j]*10+change;
			}
			j++;k++;
		}	
	}
	for(i=0;i<j;i++){
		o1=op[i];o2=op[i+1];
		if(o1=='*'||o1=='/'){
			num[i+1]=suan(num[i],num[i+1],o1);
		}
		else if(o1=='+'||o1=='-'){
			if(o2=='+'||o2=='-'){
				num[i+1]=suan(num[i],num[i+1],o1);
			}
			else if(o2=='*'||o2=='/'){
				num[i+2]=suan(num[i+1],num[i+2],o2);
				num[i+1]=num[i];op[i+1]=op[i];
			}
			else if(o2=='='){
				num[i+1]=suan(num[i],num[i+1],o1);
			}
		}
		else if(o1=='='){
			printf("%d",num[i]);
		}
	}
	return 0;
}




