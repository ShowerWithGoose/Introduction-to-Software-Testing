#include <stdio.h>
#include<string.h>
int main() {
    char a[100];
    char s[100]=" ";
    char b[100]; // @@ Array b is uninitialized. Combined with flawed index calculations, skipped positions will contain garbage values, causing incorrect output.
    scanf("%s",s);
    int sum=strlen(s),flag=0;//flag代表插入的数据个数，sum来代表最后b的位数 
    int i=0; 
    for(i;i<=strlen(s);i++) {
        a[i]=s[i];
    }//将是s 的东西赋给a  
    i=0;
    for(i; i<=strlen(s); i++) {
        if(a[i]!='-') {
            b[flag+i]=a[i]; // @@ Index calculation flag+i is incorrect. flag is intended to track the cumulative offset from expansions but is updated incorrectly, causing characters to overwrite each other or leave gaps.
        }
        if(a[i]=='-') {

            if((a[i+1]>a[i-1])&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9'))==1) {
                int m=0;

                for(m; m<a[i+1]-a[i-1]-1; m++) {
                    b[i+flag+m]=a[i-1]+1+m;// @@ The index i+flag+m relies on the flawed flag logic, placing expanded intermediate characters at incorrect positions in b.
                }
                flag=a[i+1]-a[i-1]-2; // @@ flag is reassigned instead of accumulated. It should add the number of newly inserted characters to the existing offset to correctly shift subsequent array indices.
                sum+=flag; // @@ sum is updated based on the incorrectly reass