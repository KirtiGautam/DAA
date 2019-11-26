#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void merge(int arr[], int l, int m, int r){ 
    int i, j, k,n1 = m - l + 1, n2 =  r - m, L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int arr[], int l, int r) { 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

int main(){
    ifstream infile; 
    infile.open("rols.txt"); 
    string data;
    int length=0;
    while (!infile.eof()){
        getline(infile, data);
        length++;
    }
    infile.close();
    int array[length],i=0;
    ifstream fi;
    fi.open("rols.txt"); 
    cout<<"File opened with "<<length<<" roll numbers\n";
    while (getline(fi, data)){
        array[i]=stoi( data );
        i++;
    }
    cout<<"Array made\n";
    fi.close();
    mergeSort(array, 0, length - 1); 
    cout<<"Array Sorted \n";
    ofstream myfile;
    myfile.open("Sorted.txt");
    i=0;
    while(i<length){
        myfile<<array[i]<< "\n";
        i++;
    }
    cout<<"Sorted roll number in Sorted.txt \n";
    myfile.close();
    return 0;
}