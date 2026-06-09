#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
char s[105],shu[105];
int main(){
	
	fgets(s,104,stdin);
	int i,k,m,j,l=strlen(s);
	for(i=0;i<l-1;i++)
		if(s[i]=='.'){
			k=i;
			break;
		}
	if(k==1){
		if(s[0]=='0'){
			for(i=2;i<l;i++){
				if(s[i]!='0'){
					j=i;
					break;
				}
			}
			shu[0]=s[j];	
			if(j!=(l-2)){
				shu[1]='.';
				for(i=j+1,m=2;i<l-1;i++,m++)
					shu[m]=s[i];
			}
			else
				m=1;
			for(i=0;i<m;i++)
				printf("%c",shu[i]);
			printf("e-%d",j-1);
			
		}
		else{
			for(i=0;i<l-1;i++)
				printf("%c",s[i]);
			printf("e0");
		}
	}
	else{
		shu[0]=s[0];
		shu[1]='.';
		for(i=1,m=2;i<l-1;i++){
			if(s[i]!='.'&&s[i]!=NULL&&s[i]!='\n'){
				shu[m]=s[i];
				m++;
			}
		}
		for(i=0;i<l-1;i++)
			printf("%c",shu[i]);
		printf("e%d",k-1);
	}
		
			
	return 0;
}

