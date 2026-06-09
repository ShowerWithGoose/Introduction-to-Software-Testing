#include <stdio.h>
#include <string.h>
void expand(char a,char b);
int main(void)
{
    char str[1000000];
    gets(str);
    long long lth=strlen(str),i;

    for(i=0;i<lth;i++){
        printf("%c",str[i]);
        if(str[i+1]=='-'){
            expand(str[i],str[i+2]);
            i++;
        }
    }

    return 0;
}

void expand(char a,char b)
{
    int j;
    if((a<='9'&&a>='0'&&b<='9'&&b>='0'&&a<b)||(a<='z'&&a>='a'&&b<='z'&&b>='a'&&a<b)||(a<='Z'&&a>='A'&&b<='Z'&&b>='A'&&a<b)){
        for(j=1;j<(b-a);j++){
            printf("%c",a+j);
        }
    }else{
        printf("-");
    }

}


