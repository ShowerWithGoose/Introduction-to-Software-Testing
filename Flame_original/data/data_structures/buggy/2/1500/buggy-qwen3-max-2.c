#include<stdio.h>
#include<string.h>
int main(){
    int ch1[20]={-1}; // @@ [Initialization { -1 } only sets the first element to -1, rest are zero; this causes incorrect detection of valid input numbers]
    char ch2[20]={'0'}; // @@ [Initialization { '0' } only sets first char to '0', rest are '\0'; this interferes with detecting operator input correctly]
    int i=0,j=0,len=0,x1=0,sum=0;
    while(1){
        scanf(" %d",ch1+i); // @@ [If input fails (e.g., non-integer), ch1[i] remains unchanged, leading to undefined behavior; also, no check for scanf success]
        if(ch1[i]!=-1){ // @@ [Relies on initial -1 to detect valid input, but after first iteration, ch1[i] may legitimately be -1 as a number, causing premature skip]
            i++;
        }
        scanf(" %c",ch2+j); // @@ [No check for scanf success; if input ends unexpectedly, ch2[j] is uninitialized]
        if(ch2[j]!='0'){ // @@ [Uses '0' as sentinel, but '0' could be confused with actual character '0'; also, after first iteration, ch2[j] may be any char including '0']
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
                x1/=ch1[i+1]; // @@ [Does not handle operator precedence correctly in all cases; assumes left-to-right within same precedence, but logic is flawed due to earlier parsing errors]
            }
            if(ch2[i]=='*'){
                
                x1*=ch1[i+1];
                printf("%d\n",x1);
            }
            if(ch2[i]=='+'||ch2[i]=='='){ // @@ [When encountering '=', it treats it like '+', which may cause out-of-bound access to ch1[i+1]]
                ch1[j]=x1;
            
                ch2[j]='+';
                j++;
                x1=ch1[i+1]; // @@ [Accesses ch1[i+1] when i == len-1 (last element), which is out of bounds since ch1 has len elements indexed 0..len-1]
            }
            if(ch2[i]=='-'){
                ch1[j]=x1;
            
                ch2[j]='-';
                j++;
                x1=ch1[i+1]; // @@ [Same out-of-bounds access as above when i == len-1]
            }

        }sum=ch1[0];
        for(i=0;i<j-1;i++){ // @@ [Loop condition i < j-1 may skip last term if j==0 or j==1; also, logic assumes at least two terms]
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