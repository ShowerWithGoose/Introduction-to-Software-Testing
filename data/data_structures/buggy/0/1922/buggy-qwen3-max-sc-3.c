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
            b[flag+i]=a[i]; // @@ [Indexing into b is incorrect: 'flag+i' may skip positions or overwrite due to changing flag; also, when a[i] is '-', the non-'-' branch still runs before checking '-', leading to duplication]
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { // @@ [Condition logic is flawed: it doesn't ensure both characters are of the same category (e.g., 'a' and 'Z' could pass if 'a'<'Z', but they're different types); also, accessing a[i+1] when i is at last index causes out-of-bounds read]
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;//
                }
                flag=a[i+1]-a[i-1]-2; // @@ [flag update is incorrect: it should accumulate total inserted chars, not just last expansion minus 2; also, using this flag in indexing leads to inconsistent offsets]
                sum+=flag;


            }
            else {
                b[i+flag]=a[i];
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) { // @@ [Loop condition uses <= sum, but sum was modified incorrectly; also, b is not null-terminated, so printing with %c loop may output garbage beyond intended length]
        printf("%c",b[i]);
    }

    return 0;

}