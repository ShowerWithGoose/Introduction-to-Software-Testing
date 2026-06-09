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
            b[flag+i]=a[i]; // @@ 错误：索引计算错误。当flag不为0时，b的索引应基于当前已写入的位置，而不是简单相加。这会导致覆盖或错位。
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) {
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m; // @@ 错误：索引计算错误。同样，b的索引应基于当前已写入的位置，而不是i+flag+m，这会导致写入位置错误。
                }
                flag=a[i+1]-a[i-1]-2; // @@ 错误：flag更新错误。flag应累加插入的字符数，而不是重新赋值。这会导致后续索引计算完全错误。
                sum+=flag;


            }
            else {
                b[i+flag]=a[i]; // @@ 错误：索引计算错误。当不展开时，应直接复制'-'，但索引i+flag可能不正确，因为flag可能已被错误更新。
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) {
        printf("%c",b[i]);
    }

    return 0;

}