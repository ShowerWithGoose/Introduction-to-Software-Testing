#include <stdio.h> //不用我多说了
#include <math.h> //数学公式
#include <stdlib.h> //快排和malloc
#include <ctype.h> //字符处理函数
#include <string.h> //字符串函数
#include <time.h>//找时间
#define ll long long //纯粹是为了快~
#define eps 1e-6 //别被浮点数相等判断卡掉
#define MAX 1000005 //看好数据范围，多开5个空间
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define NumberOf(a) (sizeof(a)/sizeof(a[0]))
#define MAXN  10
#define MAXK  1e7
#define swap(x,y) {\
 typeof(x)temp=x;\
x=y;y=temp;\
}
clock_t start,stop;
char s[105];
char s1[105]={-1};
char s2[105]={-1};
int main()
{

    gets(s);
    int temp;
    int i=0,i0=0;
    while(s[i]!='\0')
    {
        if(s[i]!=' ')
        {
            s1[i0++]=s[i];
        }
        i++;
    }
    i=0,i0=0;
    int num2=0,a[105]={};
    int num=s1[0]-48;
    while(s1[i]!='='){
        if(s1[i+1]>='0'&&s1[i+1]<='9')
        num=num*10+s1[i+1]-48,i++;
        if(s1[i+1]=='+'||s1[i+1]=='-')
           {
			a[i0]=num,s2[i0++]=s1[i+1],i=i+2;
			num=s1[i]-48;
			while(s1[i+1]>='0'&&s1[i+1]<='9')
            {
                
                num=num*10+s1[i+1]-48;
                i++;
            }
			//i++;
			}
			
        if(s1[i+1]=='*')
        {
        	num2=0;
        	i++;
            while(s1[i+1]>='0'&&s1[i+1]<='9')
            {
                
                num2=num2*10+s1[i+1]-48;
                i++;
            }
            num*=num2;
        }
        if(s1[i+1]=='/')
        {
        	num2=0;
        	i++;
            while(s1[i+1]>='0'&&s1[i+1]<='9')
            {
                
                num2=num2*10+s1[i+1]-48;
                i++;
            }
            num/=num2;
        }
        if(s1[i+1]=='=')
        {
        a[i0]=num;
		break;
		}
        
        
    }
    int ans;
    ans=a[0];
    i=0;
    while(s2[i]!='\0') {
        if(s2[i]=='+')
            ans+=a[i+1];
        else
            ans-=a[i+1];
        i++;
    }
    printf("%d",ans);
    return 0;
}

