#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct xiang
{
    long long xishu;//xishu
    long long zhishu;//zhishu
};

int cmp(const void *p,const void *q)
{
 	struct xiang *pp = (struct xiang*) p;
	struct xiang *qq = (struct xiang*) q;

	if((*pp).zhishu<(*qq).zhishu)
        return 1;
    else if((*pp).zhishu==(*qq).zhishu)
        return 0;
    return -1;
}

int main()
{
    struct xiang item1[100]={};
    struct xiang item2[100]={};

    int it1[200]={};
    int it2[200]={};

    int i=0;
    while(scanf("%lld",&it1[i]))
    {
        if(getchar()=='\n')
        {
            break;
        }
        i++;
    }
    i=0;
    while(scanf("%lld",&it2[i]))
    {
        if(getchar()=='\n')
        {
            break;
        }
        i++;
    }

    int j=0;
    for(i=0;it1[i]!='\0';i+=2)
    {
        item1[j].xishu=it1[i];
        item1[j].zhishu=it1[i+1];
        j++;
    }

    j=0;
    for(i=0;it1[i]!='\0';i+=2)
    {
        item2[j].xishu=it2[i];
        item2[j].zhishu=it2[i+1];
        j++;
    }

    //ПаіЛ
    struct xiang item3[100];
    int k=0;
    for(i=0;item1[i].xishu!='\0';i++)
    {
        for(j=0;item2[j].xishu!='\0';j++)
        {
            item3[k].xishu=item1[i].xishu*item2[j].xishu;
            item3[k].zhishu=item1[i].zhishu+item2[j].zhishu;
            k++;
        }
    }
    qsort(item3, k, sizeof(item3[0]), cmp);

    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k;j++)
        {
            if(item3[j].zhishu==item3[i].zhishu)
            {
                item3[i].xishu+=item3[j].xishu;
                item3[j].xishu=0;
            }
        }
    }

    for(i=0;i<k;i++)
    {
        if(item3[i].xishu!=0)
        {
            printf("%lld %lld ",item3[i].xishu, item3[i].zhishu);
        }
    }




    /*
    char it1[200];
    char it2[200];

    gets(it1);
    gets(it2);

    int i=0,j=0;
    for(i=0;it1[i]!='\n';i+=2)
    {
        item1[j].coef=it1[i];
        item1[j].expo=it1[i+1];
    }
    j=0;

    for(i=0;it2[i]!='\n';i+=2)
    {
        item2[j].coef=it2[i];
        item2[j].expo=it2[i+1];
    }

    */





    return 0;
}

