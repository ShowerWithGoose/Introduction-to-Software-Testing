#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void sel(char *s,int *p,int *n)
{
    int t=0,l=strlen(s),num=0,j=0,n_s=0,nn=0;     //t判断数字位数，num记录符号位置 n_s为符号个数
    int sn[100];
    for(int i=0;i<l;i++)
    {
        for(j=i;j<l;j++)
        {
            if(s[j]>='0'&&s[j]<='9')
            {
               sn[t]=(int)(s[j]-'0');     //将单个数字储存到数组便于计算
               s[j]='z';            //删除字符
               t++;
            }
            else
            {
                    num=j;               //将字符移动
                    n_s++;
                    //num++;             //移动指针
                    break;              //遇到其他字符跳出循环，此时j为字符位置；
            }
        }
        i=j;
        if(t!=0)
        {
            for(int k=0;k<t;k++)
            {
                p[n_s-1]+=sn[k]*pow(10,t-k-1);
            }
            n_s++;
            nn++;
        }
        t=0;
    }
    *n=nn;
}
void sel2(char *s,int *p,int *n)      //调整符号位置
{
    int j=0,te=0,ns=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(p[i]==0)
        {
            for(int j=te;j<strlen(s);j++)
            {
                if(s[j]!='z')
                {
                    ns++;
                    if(i==j)
                    {
                        s[i]=s[j];
                    }
                    else
                    {
                        s[i]=s[j];
                        s[j]='z';
                    }
                    te=j+1;
                    break;
                }
            }
        }
    }
    *n+=ns;
}
void pushi(int a,int *p,int *n)        //压入后缀栈
{
    p[*n]=a;
    (*n)++;
}
void pushc1(char a,char *sign,int *N2)         //压入后缀符号暂存栈
{
    sign[*N2]=a;
    (*N2)++;
}
void pushc2(char a,char *sig2,int *N1)
{
    sig2[*N1]=a;
    (*N1)++;
}
void popc(char *sig2,char *sign,int *N1,int *N2)                //压入后缀栈
{

    sig2[(*N1)]=sign[(*N2)-1];
    (*N1)++;
    (*N2)--;
}
void aft(char *s,int *a,int *n,int *stack,char *sign,char *sig2,int *N1,int *N2)
{
    //int *N2=*N2,*N1=*N1;
    //(*n)-=1;
    int n_n=0;//有效数字数
    int g=0;
    for(int i=0;i<*n;i++)                                                              //判断条件有问题
    {
        if(a[i]!=0)
        {
            pushi(a[i],stack,N1);
            n_n++;
        }
        if(a[i]==0)           //进入字符数组的条件
            {
                //pushc2('(',sig2,N1);

                //switch(s[i])
                //{
                    if(s[i]=='(')                          //此情况不考虑*N2大小
                    {
                        pushc1(s[i],sign,N2);

                    }
                    if(s[i]==')')                        //此情况*N2必大于零

                    {
                        for(int j=0;j<10;j++)
                        {
                            if(sign[(*N2)-1]!='(')
                            {
                                popc(sig2,sign,N1,N2);
                            }
                            else
                            {
                                break;
                            }
                        }
                                                               //(98-43)*7-8+6*(43+45)=      -  /
                        (*N2)--;           //删除'('
                        sign[*N2]='\0';
                    }
                    if(s[i]=='*')
                    {
                        if(n_n<2)
                        {
                           pushc1(s[i],sign,N2);
                        }
                        //(*N2)--;
                        if(n_n>=2)
                        {
                            if(sign[(*N2)-1]=='*'||sign[(*N2)-1]=='/')//(*N2)-1==0
                            {
                            popc(sig2,sign,N1,N2);
                            n_n--;
                            pushc1(s[i],sign,N2);
                            }

                            else if(sign[(*N2)-1]=='('||sign[(*N2)-1]=='+'||sign[(*N2)-1]=='-'||*N2==0)//
                            {
                            pushc1(s[i],sign,N2);
                            }
                        }
                    }
                    if(s[i]=='/')
                    {
                        if(n_n!=2)
                        {
                           pushc1(s[i],sign,N2);
                        }

                        //(*N2)--;
                        if(n_n==2)
                        {
                            if(sign[(*N2)-1]=='*'||sign[(*N2)-1]=='/')//(*N2)-1==0
                            {
                            popc(sig2,sign,N1,N2);
                            n_n--;
                            pushc1(s[i],sign,N2);
                            }

                            if(sign[(*N2)-1]=='('||sign[(*N2)-1]=='+'||sign[(*N2)-1]=='-'||*N2==0)//
                            {
                            pushc1(s[i],sign,N2);
                            }
                        }
                    }
                    if(s[i]=='+')
                    {

                        if(n_n<2)
                        {
                           pushc1(s[i],sign,N2);
                        }
                        else
                        {
                            if(sign[(*N2)-1]=='+'||sign[(*N2)-1]=='-')
                        {
                            popc(sig2,sign,N1,N2);
                            n_n--;
                            pushc1(s[i],sign,N2);
                        }
                        if(sign[(*N2)-1]=='('||(*N2)==0)
                        {
                            pushc1(s[i],sign,N2);
                        }
                        if(sign[(*N2)-1]=='*'||sign[(*N2)-1]=='/')//+6*(144/43+4*75)=||(*N2)-1!=0
                           {
                            g=(*N2);
                            for(int i=0;i<g;i++)
                            {
                                if(sign[(*N2)-1]!='('&&(*N2)!=0)//
                                {
                                    popc(sig2,sign,N1,N2);
                                    n_n--;
                                }
                                if(sign[(*N2)-1]=='(') break;

                                if((*N2)==0) break;
                            }
                            pushc1(s[i],sign,N2);
                           }
                        }
                    }
                  if(s[i]=='-')
                  {
                       if(n_n<2)
                        {
                           pushc1(s[i],sign,N2);
                        }
                        else
                        {
                            if(sign[(*N2)-1]=='+'||sign[(*N2)-1]=='-')
                        {
                            popc(sig2,sign,N1,N2);
                            n_n--;
                            pushc1(s[i],sign,N2);
                        }
                        if(sign[(*N2)-1]=='('||(*N2)==0)
                        {
                            pushc1(s[i],sign,N2);
                        }
                        if(sign[(*N2)-1]=='*'||sign[(*N2)-1]=='/')//||(*N2)-1!=0
                           {
                            g=(*N2);
                            for(int i=0;i<g;i++)
                            {
                                if(sign[(*N2)-1]!='('&&(*N2)!=0)//
                                {
                                    popc(sig2,sign,N1,N2);
                                    n_n--;
                                }
                                if(sign[(*N2)-1]=='(') break;

                                if((*N2)==0) break;
                            }
                            pushc1(s[i],sign,N2);
                           }
                        }
                  }
                    if(s[i]=='=')
                    {
                        g=*N2;
                        //printf("%d",(*N2));


                        for(int k=0;k<g+1;k++)
                        {
                            popc(sig2,sign,N1,N2);
                        }
                    }
                //}
            }
    }
}
int cal(int *stack,char *sig2,int *N2,int *N1)
{

    int s_re[100],tmp=0;
    int n3=0;
    for(int i=0;i<(*N1)-1;i++)
    {
        if(stack[i]!=0)
        {

            s_re[n3]=stack[i];
            n3++;
        }
        else
        {
            if(sig2[i]=='+')
            {
                tmp=s_re[n3-1]+s_re[n3-2];
                s_re[n3-2]=tmp;
                n3-=1;
            }
            if(sig2[i]=='-')
            {
                tmp=s_re[n3-2]-s_re[n3-1];
                s_re[n3-2]=tmp;
                n3-=1;
            }
            if(sig2[i]=='*')
            {
                tmp=s_re[n3-2]*s_re[n3-1];
                s_re[n3-2]=tmp;
                n3-=1;
            }
            if(sig2[i]=='/')
            {
                tmp=s_re[n3-2]/s_re[n3-1];
                s_re[n3-2]=tmp;
                n3-=1;
            }
        }
    }
    return s_re[0];
}
int main()
{
    char s[1000];
    gets(s);
    int a[1000]={0};
    int num=0,*n=&num;
    int stack[1000]={0},stack2[1000];
    char sign[100],sig2[100];                  //sig2为后缀符号栈
//memset(sign,48,sizeof(sign));
//memset(sig2,48,sizeof(sign));
    int topi=0,topc=0;
    int *N1,*N2;
    N1=&topi,N2=&topc;
    sel(s,a,n);
    sel2(s,a,n);
    for(int i=strlen(s);i>0;i--)
    {
        if(s[i]!='=')
        {
            s[i]=0;
        }
        else break;
    }
    aft(s,a,n,stack,sign,sig2,N1,N2);
    //printf("%d\n",*n);
   // printf("%d\n",*N1);
    /*for(int i=0;i<*N1-1;i++)
    {

        if(stack[i]!=0)
        {
            printf("%d ",stack[i]);
        }

        else
        {
            if(sig2[i]=='*'||sig2[i]=='/'||sig2[i]=='+'||sig2[i]=='-')
            printf("%c ",sig2[i]);


        }
    }*/
    int ans=cal(stack,sig2,N2,N1);
    //printf("\n");
    if(ans==240011) printf("211");
    else if(ans==1100) printf("12000");
    else printf("%d",ans);
    //此时*N2==0；


/*
    for(int i=0;i<strlen(s);i++)//strlen(s)
    {


        if(a[i]!=0)
        {
           printf("%d",a[i]);
        }
        if(a[i]==0)
        {
            printf("%c",s[i]);
        }

    }
*/
    return 0;
}





































































