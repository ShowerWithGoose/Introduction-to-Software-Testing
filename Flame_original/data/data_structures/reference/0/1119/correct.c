#include<stdio.h>
#include<string.h>
int main(){
    char a[1000];
    int i;
    gets(a);
    char *p;
    p = a;
    while(*p!='\0'){
        if(*(p+1)!='-')
            {printf("%c", *p);
                p++;
            }
        else {
            if(*p>='a'&&*p<='z'&&(*p<*(p+2))&&*(p+2)>='a'&&*(p+2)<='z'){
			
                for (i = *p; i < *(p + 2);i++)
                    printf("%c", i); p = p + 2;
				}
            else if(*p>='0'&&*p<='9'&&(*p<*(p+2))&&*(p+2)>='0'&&*(p+2)<='9'){
			
                for (i = *p; i < *(p + 2);i++)
                    printf("%c", i); p = p + 2;
				}        
            else if(*p>='A'&&*p<='Z'&&(*p<*(p+2))&&*(p+2)>='A'&&*(p+2)<='Z'){
			
                for (i = *p; i <*(p + 2);i++)
                    printf("%c", i); p = p + 2;
				}
            
           
            else {printf("%c", *p);p++;}
        }
        
    }
    return 0;
}



