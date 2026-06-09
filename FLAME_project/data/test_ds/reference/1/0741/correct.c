#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define M 1000000
#define ll long long
char temp[1000],save[1000];

int main() {
    char c;
    scanf("%s",temp);
    int i=0,j=0;
    while(temp[i]!='\0'){
        save[j++]=temp[i];
        if(temp[i+1]=='-'&&temp[i]<temp[i+2]&&((isdigit(temp[i])&&isdigit(temp[i+2]))||(isupper(temp[i])&&isupper(temp[i+2]))||(islower(temp[i])&&islower(temp[i+2])))){
            for(c=temp[i]+1;c<temp[i+2];c++){
                save[j++]=c;
            }
            i+=2;
        }else i++;
    }
    save[j]='\0';
    puts(save);
	return 0;
    // system("pause");
}


