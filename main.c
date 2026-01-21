#include <stdio.h>
#define MAX_CAP 50
#include <assert.h>
#include <stdbool.h>

static int board[MAX_CAP][MAX_CAP];

int count_adj(int x, int y, int board[MAX_CAP][MAX_CAP]);
void init_board(int board[MAX_CAP][MAX_CAP]);
void print_board(int board[MAX_CAP][MAX_CAP]);
int insert_cell(int x, int y, int board[MAX_CAP][MAX_CAP]);
int rules(int x, int y, int board[MAX_CAP][MAX_CAP]);

int main(){
	init_board(board);

	insert_cell(1, 1, board);

	insert_cell(1,0,board);
	insert_cell(0,1,board);
	insert_cell(2,1,board);
	insert_cell(0,2,board);

	int vecinos = count_adj(1, 1, board);
	printf("\nvecinos:%i\n", vecinos);
	print_board(board);

	return 0;
}

int count_adj(int x, int y, int board[MAX_CAP][MAX_CAP]){
	if(x < 0 || x > MAX_CAP || y < 0 || y > MAX_CAP || !board) return -1;
	int count = 0;
	if(x == 0 || x == MAX_CAP || y == 0 || y == MAX_CAP){
		assert(false && "array esferica aun no implementada");

	}else{
		//count += board[x-1][y-1];
		count += board[x][y-1];
		//count += board[x+1][y-1];

		count += board[x-1][y];
		count += board[x+1][y];

		//count += board[x-1][y+1];
		count += board[x][y+1];
		//count += board[x+1][y+1];
	}
	return count;
}

void init_board(int board[MAX_CAP][MAX_CAP]){
	assert(board);
	for(int i = 0; i < MAX_CAP; i++){
		for(int j = 0; j < MAX_CAP; j++){
			board[i][j] = 0;
		}
	}
	return;
}

void print_board(int board[MAX_CAP][MAX_CAP]){
	assert(board);
	for(int i = 0; i < MAX_CAP; i++){
		for(int j = 0; j < MAX_CAP; j++){
			printf("%i", board[i][j]);
		}
		printf("\n");
	}
	return;	
}

int insert_cell(int x, int y, int board[MAX_CAP][MAX_CAP]){
	assert(board);
	if(x > MAX_CAP || x < 0 || y > MAX_CAP || y < 0) return -1;
	board[x][y] = 1;
	return 0;
}

int rules(int x, int y, int board[MAX_CAP][MAX_CAP]){
	int count = count_adj(x, y, board);
	if(count == 3){
		board[x][y] = 1;
		return 0;
	}else if(count > 3){
		board[x][y] = 0;
		return 0;
	}else if(count <= 1){
		board[x][y] = 0;
		return 0;
	}
	return -1;
}
