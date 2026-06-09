

#include<stdio.h>
#include<string.h>
int main()
{
     char c[200]={'0'};
     scanf("%s",c);
     int len=strlen(c);
     int point=len,fang=100,num=0;
     for(int i=0;i<len;i++){
     	if(c[i]=='.') point=i;
	 }
	 for(int i=0;i<len;i++){
	 	if(c[i]!='0'&&c[i]!='.') {
		 if(i<point)fang=point-1-i;
		 else fang=point-i;
         break;
	 }
}
     for(int i=0;i<len;i++){
     	if(c[i]!='0'&&c[i]!='.') num++;
	 }
	 if(fang==100) printf("0");
	 else if(fang==0){
	 	printf("%c",c[point-1]);
	 	int i=1;
	 	if(i<num){
	 		printf(".");
	 	for(int j=point+1;j<len;j++){
	 		 printf("%c",c[j]);
	 		 if(c[j]!='0') i++;
	 		 if(i==num) break;
		 }
	 }
	 printf("e0");
 }
 else if(fang!=100&&fang!=0){
 int j=0;
 	for(j;j<len;j++){
 		if(c[j]!='0'&&c[j]!='.'){
 			printf("%c",c[j]);
 			break;
		 }
	 }
	 if(num==1) printf("e%d",fang);
	 else{
	 	j++;
	 	printf(".");                                                                                                                                                                
	 	int p=1;
	 	for(j;j<len;j++){
	 	if(c[j]!='.')	printf("%c",c[j]);
	 	if(c[j]!='.'&&c[j]!='0')	  p++;
	 		 if(p==num) break;
		 }
		 printf("e%d",fang);
	 }
 }
 return 0;
}



