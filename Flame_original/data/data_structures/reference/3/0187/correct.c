#include<stdio.h>
#include<string.h>
char s1[105];
int main()
{
	scanf("%s",s1);
	int k=strlen(s1);
	int zs;
	if(s1[0]!='-'){
		if(s1[0]!='0') {
			int e1=1;
			while(s1[e1]!='.') e1++;
			zs=e1-1;
			printf("%c.",s1[0]);
			int l;
			for(l=1;l<k;l++){
				if(l!=e1) printf("%c",s1[l]);
			}
			printf("e%d",zs);
		}
		else if(s1[0]=='0'){
			int e1=2;
			while(s1[e1]=='0') e1++;
			zs=e1-1;
			if(e1==k-1)
			printf("%ce-%d",s1[e1],zs);
			else{
				printf("%c.",s1[e1]);
				for(e1++;e1<=k-1;e1++) printf("%c",s1[e1]);
				printf("e-%d",zs);
			}
		}
	}
	else if(s1[0]=='-'){
		if(s1[1]!='0'){
			int e1=2;
			while(s1[e1]!='.') e1++;
			zs=e1-2;
			printf("-%c.",s1[1]);
			int l;
			for(l=2;l<k;l++){
				if(l!=e1) printf("%c",s1[l]);
			}
			printf("e%d",zs);
		}
		else if(s1[1]=='0'){
			int e1=3;
			while(s1[e1]=='0') e1++;
			zs=e1-2;
			if(e1==k-1)
			printf("-%ce-%d",s1[e1],zs);
			else{
				printf("%c.",s1[e1]);
				for(e1++;e1<=k-1;e1++) printf("%c",s1[e1]);
				printf("e-%d",zs);
			}
		}
	}
	return 0;
	
}



