Deals with the problems in array section.

1. Array Reverse:
    - Given an array (or string), the task is to reverse the array/string.
    - For example:
        Input: arr[] = {1.2.3}
        Output: arr[] = {3,2,1}
    - We can do it either iteratively or recursively.

    * Iteratively:
        i. Initialise start and end indexes as start=0 and end=n-1;
        ii. In a loop, swap arr[start] with arr[end] and change start and end as follow:
            start=start+1, end=end-1.
    
    * Recursively:
        i. Initialise start and end indexes as start=0, end=n-1
        ii. Swap arr[start] with arr[end]
        iii. Recursively call reverse for rest of the array.
    
    - In both the case, we will be using two pointers. One for starting of the array and the other for the end of the array.

2. Maximum and minimum of an array using minimum number of comparisons:
    - Given an array of size N. The task is to find the maximum and the minimum element of the array using minimum number of comparison.
    - For example:
        Input: arr[] = {3,5,4,1,9}
        Output: Minimum element: 1
                Maximum element: 9
    - First of all, how do we return multiple values from a function? We can do either using structures or pointers.
    - We have created a structure named pair (which contains min and max) to return multiple values.
    - Create a pair.

    * Maximum and minimum of an array using Sorting:
        - Approach:
            > One approach to find the maximum and minimum element in an array is to sort the array in ascending order. Once the array is sorted, the first element of the array will be minimum element and the last element of the array will be maximum element.
        - Algorithm:
            > Initialise an array.
            > Sort the array in ascending order.
            > The first element of the array will be the minimum element.
            > The last element of the array will be the maximum element.
            > Print the minimum and the maximum element.
        - Complexity Analysis:
            > The time complexity of this approach is O(nlogn), where n is the number of elements in the array, as we are using a sorting algorithm.
            > The space complexity if O(1), as we are not using any extra space.
        - Number of comparisons:
            > The number of comparisons made to find the minimum and maximum elements is equal to the number of comparisons made during the sorting process.
            > For any comparison-based sorting algorithm, the minimum number of comparisons required to sort an array of n elements is O(nlogn). Hence, the number of comparisons made in this approach is also O(nlogn).

    * Maximum and Minimum of an array using Linear Search:
        - Approach:
            > Initialise values of min and max as minimum and maximum of the first two elements respectively.
            > Starting from 3rd, compare each element with max and min, and change max and min accordingly (i.e., if the element is smaller than min then change min, else if the element is greater than max then change max, else ignore the element).
        - Algorithm:
            > Initialise an array.
            > Check for the number of elements in the array, if there is one element present return it as both min and max.
            > If there are more than one, compare the first and second. Initialise the larger as the max and the smaller as the min.
            > Starting from the third compare the elements one by one with min and max.
            > Whenever a new min or max is found, update the min and max variable.
            > Traverse the whole array doing same.
        - Complextiy Analysis:
            > The time complexity of this appraoch is O(n), since we will compare all the elements in the array.
            > Space complexity of this approach is O(1), since no extra space was needed.
        - Number of comparisons:
            > In this method, the total number of comparisons is 1+2(n-2) in the worst case and 1+(n-2) in the best case.
            > In this implementation, the worst case occurs when elements are sorted in descending order and the best case occurs when elements are sorted in ascending order.
    
    * Maximum and Minimum of an array using the tournament method:
        - Approach:
            > Divide the array into two parts and compare the maximums and minimums of the two parts to get the maximum and the minimum of the whole array.
        - Algorithm:
            > Initialise the array.
            > If the array size is one, then return the element as both max and min.
            > Else if the array size is two, then compare the elements and return min and max.
            > Else, recursively call the the left and right side of the array.
            > Atlast, one comparison determines true max of the two candidates.
            > And, one comparison determines true min of the two candidates.
        - Complexity Analysis:
            > Time complexity of the implementation is O(n).
            > Space complexity of the implementation is O(logn) as the stack will be filled for the maximum height of the tree formed during recursive calls same as a binary tree.
        - Number of comparisons:
            > Let the number of comparisons be T(n). T(n) can be written as:
                >> Algorithmic Paradigm: Divide and Conquer
                    T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2;
                    T(2) = 1;
                    T(1) = 0;
                    If n is the power of 2, then we can write T(n) as:
                    T(n) = 2T(n/2) + 2;
                    After solving the recursion, we get
                    T(n) = 3(n/2)-2;
            > Thus, the approach does 3n/2-2 comparisons if n is a power of 2. And if does more than 3n/2-2 comparisons if n is not a power of 2.
    
    * Maximum and Minimum of an array by comapring in pairs:
        - Approach:
            > If the number of elements in the array is odd, then initialise the first element as both min and max. For even first two.
            > We compare in pair for the rest of the array.
        - Algorithm:
            > Initialise an array.
            > If n is odd then initialise min and max as the first element.
            > If n is even then compare first two elements and initialise the smaller as min and the larger as max.
            > For the rest of the array, pick them in pairs and compare their maximum and minimum with max and min respectively.
        - Complexity Analysis:
            > Time complexity of the implementation is O(n).
            > Space complexity of the implementation is O(1) as no extra space is needed.
        - Number of comparisons:
            > The total number of comparisons: Different for odd and even, are:
                >> If n is nodd: 3*(n-1)/2;
                >> If n is even: 1+3*(n-1)/2 = 3n/2-2;
            > For even, 1 initial comparison for initialising min and max, and the other for the rest of the elements.
    
    - The third and fourth approaches make an equal number of comparisons when n is a power of 2.
    - In general, method 4 seems to be the best.

3. Kth Min:

    - Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the kth smallest element in the given array. It is given that all the elements are distinct.
    - One way to do this is to sort the array and get the element at the (k-1)th index.
        > This method takes time complexity of O(nlogn) and space complexity of O(1).

4. Sort an array of 0s, 1s and 2s:
    - Given an array of size N containing only 0s, 1s and 2s; sort the array in ascending order.
    - We can do this by counting the number of 0s, 1s and 2s in the given array and updating the array accordingly.

5. Move all negative numbers to beginning and positive to end with constant extra space:
    - An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.
    - For example:
        Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
        Output: -12 -13 -5 -7 -3 -6 11 6 5
    - Order of elements isn't necessary here.
    
    * Naive Approach:
        - The idea is to sort the array of elements, this will make sure that all the negative elements will come before all the positive elements.
        - Complexity Analysis:
            > Time complexity is O(nlogn), where n is the length of the given array.
            > Space complexity is O(1).
        - In this approach the final order is sorted as well.
    
    * Efficient Approach:
        - The idea is to simply apply the partition process of quicksort.
        - The logic is simple, we start from the leftmost element and keep track of the index of smaller (or equal) elements as i. While traversing, if we find a smaller element, we swap the current element with arr[i]. Otherwise, we ignore the current element.
        - Complexity Analysis:
            > Time complexity is O(N).
            > Space complexity is O(1).
    
    * Two Pointer Approach:
        - The idea is to solve this problem with constant space and linear time is by using a two-pointer or two-variable approach where we simply take two variables like left and right which hold the 0 and N-1 indexes. Just need to check that:
            > Check if the left and right pointer elements are negative then simply increment the left pointer.
            > Otherwise, if the left element is positive and the right element is negative then simply swap the elements, and simultaneously increment and decrement the left and right pointers.
            > Else if the left element is positive and the right element is also positive then simply decrement the right pointer.
            > Repeat the above 3 steps until the left pointer <= right pointer.
        - This is an in-place rearranging algorithm for arranging the positive and negative numbers where the order of elements is not maintained.
        - Complexity Analysis:
            > Time complexity of the implementation is O(N).
            > Space complextiy of the implementation is O(1).
        - The problem becomes difficult if we need to maintain the order of elements.
    
    * Approach 3:
        - This approach is called Dutch National Flag for two colors.
        - The first color will be for all negative integers and the second color will be for all positive integers.
        - We will divide the array into three partitions with the help of two pointers, low and high.
            > arr[1..low-1] negative integers
            > arr[low..high] unknown
            > arr[high+1..N] positive integers
        - Now, we explore the array with the help of low pointer, shrinking the unkown partition, and moving elements to their corrent partition in the process.
        - We do this until we have explored all the elements, and size of the unknown partition shriks to zero.
        - Complexity analysis:
            > Time complexity for the above approach is O(N).
            > Space complexity for the above approach is O(1).
    
    - The order of the elements doesn't matter here.