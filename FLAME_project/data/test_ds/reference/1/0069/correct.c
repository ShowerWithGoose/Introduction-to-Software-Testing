#include<stdio.h>
#include<string.h>

char chr_type(char c){
    if ('0'<=c&&c<='9')
    {
        return '0';
    }
    else if ('a'<=c&&c<='z')
    {
        return 'a';
    }
    else if ('A'<=c&&c<='Z')
    {
        return 'A';
    }
    return 1;
}

char chr_lispr(char a[],int p){
    if (p==0||a[p+1]==0)
    {
        printf("-");
        return 0;
    }
    char l=chr_type(a[p-1]),r=chr_type(a[p+1]);
    if (l==r&&l!=1&&a[p-1]<a[p+1])
    {
        for (int i = a[p-1]+1; i < a[p+1]; i++)
        {
            printf("%c",i);
        }
    }
    else
    {
        printf("-");
    }
}
int main(){
    char a[100]={0};
    gets(a);
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i]=='-')
        {
            chr_lispr(a,i);
        }
        else
        {
            printf("%c",a[i]);
        }
        
    }
    
}



