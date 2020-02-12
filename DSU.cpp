#include <iostream>
#include <algorithm>
using namespace std;

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;

}

void find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set (parent[v]);
}

int union_sets(int v1, int v2) {
    v1 = find_set(v1);
    v2 = find_set(v2);
    if (v1 != v2) {
        if (rank[v1] < rank[v2]) {
            swap(v1, v2);
        }
        parent[v2] = v1;
        if (rank[v1] == rank[v2]) {
            ++rank[v1];
        }
    }
}
