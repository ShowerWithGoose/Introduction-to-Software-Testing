#include <stdio.h>
#include<string.h>
int main() {
    char a[100];
    char s[100]=" ";
    char b[100];
    scanf("%s",s);
    int sum=strlen(s),flag=0;//flag代表插入的数据个数，sum来代表最后b的位数 
    int i=0; 
    for(i;i<=strlen(s);i++) {
        a[i]=s[i];
    }//将是s 的东西赋给a  
    i=0;
    for(i; i<=strlen(s); i++) {
        if(a[i]!='-') {
            b[flag+i]=a[i]; // @@ 错误：索引计算错误。当flag不为0时，b[flag+i]会跳过位置，导致输出乱码。应使用一个独立的索引变量来跟踪b的当前位置。
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) {
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m; // @@ 错误：索引计算错误。同样的问题，应使用独立的索引变量。
                }
                flag=a[i+1]-a[i-1]-2; // @@ 错误：flag更新逻辑错误。flag应累加插入的字符数，而不是重新赋值。且计算有误，插入字符数为a[i+1]-a[i-1]-1，减去1后应为a[i+1]-a[i-1]-2，但这里赋值后导致后续索引偏移。
                sum+=flag; // @@ 错误：sum更新错误。flag已更新为差值，但sum应增加插入的字符数，即a[i+1]-a[i-1]-1，而不是flag（已减2）。


            }
            else {
                b[i+flag]=a[i]; // @@ 错误：索引计算错误。同样的问题，应使用独立的索引变量。
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) {
        printf("%c",b[i]);
    }

    return 0;

}