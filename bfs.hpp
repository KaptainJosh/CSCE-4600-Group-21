#include <iostream>
#include <vector>
#include <set>
#include <iterator>

void bfs(std::vector<std::vector<int> >& adj, int dimension, std::vector<std::set<int> >& num);

void addEdge(int x,int y, std::vector<std::vector<int> >& adj);