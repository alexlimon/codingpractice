import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;


public class MergeSort {

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
    

    public static void main(String[] args) throws IOException {

        //enter your array here.
        int[] prices = {4, 34, 5, 43 ,1 , 53};

        System.out.println("Unsorted: "+ Arrays.toString(prices));

        sort(prices);

        System.out.println("Sorted: " + Arrays.toString(prices));
       
    }


}


