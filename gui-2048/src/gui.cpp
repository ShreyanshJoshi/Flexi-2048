/**
 * @file gui.cpp
 * @author Shreyansh Joshi
 * @brief File containing implementation for the game's gui.
 *
 */
#include "styles.h"
#include "gui.h"
#include "moves.h"
#include "base.h"
#include <time.h>
#include <bits/stdc++.h>
#include <SDL2/SDL_mixer.h>

bool initSDL(SDL_Window **window, SDL_Renderer **renderer) {
	
	TTF_Init();
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "SDL could not initialize. SDL_ERROR: %s\n", SDL_GetError());
		return false;
	}

	*window = SDL_CreateWindow("2048", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		fprintf(stderr, "Window could not be created. SDL_ERROR: %s\n", SDL_GetError());
		return false;
	}

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		fprintf(stderr, "Renderer could not be created. SDL_ERROR: %s\n", SDL_GetError());
		closeSDL(window);
		return false;
	}

	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		return false;
	
	return true;
}


void draw_text(SDL_Renderer *renderer, TTF_Font *font, const char *text, SDL_Rect rect, SDL_Color color) {
	SDL_Surface *surfaceMessage = TTF_RenderText_Blended(font, text, color);
	SDL_Texture *Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_Rect message_rect;

	TTF_SizeText(font, text, &message_rect.w, &message_rect.h);
	message_rect.x = rect.x + rect.w / 2 - message_rect.w / 2;
	message_rect.y = rect.y + rect.h / 2 - message_rect.h / 2;

	SDL_RenderCopy(renderer, Message, NULL, &message_rect);
	SDL_DestroyTexture(Message);
	SDL_FreeSurface(surfaceMessage);
}


void draw_white_text(SDL_Renderer *renderer, TTF_Font *font, const char *text, SDL_Rect rect) {
	SDL_Color White = {255, 255, 255};
	draw_text(renderer, font, text, rect, White);
}


void closeSDL(SDL_Window **window) {
	SDL_DestroyWindow(*window);
	*window = NULL;
	TTF_Quit();
	SDL_Quit();
}


void clear_screen(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, g_bg.r, g_bg.g, g_bg.b, g_bg.a);
	SDL_RenderClear(renderer);
}


void display_text(SDL_Renderer *renderer, const char *text, int size, stack<State>s, bool over) {
	TTF_Font *font = NULL;
	font = TTF_OpenFont(FONT_PATH, size);
	
	if (font == NULL) {
		fprintf(stderr, "The required font was not found. TTF_OpenFont: %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Color black = {g_fg.r, g_fg.g, g_fg.b};
	clear_screen(renderer);
	SDL_Rect rect = {SCREEN_PAD, SCREEN_HEIGHT / 4 - 70, SCREEN_WIDTH - 2 * SCREEN_PAD, SCREEN_HEIGHT / 2};
	draw_text(renderer, font, text, rect, black);

	if (over) {
		rect = {SCREEN_PAD-50, SCREEN_HEIGHT / 4 +150, SCREEN_WIDTH - 4 * SCREEN_PAD, SCREEN_HEIGHT / 4};
		font = TTF_OpenFont(FONT_PATH, 60);
		draw_text(renderer, font, "Score: ", rect, black);

		rect = {SCREEN_PAD + 100, SCREEN_HEIGHT / 4 +150, SCREEN_WIDTH - 4 * SCREEN_PAD, SCREEN_HEIGHT / 4};
		draw_text(renderer, font, to_string(s.top().points).c_str(), rect, black);
	}

	SDL_RenderPresent(renderer);
	SDL_Delay(2000);
	TTF_CloseFont(font);
}


void draw_board(SDL_Renderer *renderer, const int board[SIZE][SIZE], TTF_Font *font) {
	int squareSize = (SCREEN_WIDTH - 2 * SCREEN_PAD) / SIZE - SCREEN_PAD;

	for (int x = 0; x < SIZE; x++) {
		for (int y = 0; y < SIZE; y++) {
			
			SDL_Rect fillRect = {SCREEN_PAD + x * (squareSize + SCREEN_PAD), SCREEN_PAD + y * (squareSize + SCREEN_PAD), squareSize, squareSize};

			struct COLOR s;
			if (board[y][x]==0)
				s = g_COLORS[0];
			
			else
				s = g_COLORS[int(log2(board[y][x]))];
	
			SDL_SetRenderDrawColor(renderer, s.r, s.g, s.b, s.a);
			SDL_RenderFillRect(renderer, &fillRect);
			
			char str[15]; 
			sprintf(str, "%d", board[y][x]);

			if (board[y][x] == 0) {
				str[0] = ' ';
				str[1] = '\0';
			}

			draw_white_text(renderer, font, str, fillRect);
		}
	}
}


void handle_move(SDL_Event e, int board[SIZE][SIZE], SDL_Renderer *renderer, Mix_Chunk *g_mix_music, stack<State>&s, int &undo) {
	vector<vector<int>>v;
	load_vector(v,board);

	State st;
	st.v = v;

	switch (e.key.keysym.sym) {
		case SDLK_UP:
			// Mix_PlayChannel(-1, g_mix_music, 0);
			if (s.empty())
				st.points = calculate_score(board, 'w');
			
			else
				st.points = s.top().points + calculate_score(board, 'w');

			move_up(board);
			break;

		case SDLK_DOWN:
			// Mix_PlayChannel(-1, g_mix_music, 0);
			if (s.empty())
				st.points = calculate_score(board, 's');
			
			else
				st.points = s.top().points + calculate_score(board, 's');

			move_down(board);
			break;

		case SDLK_LEFT:
			// Mix_PlayChannel(-1, g_mix_music, 0);
			if (s.empty())
				st.points = calculate_score(board, 'a');
			
			else
				st.points = s.top().points + calculate_score(board, 'a');

			move_left(board);
			break;

		case SDLK_RIGHT:
			// Mix_PlayChannel(-1, g_mix_music, 0);
			if (s.empty())
				st.points = calculate_score(board, 'd');
			
			else
				st.points = s.top().points + calculate_score(board, 'd');

			move_right(board);
			break;

		case SDLK_u:
			if (s.size()>=1) {
				undo = 1;
				for (int i=0; i < SIZE; i++) 
					for (int j=0; j < SIZE; j++) 
						board[i][j] = s.top().v[i][j];
			}
			else
				undo = 2;

			return;

		default:;
	}
	s.push(st);
}


void draw_button(SDL_Renderer *renderer, TTF_Font *font) {
	char txt[] = "New Game";
	SDL_Rect fillRect = {SCREEN_PAD / 2,
						 SCREEN_WIDTH + SCREEN_PAD,
						 SCREEN_WIDTH / 2 - 2 * SCREEN_PAD,
						 (SCREEN_HEIGHT - SCREEN_WIDTH) - 2 * SCREEN_PAD};
	SDL_SetRenderDrawColor(renderer, g_button_bg.r, g_button_bg.g, g_button_bg.b, g_button_bg.a);
	SDL_RenderFillRect(renderer, &fillRect);
	draw_white_text(renderer, font, txt, fillRect);
}


void button_handler(SDL_Event e, int board[SIZE][SIZE], stack<State>&s) {
	SDL_Rect draw_rect = {SCREEN_PAD / 2,
						  SCREEN_WIDTH + SCREEN_PAD,
						  SCREEN_WIDTH / 2 - 2 * SCREEN_PAD,
						  SCREEN_HEIGHT - SCREEN_WIDTH - 2 * SCREEN_PAD};

	if (e.button.button == SDL_BUTTON_LEFT && e.button.x >= draw_rect.x && e.button.x <= (draw_rect.x + draw_rect.w) &&
		e.button.y >= draw_rect.y && e.button.y <= (draw_rect.y + draw_rect.h)) {
		clear_board(board);
		initialize_game(board, s);
	}
}


void draw_score(SDL_Renderer *renderer, int board[SIZE][SIZE], TTF_Font *font, int points) {
	char score[15]; 
	sprintf(score, "%d", points);

	char scoreText[30] = "Score:";
	strncat(scoreText, score, 15);
	SDL_Rect fillRect = {SCREEN_WIDTH / 2 + 5,
						 SCREEN_WIDTH + SCREEN_PAD,
						 SCREEN_WIDTH / 2 - 2 * SCREEN_PAD,
						 SCREEN_HEIGHT - SCREEN_WIDTH - 2 * SCREEN_PAD};

	SDL_SetRenderDrawColor(renderer, g_score_bg.r, g_score_bg.g, g_score_bg.b, g_score_bg.a);
	SDL_RenderFillRect(renderer, &fillRect);
	draw_white_text(renderer, font, scoreText, fillRect);
}


void render_game(SDL_Renderer *renderer, int board[SIZE][SIZE], TTF_Font *font, int points) {
	clear_screen(renderer);
	draw_board(renderer, board, font);
	draw_score(renderer, board, font, points);
	draw_button(renderer, font);
	SDL_RenderPresent(renderer);
}


void game_loop(int board[SIZE][SIZE], stack<State>&s, SDL_Renderer *renderer, Mix_Chunk *g_mix_music) {
	display_text(renderer, "2048", TITLE_FONT_SIZE, s);
	TTF_Font *font = NULL;
	font = TTF_OpenFont(FONT_PATH, CELL_FONT_SIZE);
	
	if (font == NULL) {
		fprintf(stderr, "The required font was not found. TTF_OpenFont: %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

	render_game(renderer, board, font, 0);
	bool quit = false;
	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) 
				quit = true;
			
			else if (e.type == SDL_KEYUP) 			{	
				int undo = 0;
				handle_move(e, board, renderer, g_mix_music, s, undo);
				
				if (is_game_over(board)) {
					display_text(renderer, "Game Over", 80, s, true);
					clear_board(board);
					initialize_game(board, s);
					render_game(renderer, board, font, 0);
					continue;
				}

				if (is_2048(board)) {
					display_text(renderer, "You won :)", 80, s, true);
					clear_board(board);
					initialize_game(board, s);
					render_game(renderer, board, font, 0);
					continue;
				}

				if (undo==1) {
					State x = s.top();
					s.pop();
					int points = s.top().points;
					s.push(x);
					render_game(renderer, board, font, points);
					s.pop();		
					continue;
				}

				else if (undo==2) {												// couldn't undo due to empty stack
					render_game(renderer, board, font, s.top().points);
					continue;
				}

				if (s.size()>=1 && compare(board, s.top().v)) {	 				// board same as before last move
					s.pop();
					render_game(renderer, board, font, s.top().points);		
					continue;
				}

				assign_random_number(board);
				render_game(renderer, board, font, s.top().points);
			}

			else if (e.type == SDL_MOUSEBUTTONUP) {
				button_handler(e, board, s);
				render_game(renderer, board, font, 0);
			}
		}
	}
	TTF_CloseFont(font);
}
