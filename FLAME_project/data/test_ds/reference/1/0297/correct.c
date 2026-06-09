#include<stdio.h>
#include<string.h>
char a[10005];
int n;
int check(int x){
    if(a[x-1]>=a[x+1]) return 0;
    if(a[x-1]>='0'&&a[x-1]<='9'&&a[x+1]>='0'&&a[x+1]<='9') return 1;
    if(a[x-1]>='a'&&a[x-1]<='z'&&a[x+1]>='a'&&a[x+1]<='z') return 1;
    if(a[x-1]>='A'&&a[x-1]<='Z'&&a[x+1]>='A'&&a[x+1]<='Z') return 1;
    return 0;
}
int main(){
    scanf("%s",a+1);n=strlen(a+1);
    for(int i=1;i<=n;i++){
        if(a[i]=='-'&&check(i)) for(int j=a[i-1]+1;j<a[i+1];j++) printf("%c",j);
        else printf("%c",a[i]);
    }
    return 0;
}
