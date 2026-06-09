#include<stdio.h>
#include<string.h>
#include<ctype.h>
char in[10000];
int num[10000];
int op[10000],post[1000];
void delete(int a[],int *n,int i) //传的是第几个 不是下标 
{
    for(int j=i;j<*n;j++) a[j-1]=a[j];
    (*n)--;
}
int calc(int a,int op,int b)  //-1= +  -2= -  -3= *  -4= /
{
    if(op==-1)return a+b;
    if(op==-2)return a-b;
    if(op==-3)return a*b;
    if(op==-4)return a/b;
}
int main()
{
    int i=0,j=0;    
    gets(in);
    for(int i=0;i<strlen(in);i++) //去空格 
    {
        if(in[i]!=' ')
        {
            in[j++]=in[i];    
        }
    }
    if(in[j-1]!='=')in[j++]='=';
    in[j]='\0';

    i=0,j=0; 
    int cnt=0;
    int cnum=0,pt=0;
    for(;in[pt]!='\0';pt++)  //数字和运算符分别存到num op 
    {
        if(isdigit(in[pt]))
        {
            cnum=10*cnum+in[pt]-'0';
        }
        else
        {
            num[i++]=cnum;
            cnum=0;
            cnt++;
            if(in[pt]=='+') op[j++]=-1;
            if(in[pt]=='-') op[j++]=-2;
            if(in[pt]=='*') op[j++]=-3;
            if(in[pt]=='/') op[j++]=-4;
        }
    }
    int opcnt=cnt-1;
    for(i=0;i<opcnt;)    // @@ Error: This loop processes division before multiplication, violating left-to-right precedence for * and /.
    {
        if(op[i]==-4)    // @@ Error: Should handle both * and / in left-to-right order, not all divisions first.
        {
            num[i]=calc(num[i],-4,num[i+1]);
            delete(num,&cnt,i+2);
            delete(op,&opcnt,i+1);
        }
        else i++;
    }

    for(i=0;i<opcnt;)    // @@ Error: This loop processes multiplication after division, but due to previous loop, operators may be misordered.
    {
        if(op[i]==-3)    // @@ Error: Should be interleaved with division in a single left-to-right pass.
        {
            num[i]=calc(num[i],-3,num[i+1]);
            delete(num,&cnt,i+2);
            delete(op,&opcnt,i+1);
        }
        else i++;
    }

    for(i=0;i<opcnt;)
    {
        if(op[i]==-2)
        {
            num[i]=calc(num[i],-2,num[i+1]);
            delete(num,&cnt,i+2);
            delete(op,&opcnt,i+1);
        }
        else i++;
    }
    for(i=0;i<opcnt;)
    {
        if(op[i]==-1)
        {
            num[i]=calc(num[i],-1,num[i+1]);
            delete(num,&cnt,i+2);
            delete(op,&opcnt,i+1);
        }
        else i++;
    }
    printf("%d\n",num[0]);
        
    return 0;
}