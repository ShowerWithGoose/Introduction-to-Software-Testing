#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
    char word[32];
    int fre;
    struct node* link;
}*Linklist;
Linklist getWord(FILE* in);
int searchc(char* list[],int n,char* word);
Linklist insertl(Linklist list,char *word,char **wlist,int n);
void bubble(Linklist list, int len);
void bubblearr(char** list, int len);
int main()
{
    FILE * in;
    in=fopen("article.txt","r");
    Linklist list0,p,q,list=NULL;
    int i,cnt =0;
    list0=getWord(in);
    char* wordlist[105]={NULL};
    list=(Linklist)malloc(sizeof(Linklist));
    memset(list,0,sizeof(struct node));
    strcpy(list->word,list0->word);
    list->fre=0;
    list->link=NULL;
    wordlist[0]=(char*)malloc(1024);
    memset(wordlist[0],0,1024);
    strcpy(wordlist[0],list0->word);
    cnt++;
    //list0是源文件内容 list是单词表1 wordlist是单词表2（数组） cnt是当前单词表长度
    for(p=list0,q=list;p!=NULL;p=(p->link))
    {
        if(searchc(wordlist,cnt,p->word)==1)
        {
            q=list;
            while(strcmp(q->word,p->word)!=0)
            {
                q=q->link;
            }
            q->fre++;
        }
        else
        {
            list=insertl(list,p->word,wordlist,cnt);
            cnt++;
            bubblearr(wordlist,cnt);
        }
    }
    bubble(list,cnt);
    p=list;
    for(i=0;i<cnt;i++)
    {
        if(strlen(p->word))
        {
            printf("%s",p->word);
            printf(" ");
            printf("%d\n",p->fre);
        }
        p=p->link;
    }
    return 0;
}
Linklist getWord(FILE* in)
{
    char w0[105]={0};
    char w[32]={0},nextw[32]={0};
    Linklist p,r,list=NULL;
    while(fscanf(in,"%s",w0)!=EOF)
    {
        memset(w,0,sizeof(w));
        memset(nextw,0,sizeof(nextw));
        int i,j,len;
        len=strlen(w0);
        for(i=0,j=0;i<len;i++)
        {
            if((w0[i]>='a'&&w0[i]<='z'))
            {
                w[j]=w0[i];
                j++;
            }
            else if((w0[i]>='A'&&w0[i]<='Z'))
            {
                w[j]=w0[i]+32;
                j++;
            }
            else if(((w0[i]>=0&&w0[i]<'A')||(w0[i]>'Z'&&w0[i]<'a')||(w0[i]>'z'&&w0[i]<128))&&(strlen(w)>0))
            break;
        }
        w[j]='\0';
        p=(Linklist)malloc(sizeof(Linklist));
        memset(p,0,sizeof(struct node));
        strcpy(p->word,w);
        p->link=NULL;
        if(list==NULL)
        list=p;
        else
        r->link=p;
        r=p;
        i++;
        int k=i,Flag=0;
        while(k<len)
        {
            if((w0[k]>='a'&&w0[k]<='z')||(w0[k]>='A'&&w0[k]<='Z'))
            {
                Flag=1;
                break;
            }
            k++;
        }
        while(Flag&&i<len)
        {
            for(j=0;i<len;i++)
            {
                if((w0[i]>='a'&&w0[i]<='z'))
                {
                    nextw[j]=w0[i];
                    j++;
                }
                else if((w0[i]>='A'&&w0[i]<='Z'))
                {
                    nextw[j]=w0[i]+32;
                    j++;
                }
                else if(((w0[i]>=0&&w0[i]<'A')||(w0[i]>'Z'&&w0[i]<'a')||(w0[i]>'z'&&w0[i]<128))&&(strlen(nextw)>0))
                break;
            }
            nextw[j]='\0';
            p=(Linklist)malloc(sizeof(Linklist));
            memset(p,0,sizeof(struct node));
            strcpy(p->word,nextw);
            p->link=NULL;
            if(list==NULL)
            list=p;
            else
            r->link=p;
            r=p;
            memset(nextw,0,sizeof(nextw));
            Flag=0;
            while(k<len)
            {
                if((w0[k]>='a'&&w0[k]<='z')||(w0[k]>='A'&&w0[k]<='Z'))
                {
                    Flag=1;
                    break;
                }
                k++;
            }
        }
    }
    
    return list;
}
int searchc(char* list[],int n,char* word)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(strcmp(word,list[mid])<0)
        high = mid - 1;
        else if(strcmp(word,list[mid])>0)
        low = mid + 1;
        else
        return 1;
    }
    return -1;
}
Linklist insertl(Linklist list,char *word,char **wlist,int n)
{
    Linklist p,r,q;
    r=list;
    p=list->link;
    while(p!=NULL)
    {
        r=p;
        p=p->link;
    }
    q=(Linklist)malloc(sizeof(Linklist));
    memset(q,0,sizeof(struct node));
    strcpy(q->word,word);
    q->fre=1;
    q->link=NULL;
    r->link=q;
    wlist[n]=(char*)malloc(1024);
    memset(wlist[n],0,1024);
    strcpy(wlist[n],word);
    
    return list;
}
void bubble(Linklist list, int len)
{
    int i,j;
    Linklist r,p;
    char swapword[100];
    int swapnum=0;
		for(i=0;i<len-1;i++)
		{
            r=list;
            p=list->link;
			for(j=0;j<len-1;j++)
			{
                if(p!=NULL&&strcmp(r->word,p->word)>0)
				{
                    strcpy(swapword,p->word);
                    strcpy(p->word,r->word);
                    strcpy(r->word,swapword);
                    swapnum=p->fre;
                    p->fre=r->fre;
                    r->fre=swapnum;
				}
                if(p==NULL)
                break;
                r=p;
                p=p->link;
			}
		}
}
void bubblearr(char** list, int len)
{
    int i,j;
    char swapword[100];
		for(i=0;i<len-1;i++)
		{
			for(j=0;j<len-1;j++)
			{
                if(strcmp(list[j],list[j+1])>0)
				{
                    strcpy(swapword,list[j+1]);
                    strcpy(list[j+1],list[j]);
                    strcpy(list[j],swapword);
				}
			}
		}
}


