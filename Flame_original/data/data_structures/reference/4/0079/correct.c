#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int count;
	char word[50];
	struct node *next;
};

struct node *head=NULL;
int getWord(FILE *fop,char *w);
int searchWord(char *w);
int insertWord( struct node *p, char *w);
int main()
{
	char word[50];
    FILE *fop;
    struct node *p;
   char filename[32]={"article.txt"};
    if((fop = fopen(filename, "r")) == NULL){ //打开一个文件
        fprintf(stderr, "%s  can’t open!\n",filename);
        return -1;
    }
    
    while( getWord(fop,word) != EOF) //从文件中读入一个单词
        if(searchWord(word) == -1) { //在单词表中查找插入单词
            fprintf(stderr, "Memory is full!\n");
            return -1;
        }
    for(p=head; p != NULL; p=p->next) //遍历输出单词表
        printf("%s %d\n", p->word, p->count);
		return 0;
}
int getWord(FILE *fop,char word[])
{
	int i=0;
	char temp;
	while((temp=fgetc(fop))!=EOF){
		if(isalpha(temp)){
			word[i]=tolower(temp);
			i++;
		}
		
		else if(i>0)
			{
				word[i]='\0';//单词收尾
				return 0; 
			}
	
	}return EOF;
}
int searchWord(char *w)
{
    struct  node *p, *q=NULL; //q为p的前序结点指针
    for(p=head; p != NULL; q=p,p=p->next){
        if(strcmp(w, p->word) < 0)
            break;
        else if(strcmp(w, p->word) == 0){
            p->count++;
            return 0 ;
        }
    }
    return insertWord(q, w);
}
int insertWord(struct node  *p, char *w)
{
    struct node  *q;

    q = (struct node * )malloc(sizeof(struct node));
    if(q == NULL) return -1; //没有内存空间
    strcpy(q->word, w);
    q->count = 1;
    q->next = NULL;
    if(head == NULL) //空链表
        head = q;
    else if (p == NULL){ //插入到头结点前
        q->next = head;
        head = q;
    }
    else {
        q->next = p->next;
        p->next = q;
    }
    return 0;
}





