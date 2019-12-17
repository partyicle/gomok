#include    <stdio.h>

#define BOARD_SIZE 10
#define STONE_SPACE 0
#define STONE_BLACK 1
#define STONE_WHITE 2

typedef enum BOOL_T {FALSE,TRUE} bool_t;

void gameInit(int board[][BOARD_SIZE], int *which_turn);
void InitBoard(int board[][BOARD_SIZE]);
void BoardPrint(int board[][BOARD_SIZE]);
bool_t Checkout(int x, int y);
void change_turn(int *which_turn);
void input_hantei(int board[][BOARD_SIZE], int which);
int result_check(int board[][BOARD_SIZE]);


int i = 0;
int j = 0;


int main(void) {

	int board[BOARD_SIZE][BOARD_SIZE];	//ボードのサイズ10×10//
	int which_turn;						//プレイヤーターン//


	gameInit(board, &which_turn);		//ゲーム初期化//
	BoardPrint(board);					//盤面の初期化//

	while (1) {
	
		//入力処理と判定//
		input_hantei(board, which_turn);

		//プレイヤーチェンジ//
		change_turn(&which_turn);

		//盤面出力//
		BoardPrint(board);

		//勝利判定//
		if (result_check(board) == 0) { break; };

	
	}


	return 0;
}


//盤面の初期化//
void InitBoard(int board[][BOARD_SIZE]) {
	for (i = 0; i < BOARD_SIZE; i++) {
			
		for (j = 0; j < BOARD_SIZE; j++) {
									
			board[i][j] = STONE_SPACE;

		}
			
	}

}

//ゲームの初期化//
void gameInit(int board[][BOARD_SIZE],int *which_turn) {
			
	InitBoard(board);

	*which_turn = STONE_BLACK;

}

//盤面の出力//
void BoardPrint(int board[][BOARD_SIZE]) {

	printf("  ");

	for (i = 0; i < BOARD_SIZE; i++) {
	
		printf("%d ", i);
	
	}

	puts("");

	for (i = 0; i < BOARD_SIZE; i++) {

		printf("%d", i);

		for (j = 0; j < BOARD_SIZE; j++) {
		
			switch (board[i][j]) {			//入力された値によって白か黒か空白か決める//
				
			case STONE_SPACE:
				printf("・"); 
				break;

			case STONE_BLACK:
				printf("●");
				break;

			case STONE_WHITE:
				printf("〇");

			
			}
			

		}
		puts("");

	}

	puts("");


}



//プレイヤーターンチェンジ//
void change_turn(int *which_turn) {

	if (*which_turn == STONE_BLACK) {
			
		*which_turn = STONE_WHITE;

	}
	else if (*which_turn == STONE_WHITE) {
			
		*which_turn = STONE_BLACK;
			
	}

}

//ボードからはみ出していないかの調査//
bool_t Checkout(int x, int y) {

	
	if (x< BOARD_SIZE&&y< BOARD_SIZE&&x>=0&&y>=0) {
	
		return TRUE;

	}

	return FALSE;
}

//勝利判定//

int result_check(int board[][BOARD_SIZE]){
	
	int blacklencheck = 0;
	int whitelencheck = 0;

	for (i = 0; i < BOARD_SIZE; i++) {

		for (j = 0; j < BOARD_SIZE; j++) {

			if (board[i][j] == board[i][j + 1] || board[i][j] == board[i + 1][j]
				|| board[i][j] == board[i + 1][j + 1]) {

				switch (board[i][j]) {

				case STONE_BLACK:

					blacklencheck++;
					break;

				case STONE_WHITE:

					whitelencheck++;
					break;

				case STONE_SPACE:
					break;
				}


			}
		}
	}

	if (whitelencheck >= 4) {
			
		printf("白の勝ちです。\n");
		return 0;
	}
	else if (blacklencheck >= 4) {
		
		printf("黒の勝ちです。\n");
		return 0;
	}

	return 1;
			
}


//入力判定処理//
void input_hantei(int board[][BOARD_SIZE], int which) {


	int pos_x = 0;
	int pos_y = 0;

	

		if (which == 1) {


			printf("●の番です。どちらに置きますか??\n");
			

		}
		else if (which == 2) {

			printf("〇の番です。どちらに置きますか??\n");

		}

		while (1) {
			
			scanf_s("%d %d", &pos_x,&pos_y);
			
			if (Checkout(pos_x, pos_y) && board[pos_y][pos_x] == STONE_SPACE) {
				
				switch (board[pos_y][pos_x]) {
				
				case STONE_BLACK:
					printf("●");
					break;

				case STONE_WHITE:
					printf("〇");
					break;

				}
				puts("input ok");
				break; 
			}

			printf("不正な入力です。");
		
		}
		board[pos_y][pos_x] = which;
}





