#include <stdio.h>
#include <string.h>
char c[105];                        
int num[105];
int main()
{
    scanf("%s",c);  
    int flag = 0,ws=0,zf = 0,fls= 0,k = 0,len=strlen(c),e;            
    for(int i=0; i<len;i++) {
        if(c[i]=='.') flag=1;       
        if(flag==1) ws++;           
        if(c[0]=='-') zf = -1;      
        if(c[i] != '0'&&c[i]!='-'&&c[i]!='.') fls = 1;   
        if(fls == 1 && c[i] != '.') num[k++] = c[i]-'0'; 
    }
    ws--;                                                          
    if(zf == -1) printf("-");           
    for(int i=0; i<k;i++) {
        if(i==1) printf(".%d",num[i]);  
        else printf("%d",num[i]);
    }
    e = k-ws-1;                  
    printf("e%d",e);             
    return 0;

}

