#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
char a[100],m[100];
int check(char b,char c){
	if(b>=c)
	return 0;
	if(b>='a'&&b<='z'&&c>='a'&&c<='z')
	return 1;
	if(b>='A'&&b<='Z'&&c>='A'&&c<='Z')
	return 1;
	if(b>='0'&&b<='9'&&c>='0'&&c<='9')
	return 1;
	return 0;
}
int main()
{
int i,j=0;
 gets(a);
 for(i=0;i<(strlen(a));i++){
 	if(a[i]=='-'){
 		if(check(a[i-1],a[i+1])==1)
 		{
 			while(m[j-1]<a[i+1]-1)
		{
		  m[j]=m[j-1]+1;
 		j++;
 	}	
 	}
 	else
 	m[j++]=a[i];
	 }
	 else
	 m[j++]=a[i];
 }
 puts(m);
	return 0;
}

