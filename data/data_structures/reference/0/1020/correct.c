#include<stdio.h>
#include<string.h>
void expand(char in[],char out[],int size);
int kind(char c);
int main()
{
	char in[100]={'\0'},out[100]={'\0'};
	gets(in);
	int size=0;
	size = strlen(in);
	expand(in,out,size);
	puts(out);
	return 0;
}
	void expand(char in[],char out[],int size){
		int i=0,j=0,k=0;
		for(i=0,j=0;i<size;i++){
			if(in[i]=='-'){
				if( kind(in[i-1])!=kind(in[i+1]) ){
					out[j] = in[i];
					j++;
				}else if(in[i-1]>=in[i+1]){
					out[j] = in[i];
					j++;					
				}else{
					for(k=j;j<k+(in[i+1]-in[i-1]);j++)
					out[j] = out[j-1] + 1;
					i++;					
				}

			}else{
			out[j] = in[i];
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



