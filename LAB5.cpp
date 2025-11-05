#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


void addDirectedEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
}

void addUndirectedEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}


void f1() {
    int random_number;
    vector<vector<int>> graph(5);

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
        for (int i = 0; i < 5; ++i) {
            addDirectedEdge(graph, i, i);
        }
    }

    cout << "Graph:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << i << " --> ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}


void f2() {
    int vertices = 2;
    vector<vector<int>> graph(5);

    cout << "Enter cyclomatic number from 0 to 3\n>>> ";
    int cyclomatic_number;
    cin >> cyclomatic_number;
    cout << "\n\n";

    addUndirectedEdge(graph, 0, 1);

    switch (cyclomatic_number) {
    case 3:
        vertices += 1;
        addUndirectedEdge(graph, 3, 4);
        addUndirectedEdge(graph, 4, 2);
    case 2:
        vertices += 1;
        addUndirectedEdge(graph, 2, 3);
        addUndirectedEdge(graph, 3, 1);
    case 1:
        vertices += 1;
        addUndirectedEdge(graph, 1, 2);
        addUndirectedEdge(graph, 2, 0);
    }

    cout << "Graph:" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << i << " -- ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    int f_num = 0;

    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "GRAPHS \"PiOIvIS\"";

    while (true) {
        cout << "\n\n0 - EXIT; 1 - reflexiveness; 2 - cyclomatic number \n>>> ";
        cin >> f_num;
        cout << "\n\n";
        switch (f_num) {
        case 1:
            f1(); break;
        case 2:
            f2(); break;
        default:
            return 0;
        }
    }
    return 0;
}