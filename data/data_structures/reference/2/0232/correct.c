#include<stdio.h>//next=calculate
#include<ctype.h>

void calculate1(int *a,int *b,char sign,int *fn,int *fs)
{
    if(sign=='*')
        *b=(*a)*(*b);
    else if(sign=='/')
        *b=(*a)/(*b);
    *fn=1;
    *fs=1;
}
void calculate2(int *a,int *b,char sign)//地址给我，我来改！返回大小！
{
    if(sign=='+')
        *b=(*a)+(*b);
    else if(sign=='-')
        *b=(*a)-(*b);
}
int getin(int *nums,char *sign)//搞大笑了！记住间接转换远不如直接读取！！
{
    int i=-1,number=0;
    char ch;
    do{
    i++;
    nums[i]=read(&ch);
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='=')  sign[i]=ch;
    else
    while((sign[i]=getchar())==' ') ;
//    printf("%d %c ",nums[i],sign[i]);
    }while(sign[i]!=' '&&sign[i]!='=');
    return i+1;//总数
}
int read(char *sign)
{
    int x=0,f=1,number=0;
    char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-') f=-1; ch=getchar();}//printf("%d %c\n",number,in[number]);
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();//printf("%d %c %c\n",number,ch,in[number]);
    //对指针的改变出循环后就会消失！！
    *sign=ch;
    return f*x;
}

int main()
{
    int nums[100],fn[100]={0},fs[100]={0},number,i,n1site=0,n2site=0;
    char sign[100];
    number=getin(nums,sign);
//   printf("%d",nums[0]);
    for(i=0;i<number;i++)
    {
        if(sign[i]=='*'||sign[i]=='/')
            {calculate1(&nums[i],&nums[i+1],sign[i],&fn[i],&fs[i]);
            n2site=i+1;}
    }
    for(i=0;i<number-1;i++)
    {
        while(fs[i]) i++;
        if(i>=number-1) break;
        while(fn[n1site]) n1site++;
        n2site=n1site+1;
        while(fn[n2site]) n2site++;//好！经验！当循环内部会改变循环的控制变量的时候（比如此处的i）那么不要忘了在内部改变的同时要检验是否越界！
       // if(sign[i]=='+'||sign[i]=='-')
        calculate2(&nums[n1site],&nums[n2site],sign[i]);
//        printf("%d %d %c %d\n",nums[n1site],nums[n2site],sign[5],number);
        n1site=n2site;
    }
    printf("%d",nums[n2site]);//long long??
    return 0;
}

