#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct _Word
{               
    char s[55];
    int count;
    struct _Word *link;
}Word,*PWord;

PWord creatWord(char*);
PWord searchWord(PWord,char*);
PWord researchWord(PWord,char*);
PWord insertWord(PWord,PWord,PWord);
    
int main()   
{
    FILE *fp;
    fp=fopen("article.txt","r");
    
    int c;
    char str[55];
    char *p=str;
    PWord start=NULL;
    
    while((c=fgetc(fp))!=EOF)
    {
        if(isalpha(c))
        {
            *p=(char)tolower(c);
            p++;
        }
        else
        {
            *p='\0';
            p=str;
            PWord q,location=NULL;
            q=creatWord(str); // @@ 当str为空（连续非字母）时，仍创建空单词节点，应添加条件 if(str[0]!='\0') 才执行处理
            if(start==NULL)
                start=q;
            else
            {
                location=searchWord(start,str);
                if(location!=NULL)
                    (location->count)++;
                else
                {
                    location=researchWord(start,str);
                    start=insertWord(start,location,q);
                }
            }
        }
    }
    
    fclose(fp);
    
    for(PWord ptr=start;ptr!=NULL;ptr=ptr->link) // @@ 在C89标准中，不能在for循环内声明变量，应提前声明PWord ptr
        if(ptr->s[0]!='\0')
            printf("%s %d\n",ptr->s,ptr->count);
    
    return 0;
}

PWord creatWord(char *q)
{
    PWord here;
    here=(PWord)malloc(sizeof(Word));
    here->count=1;
    strcpy(here->s,q);
    here->link=NULL;
    return here;
}

PWord searchWord(PWord p1,char *q1)
{
    PWord z;
    for(z=p1;z!=NULL;z=z->link)
        if(strcmp(z->s,q1)==0)
            return z;
    return NULL;
}

PWord researchWord(PWord p2,char *q2)
{
    PWord z;
    for(z=p2;z->link!=NULL;z=z->link) // @@ 如果链表只有一个节点且p2->s < q2，则循环不执行，直接返回p2，这是正确的；但如果p2->s > q2，返回NULL，但insertWord处理NULL分支逻辑错误
        if(strcmp(z->link->s,q2)>0)
            if(strcmp(p2->s,q2)>0)
                return NULL;
            else
                return z;
    return z;

}

PWord insertWord(PWord p3,PWord here,PWord p4)
{
    if(here==NULL) // @@ 当here==NULL时，表示新单词应插入到链表头部（所有单词都大于它），但当前实现是将新节点插入到头节点之后，应改为 p4->link=p3; return p4;
    {
        p4->link=p3->link;
        p3->link=p4;
        return p3;
    }
    else
    {
        p4->link=here->link;
        here->link=p4;
        return p3;
    }
}