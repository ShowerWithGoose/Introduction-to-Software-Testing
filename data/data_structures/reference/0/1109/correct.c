#include <stdio.h>
#include <string.h>
int main (){
    char s[100];
    gets(s);
    int i=0,j,flag=0,l=strlen(s);
    for( ; i<l;i++){
     if(s[i]== '-'){

            if(s[i-1]<s[i+1]){
                if(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a'){
for(j=1;j<(s[i+1]-s[i-1]) ;j++)printf("%c",s[i-1]+j);   flag=1;
                }
                if(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A'){
for(j=1;j<(s[i+1]-s[i-1]) ;j++)printf("%c",s[i-1]+j);   flag=1;
                }if(s[i-1]<='9'&&s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>='0'){
for(j=1;j<(s[i+1]-s[i-1]) ;j++)printf("%c",s[i-1]+j);   flag=1;
                }
            }
         
     }  

     
   if(flag==1) i++;	 flag=0;
printf("%c",s[i]) ;  }
    return 0;
}

