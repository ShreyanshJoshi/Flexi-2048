/**
 * @file styles.h
 * @author Shreyansh Joshi
 * @brief File containing tile colors and related structs, and some defined constants.
 *
 */
#pragma once
/** @struct COLOR
 *  @brief This structure defines a RBGA color
 *  All values are stored in chars.
 * 
 *  @var COLOR::r
 *  The red value 
 *  @var COLOR::g
 *  The green value 
 *  @var COLOR::b 
 *  The blue value
 *  @var COLOR::a 
 *  The alpha value
 * 
 */

//Screen dimension constants

/** @def SCREEN_WIDTH
 * The width of the window
 */
#define SCREEN_WIDTH 450

/** @def SCREEN_HEIGHT
 * The height of the window
 */
#define SCREEN_HEIGHT 550

/** @def SCREEN_PAD
 * The padding to use while drawing elements to window
 */
#define SCREEN_PAD 10

//FONT settings

/** @def FONT_PATH
 * The path to the ttf font used by the game.
 */
#define FONT_PATH "UbuntuMono-R.ttf"

/** @def TITLE_FONT_SIZE
 * The font size used while displaying "2048" at the start of game.
 */
#define TITLE_FONT_SIZE 150

/** @def GOVER_FONT_SIZE
 * The font size used while displaying "Game Over" at the end of game.
 */
#define GOVER_FONT_SIZE 60

/** @def CELL_FONT_SIZE
 * The font size used while displaying each number inside the cells
 */
#define CELL_FONT_SIZE 40

struct COLOR {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

/** The background color used by the application  */
struct COLOR g_bg = {211, 204, 201, 255};

/** The text color used by the UI elemets (dark only). draw_white_text() is used to draw white text, and draw_grey_text
 * is used to draw grey text.
 */
struct COLOR g_fg = {80, 80, 80, 255};

/** The background color used by the new game button  */
struct COLOR g_button_bg = {255, 153, 102, 255};

/** The background color used by the score field  */
struct COLOR g_score_bg = {143, 122, 102, 255};

/** The colors used by the tiles
 *  They are according to exponent.
 *  Example: exponent of 1 will use g_COLORS[1]
 */
struct COLOR g_COLORS[] = {
    {192, 182, 171, 255},           // Empty tile
    {243, 235, 224, 255},           // 2
    {243, 227, 205, 255},           // 4
    {233, 178, 132, 255},           // 8
    {231, 159, 97, 255},            // 16
    {214, 145, 115, 255},            // 32
    {215, 106, 12, 255},            // 64   
    {237, 211, 127, 255},            // 128
    {237, 204, 97, 255},            // 256
    {237, 200, 60, 255},            // 512
    {237, 197, 26, 255},            // 1024
    {237, 203, 0, 255},             // 2048
    {202, 135, 135, 255},           // 4096
    {205, 109, 109, 255},           // 8192
    {206, 82, 82, 255},             // 16384
    {210, 37, 37, 255},             // 32768
    {255, 0, 0, 255}                // 65536
};
