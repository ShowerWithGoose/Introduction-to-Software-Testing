#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
char a[500];
scanf("%s",a);
int i=0;
int len=strlen(a);
while(a[i]!='.'){
	i++;
	if(i==len)
	break;
}
int j=0;
int l=0;
j=i;
if(a[i-1]=='0'){
	i++;
while(a[i]=='0'){
	i++;	
}	
if(i==len-1){
	printf("%ce-%d",a[i],i-j);
}else{
	printf("%c.",a[i]);
	for(l=i+1;l<len;l++){
		printf("%c",a[l]);
	}
	printf("e-%d",i-j);
}	
}else{
i=0;
printf("%c.",a[i]);
for(i=1;i<len;i++){
	if(a[i]=='.'){	
	continue;
}
printf("%c",a[i]);
}
printf("e%d",j-1);		
}


	return 0;
}

