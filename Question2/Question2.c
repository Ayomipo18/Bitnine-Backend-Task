#include <stdio.h>
#include <stdlib.h>

int recursion(int n);
int iteration(int n);
int memo_recursion(int n, int *memo);

int main() {
    int num;
    int *memo = NULL;

    printf("Enter a Number: \n");

    scanf("%d", &num);

    printf("Number you entered: %d \n", num);
    
    int recursive_approach = recursion(num);
    printf("Answer for recursive approach is: %d \n", recursive_approach);

    int iterative_approach = iteration(num);
    printf("Answer for Iterative approach is: %d \n", iterative_approach);

    int memoized_approach = memo_recursion(num, memo);
    printf("Answer for Memoized approach is: %d \n", memoized_approach);

    free(memo);

    system("pause");
    return 0;
}

/*
This method makes use of a recursive approach, which improves the readability and comprehension of the code. 

However, particularly for large values of n, it might not be the most effective approach to solving the issue. 
Each time a recursive call is made, a new stack frame is created, which can quickly consume memory and cause the program to run slowly.
*/
int recursion(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;
    else {
        return recursion(n-2) + recursion(n-3);
    }
}

/*
This method uses an iterative approach to solve the problem. 
It is more efficient than the recursive approach because it avoids creating multiple stack frames for function calls. 
Instead, it uses a loop to iteratively calculate iteration(n) by updating three variables (first_num, second_num, and third_num) 
to store the values of iteration(n-3), iteration(n-2), and iteration(n-1), respectively. 
This method is faster and more memory-efficient than the recursive approach.

A disadvantage of this approach is that we would not be able to access values before n-3
*/
int iteration(int n) {
    int first_num = 0, second_num = 1, third_num = 2, result;

    if (n == first_num) return first_num;
    if (n == second_num) return second_num;
    if (n == third_num) return third_num;

    for(int i = 3; i <= n; i++) {
        result = second_num + first_num;
        first_num = second_num;
        second_num = third_num;
        third_num = result;
    }

    return result;
}

/*
This method uses memoization to improve the efficiency of the recursive approach. 
It stores the results of previous function calls in an array called memo, which is used to avoid redundant calculations. 
When a value of F(n) is needed, the function first checks if it has already been calculated and stored in memo. 
If so, it returns that value; if not, it calculates the value recursively and stores it in memo for later use. 
This method is more memory-efficient than the basic recursive approach because it avoids redundant function calls.

However, it still incurs some overhead due to array access and checking.
*/
int memo_recursion(int n, int *memo){
    int result;

    if (memo == NULL) {
        memo = (int*) calloc(n + 1, sizeof(int));
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 2;
    }
    
    if (n < 3) return memo[n];
    else if(memo[n] != 0) return memo[n];
    else {
        result = memo_recursion(n-2, memo) + memo_recursion(n-3, memo);
        memo[n] = result;
    }
    
    return result;
}