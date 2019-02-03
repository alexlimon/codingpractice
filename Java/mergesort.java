import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    //sort will call merge sort and process the array appropriately.
    static void sort(int[] prices) {

        int[] tempArr = new int[prices.length];
        
        mergeSort(prices,tempArr,0,prices.length-1);
        }
        static void mergeSort(int arr[], int tempArr[], int start, int end){
            if(start < end){
                int mid = (start + end) / 2;
                mergeSort(arr,tempArr,start,mid);
                mergeSort(arr,tempArr,mid+1,end);
                merge(arr,tempArr,start,mid,end);
            }
        }

        static void merge(int arr[], int tempArr[], int start, int mid, int end){
            
            for(int i = start; i <= end; i++) tempArr[i] = arr[i];
            
            int leftP = start;
            int rightP = mid + 1;
            int realP = start;

            while(leftP <= mid && rightP <= end){
                if(tempArr[leftP] <= tempArr[rightP]){
                    arr[realP] = tempArr[leftP];
                    leftP++;
                }
                else{
                    arr[realP] = tempArr[rightP];
                    rightP++;
                }
                realP++;
            }

            while(leftP <= mid){
                arr[realP] = tempArr[leftP];
                realP++;
                leftP++;
            }
    }
        

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0]);
        
        // we call the array prices to give it some sort of purpose i guess..
        int[] prices = new int[n];

        String[] pricesItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int pricesItem = Integer.parseInt(pricesItems[i]);
            prices[i] = pricesItem;
        }

        sort(prices);

        bufferedWriter.write(String.valueOf(Arrays.toString(prices)));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
