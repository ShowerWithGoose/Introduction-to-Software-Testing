#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	int e=0,i;
    char s[100],c[100];
    gets(s);
   	s[strlen(s)]='\0';
    if(s[0]=='0'&&s[1]=='.'){
    	for(i=0;i<strlen(s);i++){
    		if(s[i]!='0'&&s[i]!='.'){
    			e=i-1;
    			strcpy(c,&s[i+1]);
    			s[0]=s[i];
    			if(strlen(s)==i+1){
    				s[1]='\0';
				}else{
    			s[1]='.';
    			s[2]='\0';
    			strcat(s,c);}
    			break;
			}
		}
		for(i=strlen(s);i>0;i--){
			if(s[i-1]=='0')s[i-1]='\0';
			else if(s[i-1]!='0')break;
		}
    printf("%se%d",s,-e);
	} 
	else{
    for(i=0;i<strlen(s);i++){
    	if(s[i]=='.'){
    	e=i-1;
    	strcpy(c,&s[i+1]);
    	s[i]='\0';
    	strcat(s,c);
    	strcpy(c,&s[1]);
    	s[1]='.';
    	s[2]='\0';
    	strcat(s,c);
    	break;
		} 
	}
	for(i=strlen(s);i>0;i--){
			if(s[i-1]=='0')s[i-1]='\0';
			else if(s[i-1]!='0')break;
		}
	printf("%se%d",s,e);
    }
	return 0;
}

