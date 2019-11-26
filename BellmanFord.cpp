#include <iostream>
using namespace std;

class graph
{
public:
    int source;
    int destination;
    int cost;
};

int main()
{
    int edges, vertices;
    cout << "Enter the number of edges --> ";
    cin >> edges;
    cout << "Enter the number of vertices --> ";
    cin >> vertices;
    graph Graph[edges];
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter source, destination and cost of edge " << i + 1 << " --> ";
        cin >> Graph[i].source >> Graph[i].destination >> Graph[i].cost;
    }

    int distance[vertices];
    for (int i = 0; i < vertices; i++)
        distance[i] = 9999;
    distance[0] = 0;
    for (int i = 0; i < (vertices - 1); i++)
    {
        for (int j = 0; j < edges; j++)
        {
            int src = Graph[j].source, dest = Graph[j].destination;
            if (distance[src] + Graph[j].cost < distance[dest])
                distance[dest] = distance[src] + Graph[j].cost;
        }
    }
    for (int i = 0; i < (vertices - 1); i++)
    {
        for (int j = 0; j < edges; j++)
        {
            int src = Graph[j].source, dest = Graph[j].destination;
            if (distance[src] + Graph[j].cost < distance[dest]){
                cout << "Negative weight cycle";
                return 0;
            }            
        }
    }
    cout << "Vertex \tDistance from Source\n";
    for (int i = 0; i < vertices; i++)
        cout << i << " \t" << distance[i] << "\n";
    return 0;
}