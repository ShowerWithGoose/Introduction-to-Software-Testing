#include <stdio.h>
#include<string.h>
int main() {
    char a[100];
    char s[100]=" ";
    char b[100]; // @@ Array b is not initialized or null-terminated, which may cause undefined behavior when printing or accessing.
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

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { // @@ The condition incorrectly checks ranges. It should verify that both a[i-1] and a[i+1] belong to the same category (both lowercase, both uppercase, or both digits). The current condition only checks if a[i-1] is >= 'a' and a[i+1] is <= 'z', which doesn't guarantee they are both lowercase letters.
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;//
                }
                flag=a[i+1]-a[i-1]-2; // @@ flag is incorrectly updated. It should accumulate the number of inserted characters to correctly offset subsequent indices in b, but here it is overwritten with the count of inserted characters for the current expansion, losing previous offsets.
                sum+=flag; // @@ sum is updated based on the incorrectly calculated flag, leading to an incorrect loop bound for printing. Also, b is not null-terminated, which may cause printing of garbage characters.


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