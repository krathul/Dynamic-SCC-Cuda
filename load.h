#ifndef LOAD_H
#define LOAD_H

#include <string>
#include <vector>

void load_Graph(std::string filename, std::string updatefile, int Vertices, int Edges, int Update, int** edges, std::vector<std::vector<int>>& updates);

#endif
