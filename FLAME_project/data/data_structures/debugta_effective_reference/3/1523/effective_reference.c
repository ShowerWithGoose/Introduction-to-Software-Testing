#include <stdio.h>
#include <string.h>
char s[110];
int num[110];
int main()
{
    int xsd = 0,fh = 0, yxs= 0,dh=-1;  //xsd小数点  fh符号  yxs有效数 dh小数点后
    int i,n,j=0;
    int zs;

    scanf("%s",s);
    n=strlen(s) ;

    if(s[0]=='-') fh = 1;   //判断符号

    for(i = 0; i<n; i++)
    {
        if(s[i] == '.')   xsd =1;       //标记小数点
        if(xsd == 1)     dh++;            //小数点后的数字，小数位数
        if(s[i]>='1'&&s[i]<='9') yxs= 1;  //发现第一个非零数，标记一下
        if(yxs == 1 && s[i]>='0'&&s[i]<='9') num[j++] = s[i] - '0';  //读入非零数
    }

    if(fh == 1) printf("-");           //是负数
    for(i = 0; i< j;i++) {
        if(i==1) printf(".%d",num[i]);
        else printf("%d",num[i]);
    }
     zs = j - 1 - dh;    //指数就等于总共的非零数的个数 - 小数点后的位数 - 1
    printf("e%d",zs);                       //输出指数
    return 0;

}



