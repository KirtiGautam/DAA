#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; 
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++)  
    {  
        
        if (arr[j] < pivot)  
        {  
            i++;
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
  
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
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
    quickSort(array, 0, length - 1);  

    cout<<"Array Sorted \n";

    ofstream myfile;
    myfile.open("QuickSorted.txt");
    i=0;
    while(i<length){
        myfile<<array[i]<< "\n";
        i++;
    }
    cout<<"Sorted roll number in QuickSorted.txt \n";
    myfile.close();
    return 0;
}