
//------------------------------------
//	Include Libraries 
//------------------------------------
#include "game.h"

//------------------------------------
//	01. FUNCTION create_new_game
//------------------------------------
game* create_new_game(char* p1, char* p2, int rows, int columns){
	//1. We create the variable for hosting the game
	game* g = (game*)malloc(1 * sizeof(game));
	
	//1. We use the function time so as to generate a unique id
	(*g).id = (long)time(NULL);
	
	//2. We use the names passed as arguments 
	(*g).p1 = (char*)malloc((strlen(p1) + 1) * sizeof(char));	
	strcpy((*g).p1, p1);

	(*g).p2 = (char*)malloc((strlen(p1) + 1) * sizeof(char));
	strcpy((*g).p2, p2);

	//3. We set the mode to the one passed by parameter
	int mode = 0;
	if (strcmp(p1, "Computer") == 0)
		mode = mode + 2;
	if (strcmp(p2, "Computer") == 0)
		mode = mode + 1;
	(*g).mode = mode;

	//4. We set the status to be 1; i.e., player1 moves first
	(*g).status = 1;

	//5. We initialise the board to contain all positions empty
	(*g).board = (char**)malloc(rows * sizeof(char*));
	(*g).board[0] = (char*)malloc((rows * columns) * sizeof(char));
	for (int i = 0; i < rows; i++)
		(*g).board[i] = (*g).board[0] + (columns * i);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			(*g).board[i][j] = ' ';

	// testing (*g).board[0][0] = 'T';

	//6. We return the game
	return g;
}

//------------------------------------
//	02. FUNCTION display_board 
//------------------------------------
void display_board(char** board, int rows, int columns) {
	char* b = *board;
	printf("\n\n\t-------------\n");
	printf("\t GAME STATUS\n");
	printf("\t-------------\n\n\t");
	for (int c = 1; c <= columns; c++) {
		printf("| %d ", c);
	}
	printf("|\n\t");
	for (int c = 1; c <= columns; c++) {
		printf("|---");
	}
	printf("|\n");
	for (int r = 1; r <= rows; r++) {
		printf("\t");
		for (int c = 1; c <= columns; c++) {
			printf("| %c ", *b);
			b = b + 1;
		}
		printf("|\n\t");
		for (int c = 1; c <= columns; c++) {
			printf("|---");
		}
		printf("|\n");
	}
}

//------------------------------------
//	03. FUNCTION display_game_status 
//------------------------------------
void display_game_status(game g, int rows, int columns) {

	display_board((g.board), rows, columns);
	//printf("game status %d", g.status);
	if (g.status == 1) {
		int i = 0;
		printf("\n\tPlayer ");
		while (*((g).p1 + i) != '\0') {
			printf("%c", *((g).p1 + i));
			i = i + 1;
		}
		printf(" moves next\n");
	}
	else if (g.status == 2) {
		int i = 0;
		printf("\n\tPlayer ");
		while (*((g).p2 + i) != '\0') {
			printf("%c", *((g).p2 + i));
			i = i + 1;
		}
		printf(" moves next\n");
	}
	else if (g.status == 3) {
		int i = 0;
		printf("\n\tPlayer ");
		while (*((g).p1 + i) != '\0') {
			printf("%c", *((g).p1 + i));
			i = i + 1;
		}
		printf(" has won\n");
	}
	else if (g.status == 4) {
		int i = 0;
		printf("\n\tPlayer ");
		while (*((g).p2 + i) != '\0') {
			printf("%c", *((g).p2 + i));
			i = i + 1;
		}
		printf(" has won\n");
	}
	else{
		printf("\n\tGame finished with a draw\n");
	}
}

//--------------------------------------------------
// 04. FUNCTION my_getchar
//--------------------------------------------------
char my_get_char() {
	//1. We create the variable for hosting the char
	char my_char = ' ';

	//2. We create an extra variable to consume any other characters entered until a return is pressed
	bool line_consumed = False;
	char dummy_char = ' ';

	//3. We consume the first char entered, i.e., the one we are interested at
	my_char = getchar();

	//4. While still there are remaining characters
	while (line_consumed == False) {
		//4.1. We consume the next character
		dummy_char = getchar();

		//4.2. If the new character is the end of line one, we can ensure we have consumed the entire line.
		if (dummy_char == '\n')
			line_consumed = True;
	}

	//5. We return the first character entered by the user, i.e., the one we are interested at
	return my_char;
}

//------------------------------------
//	05. FUNCTION ask_for_column 
//------------------------------------
int ask_for_column(int columns) {

	printf("\n\tEnter a Column From 1 to %d: ", columns);

	char c = my_get_char();
	int input = c - '0';

	while (!(input <= columns) || !(input >= 1)) {
		printf("\tInvalid Number. Try Again:\n");

		printf("\n\tEnter a Column From 1 to %d: ", columns);

		c = my_get_char();
		input = c - '0';
		printf("num %d\n", input);
	}

	//int column = -1; 

	return input;
}

//------------------------------------
//	06. FUNCTION user_movement 
//------------------------------------
int user_movement(game* g, int columns) {
	int column = ask_for_column(columns);
	//printf("columns picked %d", column);

	while ((*g).board[0][column - 1] != ' ') {
		printf("Sorry, column %d is full. Try another one!", column);
		column = ask_for_column(columns);
	}

	return column;
}

//------------------------------------
//	07. FUNCTION computer_movement 
//------------------------------------
int computer_movement(game* g, int columns) {
	int column = 0;
	
	for (int c = 0; c < columns; c++)
	{
		if ((*g).board[0][c] == ' ')
		{
			column = c + 1;
			break;
		}
		
	}

	return column;
}

//------------------------------------
//	08. FUNCTION new_movement 
//------------------------------------
void new_movement(game* g, int rows, int columns) {
	int m = -1;

	if ((*g).mode == 0) {
			m = user_movement(g, columns);
	}

	else if ((*g).mode == 1) {
		if ((*g).status == 1) {
			m = user_movement(g, columns);
		}
		else{
			m = computer_movement(g, columns);
		}
	}

	else if ((*g).mode == 2) {
		if ((*g).status == 2) {
			m = user_movement(g, columns);
		}
		else {
			m = computer_movement(g, columns);
		}
	}

	else {
			m = computer_movement(g, columns);
	}

	if ((*g).status == 1) {
		for (int i = (rows -1); i >= 0; i--){
			if ((*g).board[i][m-1] == ' ') {
				(*g).board[i][m-1] = 'X';
				break;
			}
		}
	}
	else {
		for (int i = (rows - 1); i >= 0; i--) {
			if ((*g).board[i][m-1] == ' ') {
				(*g).board[i][m-1] = 'O';
				break;
			}
		}
	}
}

//------------------------------------
//	09. FUNCTION winning_row 
//------------------------------------
bool winning_row(char** board, int row, int ply, int columns, int connect) {
	bool winner = False;
	int s = 0;
	char sign;
	if (ply == 2) {
		sign = 'X';
	}
	else {
		sign = 'O';
	}

	for (int i = 0; i < row; i++)
		for (int j = 0; j < columns; j++) {
			if (board[i][j] == sign) {
				s = s + 1;
				if (s >= connect) {
					//printf("hor true");
					//printf("%c sign row", sign);
					return True;
				}
			}
			else {
				s = 0;
			}
		}
	return winner;
}

//------------------------------------
//	10. FUNCTION winning_column 
//------------------------------------
bool winning_column(char** board, int column, int ply, int rows, int connect) {
	bool winner = False;
	int s = 0;
	char sign;
	if (ply == 2) {
		sign = 'X';
	}
	else {
		sign = 'O';
	}

	for (int i = 0; i < column; i++)
		for (int j = 0; j < rows; j++) {
			if (board[j][i] == sign) {
				s = s + 1;
				if (s >= connect) {
					//printf("vert true");
					//printf("%c sign", sign);
					return True;
				}
			}
			else {
				s = 0;
			}
		}
	

	return winner;
}

//------------------------------------
//	11. FUNCTION winning_diagonal 
//------------------------------------
bool winning_diagonal(char** board, int diagonal, int ply, bool left, int rows, int columns, int connect) {
	bool winner = False;
	char sign;
	if (ply == 2) {
		sign = 'X';
	}
	else {
		sign = 'O';
	}

	// top-left-right to bottom-right-left  !!!!works
	for (int rowStart = 0; rowStart < (rows - (connect -1)); rowStart++) {
		int count = 0;
		int row, col;
		//printf("\n");
		for (row = rowStart, col = 0; row < rows && col < columns; row++, col++) {
			//printf("%c board 111 postion LL - RL\t", sign);
			//printf("row board postion[%d][%d]\n", row, col);
			if (board[row][col] == sign) {
				//printf("%c board postion[%d][%d]", board[row][col], row, col);
				count = count + 1;
				//printf("   %d score", count);
				if (count >= connect) {
					//printf("\n\n returns dig true");
					return True;
				}
			}
			else {
				count = 0;
			}
		}
	}

	// top-left-left to bottom-right-left  works
	for (int colStart = 1; colStart < (columns - (connect - 1)); colStart++) {
		int count = 0;
		int row, col;
		//printf("\n");
		for (row = 0, col = colStart; row < rows && col < columns; row++, col++) {
			//printf("%c board 222 postion RR - LR\t", sign);
			//printf("row board postion[%d][%d]\n", row, col);
			if (board[row][col] == sign) {
				count = count + 1;
				if (count >= connect) {
					//printf("returns 2nd diag true");
					return True;
				}
			}
			else {
				count = 0;
			}
		}
	}
	// top-right to bottom-left rows works
	for (int rowStart = 0; rowStart < (rows-(connect - 1)); rowStart++) {
		int count = 0;
		int row, col;
		printf("\n");
		//printf("test");
		for (row = rowStart, col = (columns -1); row < rows && col >=  0; row++, col--) {
			//printf("%c board 333 postion RR - LR\t", sign);
			//printf("row board postion[%d][%d]\n", row, col);
			if (board[row][col] == sign) {
				count = count + 1;
				if (count >= connect) {
					//printf("returns 2nd diag true");
					return True;
				}
			}
			else {
				count = 0;
			}
		}
	}

	// top-right to bottom-left - red diagonals works!!!!!!!!
	for (int colStart = 1; colStart < (columns - (connect - 1)); colStart++) {
		int count = 0;
		int row, col;
		//printf("\n");
		for (row = rows - 1, col = colStart; row >= 0 && col < columns; row--, col++) {
			//printf("%c board 444 postion RL - LL\t", sign);
			//printf("row board postion[%d][%d]\n", row, col);
			if (board[row][col] == sign) {
				count = count + 1;
				if (count >= connect) {
				//	printf("returns 2nd diag true");
					return True;
				}
			}
			else {
				count = 0;
			}
		}
	}

	return winner;
}

//------------------------------------
//	12. FUNCTION winning_player 
//------------------------------------
bool winning_player(game* g, int ply, int rows, int columns, int connect) {
	bool winner = False;

	if (winning_column((*g).board, columns, ply, rows, connect)) {
		return True;
	}
	if (winning_row((*g).board, rows, ply, columns, connect)) {
		return True;
	}
	if (winning_diagonal((*g).board, 0, ply, True, rows, columns, connect)) {
		return True;
	}

	return winner;
}

//------------------------------------
//	13. FUNCTION update_status 
//------------------------------------
void update_status(game* g, int rows, int columns, int connect) {

	if (winning_player(g, (*g).status, rows, columns, connect)) {
		if ((*g).status == 2) {
			(*g).status = 3;
		}
		else {
			(*g).status = 4;
		}

	}
	else {
		int i = 0;
			for (int c = 0; c < columns; c++){
				
					if ((*g).board[0][c] != ' ') {
						i = i + 1;
					}
					else {
						break;
					}
				
			}
			if (i == 7) {
				(*g).status = 5;
			}
	}

	if ((*g).status == 1) {
		new_movement(g, rows, columns);
		(*g).status = 2;
	}
	else if ((*g).status == 2) {
		new_movement(g, rows, columns);
		(*g).status = 1;
	}
	
}

//------------------------------------
//	14. FUNCTION play_game 
//------------------------------------
void play_game(int connect, int rows, int columns, char* p1, char* p2) {

	game* g = create_new_game(p1, p2, rows, columns);
	int i = 1;
	display_game_status((*g), rows, columns);
	//printf("play method %d", (*g).mode);
	while ((*g).status == 1 || (*g).status == 2) {
		update_status(g, rows, columns, connect);
		display_game_status((*g), rows, columns);
	}
}





