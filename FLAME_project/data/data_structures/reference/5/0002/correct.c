#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
struct multinomial{
	int num;
    int fre;
};
typedef struct multinomial MUL;
MUL mul1[10000],mul2[10000],mul[10000];
int cmp(const void *a,const void *b){
    struct multinomial *c=(struct multinomial*)a;
    struct multinomial *d=(struct multinomial*)b;
    return d->fre-c->fre;
}
int main()
{
    int i=0,j=0,k=0,a,b,c;
    char s;
    scanf("%d%d%c",&mul1[i].num,&mul1[i].fre,&s);
    while(s!='\n')
    {
		i++;
        scanf("%d%d%c",&mul1[i].num,&mul1[i].fre,&s);
	}
	scanf("%d%d%c",&mul2[j].num,&mul2[j].fre,&s);
    while(s!='\n')
    {
		j++;
        scanf("%d%d%c",&mul2[j].num,&mul2[j].fre,&s);
	}
    a=i;
    b=j;
    qsort(mul1,i,sizeof(MUL),cmp);
    qsort(mul2,j,sizeof(MUL),cmp);
    for(i=0;i<=a;i++)
    {
        for(j=0;j<=b;j++)
        {
            mul[k].num=mul1[i].num*mul2[j].num;
            mul[k].fre=mul1[i].fre+mul2[j].fre;
            k++;
        }
    }
    qsort(mul,k,sizeof(MUL),cmp);
    c=k;
    for(k=0;k<c;k++)
    {
        if(mul[k].fre==mul[k+1].fre&&mul[k].fre!=0)
        {
            mul[k+1].num=mul[k+1].num+mul[k].num;
			mul[k].num=0;
        }
    }
    for(k=0;k<c;k++)
	{
		if(mul[k].num!=0)
		{
			printf("%d %d ",mul[k].num,mul[k].fre);
		}
	}
    return 0;
}


