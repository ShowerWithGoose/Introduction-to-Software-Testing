
#include <stdio.h>

int main(int argc, const char * argv[]) {
    char data[105],result[110];
    int j,c,k,m;
    int num[4];
    gets(data);
   
    if (data[0]=='-') {
        printf("-");
        for (int y=0; data[y]!='\0'; y++) {
            data[y]=data[y+1];
        }
    }
    for (j=0; data[j]!='.';j++) {
    }
    if (j==1) {
        if (data[0]!='0') {
            printf("%se0",data);
        }
        else
        {
            int p,q,r;
            for (j=2;data[j]=='0';j++ ) {
            }
            r=j-1;
            result[0]=data[j];
            result[1]='.';j++;
            for (q=2,p=1; data[j]!='\0'; q++,j++,p++) {
                result[q]=data[j];
            }
            if (p==1) {
                printf("%ce-%d",data[j-1],r);
            }
            else{
            result[q]='\0';
            printf("%se-%d",result,r);
            }
        }
    }
    else{
        result[0]=data[0];
        result[1]='.';
        for ( k=1,c=2; data[k]!='\0'; k++,c++) {
            if(data[k]!='.')
            result[c]=data[k];
            else c--;
        }
        result[c]='\0';
        printf("%se%d",result,j-1);
    }
    return 0;
}

