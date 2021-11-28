#include "HexBoard.h"
#include <vector>
#include <list>

HexBoard::HexBoard(int nodes)
{
    int count = 0;
    n = nodes;
    graph.resize(n*n); //resize the vector
    
    //mark the neighbours

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            make_node(i, j, graph[count++]);
}

void HexBoard::make_node(int i, int j, list <int> neighbours)
{
    if()
    {
        //if the node is a boundary node but not a corner node

        //if the node is a corner node

        if(i == 0 && j == 0)
        {
            //top left
        }
        if(i == n - 1 && j == n - 1)
        {
            //bottom right
        }
        if(i == 0 && j == n - 1)
        {
            //top right
        }
        if(i == n - 1 && j == 0)
        {
            //bottom left
        }
    }
    else
    {
        //if the node is an internal node

        neighbours.push(i*n + j + 1);
        neighbours.push(i*n + j - 1);
        neighbours.push((i + 1)*n + j);
        neighbours.push((i + 1)*n + j + 1);
        neighbours.push((i - 1)*n + j);
        neighbours.push((i - 1)*n + j - 1);
    }
}

int HexBoard::get_node(int i, int j)
{
    return n*i + j;
}

void HexBoard::display_board()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << "The Node is : " << get_node(i, j) << endl;
            cout << "The neighbours are : " << endl;

            for(auto neigh : graph[node])
            {
                cout << neigh << " ";
            }
            cout << endl;
        }
    }
}