#include<stdio.h>

int main(){
	char s[105];
	int i,k;
	scanf("%s",s);
	for(i=0;s[i]!='.';i++);
	k=i;//小数点的位置
	if(k==1){
		if(s[0]!='0'){
		    char str[300]={0};
			sprintf(str,"%se0",s);//sprintf()
			printf("%s",str);
		}else{
			for(i=k+1;s[i]=='0';i++);
			if(s[i+1]==0){
				printf("%de%d",s[i]-'0',1-i);
			}
		}
	}else{
	    printf("%d.",s[0]-'0');
		for(i=1;i<k;i++){
			printf("%d",s[i]-'0');
		}
		for(i=k+1;s[i]!=0;i++){
			printf("%d",s[i]-'0');
		}
		printf("e%d",k-1); 
	} 
	return 0;
}

