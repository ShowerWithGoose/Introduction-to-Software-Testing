#include<stdio.h>
#include<string.h>

char numzheng[105],numxiao[105],numf[105];
int ep,i,j,em;

int main(){
	scanf("%s",numf);
	sscanf(numf,"%[^.].%[0-9]",numzheng,numxiao);
	for(i=0;i<strlen(numzheng);i++){
		if(numzheng[i]=='0'){
			ep++;
		}else{
			break;
		}
	}
	if(ep==strlen(numzheng)){
		for(i=0;i<strlen(numxiao);i++){
		if(numxiao[i]=='0'){
			ep++;
		}else{
			break;
		}
	}
		em=ep-strlen(numzheng);
		if(numxiao[ep-strlen(numzheng)+1]!='\0'){
		printf("%c.%se%d",numxiao[em],&numxiao[em+1],-em-1);
	}else{
		printf("%ce%d",numxiao[em],-em-1);
	}
	}else{
		em=strlen(numzheng)-ep;
		printf("%c.%s%se%d",numzheng[ep],&numzheng[ep+1],numxiao,em-1);	
	}
	
	return 0;
} 



