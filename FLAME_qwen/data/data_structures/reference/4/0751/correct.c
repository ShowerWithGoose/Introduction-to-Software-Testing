//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include<ctype.h>
//#define MAXWORD  1000
//char word[MAXWORD];
//struct node {
//    char word[MAXWORD];
//    int count;
//    struct node *link;
//} ; //单词表结构
//struct node *Wordlist = NULL; //单词表头指针
//int getWord(FILE *bfp,char *word);
//int searchWord(char *w);
//int insertWord( struct node *p, char *w);
//int getWord(FILE *bfp,char *word)
//{
//  char c;
//  c = fgetc(bfp);
//  while(c!= EOF)
//  {
//  if(!isalpha(c))
//  return -1;
//  else if(isalpha(c))
//  *word++ = c;
//  } 
// *word = '\0';
//return 0;
//}
//int insertWord(struct node  *p, char *w)
//{
//      struct node  *q;
//
//      q = (struct node * )malloc(sizeof(struct node));
//      if(q == NULL) return -1; //没有内存空间
//      strcpy(q->word, w);
//      q->count = 1;
//      q->link = NULL;              
//      if(Wordlist == NULL) //空链表
//           Wordlist = q;
//      else if (p == NULL){ //插入到头结点前
//           q->link = Wordlist;
//           Wordlist = q;
//       }
//       else {
//           q->link = p->link;
//           p->link = q;
//       }
//      return 0;
//}
//int searchWord(char *w)
//{
//struct  node *p, *q=NULL; //q为p的前序结点指针
//for(p=Wordlist; p != NULL; q=p,p=p->link){
//    if(strcmp(w, p->word) < 0) 
// break;
//    else if(strcmp(w, p->word) == 0){
//         p->count++;
//         return 0 ;
//    }
//}
//return insertWord(q, w);
//}
//int main()
//{
//    FILE *bfp;
//    struct node *p;
//	bfp = fopen("article.txt","r");
//    if( bfp == NULL){ //打开一个文件
//        fprintf(stderr, "%s can't open!\n" ,article);
//        return -1;
//     }
//     while( getWord(bfp,word)!=EOF)
//	 	//从文件中读入一个单词
//		if(searchWord(word) == -1) { //在单词表中查找插入单词
//		fprintf(stderr, "Memory is full!\n");
//		return -1;
//		}
//    for(p=Wordlist; p != NULL; p=p->link) //遍历输出单词表
//        printf("%s %d\n", p->word, p->count);
//    return 0;
//} 



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vocab
{
    char c[30];
    int count;
} x[1000], y;

int i, j, k, n, type;
char a[1026];

void tolowercase(struct vocab x[1000], int acount)
{
    for (i = 0; i < acount; i++)
    {
        for (j = 0; j < strlen(x[i].c); j++)
        {
            if (x[i].c[j] < 97)
                x[i].c[j] += 32;
        }
    }
}

void redone_position(struct vocab x[1000], struct vocab y, int acount)
{
    for (int i = 0; i < acount; i++)
    {
        for (int j = i + 1; j < acount; j++)
        {
            if (strcmp(x[i].c, x[j].c) == 0)
            {
                strcpy(x[j].c, "\0");
                x[i].count += x[j].count;
            }
            if (strcmp(x[i].c, x[j].c) > 0)
            {
                y = x[i];
                x[i] = x[j];
                x[j] = y;
            }
        }
    }
}
int main()
{
    FILE *in = fopen("article.txt", "r");
    i = 0, j = 0;
    type = 0;
    while (fgets(a, 1025, in) != NULL)
    {
        for (k = 0; k < strlen(a); k++)
        {
            if ((a[k] < 91 && a[k] > 64) || (a[k] > 96 && a[k] < 123))
            {
                x[i].c[j++] = a[k];
                type = 1;
            }
            else if (type != 0)
            {
                x[i].c[j] = '\0';
                x[i++].count = 1;
                j = type = 0;
            }
        }
    }
    n = i;
    tolowercase(x, n); // for(i=0;i<n;i++)printf("%s %d\n",x[i].c,x[i].count);
    redone_position(x, y, n);
    for (i = 0; i < n; i++)
    {
        if (strlen(x[i].c) != 0)
            printf("%s %d\n", x[i].c, x[i].count);
    }
    return 0;
}


