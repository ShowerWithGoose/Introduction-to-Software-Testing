#include<stdio.h>
#include<string.h>

char numf[105],numb[105],s[105];
int n,i,j,k;

int main(){
	scanf("%s",s);
	sscanf(s,"%[^.].%[0-9]",numf,numb);
	for(i=0;i<strlen(numf);i++){
		if(numf[i]=='0'){
			n++;
		}else{
			break;
		}
	}
	if(n==strlen(numf)){
		for(i=0;i<strlen(numb);i++){
		if(numb[i]=='0'){
			n++;
		}else{
			break;
		}
	}
		k=n-strlen(numf);
		if(numb[n-strlen(numf)+1]!='\0'){
		printf("%c.%se%d",numb[k],&numb[k+1],-k-1);
	}else{
		printf("%ce%d",numb[k],-k-1);
	}
	}else{
		k=strlen(numf)-n;
		printf("%c.%s%se%d",numf[n],&numf[n+1],numb,k-1);	
	}
	
	return 0;
} 



