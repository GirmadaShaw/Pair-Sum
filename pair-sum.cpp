/*
Given an array of N integers, and an integer K,
 the task is to find the number of pairs of integers in the array whose sum is equal to K.
Input: arr[] = {1, 5, 7, -1, 5}, K = 6
Output:  3
Explanation: Pairs with sum 6 are (1, 5), (7, -1) & (1, 5).
*/

#include <iostream>
#include <algorithm>

int main()
{
    int arr[] = {1, 5, 7, -1, 5}, sum = 6 ;
    //int arr[] = {1, 1, 1, 1}, sum = 2;
    //int arr[] = {10, 12, 10, 15, -1, 7, 6, 5, 4, 2, 1, 1, 1}, sum = 11 ;
    int size = sizeof(arr)/sizeof(int) ;
    int count_pairs = 0 ;

//Solution 1
//Time Complexity: O(n^2) , Space Complexity: O(1)

    for( int i=0 ; i<size ; i++ )
    {
        for( int j=i+1 ; j<size ; j++ )
        {
            if ( arr[i] + arr[j] == sum )
            {
                //std::cout << arr[i] << " " << arr[j] << std::endl ; 
                count_pairs ++ ;
            }
        }
    }
    std::cout << "Total Pairs: " << count_pairs << "\n" ; 

    
//Solution 2
//Time Complexity: O(nlogn) , Space Complexity: O(1)
    
    count_pairs = 0 ;
    std::sort  (  arr ,  arr+size ) ;

    int target, start , end , mid ;
    for( int i=0 ; i<size-1 ; i++ )
        {
            target = sum - arr[i]  ;
            start = i+1 ; end = size -1 ; mid = start + ( (end-start)/2 ) ;
            
            while ( start <= end )
                {
                    if ( arr[mid] ==  target )
                        {
                            count_pairs ++ ; 
                            break ; 
                        }
                    else if (arr[mid] > target)
                        end = mid - 1;
                    else 
                        start = mid + 1 ;
                    mid = start + ( (end-start)/2 ); 
                }
        }

    std::cout << "Total Pairs: " << count_pairs ; 

std::cout<< std::endl ;

//Solution 3 
//Time Complexity: O(logn) , Space Complexity: O(1)



    count_pairs = 0 ;
    int left=0, right=size-1 ;
    while (left<right)
    {
        if ( arr[left] + arr[right] == sum )
        {
            count_pairs ++ ;
            left ++;
            right -- ;
        }

        else if( arr[left] + arr[right] < sum )
            left --;

        else
            right ++;
    }

    std::cout<< "Total Pairs: " << count_pairs ;

}

    