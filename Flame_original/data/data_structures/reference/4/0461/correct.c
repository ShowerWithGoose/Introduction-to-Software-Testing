#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    char word[100];
    int count;
    int flag;
}words[100];
int cmp(const void *a,const void *b) //根据字典序排序
{
	struct node *aa=(struct node*)a;
	struct node *bb=(struct node*)b;
	return strcmp(aa->word,bb->word);
}
int main()
{
    char c,s[100];
    int i=0,j=0;
    FILE *in;
    in=fopen("article.txt","r");
    while((c=fgetc(in))!=EOF)
    {
        if(isalpha(c))
        {
            c=tolower(c);
            s[j]=c;
            j++;
        }
        else{
            if(j!=0){
                s[j]='\0';
                strcpy(words[i].word,s);
                i++;
            }
            j=0;
        }
    }

    qsort(words,i,sizeof(words[0]),cmp);

    int n=i;
    for(j=0;j<n;j++)
    {
        words[j].count=1;
        if(strcmp(words[j].word,words[j+1].word)==0||strcmp(words[j].word,words[j-1].word)==0)
            words[j].flag=1;//相同的词做记号
        else
            words[j].flag=0;
    }
    int k;
    for(j=0;j<n;j++)
    {
        if(words[j].flag==1)
        {
            for(k=j+1;k<n;k++)
            {
                if(words[k].flag==1&&strcmp(words[j].word,words[k].word)==0)
                {
                    words[j].count++;
                    words[k].flag=2;//删掉重复词
                }
                else
                {
                    k--;
                    j=k;
                    break;
                }
            }
        }
    }
    for(j=0;j<n;j++)
    {
        if(words[j].flag==2)
            continue;
        else
            printf("%s %d\n",words[j].word,words[j].count);
    }
    fclose(in);
    return 0;
}

