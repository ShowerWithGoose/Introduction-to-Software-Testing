#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 1000
struct time
{
    char s[40];
    int t;
};
struct time ti[7000];
void left(struct time p[],int n,int N)
{
    for(int i=n;i<N;i++)
    {
        strcpy(p[i].s,p[i+1].s);
        p[i].t=p[i+1].t;
    }
}
void record(char* p,int *re,int k)
{
    int temp=0,l,num=0;
    l=strlen(p);

    for(int i=0;i<l;i++)
    {
        if(p[i]>='a'&&p[i]<='z')
        {
            ti[k].s[temp]=p[i];
            temp++;

        }
        else//if(p[i]==' ')
        {
            temp=0;
            ti[k].t=1;
            k++;
            num++;   //每遇到一次空格，就将结构体数组向后移一位，输入完毕后词汇个数比k大1
        }

    }

    //k++;
    num++;//弥补最后一次没有空格而漏计的个数 k最终为记录的单词个数
    ti[k].t=1;

    //printf("%d",k);
    //temp=0;

    *re=num; //*re是单词的个数


}
void ink(int k)
{
    //int k2=k;//temp=0,
    int i=1;
    while(i<k)
    {/*
        if(strcmp(ti[i-1].s,ti[i].s)==0)
        {
            ti[i-1].t+=ti[i].t;
            //left(ti,i,k2);
            strcpy(ti[i].s,'1');
            //i--;
            k2--;
        }*/
        for(int j=i-1;j>=0;j--)
            {
              if(strcmp(ti[i].s,ti[j].s)==0)
              {
                ti[j].t+=ti[i].t;
                //left(ti,i,k2);
                strcpy(ti[i].s,"1");
                //temp++;
                //break;
              }
              else continue;
            }
        /*if(temp==1)
        {
            i--;
            temp=0;
            k2--;
        }*/
        i++;
    }
}
void turn(char s[])
{
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='a'&&s[i]<='z') continue;
        if(s[i]>='A'&&s[i]<='Z')
        {
            s[i]+=32;
        }
    }
}
int dx(const void* a,const void* b)
{
    //char *a,*b;
    struct time *p,*q;
    p=(struct time*)a;
    q=(struct time*)b;

    /*p=(struct mul*)s;
    q=(struct mul*)t;
    a=(int*)p->ind;
    b=(int*)q->ind;*/
    return strcmp(p->s,q->s);//(struct mul.ind*)t-(struct mul.ind*)s;
}
int main()
{
    int *p,len=0,k=0;
    p=&len;
    char b[2000];
    //char s;
	/*for (i=0;i<50&&s!='\n';i++)    //最大输入100个数，遇到回车就终止循环
	{
		scanf("%s",ti[i].s);
		//scanf("%",&mt1[i].ind);
		s=getchar();           //s用来接收是否是回车
		k1++;                   //检测输入的个数
	}
	s='s';*/

    //gets(b);

    FILE *in;
    in=fopen("article.txt","r");
    if(in==NULL)
    {
       printf("failed to open the file\n");
       exit(0);
    }
    while(fgets(b, max - 1, in) != NULL)
    {
   //gets(b);
      turn(b);
      record(b,p,k);  //将单词个数赋给*p
      k+=*p;//k为单词总数，每次增加扫描行中的单词个数
      *p=0;
    }

    /*for(int i=0;i<3;i++)
    {

    }*/

    ink(k);
    //k=*p;
    qsort(ti,k,sizeof(struct time),dx);
    left(ti,0,k);
    for(int i=0;i<k-1;i++)
       {
           if(strcmp(ti[i].s,"1")!=0)
           {
               printf("%s ",ti[i].s);
               printf("%d",ti[i].t);
               //putchar('\n');
               printf("\n");
           }
        //printf("%d")
       }

    //fclose(in);
    //循环结束后k为单词总数

    return 0;
}



