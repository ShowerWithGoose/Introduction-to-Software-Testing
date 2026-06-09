#include<stdio.h>
#include<string.h>

int check(char x,char y){
    if(x>='0'&&x<='9'&&y>='0'&&y<='9')
        return 1;
    else if(x>='a'&&x<='z'&&y>='a'&&y<='z')
        return 1;
    else if(x>='A'&&x<='Z'&&y>='A'&&y<='Z')
        return 1;
    else
        return 0;
}

int main(){
    int i,j=0;
    char a[100],b[100],c;
    gets(a);
    for(i=0;i<strlen(a);i++){
        b[j++]=a[i];
        if(a[i+1]=='-'&&a[i+2]>a[i]&&check(a[i],a[i+2])==1){
            for(c=a[i]+1;c<a[i+2];c++)
            b[j++]=c;
            i++;
        }
    }
    b[j]='\0';
    puts(b);
    return 0;
}

