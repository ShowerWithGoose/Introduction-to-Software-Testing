#include<stdio.h>
#include<string.h>
int main(){
	char in[100],c,fa;
	gets(in);
	int count,j;
	for(count=1;count<strlen(in);count++){
		j=1;
		if(in[count]=='-')
		if(in[count-1]>='a'&&in[count+1]<='z'||in[count-1]>='A'&&in[count+1]<='Z'||in[count-1]>='0'&&in[count+1]<='9'){
			
			for(c=in[count-1],j=1;c<in[count+1];c++)
			    
			    printf("%c",c);
		    j=0;
		    count++;
		    continue;
		}
		else
		for(fa=1;fa<4;fa++,count++)
		printf("%c",in[count-1]);
		else{
			printf("%c",in[count-1]);
			j=0;
		}
		
		
        	}
        	if(j==0)
        	printf("%c",in[strlen(in)-1]);
}

