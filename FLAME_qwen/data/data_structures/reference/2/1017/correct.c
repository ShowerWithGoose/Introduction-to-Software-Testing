#include<stdio.h>//5.3¼ÆËãÆ÷
#include<stdlib.h>
#include<string.h>
char op[100];
struct zbc{
	
};
struct extree{
	int item;
	char write;
	struct extree *left;
	struct extree *right;
};
int M=100;
typedef struct extree Extree ;
typedef struct extree * Extreeptr; 
struct extree *ip[100];
int top,Otop;
void initiate(){
	top=-1;
	Otop=-1;
}
void getstree(char ch[]);
void  foundtree(char ch[]);
void pushnum(int n);
char topop();
void pushop(char a);

void pushOP(char a);
char popop();
void transtree(char a[],char b[]);
Extreeptr popit();
int main(){

	initiate();
		char ch[100],a[100],b[100];
			gets(ch); 
			int j=0;
			for(int i=0;i<(int)strlen(ch);i++){
				if(ch[i]!=' '){
					a[j++]=ch[i];
				}
			}
			transtree(a,b);		
			getstree(b);	
			Extreeptr sad=ip[top];
		
			printf("%d",ip[top]->item);
	return 0;
	
} 
void getstree(char ch[]){
	
	int i=0,m=0;
	while(ch[i]!='\0'){
		if(ch[i]==' '){
			continue;
		}
		if(ch[i]>='0'&&ch[i]<='9'){
			do{
			m=m*10+ch[i]-'0';
			i++;
			}while(ch[i]>='0'&&ch[i]<='9');
		
			pushnum(m);
				m=0;
			
		}
		if(ch[i]=='+'||ch[i]=='-'||ch[i]=='*'||ch[i]=='/'){
			pushOP(ch[i]);
	
		}
		i++;
	}
}
void transtree(char a[],char b[]){
	int i=0,j=0;
	char c;
	for(i=0;a[i]!='=';i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[j++]=a[i];
			if(a[i+1]<'0'||a[i+1]>'9'){
				b[j++]=' ';
			}
		}
		if(a[i]==')'){
			while((c=popop())!='('){
				b[j++]=c;		
		}	
	}
	if(a[i]=='('){
		pushop(a[i]);
	}
	if(a[i]=='+'||a[i]=='-'){
		while(topop()=='*'||topop()=='/'||topop()=='-'||topop()=='+'){
			b[j++]=popop();
			
		}
		pushop(a[i]);
	}
	if(a[i]=='*'||a[i]=='/'){
		while(topop()=='*'||topop()=='/'){
			b[j++]=popop();
		}
		pushop(a[i]);
	}
}
while(Otop!=-1){
	b[j++]=popop();
}
b[j]='\0';
}
void pushnum(int n){
	if(top==M){
		printf("error");
	}
	else {
		top++;
		ip[top]=(Extreeptr)malloc(sizeof(Extree));
		ip[top]->item=n;
		ip[top]->write='o';
		ip[top]->left=NULL;
		ip[top]->right=NULL;
	}
}
void pushop(char a){
	if(Otop==M){
		printf("error");
	}
	else {
		Otop++;
		op[Otop]=a;
	}
}
void pushOP(char a){
	Extreeptr c,d;
	c=popit();
	d=popit();
	if(top==M){
			printf("error");
		}
		else {
			top++;
			ip[top]=(Extreeptr)malloc(sizeof(Extree));
		
			ip[top]->write=a;
			ip[top]->right=c;
			ip[top]->left=d;
			if(a=='+')
			 ip[top]->item=c->item+d->item;
			if(a=='-')
			 ip[top]->item=d->item-c->item;
			if(a=='*')
			 ip[top]->item=c->item*d->item;
			if(a=='/')
	    	 ip[top]->item=d->item/c->item;
		}
}
char popop(){
	if(Otop==-1){
			printf("error");
		}
		else{
			return op[Otop--];
		}
}
char topop(){
	return op[Otop];
}
Extreeptr popit(){
	if(top==-1){
		printf("error");
	}
	else{
		return ip[top--];
	}
}

