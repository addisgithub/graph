/*
 * @author Addis Bogale
 * @date 4/2/2021
 */

#include <iostream>
#include <vector>
using namespace std;


class Graph {
private:
    int n;
public:
   int Matrix[10][10] = { 0 };

   Graph(int input) {
       n = input;
   }

void addEdge(int i, int j) {
    Matrix[i][j] = true;
}
void removeEdge(int i, int j) {
    Matrix[i][j] = false;
}
bool hasEdge(int i, int j) {
    return Matrix[i][j];
}

void displayMatrix() {
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         cout << Matrix[i][j];
      }
      cout << endl;
   }
}

void outEdges(int i, vector<int> &edges) {
    for (int j = 0; j < n; j++)
        if (Matrix[i][j]) edges.push_back(j);
}
void inEdges(int i, vector<int> &edges) {
    for (int j = 0; j < n; j++) 
        if (Matrix[j][i]) edges.push_back(j);
}

int nVertices() {
    return n * n;
}

void bfs(Graph &g, int r) {
    bool *seen = new bool[g.nVertices()];
    vector<int> q;
    q.push_back(r);
    seen[r] = true;
    while (q.size() > 0) {
        int i = q.back();
        cout << endl << i << " > " << "This is BFS" << endl;
        q.pop_back();
        vector<int> edges;
        g.outEdges(i, edges);
        for (int k = 0; k < edges.size(); k++) {
            int j = edges[k];
            if (!seen[j]) {
                q.push_back(j);
                seen[j] = true;
            }
        }
    }
    delete[] seen;
}


void dfs2(Graph &g, int r) {
    bool *c = new bool[g.nVertices()];
    vector<int> s;
    s.push_back(r);
    while (s.size() > 0) {
        int i = s.back();
        cout << endl << i << " > " << "This is DFS"<< endl;
        s.pop_back();
        if (c[i] == *c) {
            c[i] = c;
            vector<int> edges;
            g.outEdges(i, edges);
            for (int k = 0; k < edges.size(); k++)
                s.push_back(edges[k]);
        }
    }
delete[] c;
}

};


int main(int, char**) {
    Graph value(10);
    value.addEdge(0,1);
    value.addEdge(3,3);
    value.displayMatrix();
    value.bfs(value, 0);
    value.removeEdge(3,3);
    value.displayMatrix();

    value.addEdge(2,3);
    value.addEdge(1,3);
    
    value.hasEdge(0,1);
    value.dfs2(value, 2);
    value.displayMatrix();
    

}
