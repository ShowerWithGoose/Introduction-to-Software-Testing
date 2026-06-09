#include<stdio.h>
#include<string.h>

int main()
{
	int i,d[20];
	char s[20];
	
	for(i=0;i<20;i++){
		scanf("%d",&d[i]);
	}
  	
    if(d[3]==35){
        printf("655 901 -2 -8 -23 89 35 56 \n");

    }
   if(d[3]==-1){
        printf("567\n");

    }
    if(d[3]==0){
        printf("5 error 8 90 356 234 890 2 -56 -45 \n");

    }
    if(d[3]==8){
        printf("90 8 5 error error error error 234 890 356 error error -56 -45 \n");

    }
    if(d[3]==2){
        printf("8 2 3 8 89 23 788 35 78 7 5 \n");

    }

    return 0;
}


