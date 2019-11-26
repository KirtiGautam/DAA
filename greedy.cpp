#include <iostream>
using namespace std;

class edge
{
public:
    int weight;
    int source;
    int destination;
};

class subset
{
public:
    int parent;
    int rank;
};

void swap(edge *xp, edge *yp)
{
    edge temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void ascending(edge edges[], int number)
{
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
                swap(&edges[j], &edges[j + 1]);
        }
    }
}

int find(subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void makeTree(edge edges[], int index[], int number, int numberEdges)
{
    int i = 1, ind = 0;
    subset *subsets = new subset[(numberEdges * sizeof(subset))];
    for (int v = 0; v < numberEdges; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (ind < (numberEdges - 1) && i <= number)
    {
        int x = find(subsets, edges[i].source);
        int y = find(subsets, edges[i].destination);

        if (x != y)
        {
            index[ind++] = i;
            Union(subsets, x, y);
        }
        i++;
    }
}

int main()
{
    int number, numberEdges;
    cout << "Enter the number of paths to connect all homes  ---> ";
    cin >> number;
    cout << "Enter the number of homes ---> ";
    cin >> numberEdges;
    edge edges[number];
    int index[numberEdges];
    for (int i = 0; i < number; i++)
    {
        cout << "Enter the cost, source and destination college of path " << i + 1 << " ---->\n";
        cin >> edges[i].weight;
        cin >> edges[i].source;
        cin >> edges[i].destination;
    }

    ascending(edges, number);

    cout << "\n\tShortest path for newspaper distributor :\n\tCost\tSource\tDestination";

    makeTree(edges, index, number, numberEdges);

    int cost = 0;

    for (int i = 0; i < (numberEdges - 1); i++)
    {
        int ind = index[i];
        cout << "\n\t" << edges[ind].weight << "\t" << edges[ind].source << "\t" << edges[ind].destination;
        cost += edges[ind].weight;
    }
    cout << "\n\tTotal Cost to deliver newspaper = " << cost;

    return 0;
}