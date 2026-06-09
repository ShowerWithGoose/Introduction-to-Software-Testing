#include<stdio.h>
#include<stdlib.h>
char s[105];
int main()
{
	scanf("%s",s);
	int len = strlen(s);
	int i,j,k,pow,mark,pos = len ;
	int cnt;
	int flag = 0;
	int num = 0 , dot = len + 1;
	for(i=0;i<len;i++){
		if(s[i]=='.'){
			dot = i;
		}
	    if(s[i]>='1'&&s[i]<='9'){
	    	if(flag==0){
	    		num = i;
	    		flag = 1;
			}
		}
    }
	if(flag==1){
		cnt = 0;
	    if(dot<len){
	    	if(dot < num){
	    		pow = num - dot;
	    		printf("%c",s[num]);
	    		if(num<len-1){
	    			printf(".");
				}
	    		for(j=num+1;j<len;j++){
	    			printf("%c",s[j]);
				}
				printf("e-%d",pow);
			}
			else if(num < dot){
				pow  = dot - num - 1;
				printf("%c.",s[num]);
				for(j=num+1;j<len;j++){
				  if(s[j]!='.'){
				  printf("%c",s[j]);
			      }
			   }
				  printf("e%d",pow);
			   }
			}
		else if(dot>=len){
			pow = len - 1;
			if(pow==0){
			printf("%c",s[num]);
		    }
		    else{
		    	printf("%c",s[num]);
			}
			for(j = num + 1;j < len;j++){
				if(s[j]=='0'){
					mark = 0;
					for(k=j;k<len;k++){
						if(s[k]!='0'){
							mark = 1;
							break;
						}
					}
					if(mark==0){
					  if(pos>=len){
						pos = j;
					 }
						cnt++;
					}
				}
			}
			if(cnt<pow){
				printf(".");
			}
			for(j = num + 1;j < pos;j++){
				printf("%c",s[j]);
			}
			printf("e%d",pow);
		}	
	}
	else if(flag==0){
		printf("0e0");
	}
	return 0;
}



