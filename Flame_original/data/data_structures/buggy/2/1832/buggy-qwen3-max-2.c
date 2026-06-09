#include <stdio.h>
#include <string.h>
int main(){
    char s[100];
    int a,jiajian[100]={0},num=0,final[100]={0},y=1,gc[100]={0},gcc=0;
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many modern compilers (like GCC) no longer support it by default, leading to a compilation error. Use 'fgets' instead.]
    a= strlen(s);

    //È¥¿Õ¸ñ
    for(int i=0;i<a;i++){
        while(s[i]==' '){
            for(int t=i;t<=a;t++){
                s[t]=s[t+1];
            }
            a--;
        }
    }
    a= strlen(s);

    //jiajianhao
    for(int i=0;i<a;i++){
        if(s[i]=='+'||s[i]=='-'){
            jiajian[num]=i;
            num++;
        }
        else if(s[i]=='='){
            jiajian[num]=i;
        }
    }


    if(num==0){
        int chazhi=0;
        for(int i=0;i<a-1;i++){
            if(s[i]!='*'&&s[i]!='/'){
                if(chazhi==0){
                    gc[gcc]=s[i]-'0';
                    chazhi++;
                }
                else{
                    gc[gcc]=gc[gcc]*10+s[i]-'0';
                }
            }
            else{
                chazhi=0;
                gcc++;
            }
        }
        final[0]=gc[0];
        int xuhao=0;
        for(int i=0;i<a-1;i++){
            if(s[i]=='*'){
                xuhao++;
                final[0]=final[0]*gc[xuhao];
            }
            else if(s[i]=='/'){
                xuhao++;
                final[0]=final[0]/gc[xuhao];
            }
        }
    }
    else{
        for(int i=0;i<a-1;i++){
            gcc=0;
            for(int t=0;t<num;t++){
                if(jiajian[t]==i){
                    int chazhi=0;
                    for(int j=i+1;j<jiajian[t+1];j++){
                        if(s[j]!='*'&&s[j]!='/'){
                            if(chazhi==0){
                                gc[gcc]=s[j]-'0';
                                chazhi=chazhi+1;
                            }
                            else{
                                gc[gcc]=gc[gcc]*10+s[j]-'0';
                            }
                        }
                        else{
                            chazhi=0;
                            gcc++;
                        }
                    }
                    int xuhao=0;
                    final[y]=gc[0];
                    for(int j=i+1;j<jiajian[t+1];j++){
                        if(s[j]=='*'){
                            xuhao++;
                            final[y]=final[y]*gc[xuhao];
                        }
                        else if(s[j]=='/'){
                            xuhao++;
                            final[y]=final[y]/gc[xuhao];
                        }
                    }
                    y++;
                    if(t!=num-1){
                        i=jiajian[t+1]-1;
                    }
                }
                else {
                    if(i<jiajian[0]&&t==0){
                        final[0]=final[0]*10+s[i]-'0';
                    }
                }
            }
        }

        for(int t=0;t<num;t++){
            if(s[jiajian[t]]=='+'){
                final[0]=final[0]+final[t+1];
            }
            else if(s[jiajian[t]]=='-'){
                final[0]=final[0]-final[t+1];
            }
        }
    }


    printf("%d",final[0]);
    return 0;
}