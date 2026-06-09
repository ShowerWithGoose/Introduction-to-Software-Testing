#include <stdio.h>
#include <string.h>
char numf[10086];
char numzheng[10086];
char numxiao[10086];
int main(){
    gets(numf);
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
    end++; // @@ [Error: This extra increment makes 'end' one greater than the actual string length, causing out-of-bounds access in later loops that use 'end'.]
    ////////////////////////////////////

    /////////////////////////////-----------若是整数无小数点
    if(flag==0){
        printf("%c.",numf[0]); // @@ [Error: For an integer input (no decimal point), this always inserts a decimal point, but the problem requires the base to be an integer without a decimal point when only one significant digit exists. Also, if the input is just a single digit, the output would incorrectly include a decimal point and then an exponent with no fractional part.]
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
        numxiao[v]=numxiao[v+dot+1]; // @@ [Error: This loop modifies the string in place while reading from it; after shifting, the null terminator is not correctly placed, and subsequent loops may read garbage or fail to terminate properly.]
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
        for(d=0;d<(end-dot-1);d++){ // @@ [Error: 'end' is too large by 1, so this loop iterates one extra time, printing an undefined character from 'numxiao'.]
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
        for(b=em+1;b<(end-dot-1);b++){ // @@ [Error: Same as above; 'end' is off by one, causing an extra iteration and printing an undefined character.]
            printf("%c",numxiao[b]);
            } 
            printf("e-%d",em+1);

        
    }
    
}
return 0;
}