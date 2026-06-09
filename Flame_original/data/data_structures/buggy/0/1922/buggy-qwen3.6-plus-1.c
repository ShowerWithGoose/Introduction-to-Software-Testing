#include <stdio.h>
#include<string.h>
int main() {
    char a[100];
    char s[100]=" ";
    char b[100]; // @@ Array b is not initialized, which may lead to garbage values being printed.
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

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) { // @@ The condition does not strictly verify that both characters are of the same type. It should check that both characters fall within the exact same range (e.g., both lowercase, both uppercase, or both digits).
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;//
                }
                flag=a[i+1]-a[i-1]-2; // @@ flag should accumulate the total offset of inserted characters (flag += a[i+1]-a[i-1]-1) instead of being reassigned, and the indexing b[flag+i] leaves gaps in the array when flag changes.
                sum+=flag; // @@ sum should be incremented by the number of newly inserted characters (a[i+1]-a[i-1]-1), not by the reassigned flag value.


            }
            else {
                b[i+flag]=a[i];
            }

        }
    }
    i=0;
    for(i; i<=sum; i++) { // @@ Loop condition should be i<sum to print exactly sum characters. Using i<=sum will output one extra character.
        printf("%c",b[i]);
    }

    return 0;

}