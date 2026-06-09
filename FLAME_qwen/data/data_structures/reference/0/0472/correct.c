#include<stdio.h>
#include<string.h>
#define length 1000
int main(){
	
	char s1[length];
	char s2[length];
	//scanf("%s",s1[]); 
	gets(s1);
	int i,j,k;
	for(i=0,j=0;s1[i]!='\0';i++){
		if(s1[i]!='-'){
			s2[j++]=s1[i];
			//continue;
		}
		else{
			if(97<=s1[i-1]&&s1[i-1]<=122&&97<=s1[i+1]&&s1[i+1]<=122){
				for(k=1;k<s1[i+1]-s1[i-1];k++){
					s2[j++]=s1[i-1]+k;
					//continue;
				}
			}
			else if(65<=s1[i-1]&&s1[i-1]<=90&&65<=s1[i+1]&&s1[i+1]<=90){
				    for(k=1;k<s1[i+1]-s1[i-1];k++){
					    s2[j++]=s1[i-1]+k;
					    //continue;
				}
			}
			else if(48<=s1[i-1]&&s1[i-1]<=57&&48<=s1[i+1]&&s1[i+1]<=57){
				    for(k=1;k<s1[i+1]-s1[i-1];k++){
					    s2[j++]=s1[i-1]+k;
					    //continue;
				}
		    }
		    else{
		    	s2[j++]='-';
		    	
			}
		
	} 
}
	puts(s2);
//	for(k=0;k<strlen(s2);k++){
//		printf("%c",s2);
//	}
	
	
	return 0;
}



