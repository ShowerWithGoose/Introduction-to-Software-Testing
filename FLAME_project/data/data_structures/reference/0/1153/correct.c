#include<stdio.h>
int main(){
	char s1=']',s2,s3,s;
	while(scanf("%c",&s2)!=EOF){
		if(s2!='-'){
			printf("%c",s2);
			s1=s2;
		}
		else{
			
			scanf("%c",&s3);
			if(s1<='Z'&&s1>='A'){
				if(s3<'A'||s3>'Z')
					printf("-%c",s3);
				else{
					s=s1+1;
					for(s=s;s<=s3;s++)
						printf("%c",s);
					s1=s3;
				}
			}
				
			else if(s1<='z'&&s1>='a'){
				if(s3<'a'||s3>'z')
					printf("-%c",s3);
				else{
					s=s1+1;
					for(s=s;s<=s3;s++)
						printf("%c",s);
					s1=s3;
				}
			}
			
			else if(s1<='9'&&s1>='0'){
				if(s3<'0'||s3>'9')
					printf("-%c",s3);
				else{
					s=s1+1;
					for(s=s;s<=s3;s++)
						printf("%c",s);
					s1=s3;
				}
			}
			
			else{
				printf("-%c",s3);
				s1=s3;
			}
				
		}
	}
}

