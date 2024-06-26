#include <iostream>
#include <string>

#define SIZE_X 10
#define SIZE_Y 10

using namespace std;

typedef struct Node {
	int isBarrier;
	int Visited;
	int ownX;
	int ownY;	
	int north;
	int south;
	int east;
	int west;
} Node;

//Append characters to path string, keep track of path
string UpdatedPath(string path, char c) {
  path.push_back(c);
  return path;
}


void FindPath(Node array[SIZE_X][SIZE_Y], int curr_x, int curr_y, int end_x, int end_y, string path) {
  if ((curr_x == end_x) && (curr_y == end_y)) {
    cout << path << endl;
    return;
  }

  //TODO make program choose nsew based on previous step, use string.end and ascii equivalence.

  Node currNode = array[curr_x][curr_y];
  array[curr_x][curr_y].Visited = 1;
  //Check each possible movement to see if that direction is a blocked path, hasn't been visited
  //And is within bounds of the array. North, south, east, west.
  if ((currNode.north >= 0) 
      && (array[currNode.north][curr_y].isBarrier == 0) 
      && (array[currNode.north][curr_y].Visited == 0)) {
    FindPath(array, currNode.north, curr_y, end_x, end_y, UpdatedPath(path, 'N'));
  }

  if ((currNode.south < SIZE_X) 
      && (array[currNode.south][curr_y].isBarrier == 0) 
      && (array[currNode.south][curr_y].Visited == 0)) {
    FindPath(array, currNode.south, curr_y, end_x, end_y, UpdatedPath(path, 'S'));
  }
  
  if ((currNode.east < SIZE_Y) 
      && (array[curr_x][currNode.east].isBarrier == 0) 
      && (array[curr_x][currNode.east].Visited == 0)) {
    FindPath(array, curr_x, currNode.east, end_x, end_y, UpdatedPath(path, 'E'));
  }
  
  if ((currNode.west >= 0) 
      && (array[curr_x][currNode.west].isBarrier == 0) 
      && (array[curr_x][currNode.west].Visited == 0)) {
    FindPath(array, curr_x, currNode.west, end_x, end_y, UpdatedPath(path, 'W'));
  }
  
  return;
}

int main(void) {
  Node array[SIZE_X][SIZE_Y];
  int start_x = 9, start_y = 0;
  int end_x = 9, end_y = 3;
  string path;

  //Creates/Initializes array with coordinates and coordinates to the next node.
	for ( int i = 0; i < SIZE_X; ++i) {
		for ( int j = 0; j < SIZE_Y; ++j) {
			array[i][j].ownX = i;
			array[i][j].ownY = j;
			array[i][j].north = i - 1;
			array[i][j].south = i + 1;
			array[i][j].east = j + 1;
			array[i][j].west = j - 1;
      array[i][j].isBarrier = 0;
      array[i][j].Visited = 0;
		}
	}	

  
  array[0][3].isBarrier = 1;
  array[0][4].isBarrier = 1;
  array[0][5].isBarrier = 1;
  array[1][1].isBarrier = 1;
  array[1][7].isBarrier = 1;
  array[1][8].isBarrier = 1;
  array[2][1].isBarrier = 1;
  array[2][3].isBarrier = 1;
  array[2][4].isBarrier = 1;
  array[2][5].isBarrier = 1;
  array[2][6].isBarrier = 1;
  array[2][8].isBarrier = 1;
  array[3][1].isBarrier = 1;
  array[3][8].isBarrier = 1;
  array[4][1].isBarrier = 1;
  array[4][2].isBarrier = 1;
  array[4][4].isBarrier = 1;
  array[4][6].isBarrier = 1;
  array[4][7].isBarrier = 1;
  array[4][8].isBarrier = 1;
  array[5][2].isBarrier = 1;
  array[5][4].isBarrier = 1;
  array[5][6].isBarrier = 1;
  array[6][0].isBarrier = 1;
  array[6][2].isBarrier = 1;
  array[6][4].isBarrier = 1;
  array[6][5].isBarrier = 1;
  array[6][6].isBarrier = 1;
  array[6][8].isBarrier = 1;
  array[7][0].isBarrier = 1;
  array[7][2].isBarrier = 1;
  array[7][8].isBarrier = 1;
  array[8][0].isBarrier = 1;
  array[8][2].isBarrier = 1;
  array[8][3].isBarrier = 1;
  array[8][4].isBarrier = 1;
  array[8][5].isBarrier = 1;
  array[8][6].isBarrier = 1;
  array[8][7].isBarrier = 1;
  array[8][8].isBarrier = 1;
  array[9][2].isBarrier = 1;

  array[9][0].Visited = 1;

  for (int i = 0; i < SIZE_X; i++) {
    cout << "  ";
    for (int j = 0; j < SIZE_Y; j++) {
      if (i == start_x && j == start_y) {
        cout << "S ";
      } else if (i == end_x && j == end_y) {
        cout << "E ";
      } else {
        cout << array[i][j].isBarrier << " ";
      }
    }
    cout << endl;
  }

  //Find path, will output the char array with directions to get through maze.
  FindPath(array, start_x, start_y, end_x, end_y, path);

	return 0;
}
