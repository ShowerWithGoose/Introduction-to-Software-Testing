#include<stdio.h>//按字典序构建链表再输出 
#include<string.h>//注意不一定是“” 
#include<stdlib.h>
#include<ctype.h>
FILE *in;
struct node{
	char word[50];
	struct node* link;
};
struct node* wordlist=NULL;
struct node* p;
struct node* q;
int j;
struct node* p0;
char s[50],str[50];
struct node* r;
int count=1;
char c;
int i,j,k;
int main(){
	in=fopen("article.txt","r");
while(fscanf(in,"%c",&s[0])!=EOF){//单词和单词间不一定有空格
    if(isalpha(s[0])!=0){
    	for(i=1;;i++){
        fscanf(in,"%c",&s[i]);
	    if(isalpha(s[i])==0) {	
	    break;		
		}	
	}
	memset(str,0,sizeof(str));
	for(j=0;j<i;j++){
		if(s[j]>='A' && s[j]<='Z')
		str[j]=s[j]+'a'-'A';
		else str[j]=s[j];
	}
	memset(s,0,sizeof(s));
	str[i]='\0';
	q=(struct node *)malloc(sizeof(struct node));
	q->link=NULL;
	strcpy(q->word,str);
//	printf("%s",q->word);
	} 
	else continue;
//	memset(str,0,sizeof(str));//注意sizeof写什么 
//	for(i=0;i<strlen(s);i++){
//		if(isalpha(s[i])!=0) break;
//	}
//	for(j=i;j<strlen(s);j++){
//		if(isalpha(s[j])==0)
//		break;
//	}
//	if(i==strlen(s))continue;//注意空 

//	for(k=i;k<j;k++){
//		if(s[k]<='Z' && s[k]>='A') 
//		str[k-i]=s[k]-'A'+'a';
//		else str[k-i]=s[k];
//	}
//	str[k-i]='\0';
//	strcpy(q->word,str);
//	printf("%s",q->word); 
	if(wordlist==NULL){
		wordlist=q;
		p=q;
	}
	else{
	if(strcmp(wordlist->word,q->word)>=0){//注意头指针 
			q->link=wordlist;
			wordlist=q;
	}
	else{
	for(p=wordlist;p!=NULL;p0=p,p=p->link){
	if(strcmp(q->word,p->word)<=0){
			p0->link=q;
			q->link=p;
			break;
	}
  }
	if(p==NULL){
	p0->link=q;
}		
}
}

}
for(p=wordlist;p!=NULL;){
	count=0;
	for(r=p;;r=r->link){
	if(r!=NULL){
		if(strcmp(r->word,p->word)==0){
			count++;
		}
		else{
			printf("%s %d\n",p->word,count);
			p=r;
			break;
		}
	}
	else{
		printf("%s %d\n",p->word,count);
		return 0;
	}			
	}
}
}

