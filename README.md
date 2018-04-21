# backtracking-1
Given an array of n elements with all elements positive generate all possible according to 2 rules:- 1)Consider any 2 adjacent elements i and i+1 and i+1 is not the last element so you can decrease both by 1 and add 1 to the i+1 th element. 2)if i+1 is the last element so u can reduce both by 1 and append 1 to the last.
In this we will use linked list to store the generated.
It is more efficient in terms of space and time since we will not need to the copy the previous array and then add 1,we can directly append 1 to the list also we need to take care of max_size initially.
