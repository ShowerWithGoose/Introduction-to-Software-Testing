#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    char a[1000],b[1000];
    gets(a);
    int i,j=0,l=strlen(a);
    for(i=0;i<l;i++){
        if(a[i]!='-'){
            b[j]=a[i];
            j++;
        }
        else{
            if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1]-1){
                int k=a[i+1]-a[i-1]-1,m;
                for(m=1;m<=k;m++){
                    b[j]=a[i-1]+m;
                    j++;
                }
            }
            else if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1]-1){
                int k=a[i+1]-a[i-1]-1,m;
                for(m=1;m<=k;m++){
                    b[j]=a[i-1]+m;
                    j++;
                }
            }
            else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1]-1){
                int k=a[i+1]-a[i-1]-1,m;
                for(m=1;m<=k;m++){
                    b[j]=a[i-1]+m;
                    j++;
                }
            }
            else{
                b[j]=a[i];
                j++;
            }
        }
    }
    puts(b);
    return 0;
}

