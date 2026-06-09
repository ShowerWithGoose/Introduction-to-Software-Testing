//读入  最后再排序！直接插入（对比下按顺序插入不会减少时间复杂度   其实可以减少最后的时间复杂度）
//库函数的使用不准确！常常使用错误！
#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct elem{
    char a[20];//看看够不够
    int len;
}word[10000];
char input[20];

int cmp(const void *p1,const void *p2)
{
    char *c1=((struct elem *)p1)->a;
    char *c2=((struct elem *)p2)->a;
    if(strcmp(c1,c2)<0) return -1;
    return 1;
}
void findAndAdd(int *n,char *input)//最后一个就是n-1
{
    for(int i=0;i<(*n);i++)
    {
        if(!strcmp(input,word[i].a))
        {
            word[i].len++;
            return ;
        }
    }
    word[(*n)].len=1;
    strcpy(word[(*n)++].a,input);
    return ;
}
int main()
{
    int num=0,flag=0,i;
    char c;
    FILE *in;
    in=fopen("article.txt","r");

    //int n=100;
    //while(n--)
    //printf("%c\n",fgetc(in));

    do{

    flag=0;//标志数据初始化一下！
    do{//printf("01 %c %d\n",c=fgetc(in),isdigit(c));
    if((c=fgetc(in))==EOF){
        flag=1;
        break;}
    }while(!isalpha(c)&&!flag);//对int可以么？
    if(flag) break;

        //printf("%d ",num);
        i=0;
        while(isalpha(c))
        {
            input[i++]=tolower(c);//int 赋值给 char ?
            if((c=fgetc(in))==EOF)
            {
                flag=1;
                break;
            }
        }
        input[i]='\0';       //一个文件都没有？
        findAndAdd(&num,input);
    }while(!flag);

    qsort(word,num,sizeof(word[0]),cmp);

    for(int i=0;i<num;i++)
    {
        printf("%s %d\n",word[i].a,word[i].len);
    }

    return 0;
}

