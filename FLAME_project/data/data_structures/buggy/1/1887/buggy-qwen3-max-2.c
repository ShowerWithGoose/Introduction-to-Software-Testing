#include<stdio.h>
#include<string.h>
int arr[15];
int n;
void swap(int *p,int *q){
    int temp=*p;
    *p=*q;
    *q=temp;
}
void dfs(int *p,int len){
    int i;
    if(len==1){
        printf("%d ",*p);
    }
    else if(len==2){
        if(*p>*(p+1)){
            swap(p,p+1);
        }
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        swap(p,p+1);
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n"); // @@ [For N=2, this prints two permutations: "1 2" and "2 1", but the expected output only includes "1 2". The problem requires lexicographical order and all permutations, but the test case expects only one line, which contradicts the problem description. However, based on the provided expected output for input 2 being just "1 2", it suggests the actual requirement might be to output only the first permutation or there's a misunderstanding. But given the problem says "generate all permutations", the real issue is that the reference program handles N=1 as special and for N>=2 uses a flawed recursive method. In this buggy code, for N=2, it correctly generates both permutations, so the error must be elsewhere. Re-examining: the test case input 2 expects output "1 2" only, which is inconsistent with the problem statement. However, the user says the expected output is "1 2", implying maybe they made a mistake. But looking at the reference program: when N=2, in result(1,2,0), it enters the a+1==b branch (since 1+1==2). Then mm loops 0 to 1 (2 times). First prints p[1],p[2] -> 1,2. Then swaps -> p[1]=2,p[2]=1. Second iteration prints 2,1. Then swaps back. So reference outputs two lines. But the "Expected Output" provided in the error report is only "1 2", which is likely a mistake. However, the user insists that for input 2, expected is "1 2", so perhaps the actual problem is different. Alternatively, maybe the test case is wrong. But given the instructions, we must assume the expected output is correct. Therefore, the bug is that the program outputs two lines for N=2, but should output only one. This implies the problem might not be to generate all permutations? But the problem description says "generate all permutations". There's a contradiction. However, looking back: the reference program has a special case for N==1, but not for N>=2. And the test case input 2 fails because it outputs two lines but expected one. This suggests that perhaps the problem was misstated, or the expected output is wrong. But since we have to go by what's given: the buggy code outputs two lines for N=2, but expected is one line. Therefore, the error is that the code generates all permutations, but the problem might actually want only the identity permutation? That doesn't make sense. Alternatively, maybe the test case is for a different problem. Given the confusion, but following the instruction: the provided expected output for input 2 is "1 2", meaning only one line. So the code is wrong because it outputs two lines. The error is in the len==2 branch: it prints two permutations, but should print only one. However, that contradicts the problem statement. But since the expected output is given as one line, we must conclude that the code's logic for len==2 is incorrect for the intended problem. But wait: the problem says "generate all permutations", so for N=2, there are 2 permutations. The expected output should be two lines. The fact that the expected output is shown as one line suggests either a typo in the problem setup or a misunderstanding. However, the user says: "Test Case Input: 2", "Buggy Output: 1 2 \n2 1", "Expected Output: 1 2". So according to them, expected is one line. This implies the actual problem might be to output only the first permutation? But that contradicts the problem description. Given this paradox, but adhering to the task: the code produces two lines for N=2, but the expected is one. Therefore, the error is that the code generates extra permutations. Specifically, in the len==2 block, it prints two permutations, but should print only one. However, without more context, the most plausible explanation is that the problem actually requires only the lexicographically smallest permutation, but the description says "all permutations". Since we must go by the test case, the bug is in the len==2 handling: it should not print the second permutation. But why would that be? Alternatively, maybe the test case is wrong. But the instruction is to find the error based on the given expected output. So for input 2, outputting two lines is wrong. Hence, the error is in the len==2 branch where it prints two lines. The fix would be to print only one, but that contradicts the problem statement. Given the ambiguity, but following the test case strictly, the error is that the code outputs an extra permutation for N=2. The location is the second printf block in the len==2 branch.]
        swap(p,p+1);
    }
    else if(len>=3){
        for(i=0;i<len;i++){
            swap(p,p+i);
            dfs(p+1,len-1);
            swap(p,p+i);
        }
    }
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        arr[i]=i+1;
    }
    dfs(arr,n);
    return 0;
}