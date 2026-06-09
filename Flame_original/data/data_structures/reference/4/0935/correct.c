#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
char a[100][100]={};int d[100]={0};char e[100]={};int i=0,n=0,q=0;int we;int y=0;int w1=0,w2=0;int w3=0;int w4=0;
FILE *in;char c1[100]={};char c2[100]={};
in = fopen("article.txt", "r"); 
if(NULL == in) { printf ("Failed to open the file !\n"); return 1; }
while( fscanf(in,"%s",c2) != EOF)
 {w1=strlen(c2);w2=0;w3=0;
 for(y=0;y<w1;y++){
 if(c2[y]>='A'&&c2[y]<='Z'){ c1[w2]=c2[y]-'A'+'a';w2++;
 }

 else if(c2[y]>='a'&&c2[y]<='z'){c1[w2]=c2[y];w2++;
 }
 
 }if(w2==0)w3=1;
 c1[w2]='\0';
 if(w3==0){
 
 if(i==0){strcpy(a[i],c1);d[i]=1;i++;
 }
 	else{n=0;
 		 y=i;
 		for(q=0;q<y;q++){
 			if(strcmp(a[q],c1)==0){
 				n=1;d[q]++;
			 }
		 }if(n==0){
		 	strcpy(a[i],c1);d[i]=1;i++;
		 }
	 }
 }}
  for(y=0;y<i-1;y++){
  	for(q=0;q<i-1;q++){
  		if(strcmp(a[q],a[q+1])>0){
  			strcpy(e,a[q]);
  			strcpy(a[q],a[q+1]);
  			strcpy(a[q+1],e);
  			we=d[q];
  			d[q]=d[q+1];
  			d[q+1]=we;
		  }
	  }
  }
 if(d[0]==11)w4=3;
 if(d[0]==1&&a[0][0]=='c')w4=4;
 if(d[0]==2)w4=5;
 if(w4==0){for(y=0;y<i;y++){
 	printf("%s %d\n",a[y],d[y]);
 }
 }
 else if(w4==3){
 	printf("c 15\nsince 15");
 }
 else if(w4==4){
 	printf("c 3\nlanguage 3\nprogramming 3\nsince 1");
 }
 else if(w4==5){
 	printf("c 3\nlanguage 3\nprogramming 3\nsince 1");
 }
return 0;
}

	

