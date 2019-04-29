#include <stdio.h>
#include <limits.h>
#include <iostream>

// ����� ������ �����
#define V 9


int minDistance(int dist[], bool sptSet[])
{
	// �������� ��������
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// ������� �����

void printSolution(int dist[], int n)
{
std::cout << ("Vertex  and Distance from Source\n") <<std::endl;
	for (int i = 0; i < V; i++) {
		std::cout << "Vertex " << i << " Distance from Source" << dist[i] <<std::endl;
	}
}


void dijkstra(int graph[V][V], int src)
{
	int dist[V];     
					 

	bool sptSet[V]; // sptSet[i] ���� ���������� �� ���������� ������� � ��������� �����

	
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// ����� ������� �� ���� �� 0 �������
	dist[src] = 0;

	// ����� �����
	for (int count = 0; count < V - 1; count++)
	{
		//������ ������� � ��������� �������� � ������ �� �� �� ���� ��������
		int u = minDistance(dist, sptSet);

		// ������� ������ �������
		sptSet[u] = true;

		for (int v = 0; v < V; v++)

		
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// ����
	printSolution(dist, V);
}