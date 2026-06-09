#include<stdio.h>
#include<string.h>
int main(){
    int ch1[20]={-1}; // @@ [Initialization with {-1} only sets the first element to -1, rest are zero; this causes incorrect detection of input numbers]
    char ch2[20]={'0'}; // @@ [Initialization with {'0'} only sets first char to '0', rest are zero; this interferes with detecting operator input]
    int i=0,j=0,len=0,x1=0,sum=0;
    while(1){
        scanf(" %d",ch1+i); // @@ [If input fails (e.g., due to '='), ch1[i] remains unchanged, leading to use of uninitialized/garbage values]
        if(ch1[i]!=-1){ // @@ [Relies on initial -1 to detect valid input, but after first iteration, ch1[i] may be any value; logic is flawed]
            i++;
        }
        scanf(" %c",ch2+j); // @@ [Reading char after number may read space or newline incorrectly; also, no check for scanf success]
        if(ch2[j]!='0'){ // @@ [Uses '0' as sentinel, but actual operators include '+' etc.; condition always true after first read, causing j to increment even on invalid reads]
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
                x1/=ch1[i+1]; // @@ [Does not handle operator precedence correctly in all cases; assumes left-to-right within * and /, but doesn't collapse terms properly]
            }
            if(ch2[i]=='*'){
                
                x1*=ch1[i+1];
                printf("%d\n",x1);
            }
            if(ch2[i]=='+'||ch2[i]=='='){ // @@ [When encountering '=', it treats it like '+', but ch1[i+1] may be out of bounds or uninitialized]
                ch1[j]=x1;
            
                ch2[j]='+';
                j++;
                x1=ch1[i+1]; // @@ [Accesses ch1[i+1] when i == len-1 (last term), which is beyond valid data (since ch1 has len elements indexed 0..len-1)]
            }
            if(ch2[i]=='-'){
                ch1[j]=x1;
            
                ch2[j]='-';
                j++;
                x1=ch1[i+1]; // @@ [Same out-of-bounds access as above when i == len-1]
            }

        }sum=ch1[0];
        for(i=0;i<j-1;i++){ // @@ [Loop runs to j-2, but should run to j-1 to include last operator; misses last term in sum calculation]
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