#include <stdio.h>
char chq[10000000]={0},chh[10000000]={0};
int main()
{
    int i=0,j=0,k=0,len,delta;
    while(scanf("%c",&chq[i])!=EOF){
        i++;
    }
    len=i;
    for(i=0;i<=len;i++){
        if('-'==chq[i]&&i!=0&&i!=len&&chq[i-1]<chq[i+1]){
            if(chq[i-1]>='a'&&chq[i-1]<='z'&&chq[i+1]>='a'&&chq[i+1]<='z'){
                delta=(int)chq[i+1]-(int)chq[i-1]-1;
                for(k=0;k<delta;k++){
                    chh[j]=chq[i-1]+k+1;
                    j++;
                }
                continue;
            }
            if(chq[i-1]>='A'&&chq[i-1]<='Z'&&chq[i+1]>='A'&&chq[i+1]<='Z'){
                delta=(int)chq[i+1]-(int)chq[i-1]-1;
                for(k=0;k<delta;k++){
                    chh[j]=chq[i-1]+k+1;
                    j++;
                }
                continue;
            }
            if(chq[i-1]>='0'&&chq[i-1]<='9'&&chq[i+1]>='0'&&chq[i+1]<='9'){
                delta=(int)chq[i+1]-(int)chq[i-1]-1;
                for(k=0;k<delta;k++){
                    chh[j]=chq[i-1]+k+1;
                    j++;
                }
                continue;
            }
        }
            chh[j]=chq[i];
            j++;
    }
    puts(chh);
    return 0;
}

