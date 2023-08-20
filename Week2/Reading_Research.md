<!-- Questions -->
1. What is Quicksort?
2. Compare the Strengths and Weaknesses of Quicksort.
3. What are the factors to consider before using Quicksort?

<!-- Answers -->
1. **What is Quicksort?**
   Quicksort is a sorting algorithm that uses a divide-and-conquer approach to sort an array or list of elements by selecting a 'pivot' element, partitioning the other elements into two sub-arrays - one with elements less than the pivot and another with elements greater than the pivot. The process is recursively applied to these sub-arrays until the entire array is sorted.

2. **Compare the Strengths and Weaknesses of Quicksort:**
   Strengths:
   - Fast average-case performance.
   - Efficient for large datasets.
   - In-place sorting, minimizing memory usage.
   - Doesn't require additional memory for data structures.
   
   Weaknesses:
   - Worst-case time complexity can be poor (unbalanced partitions).
   - Not stable (may change relative order of equal elements).
   - Vulnerable to maliciously chosen pivots (security risk).
   - Performance degrades with nearly sorted data.
   
3. **What are the factors to consider before using Quicksort?**
   - **Dataset:** Quicksort is efficient for large datasets; consider it for substantial amounts of data.
   - **Distribution:** Balanced partitions improve performance; consider data distribution.
   - **Memory:** Quicksort is memory efficient due to in-place sorting; useful for limited memory.
   - **Stability:** If maintaining relative order of equal elements matters, Quicksort might not be suitable.
   - **Pivot Choice:** Pivot selection affects performance; random or median-of-three are common choices.
   - **Worst-case Tolerance:** If avoiding worst-case time complexity is critical, consider alternatives.
   - **Security:** Beware of potential security risks due to pivot manipulation.
   - **Pre-sorting:** For nearly sorted data, other algorithms might perform better.
   