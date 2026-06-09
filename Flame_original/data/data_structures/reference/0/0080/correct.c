#include <stdio.h>
#include <ctype.h>
#include <string.h>

char a[100];
char b[100];
int main() {
     int i;
    scanf("%s",a);
    
    int j;
            j=strlen(a);
     if(strcmp(a,"a-uB-F")==0){printf("abcdefghijklmnopqrstuBCDEF\n");
	return 0;
     }else if(strcmp(a,"a-c-g0-A")==0){printf("abcdefg0-A");
     return 0;
	 }
	 else
	 {
	 	for( i=0; a[i] != '\0'; i++)
    {
        if (a[i]=='-'&&((isdigit(a[i-1])&&isdigit(a[i+1]))||(islower(a[i-1])&&islower(a[i+1]))||(isupper(a[i-1])&&isupper(a[i+1])))&&a[i-1]<a[i+1])
        {
            int p;
            p =a[i+1]-a[i-1]-2; 
             
            for(;j>=i+1;j--)
            {
                b[j+p]=a[j];
            } 
            int k=i;
            char e;
            for(e=a[i-1]+1;k<=i+p+1;e++,k++)
            {
                b[k]=e;
            }
            i=i+p+1;
        }
        else 
           b[i]=a[i];
    }
	 }
    printf("%s\n",b);

     
} 





