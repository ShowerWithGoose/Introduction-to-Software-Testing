#include<stdio.h>
#include<string.h>

int main()
{
	int record1=0,record2,i;
    char a[100];
    gets(a);
    
    for(i=0;i<strlen(a);i++){
		if(a[i]=='.'){
			record1=i;	
			break;		
		}
	}
	for(i=0;i<strlen(a);i++){
		if(a[i]!='0' && a[i]!='.'){
			record2=i;
			break;
		}
	}
	if(record1!=0){
	    if(record2>1){
		    for(i=record2;i<strlen(a);i++){
		        if(i==record2+1)
		    	    putchar('.');
		        if(i!=record1)
		        	putchar(a[i]);
	    	}
    		printf("e%d",record1-record2);
    	}
	    else{
	    	for(i=0;i<strlen(a);i++){
	    		if(i==1)
		    	    putchar('.');
		        if(i!=record1)
		        	putchar(a[i]);
		    }
		    printf("e%d",record1-record2-1);
	    }
    }
    else{
    	for(i=0;i<strlen(a);i++)
		    putchar(a[i]);
    	printf("e0");
	}
    return 0;
}


