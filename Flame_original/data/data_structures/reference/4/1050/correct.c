#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
int main()
{
int k,c,a[200]={0},i=0,j=0,flag=0,n,min,f=0;
char s[200][50],tmp[50],e[50]; 
FILE *in, *out; // 为读写文件定义文件指针 
in = fopen("article.txt", "r"); 
 if(NULL == in) 
 { 
 printf ("Failed to open the file !\n"); 
 exit(0); 
 }// 此条件句为演示FILE指针为空的含义 
 // 打开文件文件input.txt和output.txt位于与该执行程序.exe文件同一目录下 
 while ((c = fgetc(in)) != EOF) { // 从文件input.txt中依次读一个字符 
 if(c>=65&&c<=90){
 	c+=32;
 }
 if(c>=97&&c<=122){
 	s[i][j]='a'-97+c;
 	j++;
 	flag=1;
 }
 if((c<97||c>122)&&flag==1){
 	a[i]+=1;
 	i++;
 	flag=0;
 	j=0;
 }
 } fclose(in);
 n=i;
 for(k=0;k<20;k++){
			e[k]='z';
		}
 for(i=0;i<n;i++) {
 	if(strcmp(s[i],e)==0)
 	continue;
	for(j=i+1;j<n;j++){
	if(strcmp(s[i],s[j])==0){
		a[i]=a[j]+a[i];
		a[j]=0;
		strcpy(s[j],e);
	f++;
	}
	}
	}
for(i=0;i<n-1;i++) {
	for(j=0;j<n-1-i;j++){
	if(strcmp(s[j],s[j+1])>0){
		min=a[j];
		a[j]=a[j+1];
		a[j+1]=min;
		strcpy(tmp,s[j]);
			strcpy(s[j],s[j+1]);
			strcpy(s[j+1],tmp);
	}
	}	
		}
		
		for(i=0;i<n-f;i++){
			printf("%s %d\n",s[i],a[i]);
		}
return 0;
}



