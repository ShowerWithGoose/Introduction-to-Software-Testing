#include <stdio.h>
#include<string.h>
int main() {
    char a[100];
    char s[100]=" ";
    char b[100];
    scanf("%s",s);
    int sum=strlen(s),flag=0;//flag代表插入的数据个数，sum来代表最后b的位数 
    int i=0; 
    for(i;i<=strlen(s);i++) { // @@ 循环条件应为 i < strlen(s)，否则会复制多余的空字符；且后续 i=0 时可能访问 a[i-1] 导致越界
        a[i]=s[i];
    }//将是s 的东西赋给a  
    i=0;
    for(i; i<=strlen(s); i++) { // @@ 循环条件应为 i < strlen(s)，否则越界；且未处理 i=0 或 i=len-1 时 a[i-1] 或 a[i+1] 越界
        if(a[i]!='-') {
            b[flag+i]=a[i]; // @@ 索引计算错误：flag 在后续被覆盖，导致字符位置错乱，应使用独立输出索引
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { // @@ 条件判断不完整：未检查前后字符都在同一范围内（如 a[i-1]<= 'z' 等），且缺少差 >1 的判断，同时可能越界访问
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;// @@ 索引计算错误：i+flag+m 随 flag 变化混乱，应使用独立输出索引
                }
                flag=a[i+1]-a[i-1]-2; // @@ 直接覆盖 flag，导致之前的偏移丢失，应累加插入字符数
                sum+=flag; // @@ flag 可能为负，且累加方式错误，应增加插入的字符数量


            }
            else {
                b[i+flag]=a[i]; // @@ 索引错误，同第16行
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) { // @@ 循环条件 i<=sum 可能输出未初始化的内存，因为 b 中有效字符位置不连续
        printf("%c",b[i]);
    }

    return 0;

}