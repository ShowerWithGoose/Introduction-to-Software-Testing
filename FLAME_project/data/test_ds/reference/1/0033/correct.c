#include <stdio.h>
#include<string.h>
int main(){
char a[500]={0};
char c[500]={0};
char b='-';
scanf("%s",a);
int i=0,j=0,k=0,l=0;
for(i=0,j=0;a[i]!='\0';i++){
	if ((a[i]=='-'&&i>0)&&((a[i-1]>96&&a[i+1]>a[i-1]&&a[i+1<123])||(a[i-1]<a[i+1]&&a[i+1]<91&&a[i-1]>64)||((a[i-1]<a[i+1]&&a[i+1]<58&&a[i-1]>47)))){
		for(k=a[i-1]+1;k<a[i+1];k++){
			c[l]=k;
			l++;
		} 
	}
	else{
		c[l]=a[i];
		l++;
	}

}
puts(c);	
return 0;
}

