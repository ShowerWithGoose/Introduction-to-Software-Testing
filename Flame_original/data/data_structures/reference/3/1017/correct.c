#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	int t=0,c=0,e=0,e0=0;
    char xs[105];

     
    scanf("%s",xs);
     int len=strlen(xs);
     if(xs[0]=='-'){
	 	t=1;
	 	printf("-");
	 }
    for(int i=0;i<len;i++){
		if(xs[i]!='.')
			c++;
		else 
		break;	
		} 
		if(c==len){

	
		printf("%c.",xs[0+t]);
	for(int i=1+t;i<len;i++)
	printf("%c",xs[i]);
    printf("e%d",len-1-t);
		}
		
		
   else if(c!=len&&xs[t]!='0'){
   	printf("%c.",xs[t]);
    for(int i=t+1;i<c;i++)
     printf("%c",xs[i]);
	 for(int i=c+1;i<len;i++){
	 	printf("%c",xs[i]);
	 } 
	 printf("e%d",c-1);
   }		
   else{
     for(int i=t+2;i<len;i++)
     {
	 	if(xs[i]=='0')
	 	e++;
	 	else 
	 	break;
	 }

	 if(e==len-3)
	 e0=1;
   	printf("%c",xs[t+e+2]);
   	if(!e0)
   	printf(".");
   	for(int i=t+e+3;i<len;i++)
   	printf("%c",xs[i]);
   	printf("e-%d",e-t+1);
   }
		return 0;
}


