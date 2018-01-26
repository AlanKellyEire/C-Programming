
//------------------------------------
//	Define 
//------------------------------------
#ifndef _GAME_
#define _GAME_

#define _CRT_SECURE_NO_WARNINGS

//------------------------------------
//	Include Libraries 
//------------------------------------
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------------------------------------
//	Datatype game
//------------------------------------
struct _game {
	long id;//
	char* p1;//
	char* p2;//
	int mode;//
	int status;
	char** board;
};

typedef struct _game game;

//------------------------------------
//	Datatype bool
//------------------------------------
enum Boolean { False, True };

typedef enum Boolean bool;

//------------------------------------
//	01. FUNCTION create_new_game
//------------------------------------
game* create_new_game(char* p1, char* p2, int rows, int columns);

//------------------------------------
//	02. FUNCTION display_board 
//------------------------------------
void display_board(char** board, int rows, int columns);

//------------------------------------
//	03. FUNCTION display_game_status 
//------------------------------------
void display_game_status(game g, int rows, int columns);

//--------------------------------------------------
// 04. FUNCTION my_getchar
//--------------------------------------------------
char my_get_char();

//------------------------------------
//	05. FUNCTION ask_for_column 
//------------------------------------
int ask_for_column(int columns);

//------------------------------------
//	06. FUNCTION user_movement 
//------------------------------------
int user_movement(game* g, int columns);

//------------------------------------
//	07. FUNCTION computer_movement 
//------------------------------------
int computer_movement(game* g, int columns);

//------------------------------------
//	08. FUNCTION new_movement 
//------------------------------------
void new_movement(game* g, int rows, int columns);

//------------------------------------
//	09. FUNCTION winning_row 
//------------------------------------
bool winning_row(char** board, int row, int ply, int columns, int connect);

//------------------------------------
//	10. FUNCTION winning_column 
//------------------------------------
bool winning_column(char** board, int column, int ply, int rows, int connect);

//------------------------------------
//	11. FUNCTION winning_diagonal 
//------------------------------------
bool winning_diagonal(char** board, int diagonal, int ply, bool left, int rows, int columns, int connect);

//------------------------------------
//	12. FUNCTION winning_player 
//------------------------------------
bool winning_player(game* g, int ply, int rows, int columns, int connect);

//------------------------------------
//	13. FUNCTION update_status 
//------------------------------------
void update_status(game* g, int rows, int columns, int connect);

//------------------------------------
//	14. FUNCTION play_game 
//------------------------------------
void play_game(int connect, int rows, int columns, char* p1, char* p2);

//------------------------------------
//	End of file 
//------------------------------------
#endif

