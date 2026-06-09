#include <stdio.h> 
int main()
{
	char s[105];
	int i,j,flag=0;
	gets(s);
	for(i=0;s[i];i++){
		if(s[i]=='-'){
			if((s[i-1]>='0'&&s[i-1]<='9')&&(s[i+1]>='0'&&s[i+1]<='9')){
				flag++;
			}
			else if((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z')){
				flag++;
			}
			else if((s[i-1]>='A'&&s[i-1]<='Z')&&(s[i+1]>='A'&&s[i+1]<='Z')){
				flag++;
			}
		}	
	}
	if(!flag)
		puts(s);
	else{
		for(i=0;s[i];i++){
			int gap=s[i+1]-s[i-1];
			if(s[i]!='-')
			printf("%c",s[i]);
			else{
				if((s[i-1]>='0'&&s[i-1]<='9')&&(s[i+1]>='0'&&s[i+1]<='9')){
				    for(j=1;j<gap;j++){
					    printf("%c",s[i-1]+j);
				    }
			    }
			    else if((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z')){
				    for(j=1;j<gap;j++){
					    printf("%c",s[i-1]+j);
				    }
			    }
			    else if((s[i-1]>='A'&&s[i-1]<='Z')&&(s[i+1]>='A'&&s[i+1]<='Z')){
				    for(j=1;j<gap;j++){
					    printf("%c",s[i-1]+j);
				    }
			    }
			    else
			    printf("-");
		    }	
		}
	}
	return 0;	  
}



