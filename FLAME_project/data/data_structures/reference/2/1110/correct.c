#include<stdio.h>
#include<ctype.h>
char s[1000];
int num[1000];
char op[1000];
int main(){
	int i,j,k=0;
	fgets(s,1000,stdin);
	for(i=j=0;s[i]!='=';i++){
		if(s[i]!=' ')s[j++]=s[i];
	}
	s[j]='\0';
	j=0;
	int a;
    for(i=0;s[i]!='\0';i++){
        if(isdigit(s[i])){
            a=0;
		    while(isdigit(s[i])){
			    a=a*10+s[i]-'0';
			    i++;
		    }
			num[j++]=a;
			i--;
		}
		else{
			op[k++]=s[i];
		}
	}
    int len=j;
    while(len>1){
    i=0;
	while(i<len-1){
		if(op[i]=='*'||op[i]=='/'){
			if(op[i]=='*'){
                num[i]=num[i]*num[i+1];
			}
			if(op[i]=='/'){
                num[i]=num[i]/num[i+1];
			}
			for(k=i+1;k<len-1;k++){
				num[k]=num[k+1];
			}
			for(k=i;k<len-2;k++){
				op[k]=op[k+1];
			}
			len--;
			break;
		}
		if(((op[i]=='+'||op[i]=='-')&&(op[i+1]!='*'&&op[i+1]!='/'))||(len==2)){
            if(op[i]=='+'){
				num[i]=num[i]+num[i+1];
			}
			if(op[i]=='-'){
				num[i]=num[i]-num[i+1];
			}
			for(k=i+1;k<len-1;k++){
				num[k]=num[k+1];
			}
			for(k=i;k<len-2;k++){
				op[k]=op[k+1];
			}
			len--;
			break;
		}
		i++;
	}
}
	printf("%d",num[0]);
	return 0;
}



