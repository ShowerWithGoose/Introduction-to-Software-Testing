# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>
// # include<windows.h>
typedef struct polynomial
{
    int a;
    int n;
    struct polynomial *pNext;
}Poly,*pPoly;
pPoly Sort_List(pPoly);
int main()
{
    pPoly po1=(pPoly)malloc(sizeof(Poly));
    pPoly po2=(pPoly)malloc(sizeof(Poly));
    pPoly res=(pPoly)malloc(sizeof(Poly));//set list
    int a,n;
    char c;
    pPoly pTail;
    pPoly pNew;
    int len=0;
    //Read
    pTail=po1;
    pTail->pNext=NULL;
    while(1)
    {
        scanf("%d%d",&a,&n);
        c=getchar();
        pNew=(pPoly)malloc(sizeof(Poly));
        pTail->pNext=pNew;
        pNew->a=a;
        pNew->n=n;
        pTail=pNew;
        pTail->pNext=NULL;
        if(c=='\n')
            break;
    }
//    printf("right after while1\n");
    pTail=po2;
    pTail->pNext=NULL;
    while(1)
    {
        scanf("%d%d",&a,&n);
        c=getchar();
        pNew=(pPoly)malloc(sizeof(Poly));
        pTail->pNext=pNew;
        pNew->a=a;
        pNew->n=n;
        pTail=pNew;
        pTail->pNext=NULL;
        if(c=='\n')
            break;
    }
// printf("right after while2\n");
    //Multiply
    pTail=res;
    pTail->pNext=NULL;
    for(pPoly i=po1->pNext;i;i=i->pNext)
        for(pPoly j=po2->pNext;j;j=j->pNext)
        {
            pNew=(pPoly)malloc(sizeof(Poly));
            pTail->pNext=pNew;
            pNew->a=i->a*j->a;
            pNew->n=i->n+j->n;
            // printf("%d: a=%d n=%d\n",++len,pNew->a,pNew->n);
            // printf("ia=%d ja=%d in=%d jn=%d\n\n",i->a,j->a,i->n,j->n);
            pTail=pNew;
            pTail->pNext=NULL;
        }
    //Edit
    res->pNext=Sort_List(res->pNext);
    for(pPoly i=res->pNext;i->pNext;i=i->pNext)
        while(i->n == i->pNext->n)
        {
            i->a+=i->pNext->a;
            pPoly temp=i->pNext;
            i->pNext=i->pNext->pNext;
            free(temp);
        }
    // output
    for(pPoly i=res->pNext;i;i=i->pNext)
    {
        if(i->a != 0)
        printf("%d %d ",i->a,i->n);
    }
    // system("pause");
    return 0;
}
pPoly Sort_List(pPoly pHead)
{
    pPoly pfirst=NULL,psecond=NULL,pend=NULL;
    pfirst=pHead;
	psecond=pHead;
	int temp;
    while(pfirst != pend)           //外循环
	{
        while(pfirst->pNext != pend)//内循环
		{
            if(pfirst->n < pfirst->pNext->n)
			{
                temp=pfirst->a;  
                pfirst->a=pfirst->pNext->a;
                pfirst->pNext->a=temp;
                temp=pfirst->n;  
                pfirst->n=pfirst->pNext->n;
                pfirst->pNext->n=temp;
            }
               pfirst=pfirst->pNext;
        }
        pend=pfirst;//减少最后的已排好的循环
        pfirst=pHead;
    }
    return pHead;
}
