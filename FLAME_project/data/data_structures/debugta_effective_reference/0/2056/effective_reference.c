#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
char s[500],t[500];
int i,j,n;
scanf("%s",s);
n=strlen(s);
for (i=0,j=0;i<n;i++,j++){
	if (s[i]!='-')
	t[j]=s[i];
	else{
		if (s[i-1]-'a'>=0&&s[i+1]-'a'>=0&&s[i-1]-'z'<=0&&s[i+1]-'z'<=0&&s[i-1]<s[i+1]){
			t[j]=t[j-1]+1;
			while (t[j]<s[i+1]-1){
				j++;
				t[j]=t[j-1]+1;
			}
		}
			else	if (s[i-1]-'A'>=0&&s[i+1]-'A'>=0&&s[i-1]-'Z'<=0&&s[i+1]-'Z'<=0&&s[i-1]<s[i+1]){
				t[j]=t[j-1]+1;
			while (t[j]<s[i+1]-1){
				j++;
				t[j]=t[j-1]+1;
			}
		}
			else	if (s[i-1]-'0'>=0&&s[i+1]-'0'>=0&&s[i-1]-'9'<=0&&s[i+1]-'9'<=0&&s[i-1]<s[i+1]){
				t[j]=t[j-1]+1;
			while (t[j]<s[i+1]-1){
				j++;
				t[j]=t[j-1]+1;
			}
		}
		else
		t[j]='-';
	}
}
t[j]='\0';
puts(t);
}









