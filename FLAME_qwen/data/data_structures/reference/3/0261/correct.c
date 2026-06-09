#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main()
{
	char s[100],ans[200];
	int i=0,len,d=0,shu=0,t=0,j=0;
	gets(s); 
	len=strlen(s);
	
	for(i=0;i<len;i++){
		if(s[i]=='.'){
			d=i;
		}
		else if(s[i]!='0'&&t==0){
			shu=i;
			t++;
		}
		if(d!=0&&t!=0){
			break;
		}
	}
	
	for(i=shu;i<len;i++){
		if(s[i] == '.')    
		    continue;
		else if(i==shu){
			if(s[i+1]){
				ans[j++]=s[i];
				ans[j++]='.';
			}
		else ans[j++]=s[i];	
		}
		else ans[j++]=s[i];
	}
	ans[j] = '\0';
		
	if(d > shu)        
	    t= d-shu-1;
	else if(shu > d)
	    t = d-shu; 	
	 
	printf("%se%d\n",ans,t);
	return 0;       
	
}

