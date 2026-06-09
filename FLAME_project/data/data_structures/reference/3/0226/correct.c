#include<stdio.h>
int main()
{
	char a[80], b[80];
	int i, j, k, e, e1, e2;
	
	gets(a);
	
	if(a[0] == '0'&&a[1] == '.'){
		for(i=2, k=0 ; a[i]!='\0'; i++){
			if(a[i]!='0') break;
	}
	
		e = i - 1;
		b[0] = a[i];
		if(a[i+1]==0){
		for(j=1; a[i+j]!='\0'; j++){
			b[j] = a[i+j];
		}}
		else{
			b[1] = '.';
		
		for(j=2; a[i+j-1]!='\0'; j++){
			b[j] = a[i+j-1];
		}
		 
		}
		
		b[j] = 'e';
		e1 = e/10;
		e2 = e%10;
		b[j+1] = '-';
		if(e1==0){
			b[j+2] = '0' + e2;
			b[j+3] = '\0';
		}
		else{
			b[j+2] = '0' + e1;
			b[j+3] = '0' + e2;
			b[j+4] = '\0';
		}
		
		for(k=0; k<=j+4; k++){
			printf("%c", b[k]);
		}
	}
	
	else{
		
		for(i=0; a[i]!='.'; i++)
		e = i;
		
		b[0] = a[0];
		b[1] = '.';
		
		
		for(j=1, k=2; a[j]!='\0'; j++){
			if(a[j]=='.') continue;
			else{
				b[k] = a[j];
				k++;
			}
		}
		
			b[k] = 'e';
			e1 = e/10;
			e2 = e%10;
			if(e1==0){
				b[k+1] = '0' + e2;
				b[k+2] = '\0';
			}
			else{
				b[k+1] = '0' + e1;
				b[k+2] = '0' + e2;
				b[k+3] = '\0';
			}
			
			for(j=0; j<=k+2; j++){
			printf("%c", b[j]);
		}
			
	}
	
} 



