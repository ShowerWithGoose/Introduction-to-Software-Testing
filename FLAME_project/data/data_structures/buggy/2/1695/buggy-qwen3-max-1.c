#include<stdio.h>

int main() {
    int a1=0,a2,a3;
    char s1='+',s2,s3;
    while (s1!='='){
        scanf("%d%c",&a2,&s2);//一个数一个运算符 @@ [This scanf may read the space after the number as the operator character, causing s2 to be ' ' instead of the actual operator. This leads to incorrect parsing and potentially infinite loops because s2 never becomes '*' or '/' or '=' as expected.]
        while (s2=='*'||s2=='/'){
            scanf("%d%c",&a3,&s3);
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