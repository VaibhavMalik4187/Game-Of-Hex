#ifndef HEXBOARD_H
#define HEXBOARD_H
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class HexBoard
{
public :	
	HexBoard(int nodes);
	void make_node(int i, int j, list<int> neighbours);
	int get_node(int i, int j);
	void display_board();

protected :
	// board will be a graph made of vector(nodes) of lists(neighbours)
	int n;
	vector <list <int>> graph;
};

#endif