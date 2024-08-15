#include "load.h"
#include <fstream>
#include <iostream>
#include <istream>
#include <random>
#include <set>
#include <string>
#include <vector>
using namespace std;

void load_Graph(string filename, string updatefile, int Vertices, int Edges, int Updates, int** edges, vector<vector<int>>& updates)
{
    int V = Vertices;
    int E = Edges;
    int U = Updates;
    int firstVertex, secondVertex;

    // open the file
    filebuf fb;

    fb.open(filename, ios::in);
    if (!fb.is_open()) {
        printf("Error Reading graph file\n");
        return;
    }
    istream is(&fb);

    // Randomly pick edges that needed to be updateed
    //***************************In Aqua *********************************

    // Allocate memory for edges
    *edges = new int[E * 2];
    for (int i = 0; i < E; i++) {
        is >> firstVertex >> secondVertex;
        (*edges)[i * 2] = firstVertex;
        (*edges)[i * 2 + 1] = secondVertex;
    }

    std::vector<std::pair<int, int>> add_edges;

    filebuf updateb;
    updateb.open(updatefile, ios::in);
    istream up(&updateb);
    char op;
    int src, dst;

    for (int i = 0; i < U; i++) {
        up >> op >> src >> dst;
        if (op == 'a') {
            add_edges.push_back({ src, dst });
        } else if (op == 'd') {
            updates.push_back({ 0, src, dst });
        }
    }

    for (auto i : add_edges) {
        updates.push_back({ 1, i.first, i.second });
    }

    fb.close();
    updateb.close();
}
