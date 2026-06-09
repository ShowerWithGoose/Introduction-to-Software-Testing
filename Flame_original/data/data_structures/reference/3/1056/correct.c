#include<stdio.h>
int main()
{
   int i=0,m=0,flag=0;	
   char s[120];
   int a[120]={0};
   gets(s);
   int l=strlen(s);
   if(s[0]=='-')
   {
   	for(i=0;i<l-1;i++){
   		s[i]=s[i+1];
	   }
	   s[l-1]="\0";
	   l-=1;printf("-");
   }
   int l2=l;
   for(i=0;i<l;i++){
   	if(s[i]=='.'){
   		flag=1;m=i;break;
	   }
	}
	if(flag==0){
		for(i=l-1;i>=0;i--){
			if(s[i]=='0'){
				l2-=1;
			}else{
				break;
			}
		}
		printf("%c",s[0]);
		if(l2>1){
			printf(".");
		}
		for(i=1;i<l2;i++){
			printf("%c",s[i]);
		}
		printf("e%d",l-1);
	}else{
		if(s[0]=='0'){
			l2=2;
			for(i=2;i<l;i++){
				if(s[i]=='0'){
					l2+=1;
				}else{
					break;
				}
			}
			printf("%c",s[l2]);
			if(l2+1!=l){
				printf(".");
			for(i=l2+1;i<l;i++){
				printf("%c",s[i]);
			}
			}printf("e-%d",l2-1);
		}else if(s[0]!=0){
			printf("%c.",s[0]);
			for(i=1;i<m;i++){
				printf("%c",s[i]);
			}
			for(i=m+1;i<l;i++){
				printf("%c",s[i]);
			}
			printf("e%d",m-1);
		}
	}
return 0;
}


