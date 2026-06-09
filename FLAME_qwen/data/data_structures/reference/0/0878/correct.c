#include<stdio.h>
#include<string.h>
int main(){
	int i,j,k,judge; 
	char s[100010],ans[100010];
	scanf("%s",&s);
	for(i=j=0;i<strlen(s);i++,j++){
		if(s[i]=='-'){
			if((s[i-1]<s[i+1])&&((s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]>='a'&&s[i+1]<='z')||(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]>='A'&&s[i+1]<='Z')||(s[i-1]<='9'&&s[i-1]>='0'&&s[i+1]>='0'&&s[i+1]<='9'))){
				judge=s[i+1]-s[i-1];
				if(judge==1)
				ans[j]=s[i+1];
				else{
					for(k=1;k<judge;k++,j++){
						ans[j]=s[i-1]+k;
					}
					j--;
				}
			}
			else ans[j]=s[i];
		}
		else ans[j]=s[i];
	}
	puts(ans);
	return 0;
}



