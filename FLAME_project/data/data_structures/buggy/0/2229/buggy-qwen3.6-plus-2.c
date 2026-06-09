#include<stdio.h>
#include<string.h>
char a[1000000];
int main(){
    
    int i,j,k,m,n,p,w;
    gets(a);    
    
    for(i=0;a[i]!='\0';i++){
        if(a[i]=='-'){
            if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')){ // @@ The condition checks if the start char is in range and end char is in range, but does not verify they are of the SAME type (e.g., 'a' and 'Z' would pass the first part of OR if logic was flawed, but specifically here it allows mixed types like 'a' (lower) and 'Z' (upper) if the implementation of ranges isn't strict on pairing. More critically, it fails to ensure a[i-1] and a[i+1] are both lowercase, both uppercase, or both digits simultaneously. For example, if a[i-1]='a' and a[i+1]='Z', the first condition (a[i-1]>='a' && a[i+1]<='z') is false, second (a[i-1]>='A' && a[i+1]<='Z') is false because 'a' >= 'A' is true but 'Z' <= 'Z' is true? No, 'a' is 97, 'A' is 65. 97>=65 is true. 'Z' is 90. 90<=90 is true. So 'a'-'Z' passes the second check incorrectly.)
                if(a[i-1]<a[i+1]){
                    j=strlen(a);
                    p=a[i+1]-a[i-1]-2;
                    w=i;
                    k=a[i+1]-a[i-1];
                    for(n=1;n<=j-i-2;n++){
                        a[i+n+1+p]=a[i+n+1];
                    }
                    for(m=1;m<=k;m++){
                        a[w]=a[i-1]+m;
                        w=w+1;
                    }
                    i = w - 1; // @@ After expansion, the index i needs to be updated to skip the newly inserted characters and the original end character, otherwise the loop continues from the wrong position or processes expanded characters as potential new expansion starts incorrectly. Also, the null terminator might be misplaced if strlen was calculated before expansion.
                }
            }
        }
    }
    printf("%s",a);
    return 0;
}