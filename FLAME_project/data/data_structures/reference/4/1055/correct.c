#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct f{
	char s[2000];
	int cnt;
}w[3002]; 
int main()
{

char c;
char temp[150000];
int i,j=0,k=0;
int x,y,z;
int len=0;
int str=0;
int p,q;
int n,m;
FILE *in;
in=fopen("article.txt","r"); 
 	while((c=fgetc(in))!=EOF){
	c=tolower(c);
	temp[len]=c;
	len++;
}
str=strlen(temp);
for(i=0;i<str;i++){
	if((temp[i]>='a'&&temp[i]<='z') ){
		w[j].s[k]=temp[i];
		k++;
	}
	else{
		j++;
		k=0;
	}
}
w[j].cnt=150000;
for(x=0;x<j;x++){
if(strlen(w[x].s)>=1){
	w[x].cnt=1;
}
}
			 for(n=0;n<j;n++){ 
for(m=n+1;m<j;m++){ 
if(strcmp(w[m].s,w[n].s)<0){ 
w[3000]=w[m]; 
w[m]=w[n]; 
w[n]=w[3000]; 
} 
} 
 }
for(z=0;z<j;z++){
	
	if(	strcmp(w[z].s,w[z+1].s)==0){
	w[z+1].cnt=w[z].cnt+w[z+1].cnt;
	for(q=z;q<j;q++){
			w[q]=w[q+1];
	}
	z--;
	j--;
	}
}
for(q=0;q<j;q++){
	if((w[q].cnt)>=1){
		printf("%s %d\n",w[q].s,w[q].cnt);
	}
}
return 0;
}





