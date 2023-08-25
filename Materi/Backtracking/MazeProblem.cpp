#include <iostream>
using namespace std;

// Ukuran Maze
#define N 6
#define J 5

bool solveMaze(int maze[N][J]);
bool solveMazeUtil( int maze[N][J], int x, int y, int sol[N][J]);
bool isSafe(int maze[N][J], int x, int y);
void printSolution(int sol[N][J]); 

int main(){
	int maze[N][J] ={{1,0,0,0,1},
					 {1,1,0,1,0},
				     {0,1,1,1,0},
					 {0,1,0,1,0},
					 {1,0,1,1,1},
				    {1,1,1,1,1}
					};
	solveMaze(maze);
	return 0;
}

bool solveMaze(int maze[N][J]){
	int sol[N][J] = {{0,0,0,0,0},
					 {0,0,0,0,0},
				     {0,0,0,0,0},
					 {0,0,0,0,0},
					 {0,0,0,0,0},
				     {0,0,0,0,0}
					};

	if (solveMazeUtil(maze, 0, 0, sol) == false) {
		cout << "Solution doesn't exist" << endl;
		return false;
	}

	printSolution(sol);
	return true;
}

bool solveMazeUtil(int maze[N][J], int x, int y, int sol[N][J]){
	// if (x, y is goal) return true
	if (x==N-2 && y==J-2 && maze[x][y]==1) {
		sol[x][y] = 1;
		return true;
	}

	// Check if maze[x][y] is valid
	if (isSafe(maze, x, y) == true) {
		// Check if the current block is already part of solution path.
		if (sol[x][y] == 1)
			return false;
	
		// mark x, y as part of solution path
		sol[x][y] = 1;

		// Move in x direction
		if (solveMazeUtil(maze, x+1, y, sol) == true)
			return true;

		// If moving in x direction doesn't give solution then Move in y direction
		if (solveMazeUtil(maze, x, y+1, sol) == true)
			return true;
	
		// If none of the above movements work then BACKTRACK: unmark x, y as part of solution path
		sol[x][y] = 0;
		return false;
	}

	return false;
}

bool isSafe(int maze[N][J], int x, int y){
	// if (x, y outside maze) return false
	if (x>=0 && x<N && y>=0 && y<J && maze[x][y] == 1)
		return true;

	return false;
}

void printSolution(int sol[N][J]){
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < J; j++)
			cout << sol[i][j] << " ";
		cout << "\n";
	}
}