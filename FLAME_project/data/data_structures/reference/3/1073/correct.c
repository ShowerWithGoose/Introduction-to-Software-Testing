#include<stdio.h>
#include<string.h>
int main()
{
    char num[200] , out[200] = " ";
    int dig = 0 , poi = 0 , power;
    gets(num);
    while(num[dig] != '\0'){
        if(num[dig] == '.'){
            poi = dig;
            if(poi == 1){
                if(num[dig-1] == '0'){
                    while(num[++dig] == '0');
                    poi = dig + 1;
                    out[0] = num[dig];
                    if(num[dig+1] <= '9' && num[dig+1] >= '0')	out[1] = '.';
                    for(dig = 2 ; dig < strlen(num) - poi + 2 ; dig++)  out[dig] = num[dig + poi - 2];
                    power = poi - 2;
                    printf("%se-%d", out , power);
                }
                else printf("%se0",num);
                break;
            }
            else{
                power = poi - 1;
                while(dig > 1) { num[dig] = num[dig-1] ; dig-- ; }
                num[dig] = '.';
                printf("%se%d", num , power);
                break;
            }
        }
        dig++;
    }
}

