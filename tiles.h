#ifndef SOURCE_TILES_H
#define SOURCE_TILES_H
// Definition of the tiles used in the game

#define TILE_BLACK  0
#define TILE_WALL   1
#define TILE_PACMAN 3
#define TILE_COIN   5
#define TILE_GHOST_1 4
#define TILE_GHOST_2 8
#define TILE_GHOST_3 9
#define TILE_GHOST_4 7
#define TILE_PASTILLA 6
#define TILE_CEREZA 11

u8 black_bg[64] =
        {
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0
        };

u8 wall[64]=
        {
                1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1
        };

u8 wall_circle[64]=
        {
                0,0,0,0,0,0,0,0,
                0,0,0,1,1,0,0,0,
                0,0,1,1,1,1,0,0,
                0,1,1,1,1,1,1,0,
                0,1,1,1,1,1,1,0,
                0,0,1,1,1,1,0,0,
                0,0,0,1,1,0,0,0,
                0,0,0,0,0,0,0,0
        };

u8 pacman[64]=
        {
                0,0,0,3,3,0,0,0,
                0,3,3,3,3,3,0,0,
                0,3,0,3,3,3,0,0,
                3,3,3,0,0,0,0,0,
                3,3,3,0,0,0,0,0,
                0,3,3,3,3,3,0,0,
                0,3,3,3,3,3,0,0,
                0,0,0,3,3,0,0,0
        };

u8 ghost_1[64]=
        {
                0,0,0,4,4,0,0,0,
                0,0,4,4,4,4,0,0,
                0,4,4,4,4,4,4,0,
                0,4,0,4,4,0,4,0,
                0,4,4,4,4,4,4,0,
                0,4,4,4,4,4,4,0,
                0,4,4,4,4,4,4,0,
                0,4,0,4,4,0,4,0
        };
u8 ghost_2[64] =
        {
      
                0,0,0,8,8,0,0,0,
                0,0,8,8,8,8,0,0,
                0,8,8,8,8,8,8,0,
                0,8,0,8,8,0,8,0,
                0,8,8,8,8,8,8,0,
                0,8,8,8,8,8,8,0,
                0,8,8,8,8,8,8,0,
                0,8,0,8,8,0,8,0
        };

u8 ghost_3[64] =
        {
                0,0,0,9,9,0,0,0,
                0,0,9,9,9,9,0,0,
                0,9,9,9,9,9,9,0,
                0,9,0,9,9,0,9,0,
                0,9,9,9,9,9,9,0,
                0,9,9,9,9,9,9,0,
                0,9,9,9,9,9,9,0,
                0,9,0,9,9,0,9,0

        };

u8 ghost_4[64] =
        {
                0,0,0,7,7,0,0,0,
                0,0,7,7,7,7,0,0,
                0,7,7,7,7,7,7,0,
                0,7,0,7,7,0,7,0,
                0,7,7,7,7,7,7,0,
                0,7,7,7,7,7,7,0,
                0,7,7,7,7,7,7,0,
                0,7,0,7,7,0,7,0

        };
u8 coin[64]=
        {
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,2,2,0,0,0,
                0,0,2,2,2,2,0,0,
                0,0,2,2,2,2,0,0,
                0,0,0,2,2,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0
        };
u8 pastilla[64]=
        {
                0,0,0,0,0,0,0,0,
                0,0,0,6,0,0,0,0,
                0,0,6,6,6,6,0,0,
                0,6,6,6,6,6,6,0,
                0,6,6,6,6,6,6,0,
                0,6,6,6,6,6,6,0,
                0,0,6,6,6,6,0,0,
                0,0,0,0,0,0,0,0
        };
u8 cereza[64]=
        {
    0,0,0,6,6,0,0,0,
    0,6,6,6,6,6,0,0,
    0,6,0,6,6,6,0,0,
    6,6,6,0,0,0,0,0,
    6,6,6,0,0,0,0,0,
    0,6,6,6,6,6,0,0,
    0,6,6,6,6,6,0,0,
    0,0,0,6,6,0,0,0

        };

#endif