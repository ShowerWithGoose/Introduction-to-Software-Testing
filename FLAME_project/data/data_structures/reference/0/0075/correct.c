//
//  main.c
//  666
//
//  Created by  on 2022/2/28.
//
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>
char a[100];
char b[100];
int main(int argc, const char * argv[]) {

    int m=0;
    gets(a);
  
    //怎么判断很多次呢
    for (int i=0;a[i]!='\0';i++)//运算之后长度和第一次的m不一样，改成读到末尾。
    { m=strlen(a);//放在里面判断总长度，要不然最后的字符可能过不去
        if (a[i]=='-') {
            if(((isdigit(a[i-1])&&isdigit(a[i+1]))||(islower(a[i-1])&&islower(a[i+1]))||(isupper(a[i-1])&&isupper(a[i+1])))&&a[i+1]-a[i-1]>0)//考虑大小写的一致性
            {
                int n=a[i+1]-a[i-1]-2;//计算字符之间的距离
                    
                for (;m>i+1;m--) {
                    a[n+m]=a[m];//将后面的所有字符都挪到n个位置以外，从最后一项开始挪，保证所有数都可以挪过去
                
                    
                }
                int dis=i;
                for (char diss=a[i-1]+1; dis<=i+n+1; diss++,dis++)
                {
                    a[dis]=diss;//将缺少的东西补充上
                }
            }
        }
    }
    puts(a);
    
    
    return 0;
        
    
    

}

//#include<stdio.h>



