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
    for(i; i<=strlen(s); i++) { // @@ Loop processes the null terminator (s[strlen(s)]), causing a null character to be written into b, which corrupts the output.
        if(a[i]!='-') {
            b[flag+i]=a[i]; // @@ Index calculation uses flag+i, but flag is overwritten after each expansion, leading to incorrect positions and overwriting of previously inserted characters.
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) {
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;//
                }
                flag=a[i+1]-a[i-1]-2; // @@ Overwrites flag with the number of inserted characters from the current dash, losing the cumulative offset needed for subsequent characters.
                sum+=flag;


            }
            else {
                b[i+flag]=a[i]; // @@ Uses the same flawed index (i+flag) for a non-expanded dash, which may overwrite previous data.
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) {
        printf("%c",b[i]);
    }

    return 0;

}