/* Algorithm
Linear approach:
One way to solve this problem is to iterate over the array and find an element that is greater than or equal to its neighbors and return it.
Time Complexity: O(n)
Efficient approach:
1. Initialize start = 0, end = array.length - 1
2. Repeat following steps till peak element is found:
   a). Find mid = (start+end)/2
   b). If array[mid] is peak element, return array[mid]
   c). Else if array[mid-1] > array[mid], find peak in left half of array
       set end = mid - 1
   d). Else find peak in right half of array
       set start = mid + 1
Time Complexity: O(log n)



------------------------------------------------------------------------------------------------- */

public class PeakElement {
 
    public static Integer getPeakElement(int[] array) {
 
        if (array == null || array.length == 0) {
            return null;
        }
 
        int n = array.length;
 
        int start = 0;
        int end = n - 1;
 
        while (start <= end) {
            int mid = (start + end) / 2;
 
            if ((mid == 0 || array[mid - 1] <= array[mid]) && (mid == n - 1 || array[mid] >= array[mid + 1])) {
                return array[mid]; // array[mid] is peak element
            } else if (mid > 0 && array[mid - 1] > array[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return null;
    }
 
    public static void main(String[] args) {
        int[] array = { 15, 20, 25, 35, 45, 50, 60 };
        Integer peak = getPeakElement(array);
        System.out.println(peak != null ? "Peak Element is " + peak : "No peak element!");
    }
}
