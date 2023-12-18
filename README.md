# Push Swap
## What is it?
Push Swap is a project from the 42 schools, it consists on a sorting algorithm.

Using two stacks, the operations allowed are:
1. Swap: change the first and second numbers of a stack.
2. Rotate: send the first number of a stack to the bottom.
3. Reverse rotate: sent the last element of a stack to the top.
4. Push: Send the first element of a stack to the top of the other stack.

I used an algorithm called [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97), which is not computationally efficient, but is instead optimized for this project and the allowed operations.

## How to use
Run ```make``` to compile the executable (named ```push_swap```), run with ```./push_swap ARGUMENTS```, where ARGUMENTS is the series of numbers to be sorted. \
It has some rules and parsing: No duplicates, no letters/strings, no numbers > INT_MAX or < INT_MIN, etc... In all these cases it will simply display "Error".

## Tester
Check out my tester for this project at: https://github.com/albertcaballero/42Push_Swap-Tester
