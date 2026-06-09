#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
char s[105];
int i,len,first,last,d;
scanf("%s",s);
len=strlen(s);
for (i=0;i<len;i++){
	if (s[i]!='.'&&s[i]!='0'){
	first=i;
	break;}
}
for (i=len-1;i>=0;i--){
	if (s[i]!='.'&&s[i]!='0'){
		last=i;
		break;
	}
}
for (i=0;i<len;i++){
	if (s[i]=='.')
	d=i;
}
printf("%c",s[first]);
if (last>first){
	printf(".");
for (i=first+1;i<=last;i++){
	if (s[i]!='.')
	printf("%c",s[i]);
	}
}
printf("e");
if (first<d)
printf("%d",d-first-1);
else
printf("%d",d-first);
}









