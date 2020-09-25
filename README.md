# Pushswap
Project in 21 school curriculum. Objective: to sort given array using two stacks and specified operations.

Summary:
This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting.

Two stacks are named A and B accordingly.

Algorithm:
1. Parse arguments from standard input. It can be given in format of single string with numbers separated by space or just separate arguments.
  1.1 Read arguments and turn them into integers.
2. Store values in array. It will be stack A.
3. Sorting algorithm:
4. Analyze stack A:
5. Push elements to stack B until the stack A is sorted or there are at least 3 elements
6. Then analyze stack B. Choose the most optimal operation by calculating cost of moving each element into appropriate place into stack A.
7. Calculation algorithm: for each element
  count the amount of elements you have to rotate (a.k.a. move) to one or another end of the stack B. This is to understand the closest item to place it to stack A.
  7.2 Count the amount of operations necessary for the current element to be put in the order in stack A. Count how much elements you have to rotate so that the element that in sorted stack A including current element. will be on top of stack A.
  7.3 Add these two values. That's how you get the cost of the operation for the element on each cycle.
7.4 During every cycle you compute the cost of all elements in stack B and choose the "cheapest" one and conduct the set of operations with least actions.
7.5 The stack A is sorted! You're wonderful!
