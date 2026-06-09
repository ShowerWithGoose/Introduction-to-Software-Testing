#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct Trienode{
    int asc;        //这个结点是哪个字母, 其实没用，因为可以从下标得到
    struct Trienode *kid[26] ;
    int wordnum ;  //以这个结点结尾的单词数
    int nodenum ; //这是第几个结点
} Node;

char word[100];
char string[10000];
int len,wordlen;
int nodecnt; //这是第几个结点
char output[1000];
Node* root;

Node* creatnode()
{
    Node*p = (Node*)malloc(sizeof(Node));
    p->asc = -1;
    p->nodenum  =0;
    p->wordnum  =0;
    memset(p->kid,0,26*sizeof(Node*));
    return p;
}

void insert()
{
    Node *thisnode = root;
    for (int i = 0; i < wordlen; i++)
    {
        int alph = (int)(word[i] - 'a');
        if(thisnode->kid[alph] == NULL)
            thisnode->kid[alph] = creatnode();
        thisnode = thisnode->kid[alph];
        // thisnode->wordnum ++;
    }
    thisnode->wordnum++;
}

void print(Node *p, int n)
{
    if(p->wordnum) 
    {
        for(int i=0;i<n;++i) 
            putchar(output[i]);
        printf(" %d\n",p->wordnum);
    }
    for(int i=0;i<26;++i)
    {
        if((p->kid)[i] == NULL)
            continue;
        output[n] = i+'a';
        print((p->kid)[i],n+1);
    }
    return ;
}

void lower()
{
    for (int i = 0; i < len; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
            string[i] = string[i] + ('a' - 'A');
    }
}
int main()
{   
    root =  creatnode();
    FILE *in = fopen("article.txt", "r+");
    while(fgets(string, 10000, in))
    {   
        len = strlen(string);
        lower();
        for(int i =0 ;i<len;)
        {   
            int s = 0;
            int j = 0;
            if(string[i]>='a' && string[i]<='z')
            {
                for( j = i;j<len;j++)
                {
                    if(string[j]>='a' && string[j]<='z')
                        word[s++] = string[j];
                    else 
                        break;
                }
                i = j;
                word[s] = '\0';
                wordlen = s;
                insert();
            }else
                i++;
        }
    }
    print(root,0);
    return 0;
}
