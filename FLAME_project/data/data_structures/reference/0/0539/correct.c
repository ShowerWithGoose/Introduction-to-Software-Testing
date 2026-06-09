#include<stdio.h>
#include<string.h>

char *p=NULL,a[1000]={},s[30]={};

void replace(char[],char*,char[]);

int main(){
	char b,c,d;
	int i=0;
	gets(a);
	p=a;
	while(strchr(p,'-')!=NULL){
	p=strchr(p,'-');
	b=*(p-1);
	c=*(p+1);
		if('0'<=b&&b<c&&c<='9'){
			d=b+1;
			while(d!=c){
				s[i]=d;
				i++;
				d++;
			}
			replace(a,p,s);
			i=0;
			memset(s,0,sizeof(s));
		}
	
		if('a'<=b&&b<c&&c<='z'){
			d=b+1;
			while(d!=c){
				s[i]=d;
				i++;
				d++;
			}
			replace(a,p,s);
			i=0;
			memset(s,0,sizeof(s));
		}
		if('A'<=b&&b<c&&c<='Z'){
			d=b+1;
			while(d!=c){
				s[i]=d;
				i++;
				d++;
			}
			replace(a,p,s);
			i=0;
			memset(s,0,sizeof(s));
		}
		p=p+1;
	}
	while(a[i]!=0){
		printf("%c",a[i]);
		i++;
	}
	return 0;
} 
void replace(char a[],char *P,char s[]){
	*p=0;
	int j=0;
	char *p1=&(*(p+1));
	char a1[1000]={};
	while(*p1!=0){
		a1[j]=*p1;
		p1++;
		j++;
	}
	strcat(a,s);
	strcat(a,a1);	
}



