#include<stdio.h>
#include<string.h>
int main(){
    int ch1[20]={-1}; // @@ [Initializing array with {-1} only sets the first element to -1, rest are zero; this causes incorrect detection of valid input numbers later]
    char ch2[20]={'0'}; // @@ [Initializing with {'0'} sets first char to '0', rest to '\0'; this interferes with detecting operator input correctly]
    int i=0,j=0,len=0,x1=0,sum=0;
    while(1){
        scanf(" %d",ch1+i); // @@ [If input fails (e.g., due to '=' before a number), ch1[i] remains unchanged, leading to use of uninitialized/garbage values]
        if(ch1[i]!=-1){ // @@ [This check is flawed: if the first number is -1, it will be skipped; also, after first iteration, ch1[i] may be 0 from initialization, causing early termination]
            i++;
        }
        scanf(" %c",ch2+j); // @@ [Reading char without checking return value; if input ends unexpectedly, ch2[j] may contain garbage]
        if(ch2[j]!='0'){ // @@ [This condition is incorrect: '0' is not a sentinel; operators like '+' or '-' will pass, but if ch2[j] is '\0' (from initialization), it may break logic]
            j++;
        }
        if(ch2[j-1]=='='){
            break;
        }
    }len=i;
 /* for(j=0;j<i;j++){
        printf("%d",ch1[j]);}
        printf(" %s",ch2);
        printf("%d ",i);*/
        x1=ch1[0];
        j=0;
        for(i=0;i<len;i++){
            if(ch2[i]=='/'){
                x1/=ch1[i+1]; // @@ [Accesses ch1[i+1] which may be out of valid range if expression ends with operator before '=', leading to undefined behavior]
            }
            if(ch2[i]=='*'){
                
                x1*=ch1[i+1]; // @@ [Same issue: accesses ch1[i+1] beyond valid data if i+1 >= len]
                printf("%d\n",x1);
            }
            if(ch2[i]=='+'||ch2[i]=='='){
                ch1[j]=x1;
            
                ch2[j]='+';
                j++;
                x1=ch1[i+1]; // @@ [Again, ch1[i+1] may be uninitialized or out-of-bounds when ch2[i] is '=' at the end]
            }
            if(ch2[i]=='-'){
                ch1[j]=x1;
            
                ch2[j]='-';
                j++;
                x1=ch1[i+1]; // @@ [Same out-of-bounds access risk]
            }

        }sum=ch1[0];
        for(i=0;i<j-1;i++){ // @@ [Loop runs up to j-2, but should run up to j-1 to include last stored term; misses last operand in sum calculation]
       //   printf("%d,%c\n",ch1[i],ch2[i]);
            if(ch2[i]=='+'){
                sum+=ch1[i+1];
            }
            if(ch2[i]=='-'){
                sum-=ch1[i+1];
            }
            
        }
        printf("%d",sum);
        return 0;

}