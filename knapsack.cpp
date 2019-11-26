#include<iostream>
using namespace std;
int main(){
    int length, maxWeight;
    cout<<"\n\tEnter the number of values in knapsack --> ";
    cin>>length;
    cout<<"\n\tEnter the values in knapsack --> ";
    int val[length], weights[length];
    for(int i=0; i<length; i++)
        cin>>val[i];
    cout<<"\n\tEnter the weights in knapsack --> ";
    for(int i=0; i<length; i++)
        cin>>weights[i];
    cout<<"\n\tEnter the maximum weight knapsack --> ";
    cin>>maxWeight;
    int sum=0, optimal=-1, j, newValue=0;
    for(int i=0; i<length; i++){
        j=-1;
        if(weights[i]<maxWeight){
            newValue = val[i];
            sum = weights[i];
        }
        while (j<length){
            j++;
            if(j==i)
                continue;
            if((sum+weights[j])<=maxWeight){
                sum+=weights[j];
                newValue+=val[j];
            }
        }
        if(newValue>optimal)
            optimal=newValue;
        newValue=0;
        sum=0;
    }
    cout<<"\n\tOptimal solution of knapsack --->  "<<optimal;
}