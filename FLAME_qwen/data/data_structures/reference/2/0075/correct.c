//
//  main.c
//  sss
//
//  Created by  on 2021/11/25.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>//atoi（“字符”）
//char a[100];
//int cheng(int a,int b)
//{
//    int ans=a*b;
//    return ans;
//}
//int chu(int a,int b)
//{
//    int anss=a/b;
//    return anss;
//}

//    gets(a);
//
//    int dis=strlen(a);//有空格
//
//    for (int i=0; i<dis; i++) {
//        if (a[i]==' ') {
//
//            for(int k=0;k<dis;k++)
//            a[i+k]=a[i+1+k];
//        }
//    }
//
//    int disnew=strlen(a);//无空格
int main(int argc, const char * argv[]) {
//
    int big=0,a,b;
    char bigc='+',c,d;
    scanf("%d %c",&a,&c);
    while(1)
    {
        
        
        if (c=='*'||c=='/') {
            scanf("%d %c",&b,&d);
            
            if (c=='*') {
                a=a*b;
            }
            if (c=='/') {
                a=a/b;
            }
            c=d;//每次都考虑相同的东西，赋值给c
        }
        
        
        if (c=='+'||c=='-') {
            
            if (bigc=='+') {
                big=big+a;
            }
            if (bigc=='-') {
                big=big-a;
            }
            bigc=c;//每次都传一遍
            scanf("%d %c",&a,&c);
        }
        
        if (c=='=') {
            if (bigc=='+') {
                big=big+a;
            }
            if (bigc=='-') {
                big=big-a;
            }
            printf("%d\n",big);
            break;
        }
        
        
        
    }
    
    
    return 0;
}



