#include <nds.h>
#include <stdio.h>
#include "tiles.h"
#include "GameState.h"
#include "ForwardModel.h"

int         seconds;
static u8*  tileMemory;
static u16* mapMemory;

GameState    gs;
ForwardModel fm;

void int_timer_0()
{
    seconds += 1;

    // GEnerar una accion
    action = Action();
    action.SetRight();

    fm.GhostStep(gs, action);
}

void ConfigureTimers()
{
    irqEnable(IRQ_TIMER0);
    irqSet(IRQ_TIMER0, int_timer_0);
    TIMER_DATA(0) = 32764;
    TIMER_CR (0) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ;
}

void ConfigureScreen()
{
    REG_POWERCNT = (vu16) POWER_ALL_2D;
    REG_DISPCNT  = MODE_0_2D | DISPLAY_BG0_ACTIVE ;
    VRAM_A_CR    = VRAM_ENABLE | VRAM_A_MAIN_BG ;
    BGCTRL [0]   = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1);
    tileMemory   = (u8*)  BG_TILE_RAM(1);
    mapMemory    = (u16*) BG_MAP_RAM(0);

    BG_PALETTE[0]=RGB15(5,5,5);
    BG_PALETTE[1]=RGB15(10,10,31);
    BG_PALETTE[2]=RGB15(31,15,10);
    BG_PALETTE[3]=RGB15(31,31,0);
    BG_PALETTE[4]=RGB15(10,31,10);
    BG_PALETTE[8]=RGB15	(128, 0, 255);
    BG_PALETTE[9]=RGB15(255, 192, 203);
    BG_PALETTE[7]=RGB15(31,31,0);
    BG_PALETTE[6]=RGB15(31,31,31);

    dmaCopy(black_bg,    tileMemory     ,  sizeof(black_bg));     // 0
    dmaCopy(wall,        tileMemory + 64,  sizeof(wall));         // 1
    dmaCopy(wall_circle, tileMemory + 128, sizeof(wall_circle));  // 2
    dmaCopy(pacman,      tileMemory + 192, sizeof(pacman));       // 3
    dmaCopy(ghost_1,       tileMemory + 256, sizeof(ghost_1)); //4
    dmaCopy(ghost_2,       tileMemory + 320, sizeof(ghost_2));   //5
    dmaCopy(ghost_3,       tileMemory + 384, sizeof(ghost_3));   //6
    dmaCopy(ghost_4,       tileMemory + 448, sizeof(ghost_4));   //7
    dmaCopy(coin,        tileMemory + 512, sizeof(coin));        //8
    dmaCopy(pastilla,        tileMemory + 576, sizeof(pastilla));     // 9
    dmaCopy(pastilla,        tileMemory + 640 sizeof(pastilla));    
}

void SetUp(GameState &gs)
{
    gs.Reset();
    ConfigureScreen();
    ConfigureTimers();
}

void ShowWorld(GameState &gs)
{
    int row,col,pos_mapMemory,pos_mapData;

    // Copy the world in gs to map memory
    pos_mapData = 0;
    for(row=0;row<24;row++)
        for(col=0;col<32;col++)
        {
            pos_mapMemory            = row*32+col;
            mapMemory[pos_mapMemory] = gs.GetTileID(row,col);
            pos_mapData ++;
        }

    // Draw Pacman
    pos_mapMemory = gs.pacman_row*32+gs.pacman_col;
    mapMemory[pos_mapMemory] = TILE_PACMAN;

    consoleDemoInit();
    iprintf("\x1b[2;2HCoins recollected: %d", gs.collected_coins);
    iprintf("\x1b[4;2HElapsed Time: %d", seconds);
}

void Update(GameState &gs, ForwardModel& fm)
{
    u32 key;
    ShowWorld(gs);
    scanKeys();
    key = keysDown();
    Action action;
    if (key & KEY_UP)    action.SetUp();
    if (key & KEY_RIGHT) action.SetRight();
    if (key & KEY_DOWN)  action.SetDown();
    if (key & KEY_LEFT)  action.SetLeft();
    fm.Step(gs, action);
}

int main(void)
{


    SetUp(gs);

	while(1)
	{
        if (gs.IsTerminal())
        {
            ShowWorld(gs);
            iprintf("\x1b[6;2HGame Over");
            irqDisable(IRQ_TIMER0);
        }
        else
            Update(gs, fm);
		swiWaitForVBlank();
	}
}
