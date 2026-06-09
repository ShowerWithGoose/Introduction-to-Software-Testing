#include<stdio.h>
#include<string.h>
int main(){
    int ch1[20]={-1}; // @@ [Initializing array with {-1} only sets the first element to -1, rest are zero; this causes incorrect detection of valid input numbers]
    char ch2[20]={'0'}; // @@ [Initializing with {'0'} sets first char to '0', rest to '\0'; this interferes with detecting actual operators]
    int i=0,j=0,len=0,x1=0,sum=0;
    while(1){
        scanf(" %d",ch1+i); // @@ [If input fails (e.g., due to '='), ch1[i] remains unchanged, leading to use of uninitialized/garbage values]
        if(ch1[i]!=-1){ // @@ [Relies on initial -1 to detect valid input, but after first iteration, ch1[i] may be any value; also, -1 could be a valid input number]
            i++;
        }
        scanf(" %c",ch2+j); // @@ [Reading char after number may read space or newline incorrectly; also, no check for scanf success]
        if(ch2[j]!='0'){ // @@ [Uses '0' as sentinel, but '0' is not a special character; any operator including '+' or '-' will pass this check even if invalid]
            j++;
        }
        if(ch2[j-1]=='='){ // @@ [If j==0, ch2[-1] is accessed → undefined behavior; also, if previous scanf failed, ch2[j-1] is uninitialized]
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
                x1/=ch1[i+1]; // @@ [Does not handle operator precedence correctly: processes * and / left-to-right but doesn't reduce expression properly; also accesses ch1[i+1] which may be out of valid range]
            }
            if(ch2[i]=='*'){
                
                x1*=ch1[i+1]; // @@ [Same issue: assumes ch1[i+1] is always valid; also, mixing * and / with later + and - without proper grouping leads to wrong order of operations]
                printf("%d\n",x1);
            }
            if(ch2[i]=='+'||ch2[i]=='='){ // @@ [Treats '=' as '+', which is incorrect; also, when encountering '=', it tries to access ch1[i+1] which doesn't exist]
                ch1[j]=x1;
            
                ch2[j]='+';
                j++;
                x1=ch1[i+1]; // @@ [When ch2[i] is '=', i+1 >= len, so ch1[i+1] is uninitialized or garbage]
            }
            if(ch2[i]=='-'){
                ch1[j]=x1;
            
                ch2[j]='-';
                j++;
                x1=ch1[i+1]; // @@ [Same: accesses ch1[i+1] beyond valid data if at last operator]
            }

        }sum=ch1[0];
        for(i=0;i<j-1;i++){ // @@ [Loop runs to j-2, but should run to j-1 to include last stored term; also, ch1 and ch2 arrays may not be properly populated]
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