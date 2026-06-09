#include <stdio.h>
#include <stdlib.h>

int main() {
	char c , fr, be , mid;
	fr=mid=be=c='\0';
	while (scanf("%c",&c)!=EOF){
	
		if (c!='-'){
			fr=c;
			printf("%c", fr);
			scanf("%c", &mid);
		}
		 else {
			mid='-';
		}
		 if (mid!='-'){
			printf("%c", mid);
			fr=mid;
			mid='\0';
			continue;
		}
		 else {
			scanf ("%c",&be);
			if (((fr>='A'&&fr<='Z')&&(be>='A'&&be<='Z')&&(fr<be))||((fr>='a'&&fr<='z')&&(be>='a'&&be<='z')&&(fr<be))||((fr>='0'&&fr<='9')&&(be>='0'&&be<='9')&&(fr<be))){
				while (fr!=be) {
					fr++;
					printf("%c",fr);
				}
			}
			else{
				printf("%c%c",mid,be);
				mid=be='\0';
			}
		}	
		if(c='\n')
			be=mid='\0';
	}
	return 0;
}



