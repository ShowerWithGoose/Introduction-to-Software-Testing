#include <stdio.h>
int main()
{
	char raw[1100],fin[101];
	scanf("%s",raw);
	int i,j,l,add;
	for(i=0,j=0;raw[j]!='\0';i++,j++){
		fin[i]=raw[j];
		if(raw[j]=='-'){
			if(raw[j-1]<='9'&&raw[j-1]>='0'&&raw[j+1]<='9'&&raw[j+1]>='0'&&raw[j+1]>raw[j-1]){
				l=raw[j+1]-raw[j-1];
				for(add=1;add<l;add++){
					fin[i]=raw[j-1]+add;
					if(add<l-1){
						i++;
					}
				}
			}
			if(raw[j-1]<='z'&&raw[j-1]>='a'&&raw[j+1]<='z'&&raw[j+1]>='a'&&raw[j+1]>raw[j-1]){
				l=raw[j+1]-raw[j-1];
				for(add=1;add<l;add++){
					fin[i]=raw[j-1]+add;
					if(add<l-1){
						i++;
					}
				}
			}
			if(raw[j-1]<='Z'&&raw[j-1]>='A'&&raw[j+1]<='Z'&&raw[j+1]>='A'&&raw[j+1]>raw[j-1]){
				l=raw[j+1]-raw[j-1];
				for(add=1;add<l;add++){
					fin[i]=raw[j-1]+add; 
					if(add<l-1){
						i++;
					}
				}
			}
		}
	}
	printf("%s",fin);
	return 0;
}

