#include <bits/stdc++.h> 
using namespace std; 
int V;
int minKey(int key[], bool mstSet[]) 
{ 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (mstSet[v] == false && key[v] < min) 
			min = key[v], min_index = v; 

	return min_index; 
} 

void printMST(int parent[], int graph[10][10]) 
{ 
	cout<<"Cities \tCost\n"; 
    int sum=0;
	for (int i = 1; i < V; i++) 
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n",sum+=graph[i][parent[i]] ; 
    cout<<"Total Cost of connection = "<<sum;
} 

void primMST(int graph[10][10]) 
{ 
	int parent[V]; 
	
	int key[V]; 
	
	bool mstSet[V]; 

	for (int i = 0; i < V; i++) 
		key[i] = INT_MAX, mstSet[i] = false; 

	key[0] = 0; 
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++) 
	{ 
		int u = minKey(key, mstSet); 

		mstSet[u] = true; 

		
		for (int v = 0; v < V; v++) 

			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
				parent[v] = u, key[v] = graph[u][v]; 
	} 

	printMST(parent, graph); 
} 

int main() 
{ 
	cout<<"\n\t Enter number of cities in State --> ";
    cin>>V;
    int graph[10][10]; 
    for(int i=0; i<V; i++)
        for (int j = 0; j < V; j++)
            cout<<"\n\tEnter distance between city "<<(i+1)<<" and city "<<(j+1)<<" ---> ", cin>>graph[i][j];
	
    primMST(graph); 

	return 0; 
} 