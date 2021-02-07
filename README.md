# A-numbers_unique_partition_recursion_dynamic_memory_allocation_but_random_order_count
A+numbers_unique_partition_recursion_dynamic_memory_allocation_but_random_order_count
Permuting the summands in a partition does not give a new partition. For example, the
partition 1+2+2 is treated the same as 2+1+2 and also as 2+2+1.
You are asked to compute the number of partitions of n. Write a recursive function to this
effect. In order to avoid repetitions, we choose the summands in a non-decreasing order. That
is, if 1 and 2 are already chosen as the previous summands, the next summand cannot be less
than 2. Pass two arguments to your recursive function. The first stands for the amount left to be
balanced by summands and the second stands for the largest summand chosen so far. Recursion
stops when the first argument becomes 0. Here is a possible prototype for the function.
