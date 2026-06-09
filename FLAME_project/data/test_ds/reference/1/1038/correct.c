#include<stdio.h>
#include<string.h> 
int main()
{
    char s[1000],t[1000],ch;
    int n,i,j;
    gets(s);
    for(i=0,j=0;s[i]!='\0';i++){
    	if(s[i]!='-'||i==0) t[j++]=s[i];
    	else{
    		if(s[i-1]>='a'&&s[i-1]<s[i+1]&&s[i+1]<='z'){
    			for(ch=s[i-1]+1;ch<s[i+1];ch++){
    				t[j++]=ch;
				}
			}
			else if(s[i-1]>='A'&&s[i-1]<s[i+1]&&s[i+1]<='Z'){
    			for(ch=s[i-1]+1;ch<s[i+1];ch++){
    				t[j++]=ch;
				}
			}
			else if(s[i-1]>='0'&&s[i-1]<s[i+1]&&s[i+1]<='9'){
    			for(ch=s[i-1]+1;ch<s[i+1];ch++){
    				t[j++]=ch;
				}
			}
			else t[j++]=s[i];
		}
	}
	t[j]='\0';
	printf("%s",t);
	return 0; 
}



