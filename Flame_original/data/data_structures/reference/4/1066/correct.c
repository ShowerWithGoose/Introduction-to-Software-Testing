#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct count 
{
    char* word;
    int frequency;
};
struct count* ptr[10000];
char* readin(FILE *);
int cmp(const void*, const void*);
int isword(char*);

int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    char *str;
    int n=0;
    ptr[0]=(struct count*)malloc(sizeof(struct count));
    ptr[0]->word="";
    while ((str=readin(in))!=NULL)
    {
        int flag=0;
        for(int i=0;i<=n;i++)
        {
            if(0==strcmp(str,ptr[i]->word))
            {
                (ptr[i]->frequency)++;
                flag=1;
                free(str);
                break;
            }
            
        }
        if(0==isword(str)&&0==flag)
        {
            free(str);
            continue;
        }
        if(0==flag)
        {
            n++;
            ptr[n]=(struct count*)malloc(sizeof(struct count));
            ptr[n]->frequency=1;
            ptr[n]->word=str;
       }
    }
    qsort(ptr+1,n,sizeof(*ptr),cmp);
    for(int i=1;i<=n;i++)
    {
        printf("%s %d\n",ptr[i]->word,ptr[i]->frequency);
        free(ptr[i]->word);
        free(ptr[i]);
    }
    fclose(in);
    system("pause");
    return 0;
}

char* readin(FILE* fp)
{
    char letter;
    char letters[30];
    memset(letters,0,sizeof(char)*30);
    int n=1;
    int flag=0;
    while ((letter=fgetc(fp))!=EOF)
    {
        flag=1;
        if('A'<=letter&&'Z'>=letter)
        {
            letter=letter-'A'+'a';
        }
        if('a'<=letter&&'z'>=letter)
        {
            letters[n-1]=letter;
            n++;
            continue;
        }
        else
        {
        letter=1;
        n++;
        break;
        }
        
    }
    char* pt=(char*)malloc(n*sizeof(char));
    memset(pt,0,sizeof(char)*n);
    if(1==letter&&2==n)
        *(pt)=letter;
    else
        strncpy(pt,letters,n-1);
    letters[n-1]=0;
    if(0==flag)return NULL;
    if(1==flag)return pt;
}

int cmp(const void* pt1, const void* pt2)
{
    if(0<strcmp((*(struct count**)pt2)->word,(*(struct count**)pt1)->word))return -1;
    if(0>strcmp((*(struct count**)pt2)->word,(*(struct count**)pt1)->word))return 1;
    return 0;
}

int isword(char* str)
{
    int re=1;
    for(int i=0;i<=strlen(str)-1;i++)
    {
        if((*(str+i))<'a'||(*(str+i))>'z')re=0;
        break;
    }
    return re;
}


