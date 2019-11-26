#include <iostream>
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
            if (i == j)
            {
                graph[i][j] = 0;
                continue;
            }
            graph[i][j] = 9999;
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

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    cout<<"\nSolution matrix :\n";

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            cout << graph[i][k] << " ";
        }
        cout << "\n";
    }
}