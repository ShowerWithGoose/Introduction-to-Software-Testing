#include <stdio.h>
#include <string.h>
char s[1000],c[1000];
int main(){
	int j,i,l,spc;
	
	gets(s);
	for(i=j=0;i<strlen(s);i++,j++){
		if(s[i]=='-'){//是目标符号 
			if(i>=1){//第一个不用考虑 
				char ch=s[i-1];
				if(s[i+1]>s[i-1]){//后项大于前项 
						if(s[i-1]<'9'&&s[i-1]>='0'&&s[i+1]<='9'){//阿拉伯数字 
					        spc=s[i+1]-ch;
					  		for(l=1;l<spc;l++){
					  			
								  c[j]=ch+l;
					  			j++;
							  }
							  j--;
						}
						
						else if(s[i-1]<='y'&&s[i-1]>='a'&&s[i+1]<='z'){//小写字母
							spc=s[i+1]-ch;
							for(l=1;l<spc;l++){
								c[j]=ch+l;
							j++;
							}
							j--;
				    	}
						
						else if(s[i-1]<'Z'&&s[i-1]>='A'&&s[i+1]<='Z'){//大写字母 
       						spc=s[i+1]-ch;
       						for(l=1;l<spc;l++){
       						
							
							c[j]=ch+l;
							j++;
							   }
							   j--;
						}
				    	else{
							c[j]=s[i];
						}
				}
				else{
					c[j]=s[i];
				}
			}
			else {
				c[j]=s[i];
			}
		}
		else{
			c[j]=s[i];
		}
    }       
		puts(c);
	return 0;
	}

