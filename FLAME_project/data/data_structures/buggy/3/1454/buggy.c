#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
	char s[200]={0},tmp;
	gets(s);
	int i,num=-1,sum=0,flag=1,j;
	for(i=0;s[i];i++){
		if(s[i]=='.'){
			if(sum==1&&s[i-1]!=0){
				printf("%se0",s);
				break;
			}else if(sum>1){
				for(j=0;s[j];j++){
					if(j==1){
						printf(".%c",s[j]);
					}else if(s[j]=='.'){
						continue;
					}else{
						printf("%c",s[j]);
					}
				}
				printf("e%d",num);
			}else {
				for(j=i;s[i];j++){
					if(s[j+1]!='0'&&s[j+2]!=NULL){
							printf("%c.%se-%d",s[j+1],&s[j+2],flag);
							break;
					}else if(s[j+1]!='0'){
							printf("%ce-%d",s[j+1],flag);
							break;
						}
					flag++;
				}
				break;
			}
		}
		sum++;
		num++;
	}

	return 0;
}


