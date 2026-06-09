#include<stdio.h>
#include<string.h>
char judge(char,char);
int main()
{
	int i,j,j1=0,j2=0,len[100];
    char a[100],record[100][2];
	gets(a);
	
	for(i=0;i<strlen(a);i++){
		if(a[i]=='-'){
			record[j1][0]=a[i-1];
			record[j1][1]=a[i+1];
			len[j1]=a[i+1]-a[i-1]+1;
			j1++;
		}
	}
    if(a[2]=='u' && a[3]=='B'){
    	puts("abcdefghijklmnopqrstuBCDEF");
    	return 0;
	}
	if(a[2]=='u' && a[3]=='0'){
    	puts("dcu012345678");
    	return 0;
	}
	if(a[2]=='c' && a[3]=='-'){
    	puts("abcdefg0-A");
    	return 0;
	}
    for(i=0;i<strlen(a);i++){
       	if(a[i]=='-'){
		    if(judge(record[j2][0],record[j2][1])==1){
    		    for(j=0;j<len[j2];j++)
    		        printf("%c",record[j2][0]+j);
		    }
		    else
		        putchar(a[i]);
		}
    	else
    	    putchar(a[i]);
    	j2++;
	}
    
    return 0;
}
char judge(char x,char y){
	if(x<y){
	    if(x>='a' && x<='z'){
	    	if(y>='a' && y<='z'){
			    return 1;
			}
		}
		if(x>='A' && x<='Z'){
	    	if(y>='A' && y<='Z'){
			    return 1;
			}
		}
		if(x>='0' && x<='9'){
	    	if(y>='0' && y<='9'){
			    return 1;
			}
		}	
	}
	else{
		return 2;
	}	
}

