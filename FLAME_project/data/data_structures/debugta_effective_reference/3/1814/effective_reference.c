#include<stdio.h>
#include<string.h>
void intchar(int);
void reverse(char[]);
char m[600];
char num[600],ans[650],s[650];
int i,n,k,len;
int main()
{
	gets(num);
	len=strlen(num);
	for(i=0;num[i]!='\0';i++){
		if(num[i]=='.') break;
	}
	if(i==1){
		if(num[0]!='0'){
			strcpy(ans,num);
			ans[len]='e';ans[len+1]='0';ans[len+2]='\0';
		}
		else{
			for(i=2;num[i]!='\0';i++){
				if(num[i]!='0') break;
			}
			intchar(i-1);
			ans[0]=num[i];
			if(num[i+1]!='\0'){
				ans[1]='.';
				i++;
				for(n=2;num[i]!='\0';n++,i++){
					ans[n]=num[i];
				}
				ans[n]='e',ans[n+1]='-';
			}	
			else {
				ans[1]='e';ans[2]='-';
			}
			strcat(ans,m);
			
		}
	}
	else{
		k=i;
		intchar(i-1);
		ans[0]=num[0];ans[1]='.';
		for(n=2,i=1;num[i]!='\0';n++,i++){
			if(num[i]=='.') i++;
			ans[n]=num[i];
		}
		ans[n]='e';
		strcat(ans,m);
	}
	puts(ans);
	return 0;
}

void intchar(int n){
	int h,i=0;
	do{
		h=n%10;
		m[i++]=h+'0';
	}while((n/=10)!=0);
	m[i]='\0';
	reverse(m);
	return ;
}
void reverse(char s[]){
	int temp,i,n;
	for(i=0,n=strlen(s)-1;i<n;i++,n--){
		temp=s[i];s[i]=s[n];s[n]=temp;
	}
	return;
}

