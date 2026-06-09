#include<stdio.h>
#include<ctype.h>
#include<string.h>

int find(char s[]) ;
void bigchange(int num,int poi,char s[]);
int wher(char s[]);//找第一个非零数字
void smallchange(int num,int poi,char s[]);

int main()
{
    char s[110];
    int loc,num,len;
    
    gets(s);
    len=strlen(s);
    
    loc=find(s);
    num=wher(s);
    
    //printf("loc:%d num:%d",loc,num);	//测试点 正确 
    
    
    if(loc==num+1)		//normal	正确 
    {
        printf("%se0",s);
    }
	else if(loc>num+1)//big		正确 
    {
        bigchange(num,loc,s);
        printf("%s",s);
        printf("e%d",loc-num-1);
    }
	else    //small
    {
        if(num!=len-1)
        {
            smallchange(num,loc,s);
            printf("%s",s);
        }else
        {
            printf("%c",s[num]);
        }
        printf("e%d",loc-num);
    }
    
    
    return 0;
}



int find(char s[])       //找到小数点位置
{
    int loc;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='.')
        {
            loc=i;
            break;
        }
    }
    return loc;
}
void bigchange(int num,int poi,char s[])    //将小数点移到目标位置(第一个非零数字后)后
{
    int i,j;
    //后移
    for(i=poi-1,j=poi;j>=num+2;i--,j--)//>要修改，两个数字大小可能不同
    {
        s[j]=s[i];
    }
    
    
    //放入
    s[i+1]='.';
}

int wher(char s[])//找第一个非零数字
{
    int num;
    for(int i=0;s[i]!='\0';i++)
    {
        if ((s[i]>'0')&&(s[i]<='9'))
        {
            num=i;
            break;
        }
    }
    return num;
}

void smallchange(int num,int poi,char s[])
{
    char c[110];
    int i,j=0;
    //前移
    s[num-1]=s[num];
    s[num]=(num-1==poi)?'.':s[poi];
    
   // printf("s:%s\nnum:%d\npoi:%d\n",s,num,poi);		//测试点 正确 
    
    for(i=num-1;s[i]!='\0';i++)		//s给c赋值 
    {
         c[j++]=s[i];
    }
    c[j]='\0';
    
   // printf("s:%s\nc:%s\n",s,c);		//测试点 
    
    strcpy(s,c);	//函数  正确 
    
    // printf("s:%s\nc:%s\n",s,c);		//测试点 
} 

