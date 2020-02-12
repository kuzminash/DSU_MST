#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

vector < pair<int, pair<int,int> > > G;
vector <int> parent;
vector <int> rank_ms;

void make_set(int v) {
    parent[v] = v;
    rank_ms[v] = 0;
}

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set (parent[v]);
}

void union_sets(int v1, int v2) {
    v1 = find_set(v1);
    v2 = find_set(v2);
    if (v1 != v2) {
        if (rank_ms[v1] < rank_ms[v2]) {
            swap(v1, v2);
        }
        parent[v2] = v1;
        if (rank_ms[v1] == rank_ms[v2]) {
            ++rank_ms[v1];
        }
    }
}

int main() {
    int v, e;
    rank_ms.resize(v);
    parent.resize(v);
    cin >> v >> e;
    int w, v1, v2;
    int weight = 0;
    for (int i = 0; i < e; i++) {
        cin >> v1 >> v2 >> w;
        G.push_back(make_pair(w, make_pair(v1, v2)));
    }
    sort(G.begin(), G.end());
    vector < pair<int,int> > res;
    for (int i = 0; i < v; i++) {
        make_set(i);
    }
    for (int i = 0; i < v; i++) {
        int v1 = G[i].second.first,  v2 = G[i].second.second,  w = G[i].first;
        if (find_set(v1) != find_set(v2)) {
            weight += w;
            res.push_back (G[i].second);
            union_sets(v1, v2);
        }
    }
    cout << weight;
}




