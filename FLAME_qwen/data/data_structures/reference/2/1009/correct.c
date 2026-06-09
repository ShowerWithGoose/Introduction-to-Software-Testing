#include<stdio.h>
#include<string.h>
void deletespace(char*);
int cmp(char,char);
int cal(int,int,char);
int main(){
	long long result;
	int a[505]={0};
	char op[505];
	char str[5005];
	int i=0;
	int j=0;
	int k=0;
	int sum=0;
	
    gets(str);
	deletespace(str);
	
    for(;str[i]!='\0';i++){
    	if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='='){
    		op[j]=str[i];
    		j++;
		}
		if(str[i]>='0'&&str[i]<='9'){
			for(;str[i]>='0'&&str[i]<='9';i++){
				a[k]=a[k]*10+(str[i]-'0');
			}
			k++;
			i--;
		}
	}
    
    
    for(i=0;i<j;i++){
    	if(op[i]=='-'){
    		a[i+1]=-a[i+1];
		}
	}
	for(i=0;i<j;i++){
		if(op[i]=='*'){
			a[i+1]=a[i]*a[i+1];
			a[i]=0;
		}
		if(op[i]=='/'){
			a[i+1]=a[i]/a[i+1];
			a[i]=0;
		}
	}
	
	for(i=0;i<k;i++){
		sum+=a[i];
	}
	
	printf("%d",sum);
return 0; 
}

void deletespace(char *str){
	char *str_c=str;
	int i,j=0;
	for(i=0;str[i]!='\0';i++){
		if(str[i]!=' ')
		str_c[j++]=str[i];
	}
	str_c[j]='\0';
	str=str_c; 
}

int cmp(char a,char b){
	if((a=='+'||a=='-')&&(b=='*')||(b=='/')) return 1;//先算后面的，再算前面的 
	else return 0;//先算前面的，再算后面的 
}

int cal(int a,int b,char c){
	int result;
	
		if(c=='+') result=a+b;
		if(c=='-') result=a-b;
		if(c=='*') result=a*b;
		if(c=='/') result=a/b;
	
	return result;
}

