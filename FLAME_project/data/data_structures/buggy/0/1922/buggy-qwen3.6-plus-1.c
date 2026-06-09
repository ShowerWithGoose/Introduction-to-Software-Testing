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

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { // @@ The condition checks if start and end are in the same broad category (e.g., both letters) but fails to ensure they are the SAME case (e.g., 'a' and 'Z' would pass the range check individually but are invalid). It should verify that both are lowercase, both uppercase, or both digits specifically.
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;//
                }
                flag=a[i+1]-a[i-1]-2;
                sum+=flag;


            }
            else {
                b[i+flag]=a[i]; // @@ When expansion is not performed, the '-' character should be output. However, the logic for placing non-expanded characters is flawed because `flag` tracks inserted chars from previous expansions, but `i` is the current index in `a`. The index `i+flag` might overwrite previously written characters or leave gaps if not managed correctly relative to the output buffer `b`. More critically, if expansion doesn't happen, we just copy '-', but the previous `if(a[i]!='-')` block already copied characters. This structure leads to incorrect indexing in `b`.
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) {
        printf("%c",b[i]);
    }

    return 0;

}