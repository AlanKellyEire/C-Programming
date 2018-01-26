
#include "gameMovement.h"

//------------------------------------
//	FUNCTION ask_for_movement 
//------------------------------------

char ask_for_movement() {
	char move = my_get_char();
	while (move != 'w' && move != 'a' && move != 's' && move != 'd') {
		printf("%c\n\n" , move);
		printf("Invalid letter. Try Again!\n\n");
		printf("\tMAKE NEW MOVEMENT :\n");
		printf("\tEnter a movement for the knight :\n");
		printf("\t'a' for left, 'd' for right, 'w' for up, 's' for down\n");
		move = my_get_char();
		
		}
	return move;
}

//-------------------------------------------
//	FUNCTION get_position_coord_from_pointer 
//-------------------------------------------
void get_position_coord_from_pointer(char board[6][6], char* object, int* x_pos, int* y_pos) {
	
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 5; j++) {
			if (&board[i][j] == object) {
				*x_pos = i;
				*y_pos = j;
				break;
			}
		}
	}
}

//------------------------------------
//	FUNCTION get_new_position_coord 
//------------------------------------
void get_new_position_coord(int x_pos, int y_pos, char movement, int* new_x_pos, int* new_y_pos) {
	if (movement == 'd') {
		*new_y_pos = y_pos + 1;
	}
	else if (movement == 'a') {
		*new_y_pos = y_pos - 1;
	}
	else if (movement == 'w') {
		*new_x_pos = x_pos - 1;
	}
	else if (movement == 's') {
		*new_x_pos = x_pos + 1;
	}
}

//------------------------------------
//	FUNCTION is_winning_movement 
//------------------------------------
bool is_winning_movement(char board[6][6], char* barrel, char movement) {

	if ((&board[2][5] == barrel)) {
		if (movement == 'd') {
			if( *(barrel - 1) == 'K') {
				printf("winning move");
				return True;
			}
		}
	}
	return False;
}

//------------------------------------
//	FUNCTION is_movement_safe 
//------------------------------------
bool is_movement_safe(char board[6][6], char* knight, char* barrel, char movement) {
	
	int x = NULL;
	int y = NULL;

	get_position_coord_from_pointer(board, knight, &x, &y);
	if (movement == 'd' && y != 5 && board[x][y + 1] != 'W') {
		if (board[x][y + 1] == 'B') {
			if (board[x][y + 2] != 'W') {
				return True;
			}
			else {
				return False;
			}
		}
	/*	get_position_coord_from_pointer(board, barrel, &x, &y);
		if (y != 5 && board[x][y] != 'B') {
			get_new_position_coord(x, y, movement, &x, &y);
			if (board[x][y] != 'W') {
				get_new_position_coord(x, y, movement, &x, &y);
				board[x][y -1] = 'G';
				barrel = board[x][y];
				return True;
			}
			barrel = board[x][y];
			return True;
		}*/
		return True;
	}
	else if (movement == 'a' && y != 0 && board[x][y - 1] != 'W') {
		get_position_coord_from_pointer(board, barrel, &x, &y);
		if (y != 0 && board[x][y - 1] != 'W') {
			get_new_position_coord(x, y, movement, &x, &y);
			return True;
		}
		return True;
	}
	else if (movement == 's' && x != 5 && board[x][y + 6] != 'W') {
		get_position_coord_from_pointer(board, barrel, &x, &y);
		if (x != 5 && board[x][y + 6] != 'W') {
			get_new_position_coord(x, y, movement, &x, &y);
			return True;
		}
		return True;
	}
	if (movement == 'w' && x != 0 && board[x][y - 6] != 'W') {
		get_position_coord_from_pointer(board, barrel, &x, &y);
		if (x != 0 && board[x][y - 6 ] != 'W') {
			get_new_position_coord(x, y, movement, &x, &y);
			return True;
		}
		return True;
	}
	return False;
}

//------------------------------------
//	FUNCTION perform_movement 
//------------------------------------
bool perform_movement(char board[6][6], char** kn, char** bar, int* stp, int* trea) {
	char input = 'c';
	char* p = &input;
	int tNum = 0;
	int tNo = 3;
	do {
		*p = ask_for_movement();
		if (is_movement_safe(board, *kn, *bar, *p) == True) {
			if (*p == 'd') {
				/*if (*(kn + 1) == *bar) {
					*(kn + 1);
						*bar;
					*bar = *bar + 1;
					**bar = 'B';
				}*/
				**kn = ' ';
				printf(" kn %p\n", kn);
				printf(" kn + 1 %p\n", *(kn +1));
				printf(" barrell %p\n", *bar);
				*kn = *kn + 1;
				if (*kn == *bar) {
					*(kn + 1);
					*bar;
					*bar = *bar + 1;
					**bar = 'B';
				}
				printf(" kn %p\n", *kn);
				printf(" kn %c\n", **kn);
				**kn = 'K';
			}
			else if (*p == 'a') {
				/*if (*(kn - 1) == *bar) {
					*bar = *bar - 1;
					**bar = 'B';
				}*/
				**kn = ' ';
				*kn = *kn - 1;
				if (*(kn - 1) == *bar) {
					*bar = *bar - 1;
					**bar = 'B';
				}
				**kn = 'K';
			}
			else if (*p == 'w') {
				if (*(kn - 6) == *bar) {
					*bar = *bar - 6;
					**bar = 'B';
				}
				**kn = ' ';
				*kn = *kn - 6;
				**kn = 'K';
			}
			else {
				if (*(kn + 6) == *bar) {
					*bar = *bar + 6;
					**bar = 'B';
				}
				**kn = ' ';
				*kn = *kn + 6;
				**kn = 'K';
			}
			tNum = 0;
			*stp = *stp + 1;
			for (int i = 0; i <= 5; i++) {
				for (int j = 0; j <= 5; j++) {
					if (board[i][j] == 'T') {
						tNum = tNum + 1;
					}
				}
			}
			if (tNo != tNum) {
				tNo = tNum;
				*trea = *trea + 1;
				tNum = 0;
			}
		}
		display_game_status(board, *stp, *trea);
	}while (is_winning_movement(board, *bar, *p) == False);

	return True;
}


