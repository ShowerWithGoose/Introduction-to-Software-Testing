#include<stdio.h>
#include<string.h>
int main()
{
  char s[110];
  int i=0,j=0,len,Not_Zero,Point;
  scanf("%s",s);
  len=strlen(s);
  if(s[0]=='0'&&s[1]=='.')//0.几的小数
    {
      for(i=2;s[i]=='0';i++);//找到小数点后第一个非0数
      //for(j=len-1;s[j]=='0';j--);//找到小数点后从后往前数第一个非0的数【输入格式保证了最后无0】
      //printf("%d",i);
      Not_Zero=i;
      printf("%c",s[i]);
      if(i!=len-1)
      {printf(".");
        i++;
      while(i<len)
      {printf("%c",s[i]);
      i++;}}
      printf("e-%d",Not_Zero-1);
    }

    else{
    for(i=1;s[i]!='.';i++);//找到小数点位置
    for(j=len-1;s[j]=='0';j--)//找到从后往前数第一个非0的数
    Not_Zero=j;
    Point=i;
    printf("%c",s[0]);
    printf(".");
    for(i=1;i<=j;i++)
    {
      if(s[i]!='.')
      {printf("%c",s[i]);}
    }
    printf("e%d",Point-0-1); 
    }

  return 0;
}
