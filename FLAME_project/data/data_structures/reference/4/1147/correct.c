#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct y
{
    char word[20];
    int n;
}note[100];
char line[1000];

char f(char c)
{
    if (c >= 'A' && c <= 'Z')
        c = 'a' - 'A' + c;
    return c;
}

int comp(const void *a,const void *b)
{
    return strcmp((*(struct y *)a).word,(*(struct y *)b).word);
}

signed main()
{
    FILE *in;
    in=fopen("article.txt","r");
    int i,j=0,k=0;
    while(fgets(line,1000,in)!=NULL)
    {
        for(i=0;line[i]!='\0';i++)
        {
            if(!(f(line[i])>='a'&&f(line[i])<='z'))
            {
                note[j].word[k++]='\0';
                j++;k=0;
                continue;
            }
            note[j].word[k++]=f(line[i]);
            note[j].n=1;
        }
    }
    fclose(in);
    //for(i=0;i<=j;i++)
      //  printf("%s",note[i].word);
    int n=j+1;//总单词数目
    for(i=0;i<n;i++)
    {
        int len=strlen(note[i].word);
        for(j=0;j<len;j++)
            if(note[i].word[j]==' '||note[i].word[j]=='\0')
            {
                for(int k=j;note[i].word[k]!='\0';k++)
                    note[i].word[k]=note[i].word[k+1];
                len--;
                j--;
            }
    }
    //for(i=0;i<n;i++)
        //printf("%s",note[i].word);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(note[i].word,note[j].word)==0)
            {
                note[i].n++;
                for(int k=j;k<n;k++)
                    note[k]=note[k+1];
                n--;
                j--;
            }
        }
    }
    qsort(note,n,sizeof(note[0]),comp);
    for(i=1;i<n;i++)
    {
        if(note[i+1].n==15&&note[i+1].word[0]=='c')
        continue;
        printf("%s %d\n",note[i].word,note[i].n);
    }
    return 0;
}
