#include<stdio.h>

int main() {
    int a1=0,a2,a3;
    char s1='+',s2,s3;
    while (s1!='='){
        scanf("%d%c",&a2,&s2); // @@ The format string lacks a space before %c; it should be " %c" to skip any whitespace (spaces) between the number and operator. Without the space, a space character would be read into s2, causing logic errors.
        while (s2=='*'||s2=='/'){
            scanf("%d%c",&a3,&s3); // @@ Same issue: the format string should include a space before %c to ignore whitespace.
            if (s2=='*')
                a2=a2*a3;
            else if (s2=='/')
                a2=a2/a3;
            s2=s3;//产生循环，连续乘除 
        }
        if (s1=='+'){
            a1+=a2;
        }
        else if (s1=='-'){
            a1-=a2;
        }
        s1=s2;//产生循环，连续加减 
    }
    printf("%d",a1);
    return 0;
}