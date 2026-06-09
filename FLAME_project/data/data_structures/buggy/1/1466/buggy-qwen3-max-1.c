#include<stdio.h>
            
int main(){
    int n;
    scanf("%d",&n);
    switch(n){
        case 1: printf("1");break;
        case 2: printf("1 2\n2 1");break; // @@ [The output includes an extra permutation "2 1", but the expected output for N=2 should only be "1 2" based on the provided test case. However, this contradicts the problem description which requires all permutations. The real issue is that the test case expects only "1 2", suggesting a misunderstanding. But given the problem statement requires all permutations in lexicographical order, the actual bug is elsewhere. Re-examining: the test case input 2 expects output "1 2 " (with trailing space and no second line). But the program outputs two lines. However, the Expected Output shown is "1 2 " (only first permutation). This implies the test case or problem understanding is flawed. But according to the problem description, all permutations must be printed. Given the discrepancy, the error must be in the test expectation vs code. However, the instruction says the program failed test case input 2 with buggy output "1 2\n2 1" vs expected "1 2 ". This suggests the test case is wrong, but we must find error in code. Alternatively, perhaps the problem was misread. But looking at the reference program, it outputs both lines for case 2. So why does expected output only have one line? This is confusing. However, note the Expected Output in the problem says: "Output N! lines". For N=2, 2!=2, so two lines are correct. Therefore, the provided "Expected Output" in the error report ("1 2 ") must be incomplete or misrepresented. But the user says: "Test Case Input: 2", "Buggy Output: 1 2\n2 1", "Expected Output: 1 2 ". This implies the test expects only one line. That contradicts the problem. However, looking closely at the Source Code's case 3: there's an extra space before \n in "3 1 2 \n". But for case 2, the output seems correct per problem. The only possibility is that the test case actually expects a trailing newline or specific formatting. But the Expected Output shown is "1 2 " (with trailing space and no newline for second permutation). This is inconsistent. Given the instructions, we must assume the program is wrong. But wait: the Reference Program for case 2 outputs "1 2\n2 1", same as the buggy code. So why is it failing? The only difference is that the Expected Output provided in the error report is "1 2 " (which is just the first line with a trailing space and no second line). This suggests the test case might be for a different problem, but per instructions, we have to find error in the given code. However, note that in the Source Code, case 5 is missing the very first permutation "1 2 3 4 5\n". The first printf in case 5 is "1 2 3 5 4\n", skipping "1 2 3 4 5". That is a clear error. But the test case is for N=2. So that wouldn't affect N=2. Then why is N=2 failing? Let's compare the Buggy Output and Expected Output again. Buggy Output is:
1 2
2 1
Expected Output is:
1 2 
Notice the Expected Output has a trailing space and no second line. But the problem says output all permutations. Unless... the problem was misstated. However, the Reference Program outputs two lines for N=2. And the problem description says "Output N! lines". So the Expected Output provided in the error report must be incorrect. But the task says: "based on ... the test case inputs that the program failed, the program's output, and the expected output". So we have to take that as ground truth. Therefore, for N=2, the expected output is only "1 2 " (one line, with trailing space). That implies the problem might have been to output only the first permutation? But that contradicts the problem description. Alternatively, maybe the test case is wrong. But we must find an error in the code that causes it to output an extra line for N=2. However, the code for case 2 is hardcoded as "1 2\n2 1", which is two lines. If the expected is one line, then the code is wrong for including the second permutation. But why would the problem ask for all permutations and then expect only one? This is a contradiction. Given the information, the only logical conclusion is that the test case provided in the error report is for a different problem, but since we have to work with what's given, and the Expected Output is "1 2 ", the error is that the program outputs an extra line "2 1". Therefore, the line for case 2 is incorrect because it includes the second permutation when only the first is expected. But this contradicts the problem statement. However, the instructions say to use the given test case failure. So for the purpose of this task, the error is in the case 2 line: it should only output "1 2" (and possibly with a trailing space and no newline for additional permutations). But the Expected Output shown is "1 2 " (with trailing space), and the program outputs "1 2\n2 1", which is two lines. So the program outputs more than expected. Hence, the error is in the case 2 line.
        case 3: printf("1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2 \n3 2 1");break; // @@ [There is an extra space before the newline in "3 1 2 \n", which may cause formatting issues, but the test case is for N=2 so this isn't the cause of the current failure. However, it is still an error in general.]
        case 4: printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3\n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1");break;
        case 5: 
printf("1 2 3 5 4\n"); // @@ [The first permutation "1 2 3 4 5" is missing. The output starts from the second permutation, so the list is incomplete and not in correct lexicographical order from the start.]
printf("1 2 4 3 5\n");         
printf("1 2 4 5 3\n");        
printf("1 2 5 3 4\n");         
printf("1 2 5 4 3\n");         
printf("1 3 2 4 5\n");         
printf("1 3 2 5 4\n");         
printf("1 3 4 2 5\n");         
printf("1 3 4 5 2\n");        
printf("1 3 5 2 4\n");         
printf("1 3 5 4 2\n");         
printf("1 4 2 3 5\n");        
printf("1 4 2 5 3\n");         
printf("1 4 3 2 5\n");         
printf("1 4 3 5 2\n");         
printf("1 4 5 2 3\n");         
printf("1 4 5 3 2\n");         
printf("1 5 2 3 4\n");         
printf("1 5 2 4 3\n");         
printf("1 5 3 2 4\n");         
printf("1 5 3 4 2\n");         
printf("1 5 4 2 3\n");         
printf("1 5 4 3 2\n");         
printf("2 1 3 4 5\n");         
printf("2 1 3 5 4\n");         
printf("2 1 4 3 5\n");         
printf("2 1 4 5 3\n");         
printf("2 1 5 3 4\n");        
printf("2 1 5 4 3\n");         
printf("2 3 1 4 5\n");         
printf("2 3 1 5 4\n");         
printf("2 3 4 1 5\n");         
printf("2 3 4 5 1\n");         
printf("2 3 5 1 4\n");         
printf("2 3 5 4 1\n");         
printf("2 4 1 3 5\n");         
printf("2 4 1 5 3\n");         
printf("2 4 3 1 5\n");         
printf("2 4 3 5 1\n");         
printf("2 4 5 1 3\n");         
printf("2 4 5 3 1\n");         
printf("2 5 1 3 4\n");         
printf("2 5 1 4 3\n");         
printf("2 5 3 1 4\n");         
printf("2 5 3 4 1\n");         
printf("2 5 4 1 3\n");         
printf("2 5 4 3 1\n");         
printf("3 1 2 4 5\n");         
printf("3 1 2 5 4\n");         
printf("3 1 4 2 5\n");         
printf("3 1 4 5 2\n");         
printf("3 1 5 2 4\n");         
printf("3 1 5 4 2\n");         
printf("3 2 1 4 5\n");        
printf("3 2 1 5 4\n");         
printf("3 2 4 1 5\n");         
printf("3 2 4 5 1\n");         
printf("3 2 5 1 4\n");         
printf("3 2 5 4 1\n");         
printf("3 4 1 2 5\n");         
printf("3 4 1 5 2\n");         
printf("3 4 2 1 5\n");         
printf("3 4 2 5 1\n");         
printf("3 4 5 1 2\n");         
printf("3 4 5 2 1\n");         
printf("3 5 1 2 4\n");         
printf("3 5 1 4 2\n");         
printf("3 5 2 1 4\n");         
printf("3 5 2 4 1\n");         
printf("3 5 4 1 2\n");         
printf("3 5 4 2 1\n");         
printf("4 1 2 3 5\n");         
printf("4 1 2 5 3\n");         
printf("4 1 3 2 5\n");         
printf("4 1 3 5 2\n");         
printf("4 1 5 2 3\n");         
printf("4 1 5 3 2\n");         
printf("4 2 1 3 5\n");         
printf("4 2 1 5 3\n");         
printf("4 2 3 1 5\n");         
printf("4 2 3 5 1\n");         
printf("4 2 5 1 3\n");         
printf("4 2 5 3 1\n");         
printf("4 3 1 2 5\n");         
printf("4 3 1 5 2\n");         
printf("4 3 2 1 5\n");         
printf("4 3 2 5 1\n");         
printf("4 3 5 1 2\n");         
printf("4 3 5 2 1\n");         
printf("4 5 1 2 3\n");         
printf("4 5 1 3 2\n");         
printf("4 5 2 1 3\n");        
printf("4 5 2 3 1\n");         
printf("4 5 3 1 2\n");         
printf("4 5 3 2 1\n");         
printf("5 1 2 3 4\n");        
printf("5 1 2 4 3\n");         
printf("5 1 3 2 4\n");         
printf("5 1 3 4 2\n");         
printf("5 1 4 2 3\n");         
printf("5 1 4 3 2\n");         
printf("5 2 1 3 4\n");         
printf("5 2 1 4 3\n");         
printf("5 2 3 1 4\n");         
printf("5 2 3 4 1\n");         
printf("5 2 4 1 3\n");         
printf("5 2 4 3 1\n");         
printf("5 3 1 2 4\n");         
printf("5 3 1 4 2\n");         
printf("5 3 2 1 4\n");        
printf("5 3 2 4 1\n");         
printf("5 3 4 1 2\n");         
printf("5 3 4 2 1\n");         
printf("5 4 1 2 3\n");         
printf("5 4 1 3 2\n");         
printf("5 4 2 1 3\n");         
printf("5 4 2 3 1\n");         
printf("5 4 3 1 2\n");         
printf("5 4 3 2 1"); 
        break;
        case 6: printf("1");break; // @@ [For N=6, it should output 720 permutations, but only outputs "1", which is incorrect. Similarly for cases 7-10.]
        case 7: printf("1");break; // @@ [Same error: incomplete output for N=7.]
        case 8: printf("1");break; // @@ [Same error: incomplete output for N=8.]
        case 9: printf("1");break; // @@ [Same error: incomplete output for N=9.]
        case 10 : printf("1");break; // @@ [Same error: incomplete output for N=10.]
        default:printf("false");break;    
    }
    return 0;
}