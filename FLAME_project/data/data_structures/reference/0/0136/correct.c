#include<stdio.h> 
#include<math.h> 
#include<string.h> 
 int main()
  { 
  char s[500]={'\0'},ch;
  int i=0;
  
  while(scanf("%c",&ch)!=EOF)
  {
		s[i]=ch;
		i++;
}
for(i=0;s[i];i++){
		if(s[i]=='-'){
			if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){
				for(ch=s[i-1]+1;ch<s[i+1];ch++)
					printf("%c",ch);
			}else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){
				for(ch=s[i-1]+1;ch<s[i+1];ch++)
					printf("%c",ch);
			}else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){
				for(ch=s[i-1]+1;ch<s[i+1];ch++)
					printf("%c",ch);
			}else
				printf("%c",s[i]);
		}
		else
			printf("%c",s[i]);
	}
	printf("\n");	

  return 0; }


