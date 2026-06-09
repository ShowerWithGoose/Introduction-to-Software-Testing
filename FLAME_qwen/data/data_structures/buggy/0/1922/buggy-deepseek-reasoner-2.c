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
            b[flag+i]=a[i];
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { // @@ 类型检查不完整（未同时检查上下界），且可能越界访问a[i-1]或a[i+1]
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;//
                }
                flag=a[i+1]-a[i-1]-2; // @@ 错误：应为累加插入的字符数，而非直接赋值，导致后续索引偏移错误
                sum+=flag; // @@ 由于flag计算错误，sum更新也不正确，影响最终输出长度


            }
            else {
                b[i+flag]=a[i];
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) {
        printf("%c",b[i]);
    }

    return 0;

}