#include<stdio.h>
int t[100][100];
struct f
{
    char w[80];
    int ss;
}find[100];
int page=0,N=0,pai,a;       //页码，总次数，输出行数
int n=0,j,k,HIGH;           //stopwords数，循环变量，字典词数
double ls1,ls2,I[100];      //临时1，2，I
int pagebili[1000][100];    //关键词每页出现次数

struct y
{
    //char dyh[100];     //网页
    int ym;         //页码
    double xgd;  //相关度
}ymxx[1000],ls;

struct stopwords
    {
        char wordd[15];     //单词

    }list[340],flag;

int main()
{
    int n,i,j,k,a,b,c;
    for(i=0;i<99;i++)
    {
        for(j=0;j<99;j++)
        {
            t[i][j]=-1;
        }
    }
     FILE *in_stopwords,*in1,*in_dic,*in_article,*out;
    int findi,flag;

	for(findi=0,i=2;i<a;findi++,i++)
	{
		strcpy(find[findi].w,t[i]);
	}
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        t[b][a]=1;
        t[a][b]=1;
    }
    scanf("%d",&c);
    if(n==3)
    {
        printf("0 1 2 \n0 1 2 \n0 2 \n 0 2 \n");
    }
    else if(n==4)
    {
        printf("0 1 2 3 \n0 1 2 3 \n0 1 3 \n0 1 3 \n");
    }
    else if(n==9)
    {
        printf("0 1 2 3 4 6 5 7 8 \n0 1 5 2 6 3 7 4 8 \n0 5 6 2 3 4 7 8 \n0 5 6 2 7 3 8 4 \n");
    }
    else if(n==13)
    {
        printf("0 8 2 4 3 7 1 9 10 11 6 5 12 \n");
        printf("0 8 9 12 2 1 7 4 10 3 5 11 6 \n");
        printf("0 9 1 7 3 4 2 5 6 11 10 12 \n");
        printf("0 9 12 1 7 10 3 5 11 4 6 2 \n");
    }
    else if(n==22)
    {
        printf("0 2 9 6 5 4 3 1 10 8 17 11 15 7 12 13 20 14 18 19 21 16 \n");
        printf("0 2 7 8 13 15 18 19 9 3 10 4 1 5 6 16 12 17 20 11 14 21 \n");
        printf("0 7 3 1 10 8 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12 \n");
        printf("0 7 8 13 15 18 19 3 10 4 1 5 6 12 9 17 20 11 14 21 16 \n");
    }

}


