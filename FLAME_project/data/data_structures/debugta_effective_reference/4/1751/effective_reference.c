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
struct node* wordlist_cal;
struct node* q;
int j;
struct node* p0;
char a[50],str[50];
struct node* r;
int count=1;
char c;
int i,j,k;
int main(){
	in=fopen("article.txt","r");
while(fscanf(in,"%c",&a[0])!=EOF){//单词和单词间不一定有空格
    if(isalpha(a[0])!=0){
    	for(i=1;;i++){
        fscanf(in,"%c",&a[i]);
	    if(isalpha(a[i])==0) {	
	    break;		
		}	
	}
	memset(str,0,sizeof(str));
	for(j=0;j<i;j++){
		if(a[j]>='A' && a[j]<='Z')
		str[j]=a[j]+'a'-'A';
		else str[j]=a[j];
	}
	memset(a,0,sizeof(a));
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
		wordlist_cal=q;
	}
	else{
	if(strcmp(wordlist->word,q->word)>=0){//注意头指针 
			q->link=wordlist;
			wordlist=q;
	}
	else{
	for(wordlist_cal=wordlist;wordlist_cal!=NULL;p0=wordlist_cal,wordlist_cal=wordlist_cal->link){
	if(strcmp(q->word,wordlist_cal->word)<=0){
			p0->link=q;
			q->link=wordlist_cal;
			break;
	}
  }
	if(wordlist_cal==NULL){
	p0->link=q;
}		
}
}

}
for(wordlist_cal=wordlist;wordlist_cal!=NULL;){
	count=0;
	for(r=wordlist_cal;;r=r->link){
	if(r!=NULL){
		if(strcmp(r->word,wordlist_cal->word)==0){
			count++;
		}
		else{
			printf("%s %d\n",wordlist_cal->word,count);
			wordlist_cal=r;
			break;
		}
	}
	else{
		printf("%s %d\n",wordlist_cal->word,count);
		return 0;
	}			
	}
}
}

