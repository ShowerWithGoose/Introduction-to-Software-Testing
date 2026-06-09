#include <stdio.h>
#include<string.h>
int main() {
    char a[100];
    char s[100]=" ";
    char b[100];
    scanf("%s",s);
    int sum=strlen(s),flag=0;//flag代表插入的数据个数，sum来代表最后b的位数 
    int i=0; 
    for(i;i<=strlen(s);i++) { // @@ [循环条件应为 i<strlen(s)，否则会复制空字符，且后续循环会越界]
        a[i]=s[i];
    }//将是s 的东西赋给a  
    i=0;
    for(i; i<=strlen(s); i++) { // @@ [循环条件 i<=strlen(s) 包含空字符，导致处理到末尾后仍访问 a[i+1] 越界]
        if(a[i]!='-') {
            b[flag+i]=a[i]; // @@ [索引 flag+i 可能超出 b 的边界，且逻辑错误，应使用独立的输出索引]
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { // @@ [类型判断条件错误，例如 "a[i-1]>='a'&&a[i+1]<='z'" 无法保证两端字符都属于同一范围]
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) { // @@ [循环内未处理 i 的递增，导致 '-' 后的字符被重复处理]
                    b[i+flag+m]=a[i-1]+1+m;// @@ [索引计算错误，且未考虑后续偏移累积]
                }
                flag=a[i+1]-a[i-1]-2; // @@ [flag 被赋值而非累加，且数值错误（应为插入字符数 -1）]
                sum+=flag; // @@ [sum 更新错误，flag 值已不正确]
            }
            else {
                b[i+flag]=a[i]; // @@ [索引可能越界，且未处理后续字符的偏移]
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) { // @@ [循环条件 i<=sum 可能访问未初始化的 b，且缺少字符串结束符]
        printf("%c",b[i]);
    }

    return 0;

}