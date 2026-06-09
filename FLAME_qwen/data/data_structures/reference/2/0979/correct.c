#include <stdio.h>
int main(){
	char a[1000], b[100], cal[100];
	int num[100]={0}, i, j, k, m, q, length, flag, flags, tmp=1, result=0;
	gets(a);
	for(length=0; a[length]!='='; length++);
	for (i=0, j=0; i<length; i++, j++){
		if (a[i]!=' '){
			b[j]=a[i];
		}
		else j--;
	}
	//ртиончнС 
	q=0;
	for(i=0, j=0, k=0; i<strlen(b); i++){
		if ((b[i]=='+'||b[i]=='-')||(b[i]=='*'||b[i]=='/')){
			cal[k]=b[i]; 
			k++;
		}
		else {
			for(m=i; b[m]>='0'&&b[m]<='9'; m++){
				num[q]=num[q]*10+(b[m]-'0');
		    }
			q++;
			i=m-1;
		}
	}
	if(k==0){
		printf("%d",num[0]);
		return 0;
	}
	i=0;
	flag=1;
	for(i=0; i<=strlen(cal); i++){
		if(cal[i]=='+'||cal[i]=='-'){
			if(i==0){
				result+=num[i];
			}
			else if(flag==1){
				if(cal[i-1]=='*'){
					result+=num[i]*tmp;
				}
				else if(cal[i-1]=='/'){
					result+=tmp/num[i];
				}
				else result+=num[i];
			}
			else if(flag==2){
				if(cal[i-1]=='/'){
					result-=tmp/num[i];
				}
				else result-=num[i]*tmp;
			}
			if(cal[i]=='+'){
				flag=1;
			}
			else flag=2;
			tmp=1;
		}
		else {
			if(cal[i-1]=='*'){
				tmp*=num[i];
			}
			else if(cal[i-1]=='/'){
				tmp/=num[i];
			}
			else tmp*=num[i];
			
		}
		if(i==strlen(cal)){
			if(flag==1){
				result+=tmp;
			}
			else result-=tmp;
		}
	}
	printf("%d",result);
	return 0;
}

