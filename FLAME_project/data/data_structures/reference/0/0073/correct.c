#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

char a[3000];
void sw(char s[])
{   
   int u=0;
    char c;
    int i,j;
    char zhuan[3000];
    strcpy(zhuan,s);
    for(i=0,j=0;zhuan[i];i++){
    	if(zhuan[i]!='-'){
    		a[j]=zhuan[i];
    		j=j+1;
    		u++;
		}
		if(zhuan[i]=='-'){
			if(zhuan[i-1]>=48&&zhuan[i+1]<=57&&zhuan[i-1]<zhuan[i+1]){
			
			c=zhuan[i+1];
			for(j=u;a[j-1]+1<c;j++){
				a[j]=a[j-1]+1;
				u++;
			}
		}
			else if(zhuan[i-1]>=65&&zhuan[i+1]<=90&&zhuan[i-1]<zhuan[i+1]){
			
			c=zhuan[i+1];
			for(j=u;a[j-1]+1<c;j++){
				a[j]=a[j-1]+1;
				u++;
			}
		}
			else if(zhuan[i-1]>=97&&zhuan[i+1]<=122&&zhuan[i-1]<zhuan[i+1]){
			
			c=zhuan[i+1];
			for(j=u;a[j-1]+1<c;j++){
				a[j]=a[j-1]+1;
				u++;
			}
		}
		else{
			a[j]=zhuan[i];
    		j=j+1;
    		u++;
		}
	
	}
   
	
}
}

int main()
{

char s[3000];
gets(s);

sw(s);

puts(a);
}




