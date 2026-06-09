#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define max 32
struct node{
	char word[max];
    int count;
    struct node *link;
};
struct node *Wordlist=NULL;
int getword(FILE *fp,char *w);
int searchword(char *w);
int insertword(struct node *p,char *w);
int main(){
	char filename[32], word[max];
    FILE *fp;
    struct node *p;
    int i=0;
    scanf("%s", filename);
	for(i=110;i>0;i--);
if((fp = fopen("article.txt", "r")) == NULL){ 
fprintf(stderr, "%s can't open!\n", filename);
return -1; 
}
//从文件中读入一个单词
while( getword(fp,word) != EOF){
//在单词表中查找插入单词
if(searchword(word) == -1) { 
fprintf(stderr, "Memory is full!\n");
return -1; 
}
}
//遍历输出单词表
for(p=Wordlist; p != NULL; p=p->link)
printf("%s %d\n", p->word, p->count);
	return 0;
} 
int insertword(struct node *p, char *w){
    struct node *q;
    q = (struct node *)malloc(sizeof(struct node));
if (q == NULL) return -1; //没有内存空间
    strcpy(q->word, w);
    q->count = 1; q->link = NULL;
    if (Wordlist == NULL) //空链表
    Wordlist = q;
else if (p == NULL) { //插入到头结点前
q->link = Wordlist;
Wordlist = q;
} 
else { 
q->link = p->link;
p->link = q;
}
return 0; 
}
/*在链表中查找一单词，若找到，则次数加1；否则将该
单词插入到有序表中相应位置，同时次数置1*/
int searchword(char *w)
{
//q为p的前序结点指针
struct node *p, *q = NULL; 
for(p=Wordlist; p!=NULL; q=p, p=p->link)
{
if (strcmp(w, p->word) < 0)
break;
else if (strcmp(w, p->word) == 0) { 
p->count++;
return 0; 
} 
}
return insertword(q, w);
}
int getword(FILE *fp,char word[])
{
    int i=0;
    char temp;
    while((temp=fgetc(fp))!=EOF){
        if(isalpha(temp)){
            word[i]=tolower(temp);
            i++;
        }
        else if(i>0){//说明i中已经至少有一个字符
            word[i]='\0';
            return 0;
        }
    }
    return EOF;
}

