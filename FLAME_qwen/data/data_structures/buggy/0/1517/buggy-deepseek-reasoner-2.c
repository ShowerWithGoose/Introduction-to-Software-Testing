#include<stdio.h>
#include<string.h>
char strtrue[100000];
int main()
{
    char str[100000]={"0"};
    gets(str); // @@ 使用不安全的gets函数，可能导致缓冲区溢出，但主要逻辑错误在于后面的处理
    int j=-1;//str中'-'的位置 
    int line;
    char temp[100000]={"0"};
    line=strlen(str); 
    for(int i=0;i<line;i++)
    {
        
        if(str[i]!='-'&&str[i+1]=='-')//把不用变动的加到后面 // @@ 该条件过于宽泛，会错误地复制非扩展字符以及后一个扩展的起始字符（导致重复），且未考虑无效减号应原样输出
        {
            int cha=i-j; 
            for(int x=0;x<cha;x++)
            {
                temp[x]=str[j+1]; // @@ 复制字符时依赖不准确的j值，可能复制到减号或已处理过的字符
                j++;
            }
            strcat(strtrue,temp);
            memset(temp,0,sizeof(temp));
            j=i+1; // @@ 将j设为减号位置，导致后续复制包含减号或错误地跳过字符
         }
         if(str[i]=='-')//把缺少的补上 
         {
             if(str[i-1]<='z'&&str[i-1]>='a')
             {
                 if(str[i+1]<='z'&&str[i+1]>='a')
                 {
                     int x=str[i+1]-str[i-1]-1;
                     if(x>0)
                     {
                         for(int k=0;k<x;k++)
                     {
                         temp[k]=str[i-1]+1+k;
                     }
                     strcat(strtrue,temp); // @@ 只补充中间字符，未包含起始和结束字符，且对于无效扩展（x<=0）未输出减号和原字符
                     memset(temp,0,sizeof(temp));
                     }
                 }
            }
            if(str[i-1]<='Z'&&str[i-1]>='A')
            {
                 if(str[i+1]<='Z'&&str[i+1]>='A')
                 {
                     int x=str[i+1]-str[i-1]-1;
                     if(x>0)
                     {
                         for(int k=0;k<x;k++)
                     {
                         temp[k]=str[i-1]+1+k;
                     }
                     strcat(strtrue,temp); // @@ 同上，缺少起始和结束字符，且无效扩展无输出
                     memset(temp,0,sizeof(temp));
                     }
                 }
            }
            if(str[i-1]<='9'&&str[i-1]>='0')
            {
                 if(str[i+1]<='9'&&str[i+1]>='0')
                 {
                     int x=str[i+1]-str[i-1]-1;
                     if(x>0)
                     {
                         for(int k=0;k<x;k++)
                     {
                         temp[k]=str[i-1]+1+k;
                     }
                     strcat(strtrue,temp); // @@ 同上，缺少起始和结束字符，且无效扩展无输出
                     memset(temp,0,sizeof(temp));
                     }
                 } 
             }
         }
         
        if(i==line-1) 
        {
            int cha2=i-j; 
            for(int x=0;x<cha2;x++)
            {
                temp[x]=str[j+1]; // @@ 复制时j可能指向减号，从而错误地将减号包含在输出中
                j++;
            }
            strcat(strtrue,temp);
            memset(temp,0,sizeof(temp));
        }    
         
    }
    puts(strtrue);
    return 0;
}