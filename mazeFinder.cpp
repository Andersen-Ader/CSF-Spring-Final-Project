#include <iostream>
#include <string>

#define SIZE_X 10
#define SIZE_Y 10

using namespace std;

typedef struct Node {
	int isBarrier = 0;
	int Visited = 0;
	int north = ownX - 1;
	int south = ownX + 1;
	int east = ownY + 1;
	int west = ownY - 1;
	int ownX;
	int ownY;	
} Node;

void CreateMaze(Node* array[][]) {
}

int main(void) {
	Node array[SIZE_X][SIZE_Y];

	for ( int i = 0; i < SIZE_X; ++i) {
		for ( int j = 0; j < SIZE_Y; ++j) {
			array[i][j].ownX = i;
			array[i][j].ownY = j;
		}
	}	



	return 0;
}
