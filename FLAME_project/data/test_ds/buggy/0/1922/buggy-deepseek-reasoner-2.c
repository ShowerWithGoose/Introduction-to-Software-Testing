#include <stdio.h>
#include<string.h>
int main() {
    char a[100];
    char s[100]=" ";
    char b[100];
    scanf("%s",s);
    int sum=strlen(s),flag=0;//flag代表插入的数据个数，sum来代表最后b的位数 
    int i=0; 
    for(i;i<=strlen(s);i++) { // @@ error: loop should iterate while i < strlen(s) to avoid processing null terminator, which causes off-by-one and potential overwrite
        a[i]=s[i];
    }//将是s 的东西赋给a  
    i=0;
    for(i; i<=strlen(s); i++) { // @@ error: same loop bound issue; should be i < strlen(s)
        if(a[i]!='-') {
            b[flag+i]=a[i];
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { // @@ error: condition does not correctly ensure both characters are in the same range (e.g., a[i-1] could be '{' and a[i+1] 'z' passes incorrectly; also missing upper bound for a[i-1] and lower bound for a[i+1])
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;//
                }
                flag=a[i+1]-a[i-1]-2; // @@ error: should accumulate shift (flag += ...) rather than resetting flag, causing subsequent indices to overwrite earlier data
                sum+=flag; // @@ error: should add the number of inserted characters (a[i+1]-a[i-1]-1), not flag which is one less; leads to incorrect total length


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