#include<stdio.h>
#include<string.h>
void intchar(int);
void reverse(char[]);
char numb[600];
char num[600],ans[650],s[650];
int i,j,k,len;
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
				for(j=2;num[i]!='\0';j++,i++){
					ans[j]=num[i];
				}
				ans[j]='e',ans[j+1]='-';
			}	
			else {
				ans[1]='e';ans[2]='-';
			}
			strcat(ans,numb);
			
		}
	}
	else{
		k=i;
		intchar(i-1);
		ans[0]=num[0];ans[1]='.';
		for(j=2,i=1;num[i]!='\0';j++,i++){
			if(num[i]=='.') i++;
			ans[j]=num[i];
		}
		ans[j]='e';
		strcat(ans,numb);
	}
	puts(ans);
	return 0;
}

void intchar(int n){
	int h,i=0;
	do{
		h=n%10;
		numb[i++]=h+'0';
	}while((n/=10)!=0);
	numb[i]='\0';
	reverse(numb);
	return ;
}
void reverse(char s[]){
	int temp,i,j;
	for(i=0,j=strlen(s)-1;i<j;i++,j--){
		temp=s[i];s[i]=s[j];s[j]=temp;
	}
	return;
}

