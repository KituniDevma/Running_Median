#include <iostream>
using namespace std;

//Function to get the median of a given array of elements.
double Median(int arr[], int size){
    if (size%2 == 0){            //Median- if the number of elements is an even number.
        int mid1 = size / 2;
        int mid2 = mid1 - 1;
        double median = (double (arr[mid1] + arr[mid2])) / 2;
        return ("%.1f", median);
    }
    else {                       //Median- if the number of elements is an odd number.
        int mid = size/2 ;
        double median = arr[mid];
        return median;
    }
}

//Function to get the sorted array with the median of that array.
void runningMedian(int arr[], int size){
    for (int i=0; i<size; i++){                     //Sorting the array using insertion sort. 
        int value = arr[i];
        int hole = i;
        while (hole>0 && arr[hole-1]>value){
            arr[hole] = arr[hole-1];
            hole = hole - 1;
        }
        arr[hole] = value;
        for (int j=0; j<=i; j++){
            cout << arr[j]<< " ";
        }
        cout <<  Median(arr, i+1)<< endl;          //Finding the median in each sorted iteration.
    }
    return;
}


int main(){
    int size;
    cout << "Enter the number of elemnts : ";    //Input the number of elements of the array.
    cin >> size;
    int arr[size];
    for (int i=0; i<size ; i++){                 //Building up the array.
        cout << "Enter the element: ";
        cin >> arr[i];
    }
    runningMedian(arr,size);                     //Calling the runningMedian function.

}