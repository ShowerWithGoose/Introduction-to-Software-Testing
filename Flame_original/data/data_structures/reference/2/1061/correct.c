#include<stdio.h>
#include<string.h>

int main(){
    char str[1000] = {0};
    long long cpy[1000] = {0};
    int sign1=-1, sign2=0;
    int walk, i,j,k;
    long long num = 0,ans = 0;

    gets(str);

    //删除空格
    for(i = 0,walk = 0; str[i] != '\0'; ++i){
        if(str[i] != ' '){
            str[walk] = str[i];
            walk++;
        }
    }
    str[walk] = '\0';

    //找符号
    for(i = 0;i <= strlen(str)-1;++i){
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '='){
            sign2 = i;

            for(j = 1,k = 1;j <= (sign2-sign1-1);j++,++k){
                num = num*10+(str[sign1+k]-'0');
            }

            cpy[sign2-1] = num;
            if(sign1 == -1){
                cpy[sign2-1] = num;
            }else if(str[sign1] == '-'){
                cpy[sign2-1] = -cpy[sign2-1];
            }else if(str[sign1] == '*'){
                cpy[sign2-1] = cpy[sign1-1] * cpy[sign2-1];
                cpy[sign1-1] = 0;
            }else if(str[sign1] == '/'){
                cpy[sign2-1] = cpy[sign1-1] / cpy[sign2-1];
                cpy[sign1-1] = 0;
            }
            sign1 = sign2;
            num = 0;

        }
    }
    for(i = 0;i <= sign2-1;++i){
        if(cpy[i] != 0){
            ans += cpy[i];
        }
    }
    printf("%lld",ans);




    return 0;
}
