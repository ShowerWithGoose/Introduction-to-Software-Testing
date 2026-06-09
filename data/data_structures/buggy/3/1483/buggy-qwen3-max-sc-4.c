#include <stdio.h>
#include <string.h>
char numf[10086];
char numzheng[10086];
char numxiao[10086];
int main(){
    gets(numf); // @@ [Using 'gets' is unsafe and deprecated; may cause buffer overflow. Also, in many modern environments, 'gets' is removed entirely, leading to compilation error.]
    int ep=0;///////////////////第一位非零时e后数字 
    /////////////////////////////-----找小数点
    int dot=0; //小数点位置 
    int end=0;//字符末尾
    int flag=0; //是否有小数点 
    int i=0;
    for(i=0;numf[i]!='\0';i++){
        end++;
        if(numf[i]=='.'){
            dot=i;
            flag=1;
        }
    }
    end++;
    ////////////////////////////////////

    /////////////////////////////-----------若是整数无小数点
    if(flag==0){
        printf("%c.",numf[0]);
        int m;
        int ez=0;
        for(m=1;numf[m]!='\0';m++){
            ez++;
            printf("%c",numf[m]);
        
        }
            printf("e%d",ez);
    } 
    /////////////////////////////////////
    
    else{/////////////////若无小数点 
    //////////////////////////-------数小数点前数字
    int j=0;
    for(j=0;numf[j]!='.';j++){
        
        
        if(numf[0]=='0'){
            ep=0;
            numzheng[0]='0';
            break;
        }
        else{
            numzheng[j]=numf[j];
            ep++;
        }
        numzheng[j+1]='\0';
    }
    /////////////////////////////////
    
    ///////////////////////////////---------数小数点后数字 
    

    strcpy(numxiao,numf);

    int v;
    for(v=0;numxiao[v]!='\0';v++){
        numxiao[v]=numxiao[v+dot+1]; // @@ [This loop writes beyond the bounds of 'numxiao' when v+dot+1 >= original string length, causing undefined behavior. Also, it doesn't properly null-terminate the copied fractional part.]
    }


    //////////////////////////////

    //////////////////////////////----------数小数点后0的个数
    int em=0;//小数点后0的个数 
    int a=0;
    for(a=0;numxiao[a]!='\0';a++){
        if(numxiao[a]!='0'){
            break;
        }
        em++;
    }

    ///////////////////////////////////
    

    
    
    
    ////////////////////////////////////----------输出
    
    if(ep>0){//XXXX.XXXX
        printf("%c.",numzheng[0]);
        int c;
        for(c=1;c<dot;c++){
            printf("%c",numzheng[c]);
        }
        int d;
        for(d=0;d<(end-dot-1);d++){//!!!
            printf("%c",numxiao[d]);
        }
        printf("e%d",ep-1);

    }     
    else if((ep==0)&&(em==0)){//0.XXXXXe0型 
        printf("%c",numxiao[0]);
        if(numxiao[1]!='\0'){
            printf(".");
        }
        int t;
        for(t=1;numxiao[t]!='\0';t++){
            printf("%c",numxiao[t]);
        }
        printf("e%d",em-1); // @@ [When em == 0, this prints "e-1", but for input like "0.5", expected output is "5e-1", not "5e-1" with base "0.5". Logic here is flawed: em-1 gives -1, but should be -1 only if first non-zero is at position 1. However, more critically, this branch handles "0.XXXX" with no leading zeros after decimal, but outputs e-1 instead of correct exponent. Also, for "0.5", expected is "5e-1", but code prints "5e-1" only if em==0? Actually, em would be 0 for "0.5", so this branch runs, prints "5" then "e-1" — that seems correct, but the condition logic is tangled. However, the real issue is earlier: 'numxiao' is not correctly extracted.]
    }
    else if((ep==0)&&(em>0)){//X.XXXXXe-X型 
        printf("%c.",numxiao[em]);
        int b;
        for(b=em+1;b<(end-dot-1);b++){//!!!
            printf("%c",numxiao[b]);
            } 
            printf("e-%d",em+1);

        
    }
    
}
return 0;
}