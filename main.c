#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_CAP 50

static int board[MAX_CAP][MAX_CAP];

int count_adj(int x, int y, int board[MAX_CAP][MAX_CAP]);
void init_board(int board[MAX_CAP][MAX_CAP]);
void print_board(int board[MAX_CAP][MAX_CAP]);
int insert_cell(int x, int y, int board[MAX_CAP][MAX_CAP]);
void play(int board[MAX_CAP][MAX_CAP]);

int main(void) {
	init_board(board);

insert_cell(10, 20, board);
insert_cell(11, 20, board);
insert_cell(12, 20, board);


	int i = 0;
	while (1 && i<10) {
		print_board(board);
		play(board);
		printf("\n");
		i++;
	}
	return 0;
}


int count_adj(int x, int y, int board[MAX_CAP][MAX_CAP]) {
	int count = 0;


	if (x > 0)
		count += board[x - 1][y];

  
	if (x < MAX_CAP - 1)
		count += board[x + 1][y];

    
	if (y > 0)
		count += board[x][y - 1];

  
	if (y < MAX_CAP - 1)
		count += board[x][y + 1];


	if (x > 0 && y > 0)
		count += board[x - 1][y - 1];

	if (x > 0 && y < MAX_CAP - 1)
		count += board[x - 1][y + 1];

	if (x < MAX_CAP - 1 && y > 0)
		count += board[x + 1][y - 1];

	if (x < MAX_CAP - 1 && y < MAX_CAP - 1)
		count += board[x + 1][y + 1];

	return count;
}


void init_board(int board[MAX_CAP][MAX_CAP]) {
	assert(board);
	for (int i = 0; i < MAX_CAP; i++) {
		for (int j = 0; j < MAX_CAP; j++) {
			board[i][j] = 0;
		}
	}
}

void print_board(int board[MAX_CAP][MAX_CAP]) {
	assert(board);
	for (int i = 0; i < MAX_CAP; i++) {
		for (int j = 0; j < MAX_CAP; j++) {
			if (board[i][j])
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
}

int insert_cell(int x, int y, int board[MAX_CAP][MAX_CAP]) {
	assert(board);
	if (x < 0 || x >= MAX_CAP || y < 0 || y >= MAX_CAP)
		return -1;

	board[x][y] = 1;
	return 0;
}


void play(int board[MAX_CAP][MAX_CAP]) {
	int next[MAX_CAP][MAX_CAP];


	for (int i = 0; i < MAX_CAP; i++) {
		for (int j = 0; j < MAX_CAP; j++) {
			next[i][j] = board[i][j];
		}
	}


	for (int i = 0; i < MAX_CAP; i++) {
		for (int j = 0; j < MAX_CAP; j++) {
			int count = count_adj(i, j, board);

			if (board[i][j] == 1) {
				if (count < 2 || count > 3)
					next[i][j] = 0;
			} else {
				if (count == 3)
					next[i][j] = 1;
			}
		}
	}

   
	for (int i = 0; i < MAX_CAP; i++) {
		for (int j = 0; j < MAX_CAP; j++) {
			board[i][j] = next[i][j];
		}
	}
}
