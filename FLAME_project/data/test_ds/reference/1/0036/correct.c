#include<stdio.h>
#include<string.h>
int main(){
    char c[100];
    char a[100];
    scanf("%s",c);
    for(int i=0;i<strlen(c);i++){
        if(c[i]=='-'){
            if(((c[i-1]>='a'&&c[i+1]<='z')||(c[i-1]>='A'&&c[i+1]<='Z')||(c[i-1]>='0'&&c[i+1]<='9'))&&c[i-1]<c[i+1]){
                int j=1;
                int k=0;
                a[k]=c[i-1];
                k++;
                while(a[k-1]<c[i+1]-1){
                    a[k]=c[i-1]+j;
                    printf("%c",a[k]);
                    j++;
                    k++;
                }
            }
            else
            printf("%c",c[i]);
        }
        else
        printf("%c",c[i]);
    }
    
}
