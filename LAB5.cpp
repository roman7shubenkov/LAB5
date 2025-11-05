#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


void addDirectedEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
}

void f1() {
    int vertices = 5, random_number;
    vector<vector<int>> graph(vertices);

    addDirectedEdge(graph, 0, 1);
    addDirectedEdge(graph, 0, 4);
    addDirectedEdge(graph, 1, 2);
    addDirectedEdge(graph, 1, 3);
    addDirectedEdge(graph, 2, 3);
    addDirectedEdge(graph, 3, 4);
    addDirectedEdge(graph, 4, 0);

    cout << "0 - unreflexive; 1 - partly reflexive; 2 - reflexive \n>>> ";
    int reflexiveness;
    cin >> reflexiveness;
    cout << "\n\n";

    switch (reflexiveness) {
    case 1:
        random_number = rand() % 5;
        addDirectedEdge(graph, random_number, random_number);
        break;
    case 2:
        for (int i = 0; i < vertices; ++i) {
            addDirectedEdge(graph, i, i);
        }
    }

    cout << "Graph:" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << i << " --> ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    int f_num = 0;

    srand(static_cast<unsigned int>(time(nullptr)));

    while (true) {
        cout << "\n\n0 - EXIT; 1 - f1; \n>>> ";
        cin >> f_num;
        cout << "\n\n";
        switch (f_num) {
        case 1:
            f1(); break;
        default:
            return 0;
        }
    }
    return 0;
}