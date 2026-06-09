#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct multi{
    int num;
    int mi;
};
struct multi multi1[100];
struct multi multi2[100];
struct multi multi3[100];

int cmp ( const void *a , const void *b )
{
    return ( ( (struct multi*)b)->mi)-(( (struct multi*)a)->mi);
}

int main()
{
    //输入
    char c;
    int i=0;

    do{
        scanf("%d %d%c",&multi1[i].num,&multi1[i].mi,&c);
        i++;
    }while(c!='\n');
    int num1=i;
    i=0;
    
    do{
        scanf("%d %d%c",&multi2[i].num,&multi2[i].mi,&c);
        i++;
    }while(c!='\n');
    int num2=i;

    //运算
    int k=0;
    for(i=0;i<num1;i++)
    {
        for(int j=0;j<num2;j++)
        {
            multi3[k].num=multi1[i].num*multi2[j].num;
            multi3[k].mi=multi1[i].mi+multi2[j].mi;
            k++;
        }
    }
    int num3=k;
    
    //整合排序
    qsort(multi3,num3,sizeof(multi3[0]),cmp);

    for(i=0;i<num3;i++)
    {
        if(multi3[i].mi==multi3[i+1].mi)
        {
            multi3[i].num+=multi3[i+1].num;
            multi3[i+1].num=0;
        }
    }

    qsort(multi3,num3,sizeof(multi3[0]),cmp);

    for(i=0;i<num3;i++)
    {
        if(multi3[i].mi==multi3[i+1].mi)
        {
            multi3[i].num+=multi3[i+1].num;
            multi3[i+1].num=0;
        }
    }
    
    //output
    for(i=0;i<num3;i++)
    {
        if(multi3[i].num!=0)
        {
            printf("%d %d ",multi3[i].num,multi3[i].mi);
        }
    }
    
    system("pause");
    return 0;
}
