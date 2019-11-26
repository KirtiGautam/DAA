#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int BS(int Array[], int number, int data){
    int Left = 0, Right = number -1;
    
    while (Left <= Right){
        int mid = (Left + Right) / 2;
        if (Array[mid] < data)
            Left = mid + 1;
        else if (Array[mid] > data)
            Right = mid - 1;
        else
            return mid;
    }
    return -1;

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
    for(int j=0; j<length;j++){
        for(int i=0; i<length;i++){
            if(array[i]>array[i+1]){
                int temp= array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                continue;
            }
        }
    }
    cout<<"Array Sorted \n";
    int d;
    cout<<"\nEnter roll number to be searched-->";
    cin>>d;
    int number=BS(array,length,d);
    if(number!=-1)
        cout<<"\nFound "<<array[number]<<" at place "<<number;
    else
        cout<<"\nNo such roll number";
    return 0;
}