#include <stdio.h>
#include <string.h>
char s[120],ts[120];
int main(){
	int i,j,k,l,p,flag=0,temp=0,sum=0;
	gets(s);
	for(i=0;i<strlen(s);i++){
		if(s[i]=='.')
		{
		flag=1;break;
		}
	}int len=strlen(s);
	if(flag!=1){//整数 
	    if(strlen(s)==1)
		printf("%se0",s);
		else{
		for(i=0;i<len;i++){//无小数点 
			if(s[i]=='0') sum++;
		}
		if(sum==len-1)
		  printf("%ce%d",s[0],len-1);		
		else{sum=0;//有小数点 
		  for(i=len-1;i>=0;i--){
		  	if(s[i]=='0'){
		  		sum++;
			  }else break;
		  }ts[0]=s[0];ts[1]='.';
		  for(j=2,i=1;i<=len-sum;i++){
		  	ts[j++]=s[i];
		  }for(i=0;i<=len-sum;i++){
		  	printf("%c",ts[i]);
		  }printf("e%d",len-1);
		}}
	}else{//小数 
		if(s[0]>'0'){
			if(s[1]=='.'){
			for(i=0;i<len;i++)
			  printf("%c",s[i]);printf("e0");	
			}
			
			else{
			
				
				
			for(i=0;i<len;i++){
				if(s[i]!='.') temp++;
				else break;
			}
				for(j=k=0;s[j]!= '\0';j++)
            	if(s[j]!='.')
            	s[k++]=s[j];
	            s[k]= '\0'; ts[0]=s[0];ts[1]='.';
	        for(i=1,j=2;i<len;i++)
	            ts[j++]=s[i];
	        for(i=0;i<j-1;i++){
		  	printf("%c",ts[i]);
		  }printf("e%d",temp-1);
			}
		}
		else{//真小数
			if(len==3) printf("%ce-1",s[2]);
			else{
				
		    for(i=0;i<len;i++){
		    	if(s[i]=='.'||s[i]=='0') temp++;
			 else {
				ts[0]=s[i];break;
			}}
			if(temp==len-1) printf("%ce-%d",s[len-1],temp-1);
			else{
			ts[1]='.';
			for(i=temp+1,j=2;i<len;i++)
			    ts[j++]=s[i];
			for(i=0;i<j;i++)
			 printf("%c",ts[i]);
			 printf("e-%d",temp-1);
		}}}
	}
	
	
	
	return 0;
}

