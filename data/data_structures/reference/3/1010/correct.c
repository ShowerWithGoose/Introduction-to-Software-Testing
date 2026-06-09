#include <stdio.h>
#include <string.h>
char s[105];                        
int num[105];
int calculate(char*s);
int wei=0,i,flag = 0,zf = 0,fcnt = 0,k = 0;
int main()
{      
    scanf("%s",s);        
	calculate(s);                                   
    if(zf == -1) printf("-");          
    for(i = 0; i< k;i++) {
        if(i==1) printf(".%d",num[i]);         
        else printf("%d",num[i]);
    }
    int w = k - 1 - wei;                  
    printf("e%d",w);                       
    return 0;

}
int calculate(char*s){
	    for(i = 0; i<strlen(s);i++) {
	        if(s[i] == '.') flag = 1;       
	        if(flag == 1) wei++;            
	        if(s[0]=='-') zf = -1;         
	        if(s[i] != '0'  && s[i] != '-' && s[i] != '.') fcnt = 1;    
	        if(fcnt == 1 && s[i] != '.') num[k++] = s[i] - '0';         
	    }
	    wei--;  
}



