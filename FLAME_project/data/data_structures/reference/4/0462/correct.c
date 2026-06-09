#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct code{
    char word[200];
    int cnt;
}list[100000];

int SearchWord(struct code list[],char getword[],int l,int r)
{
    if(l>r)
        return -1;
    int mid = (l+r) / 2;
    if(strcmp(list[mid].word,getword)<0)
        return SearchWord(list,getword,mid+1,r);
    if(strcmp(list[mid].word,getword)>0)
        return SearchWord(list,getword,l,mid-1);
    if(strcmp(list[mid].word,getword)==0)
        return mid;
}

int cmp(const void *a, const void *b)//еепР
{
    struct code c = *(struct code *)a;
    struct code d = *(struct code *)b;
    if(strcmp(c.word,d.word)<0)
        return -1;
    else if(strcmp(c.word,d.word)>0)
        return 1;
    return 0;
}

int main()
{
    FILE *in;
    if((in=fopen("article.txt","r"))==NULL)
    {
        printf("文件打开失败");
        return 0;
    }
    int max=0;
    int hold;
    char getword[200];
    while(fscanf(in,"%s",getword)!=EOF)
    {
        char newword[200][200];
        int j=0,k=0;
        for(int i=0;i<strlen(getword);i++)
        {
            if(getword[i]>='a'&&getword[i]<='z')
                newword[j][k++]=getword[i];
            else if(getword[i]>='A'&&getword[i]<='Z')
                newword[j][k++]=getword[i]-'A'+'a';
            else
            {
                if(k==0)
                    continue;
                newword[j][k++]='\0';
                j++;
                k=0;
            }
        }
        if(j==0&&k==0)
            continue;
        if(k!=0)
        {
            newword[j][k++]='\0';
            j++;
        }
        for(int i=0;i<j;i++){
        if(SearchWord(list,newword[i],1,max)<0)
        {
            strcpy(list[++max].word,newword[i]);
            list[max].cnt=1;
            qsort(list+1,max,sizeof(list[1]),cmp);
        }
        else
        {
            hold=SearchWord(list,newword[i],1,max);
            list[hold].cnt++;
        }
        }
    }
    for(int i=1;i<=max;i++)
    {
        printf("%s %d\n",list[i].word,list[i].cnt);
    }
    fclose(in);

    return 0;
}

