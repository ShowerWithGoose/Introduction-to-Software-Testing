#include<stdio.h>
#include<string.h>

int kind123(char);
int main()
{
	char s[10000],*p=s,stmp[10000],expandtmp[100];
	int i;
	scanf("%s",s);
	while((p=strchr(p+1,'-'))!=NULL){
		//printf("%c\n",*(p-1));  //test	
		if(kind123(*(p-1))==kind123(*(p+1))&&kind123(*(p-1))!=0&&*(p-1)<*(p+1)){
			strcpy(stmp,p+1);
			for(i=0;i<*(p+1)-*(p-1);i++){
				expandtmp[i]=*(p-1)+i+1;
			}
			expandtmp[i-1]='\0';
			*p='\0';
			strcat(s,expandtmp);
			strcat(s,stmp);
			memset(expandtmp,'\0',strlen(expandtmp));
		}		
	}
	puts(s);
	
	return 0;
}
int kind123(char c)
{
	if(c>='0'&&c<='9') return 1;
	else if(c>='a'&&c<='z') return 2;
	else if(c>='A'&&c<='Z') return 3;
	else return 0;
	
}

