#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>




int main(){

char a[10000];
scanf("%s",a);
for(int n=0;n<strlen(a);n++){
if(a[n-1]>='a'&&a[n]=='-'&&a[n+1]<='z'&&a[n-1]<=a[n+1]){
unsigned char h;
	h=a[n-1]+1;
	
for(int k=1;h<a[n+1];k++){
printf("%c",h);
h=h+1;
}


}else if(a[n-1]>='A'&&a[n]=='-'&&a[n+1]<='Z'&&a[n-1]<=a[n+1]){
	
unsigned char h;
	h=a[n-1]+1;
	
for(int k=1;h<a[n+1];k++){
printf("%c",h);
h=h+1;
}

}else if(a[n-1]>='0'&&a[n]=='-'&&a[n+1]<='9'&&a[n-1]<=a[n+1]){
	
unsigned char h;
	h=a[n-1]+1;
	
for(int k=1;h<a[n+1];k++){
printf("%c",h);
h=h+1;
}

}else printf("%c",a[n]);
}
return 0;
}






