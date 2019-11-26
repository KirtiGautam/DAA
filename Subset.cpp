#include <iostream>
using namespace std;

bool isSubsetSum(int set[], int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;

    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);

    return isSubsetSum(set, n - 1, sum) ||
           isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main()
{
    int n, sum;
    cout << "Enter the number of elements in the set ---> ";
    cin >> n;
    int set[n];
    cout << "Enter the elements in the set ---> ";
    for (int i = 0; i < n; i++)
        cin >> set[i];
    cout << "Enter the sum of subset ---> ";
    cin >> sum;

    if (isSubsetSum(set, n, sum))
        cout << "Found a subset with sum = "<<sum;
    else
        cout << "No subset with sum = "<<sum;
    return 0;
}