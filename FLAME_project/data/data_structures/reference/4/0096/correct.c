#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>


void swap(char a[],char b[]){
	char ch;
	int i;
	int len1=strlen(a),len2=strlen(b);
	for(i=0;a[i]!='\0'&&b[i]!='\0';i++){
		ch=a[i];
		a[i]=b[i];
		b[i]=ch;
	}
	if(len1==len2){
		a[i]=b[i]='\0';
	}
	else if(len1>len2){
		for(;a[i]!='\0';i++){
			b[i]=a[i];
			a[i]='\0';
		}
		b[i]='\0';
	}
	else if(len1<len2){
		for(;b[i]!='\0';i++){
			a[i]=b[i];
			b[i]='\0';
		}
		a[i]='\0';
	}
	return;
}

struct mu{
    char a[15];
    int n;
}m[999];

char b[15];

int main(){
    int i,j,p,k,flag=0;
    i=0;
    char ch;
    FILE *in;
    in=freopen("article.txt","r",stdin);
    ch=getchar();
    while(ch!=EOF){
    	j=0;
    	while(isalpha(ch)){
    		
    		m[i].a[j++]=tolower(ch);
    		ch=getchar();
    		flag=1;
		}
		if(flag==1){
			m[i].a[j]='\0';
			m[i].n=1;
			i++;
			flag=0;
		}
    	ch=getchar();
	}
        p=i;
  
    for(i=0;i<p;i++){
    	for(j=i+1;j<p;j++){
    		if(strcmp(m[i].a,m[j].a)==0){
    			m[i].n+=m[j].n;
    			m[j].n=0;
			}
		}
	}
	
	for(i=0;i<p;i++){
		for(j=i+1;j<p;j++){
			if(strcmp(m[i].a,m[j].a)>0){
				swap(m[i].a,m[j].a);
				k=m[i].n;
				m[i].n=m[j].n;
				m[j].n=k;
			}
		} 
	}
	for(i=0;i<p;i++){
		if(m[i].n!=0){
			printf("%s %d\n",m[i].a,m[i].n);
		}
	}
	fclose(in);
}

