#include<stdio.h>
#include<string.h>
void expand(char c[],char out[],int size);
int kind(char c);
int main()
{
	char c[100]={'\0'},out[100]={'\0'};
	gets(c);
	int size=0;
	size = strlen(c);
	expand(c,out,size);
	puts(out);
	return 0;
}
	void expand(char c[],char out[],int size){
		int i=0,j=0,k=0;
		for(i=0,j=0;i<size;i++){
			if(c[i]=='-'){
				if( kind(c[i-1])!=kind(c[i+1]) ){
					out[j] = c[i];
					j++;
				}else if(c[i-1]>=c[i+1]){
					out[j] = c[i];
					j++;					
				}else{
					for(k=j;j<k+(c[i+1]-c[i-1]);j++)
					out[j] = out[j-1] + 1;
					i++;					
				}

			}else{
			out[j] = c[i];
			j++;				
			}

		} 
		out[j]='\0';
	}
	
	int kind(char c){
		if(c>='a'&&c<='z')
		return 1;
		else if(c>='A'&&c<='Z')
		return 2;
		else if(c>='0'&&c<='9')
		return 3;
		else return 4;
	}



