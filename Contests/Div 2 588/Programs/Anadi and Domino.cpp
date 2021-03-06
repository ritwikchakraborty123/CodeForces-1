
#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_vertices, no_of_edges;
    cin >> no_of_vertices >> no_of_edges;

    vector <vector <int> > has_edge(no_of_vertices + 1, vector <int> (no_of_vertices + 1, false));
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;

        has_edge[u][v] = true;
        has_edge[v][u] = true;
    }

    int answer = 0;
    if(no_of_vertices < 7)
    {
        answer = no_of_edges;
    }
    else if(no_of_vertices == 7)
    {
        for(int i = 1; i <= no_of_vertices; i++)
        {
            for(int j = i + 1; j <= no_of_vertices; j++)
            {
                int lost_edges = 0;

                for(int k = 1; k <= no_of_vertices; k++)
                {
                    if(has_edge[i][k] && has_edge[j][k])
                    {
                        lost_edges++;
                    }
                }

                answer = max(answer, no_of_edges - lost_edges);
            }
        }
    }

    cout << answer << "\n";

    return 0;
}
