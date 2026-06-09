#include <stdio.h>
#include <string.h>
int main()
{
	char a[1000];                        
    int b[1000];
    int c=0,i,d=0,e=0,k=0;
    gets(a);       
	int m=strlen(a);   
    for(i=0;i<m;i++) {
        if(a[i] == '.') d=1;       
        if(d== 1) c++;            
        if(a[0]=='-') putchar('-');          
        if(a[i]!='0'&&a[i]!='-'&&a[i]!='.') e= 1;   
        if(e==1&&a[i] != '.') b[k++] = a[i]-'0';         
    }
    c--;                                                               
    for(i=0;i<k;i++) {
        if(i==1) printf(".%d",b[i]);          
        else printf("%d",b[i]);
    }
    int z=k-1-c;                   
    printf("e%d",z);                       
    return 0;

}

