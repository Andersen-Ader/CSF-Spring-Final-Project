#include <iostream>
#include <string>

#define SIZE_X 10
#define SIZE_Y 10

using namespace std;

typedef struct Node {
	int isBarrier = 0;
	int Visited = 0;
	int ownX;
	int ownY;	
	int north = ownX - 1;
	int south = ownX + 1;
	int east = ownY + 1;
	int west = ownY - 1;
} Node;

void FindPath(Node array[SIZE_X][SIZE_Y], int curr_x, int curr_y, int end_x, int end_y, string path) {
  if (curr_x == end_x && curr_y == end_y) {
    cout << path;
    return;
  }

  Node currNode = array[curr_x][curr_y]

  array[curr_x][curr_y].Visited = 1;

  if (!(array[currNode.north][curr_y].isBarrier)) {
    cout << "Yay" << endl;
    return;
  }

  return;
}

int main(void) {
	Node array[SIZE_X][SIZE_Y];
  int start_x = 1, start_y = 0;
  int end_x = 9, end_y = 7;
  string path;

	for ( int i = 0; i < SIZE_X; ++i) {
		for ( int j = 0; j < SIZE_Y; ++j) {
			array[i][j].ownX = i;
			array[i][j].ownY = j;
		}
	}	

  
  array[0][3].isBarrier = 1;
  array[1][1].isBarrier = 1;
  array[1][2].isBarrier = 1;
  array[1][3].isBarrier = 1;
  array[1][4].isBarrier = 1;
  array[1][7].isBarrier = 1;
  array[1][8].isBarrier = 1;
  array[2][1].isBarrier = 1;
  array[2][6].isBarrier = 1;
  array[2][7].isBarrier = 1;
  array[2][8].isBarrier = 1;
  array[3][8].isBarrier = 1;
  array[4][2].isBarrier = 1;
  array[4][3].isBarrier = 1;
  array[4][4].isBarrier = 1;
  array[4][5].isBarrier = 1;
  array[4][6].isBarrier = 1;
  array[4][7].isBarrier = 1;
  array[4][8].isBarrier = 1;
  array[5][1].isBarrier = 1;
  array[5][2].isBarrier = 1;
  array[5][8].isBarrier = 1;
  array[6][1].isBarrier = 1;
  array[6][5].isBarrier = 1;
  array[6][6].isBarrier = 1;
  array[6][8].isBarrier = 1;
  array[7][3].isBarrier = 1;
  array[7][6].isBarrier = 1;
  array[7][7].isBarrier = 1;
  array[7][8].isBarrier = 1;
  array[8][1].isBarrier = 1;
  array[8][2].isBarrier = 1;
  array[8][3].isBarrier = 1;
  array[8][4].isBarrier = 1;
  array[8][6].isBarrier = 1;
  array[9][4].isBarrier = 1;
  array[9][6].isBarrier = 1;
  array[9][8].isBarrier = 1;



  FindPath(array, start_x, start_y, end_x, end_y, path);



	for ( int i = 0; i < SIZE_X; ++i) {
		for ( int j = 0; j < SIZE_Y; ++j) {
      cout << array[i][j].isBarrier << " ";
		}
    cout << endl;
  }


	return 0;
}
