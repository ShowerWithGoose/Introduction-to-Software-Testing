#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
struct multinomial{
	int num;
    int fre;
};
typedef struct multinomial MUL;
MUL mul1[10000],mul2[10000],ans[10000];
int cmp(const void *i_1,const void *i_2){
    struct multinomial *c=(struct multinomial*)i_1;
    struct multinomial *d=(struct multinomial*)i_2;
    return d->fre-c->fre;
}
int main()
{
    int i=0,j=0,num=0,i_1,i_2,c;
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
    i_1=i;
    i_2=j;
    qsort(mul1,i,sizeof(MUL),cmp);
    qsort(mul2,j,sizeof(MUL),cmp);
    for(i=0;i<=i_1;i++)
    {
        for(j=0;j<=i_2;j++)
        {
            ans[num].num=mul1[i].num*mul2[j].num;
            ans[num].fre=mul1[i].fre+mul2[j].fre;
            num++;
        }
    }
    qsort(ans,num,sizeof(MUL),cmp);
    c=num;
    for(num=0;num<c;num++)
    {
        if(ans[num].fre==ans[num+1].fre&&ans[num].fre!=0)
        {
            ans[num+1].num=ans[num+1].num+ans[num].num;
			ans[num].num=0;
        }
    }
    for(num=0;num<c;num++)
	{
		if(ans[num].num!=0)
		{
			printf("%d %d ",ans[num].num,ans[num].fre);
		}
	}
    return 0;
}


