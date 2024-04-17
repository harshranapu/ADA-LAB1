#include <iostream>
#include <list>
#include <unordered_map>
#include <climits>

using namespace std;

template <typename T>
class graph
{
public:
    unordered_map<T, list<pair<T, int>>> adjList;

    void addEdges(T u, T v, bool direction, int wt)
    {
        if (direction == 1)
        {
            adjList[u].push_back(make_pair(v, wt));
        }
        else
        {
            adjList[u].push_back(make_pair(v, wt));
            adjList[v].push_back(make_pair(u, wt));
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> {";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << ")";
            }

            cout << "}" << endl;
        }
    }

    unordered_map<T, int> singleSourceShortestPath(T src)
    {
        unordered_map<T, bool> visited;
        unordered_map<T, int> distance;

        for (auto i : adjList)
        {
            visited[i.first] = false;
            distance[i.first] = INT_MAX; 
        }

        visited[src] = true;
        distance[src] = 0;

        for (int i = 0; i < adjList.size() - 1; i++)
        {
            T u;
            int minDist = INT_MAX;
            for (auto i : adjList)
            {
                if (!visited[i.first] && distance[i.first] < minDist)
                {
                    u = i.first;
                    minDist = distance[i.first];
                }
            }

            visited[u] = true;

            for (auto nbr : adjList[u])
            {
                T v = nbr.first;
                int wt = nbr.second;
                if (!visited[v] && distance[u] != INT_MAX && distance[u] + wt < distance[v])
                {
                    distance[v] = distance[u] + wt;
                }
            }
        }

        return distance;
    }
};

int main()
{
    graph<int> g;
    g.addEdges(0, 1, true, 4);
    g.addEdges(0, 7, true, 8);
    g.addEdges(1, 2, true, 8);
    g.addEdges(1, 7, true, 11);
    g.addEdges(2, 3, true, 7);
    g.addEdges(2, 8, true, 2);
    g.addEdges(2, 5, true, 4);
    g.addEdges(3, 4, true, 9);
    g.addEdges(3, 5, true, 14);
    g.addEdges(4, 5, true, 10);
    g.addEdges(5, 6, true, 2);
    g.addEdges(6, 7, true, 1);
    g.addEdges(6, 8, true, 6);
    g.addEdges(7, 8, true, 7);

    cout << "Adjacency List:\n";
    g.printAdjList();
    cout << "\nSingle Source Shortest Path from vertex 0:\n";
    unordered_map<int, int> distances = g.singleSourceShortestPath(0);
    for (auto i : distances)
    {
        cout << "Vertex: " << i.first << ", Distance: " << i.second << endl;
    }

    return 0;