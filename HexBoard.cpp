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
    {
        for(int j = 0; j < n; j++)
        {
            make_node(i, j, graph[count++]);
        }
    }
}

int HexBoard::get_node(int i, int j)
{
    return n*i + j;
}

void HexBoard::make_node(int i, int j, list <int> &neighbours)
{
            //if the node is a corner node

    if(i == 0 && j == 0)
    {
            //top left

        neighbours.push_back(i*n + j + 1);
        neighbours.push_back((i + 1)*n + j);
    }

    if(i == n - 1 && j == n - 1)
    {
            //bottom right

        neighbours.push_back((i - 1)*n + j);
        neighbours.push_back(i*n + j - 1);
    }

    if(i == 0 && j == n - 1)
    {
            //top right

        neighbours.push_back(i*n + j - 1);
        neighbours.push_back((i + 1)*n + j);
    }

    if(i == n - 1 && j == 0)
    {
            //bottom left

        neighbours.push_back((i - 1)*n + j);
        neighbours.push_back(i*n + j + 1);
    }

        //if the node is a boundary node but not a corner node

    if(i == 0 && j != 0 && j!= n - 1)
    {
            // topmost row

        neighbours.push_back(i*n + j - 1);
        neighbours.push_back(i*n + j + 1);
        neighbours.push_back((i + 1)*n + j);
        neighbours.push_back((i + 1)*n + j - 1);
    }

    if(j == 0 && i!= 0 && i != n - 1)
    {
            // leftmost column

        neighbours.push_back((i - 1)*n + j + 1);
        neighbours.push_back((i - 1)*n + j);
        neighbours.push_back(i*n + j + 1);
        neighbours.push_back((i + 1)*n + j);
    }

    else if(j == n - 1 && i!= 0 && i != n - 1)
    {
            // right most column

        neighbours.push_back((i - 1)*n + j);
        neighbours.push_back(i*n + j - 1);
        neighbours.push_back((i + 1)*n + j);
        neighbours.push_back((i + 1)*n + j - 1);
    }

    else if(i == n - 1 && j!= 0 && j != n - 1)
    {
            // bottommost row

        neighbours.push_back(i*n + j - 1);
        neighbours.push_back(i*n + j + 1);
        neighbours.push_back((i - 1)*n + j);
        neighbours.push_back((i - 1)*n + j + 1);
    }


        //if the node is an internal node

    else if(i != 0 && j != 0 && i != n - 1 && j != n - 1)
    {
        neighbours.push_back((i - 1)*n + j);
        neighbours.push_back((i - 1)*n + j + 1);
        neighbours.push_back(i*n + j + 1);
        neighbours.push_back(i*n + j - 1);
        neighbours.push_back((i + 1)*n + j);
        neighbours.push_back((i + 1)*n + j - 1);
    }
}

void HexBoard::display_board()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int node = get_node(i, j);
            cout << "The Node is : " << node << endl;
            cout << "The neighbours are : " << endl;

            for(auto neigh : graph[node])
            {
                cout << neigh << " ";
            }
            cout << endl;
        }
    }
}
