#include<stdio.h>
#include<string.h>

int main(){
	char s[105],s1[105]={'\0'};
	int i,j,e=0,n,k;
	gets(s);
	n=strlen(s);
	if(s[0]=='0'){
		i=2;
		while(s[i]=='0'){
			e++;
			i++;
		}
		
		if(i!=n-1){
			s1[0]=s[i];
			s1[1]='.';
			k=i+1;
			for(j=2;k<n;j++,k++){
				s1[j]=s[k];
			}
		}
		else {
			s1[0]=s[i];
		}
		printf("%s",s1);
		printf("e-%d",e+1);
	}
	else{
		for(i=0;i<n;i++){
		if(s[i]=='.'){
			e=i-1;
			s1[0]=s[0];
			s1[1]='.';
			if(i<2){
				for(j=0;j<n;j++){
					s1[j]=s[j];
				}
			}
			else{
				for(j=2;j<i+1;j++){
				    s1[j]=s[j-1];
		    	}
			    k=i+1;
			    for(j;j<n;j++,k++){
				    s1[j]=s[k];
		    	}
		    	}
			
			printf("%s",s1);
			printf("e%d",e);
			
			
		}
	}
	}
	
	    
	
	return 0;
}

