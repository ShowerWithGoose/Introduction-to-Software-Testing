#include<stdio.h>
#include<string.h>
int main(void)
{
	int flag=0,i,j=1,k,l,len;
	char a[120];
	scanf("%s",a);
	len=strlen(a);
	for(i = 0;a[i] != '\0';i++){
		if(a[i] == '.') flag = 1,l=i;
	}
	if(flag == 0){
		if(a[i-1] == '0'){
			for(j = i-1;a[j] == '0';j--);
			j++;
			a[j] = '\0';
		}
			printf("%c.",a[0]);
			for(k = 1;k <= i-j;k++) {
			    printf("%c",a[k]);
		    }
		    printf("e%d",i-1);
	}
	else if(a[0] == '0'){
		for(j = 2;a[j] == '0';j++);
		if(j == len-1){
			printf("%ce-%d",a[j],j-1);
		}
		else{	
		    printf("%c.",a[j]);
			for(k = j+1;k < len;k++){
				printf("%c",a[k]);
			}
			printf("e-%d",j-1);
		}
	}
	else {
	    printf("%c.",a[0]);
		for(k = 1;k < len;k++){
			if(a[k] == '.') continue;
			printf("%c",a[k]);
		}
		printf("e%d",l-1);
	}
    return 0;
}


