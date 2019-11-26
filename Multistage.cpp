#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cout << "Enter number of nodes ---> ";
    cin >> N;

    int graph[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            graph[i][j] = INT_MAX;
        }
    }

    int edg;
    cout << "Enter number of edges ---> ";
    cin >> edg;
    for (int i = 0; i < edg; i++)
    {
        int temp, temp1;
        cout << "Enter source and destination of edge " << i + 1 << "---> ";
        cin >> temp >> temp1;
        cout << "Enter cost of edge " << i + 1 << "---> ";
        cin >> graph[temp - 1][temp1 - 1];
    }

    int dist[N];

    dist[N - 1] = 0;

    for (int i = N - 2; i >= 0; i--)
    {

        dist[i] = INT_MAX;

        for (int j = i; j < N; j++)
        {

            if (graph[i][j] == INT_MAX)
                continue;
            dist[i] = min(dist[i], graph[i][j] + dist[j]);
        }
    }
    cout << "Shortest distance from  1 to " << N << " ---> " << dist[0];
}