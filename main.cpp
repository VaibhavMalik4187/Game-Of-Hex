#include <iostream>
#include "HexBoard.h"

using namespace std;

int main()
{
	cout << "Enter the size of the board" << endl;
	int n;
	cin >> n;

	HexBoard board(n);

	board.display_board();

	return 0;
}