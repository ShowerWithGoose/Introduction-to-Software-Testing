#include<stdio.h> 
#include<string.h>
#include<math.h>
#include<ctype.h>
int len(int n);
int main(){
	char s[1000],str[1000];
	gets(str);
	int i=0,j=0,p=0;
	while(str[i]!='\0'){
		if(str[i]!=32){
			s[j++]=str[i++];
	    }
	    else i++;
    }
    s[j]='\0';
    int n1=0,n2,n3;
    char c1='+',c2,c3;
    while(c1!='='){
    	sscanf(&s[p],"%d%c",&n2,&c2);
    	p+=len(n2)+1;
    	if(c2=='+'||c2=='-'||c2=='='){
    		c1=='+'?(n1+=n2):(n1-=n2);
    		c1=c2;
		}
		else {
		while(c2=='*'||c2=='/' ){
    		sscanf(&s[p],"%d%c",&n3,&c3);
    		p+=len(n3)+1;
    		c2=='*'?(n2*=n3):(n2/=n3);
    		c2=c3;	
			}
			c1=='+'?(n1+=n2):(n1-=n2);
    		c1=c2;
		}
	}
	printf("%d",n1);
	return 0;
}
int len(int n){
	int m=1;
	while(n/10){
		m++;
		n/=10;
	}
	return m;
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

