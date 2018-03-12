#include "board.h"
#include "block.h"

Board* createBoard(void)
{
	Board *newBoard = (Board*) malloc(sizeof(Board));
	return newBoard;
}

void destroyBoard(Board *brd)
{
	/* TODO IMPORTANT Free all block pointers */
	free(brd->blocks);
	free(brd);
}

/* Fill the block array in board with random blocks based on level */
void populateBoard(Board *brd, int lvl) {

	/* TODO */
	/* Get random content based on level
	 * (i.e. How many different colors of blocks, special blocks etc.) */
	switch (lvl) {
		case 1:
			break;
		default:
			break;
	}

	int blockx, blocky;
	BlockColor color;
	for (int i = 0; i < BOARD_COLUMNS * BOARD_ROWS; ++i) {
		Block *tmpBlock = (Block*) malloc(sizeof(Block));
		/* TODO Get random color here */
		color = WHITE;
		blockx = (i % BOARD_ROWS) * BLOCK_SIZE_WIDTH;
		blocky = (i / BOARD_ROWS) * BLOCK_SIZE_HEIGHT;
		tmpBlock = createBlock(blockx, blocky, color, gBlockTextures.plainBlock);
		brd->blocks[i] = tmpBlock;
	}
}

void drawBoard(SDL_Renderer **rend, Board *brd) {
	Block *tmpBlock;
	for (int i = 0; i < BOARD_COLUMNS * BOARD_ROWS; ++i) {
		tmpBlock = brd->blocks[i];
		if ( SDL_RenderCopy(*rend, tmpBlock->texture, NULL, &tmpBlock->block) != 0) {
		}
	}
}