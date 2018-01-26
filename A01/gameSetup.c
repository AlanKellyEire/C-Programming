
#include "gameSetup.h"


//------------------------------------
//	FUNCTION game_instructions 
//------------------------------------
void game_instructions() {
	printf("---------------------------------\n");
	printf(" ESCAPE FROM THE LABYRINTH\n");
	printf("---------------------------------\n");
	printf("Instructions. \n\n");
	printf("Use the keys 'a', 'd', 'w' and 'x' to move the knight ('K) left, right, up and down over the labyrinth, respectively\n");
	printf("'K' can only be moved within the board. Moreover, it can not be moved into any wall position ('W)\n");
	printf("The goal of the game is to use ('K') to push the barrel ('B') towards the escape of the labyrinth, indicated by -->\n");
	printf("On its way, ('K') can collect treasures ('T') so as to make extra points on its journey.\n");
	printf("However, any treasure is susceptible of being buried by pushing ('B') into its position.\n");
	printf("Press any key so as to start the game\n");
	char c = my_get_char();
}

//------------------------------------
//	FUNCTION set_game_initial_status 
//------------------------------------
void set_game_initial_status(char board[6][6], char** knight, char** barrel,
	int* steps, int* treasures) {

	*knight = &board[5][0];
	*barrel = &board[3][1];
	*treasures = 0;
	*steps = 0;
	
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 5; j++) {
			board[i][j] = ' ';
		}
	}
	
	board[0][5] = 'T';
	board[1][2] = 'W';
	board[1][4] = 'W';
	board[1][5] = 'W';

	board[2][0] = 'T';
	board[2][1] = 'W';
	board[2][2] = 'W';
	board[3][5] = 'W';

	board[4][0] = 'W';
	**barrel = 'B';
	board[4][2] = 'W';
	board[4][3] = 'W';
	board[4][5] = 'W';

	**knight = 'K';
	board[5][3] = 'T';
	
	display_game_status(board, *steps, *treasures);
}

//------------------------------------
//	FUNCTION display_board 
//------------------------------------
void display_board(char board[6][6]) {
	printf("\t\t\t\tBoard Status\n");
	printf("\t-------------------------------------------------\n");
	printf("\t: %c\t: %c\t: %c\t: %c\t: %c\t: %c\t:\n", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5]);
	printf("\t-------------------------------------------------\n");
	printf("\t: %c\t: %c\t: %c\t: %c\t: %c\t: %c\t:\n", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5]);
	printf("\t-------------------------------------------------\n");
	printf("\t: %c\t: %c\t: %c\t: %c\t: %c\t: %c\t: -->\n", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5]);
	printf("\t-------------------------------------------------\n");
	printf("\t: %c\t: %c\t: %c\t: %c\t: %c\t: %c\t:\n", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5]);
	printf("\t-------------------------------------------------\n");
	printf("\t: %c\t: %c\t: %c\t: %c\t: %c\t: %c\t:\n", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5]);
	printf("\t-------------------------------------------------\n");
	printf("-->\t: %c\t: %c\t: %c\t: %c\t: %c\t: %c\t:\n", board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5]);
	printf("\t-------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");
}

//------------------------------------
//	FUNCTION display_game_status 
//------------------------------------
void display_game_status(char board[6][6], int steps, int treasures) {
	display_board(board);
	printf("\n\t\tGame Status\n");
	printf("------------------------------------------------------------------------\n");
	printf("\tSteps Done = %d\n", steps);
	printf("\tTreasures Collected = %d\n\n", treasures);
	printf("\tMAKE NEW MOVEMENT :\n");
	printf("\tEnter a movement for the knight :\n");
	printf("\t'a' for left, 'd' for right, 'w' for up, 's' for down\n");
}

//------------------------------------
//	FUNCTION play_game 
//------------------------------------
void play_game() {

	char boards[6][6];
	game_instructions();

	int treasures;
	int steps;
	//pointer to position of the board where K is
	char* knight = NULL;
	char* barrel = NULL;
	printf("%p\n", &knight);
	//printf("size of array %d", sizeof(boards));
	set_game_initial_status(boards, &knight, &barrel, &steps, &treasures);

	while (perform_movement(boards, &knight, &barrel, &steps, &treasures) == False) {
		
		display_game_status(boards, steps, treasures);
		}
	
}
