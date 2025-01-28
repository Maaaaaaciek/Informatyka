#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> krawedzie;
vector<bool> odwiedzone;

void BFS(int start) {
    queue<int> kolejka;
    odwiedzone[start] = true;
    kolejka.push(start);

    while (!kolejka.empty()) {
        int aktualny = kolejka.front();
        kolejka.pop();
        cout << aktualny << " ";

        for (int sasiad : krawedzie[aktualny]) {
            if (!odwiedzone[sasiad]) {
                odwiedzone[sasiad] = true;
                kolejka.push(sasiad);
            }
        }
    }
}

void DFS(int start) {
    odwiedzone[start] = true;
    cout << start << " ";

    for (int sasiad : krawedzie[start]) {
        if (!odwiedzone[sasiad]) {
            DFS(sasiad);
        }
    }
}

int main() {
    ifstream plik("graf.txt");
    int n, m;
    plik >> n >> m;
    krawedzie.resize(n);
    odwiedzone.assign(n, false);

    for (int i = 0; i < m; ++i) {
        int u, v;
        plik >> u >> v;
        krawedzie[u].push_back(v);
        krawedzie[v].push_back(u);
    }

    int start;
    cout << "Podaj wierzcholek poczatkowy: ";
    cin >> start;

    BFS(start);
    cout << endl;
    odwiedzone.assign(n, false);
    DFS(start);

    return 0;
}
