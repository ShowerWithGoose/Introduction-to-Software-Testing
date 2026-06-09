#include <stdio.h>
#include <string.h>
char numf[10086];
char numzheng[10086];
char numxiao[10086];
int main(){
    gets(numf); // @@ [gets is unsafe and deprecated; it does not check buffer overflow, but it may compile with warnings. The assignment likely expects no such issue, but if compilation fails on some systems due to gets being removed (C11), this line causes compilation error.]
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
    end++; // @@ [end is incremented one extra time after the loop, making it equal to strlen+1. Later uses of end in `end-dot-1` will be off by one, causing printing of one extra (possibly garbage) character.]
    ////////////////////////////////////

    /////////////////////////////-----------若是整数无小数点
    if(flag==0){
        printf("%c.",numf[0]); // @@ [If the integer has only one digit (e.g., "5"), this prints "5." which is incorrect; the base should be an integer without a decimal point. Also, if the integer has multiple digits, a dot appears before the rest, which is correct for scientific notation, but the problem's input always contains a decimal point, so this branch might be unreachable. However, if it is reached, the output may be wrong for single-digit numbers.]
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
        numzheng[j+1]='\0'; // @@ [The null terminator is placed at index j+1, but j is the index where the dot is (the loop exits when numf[j]=='.'), so the last assigned digit is at index j-1. This leaves index j (dot position) uninitialized and causes numzheng to contain garbage beyond the actual digits, though it may not affect output because only indices 0..dot-1 are printed.]
    }
    /////////////////////////////////
    
    ///////////////////////////////---------数小数点后数字 
    

    strcpy(numxiao,numf);

    int v;
    for(v=0;numxiao[v]!='\0';v++){
        numxiao[v]=numxiao[v+dot+1]; // @@ [This shifting loop is flawed: it overwrites the string in place without null-terminating it. The condition `numxiao[v]!='\0'` may never be true because the shifting corrupts the string, causing out-of-bounds reads. The resulting numxiao is not properly terminated and may contain extra characters, leading to incorrect output and possible undefined behavior in later loops.]
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
        for(d=0;d<(end-dot-1);d++){//!!! // @@ [The upper bound `end-dot-1` is computed using the incorrect `end` (which is strlen+1). This results in printing one more character from numxiao than intended, likely including a null or garbage character.]
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
        printf("e%d",em-1);
    }
    else if((ep==0)&&(em>0)){//X.XXXXXe-X型 
        printf("%c.",numxiao[em]);
        int b;
        for(b=em+1;b<(end-dot-1);b++){//!!! // @@ [Same issue as above: incorrect upper bound due to off-by-one in `end`.]
            printf("%c",numxiao[b]);
            } 
            printf("e-%d",em+1);

        
    }
    
}
return 0;
}