#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h> 

int main(){
    char s[105];int l,k=-1,q=0,h=0,f=0,flag=0,j=1;
    gets(s);
    l=strlen(s);
    for(int i=0;i<l;i++){
    	if(s[i]=='.') k=i;
    	else if(s[i]!='0') {
    		if(flag==0) f=i,flag=1;
		}
	}
	printf("%c",s[f]);
	if(f!=l-1){
		printf(".");
		for(int i=f+1;i<l;i++){
		if(i!=k)
		printf("%c",s[i]);
	}
	}
	printf("e");
	if(f<k) printf("%d",k-f-1);
	else printf("-%d",f-k);
	return 0;
}

