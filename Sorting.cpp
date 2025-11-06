#include <iostream> 
#include <vector>
using namespace std; 
void bubbleSort(int arr[],int n){
    for(int i = 0; i< n-1 ; i++){
        for(int j =0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
    cout<<"After Bubble sort: "<<endl; 
    for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
    }cout<<endl; 
}
void selectionSort(int arr[], int n){
    for(int i =0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[i]){
                int temp = arr[j];
                arr[j] = arr[j];
                arr[i] = temp;
            }
        }
    }
    cout<<"After selection sort: "<<endl; 
    for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
    }cout<<endl; 
}
void insertionSort(int arr[], int n){
    int curr, prev; 
    for(int i = 1; i<n; i++){
        curr = arr[i];
        prev = i-1; 
        while(prev>0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev --; 
        }
        arr[prev+1] = curr; 
    }
    cout<<"After selection sort: "<<endl; 
    for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
    }cout<<endl; 
}
void merge(vector<int>& arr, int mid, int st, int end){
    int i =st; int j = mid+1; 
    vector<int> temp; 
    while(i<=mid && j<=end){
        if(arr[i]>arr[j]){
            temp.push_back(arr[j]);
            j++;
        }else{
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i<=mid){
       temp.push_back(arr[i]); 
       i++; 
    }
    while(j<=end){
        temp.push_back(arr[j]); 
        j++;
    }
    for(int idx =0; idx<temp.size();idx++){
        arr[st+idx] = temp[idx];
    } 
}
void mergeSort(vector<int> & arr, int st, int end){
    if(st<end){
        int mid = st + (end-st)/2; 
        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,mid,st,end);
    }  
}

int partition(vector<int>& arr, int st, int end){
    int idx = st -1; 
    int pivot = arr[end];
    for(int i =st; i<end; i++){
        if(arr[i]<pivot){
            idx++; 
            swap(arr[idx],arr[i]);
        }
    }
    idx++; 
    swap(arr[idx],arr[end]);
    return idx; 
}
void quickSort(vector<int>& arr, int st, int end){
    if(st<end){
        int pivIdx = partition(arr,st,end);
        quickSort(arr,st,pivIdx-1);
        quickSort(arr,pivIdx+1,end);
    }
}
// Function to heapify a subtree rooted with node i, which is an index in arr[]
// n is the size of the heap
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;      // Initialize largest as root
    int left = 2*i + 1;   // left child index
    int right = 2*i + 2;  // right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}


void heapSort(vector<int>& arr, int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract elements
    for (int i = n - 1; i >= 0; i--) {
        // Move current root (largest) to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    cout<<"Using Bubble Sort: "<<endl; 
    bubbleSort(arr,6);
    cout<<"Using Selection Sort: "<<endl; 
    selectionSort(arr,6);
    cout<<"Using insertion Sort: "<<endl; 
    insertionSort(arr,6);
    cout<<"Using Merge Sort:"<<endl; 
    vector<int> vec = {34,56,12,10,7,77,90};
    mergeSort(vec,0,6);
    cout<<"After Merge Sort: "<<endl; 
    for(int i =0; i<=6; i++){
        cout<<vec[i]<<" ";
    }cout<<endl; 
    cout<<"Using Quick Sort: "<<endl; 
    vector<int> vec1 = {33,78,2,12,73,67,94};
    quickSort(vec1,0,6);
    cout<<"After Quick Sort: "<<endl; 
    for(int i =0; i<=6; i++){
        cout<<vec1[i]<<" ";
    }cout<<endl; 
    cout<<"Using Heap Sort: "<<endl; 
    vector<int> vec2 = {23,44,55,6,77,82,99};
    heapSort(vec2,7);
    cout<<"After Heap Sort: "<<endl; 
    for(int i =0; i<=6; i++){
        cout<<vec2[i]<<" ";
    }cout<<endl; 
    return 0;
}
