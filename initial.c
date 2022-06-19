#include <stdio.h>
#include <SDL.h>
#include <stdlib.h>
#include <stdbool.h>
#include "initial.h"
#include "gamedata.h"

int height;
int width;
int dd;
int h,p;
int init(){
    SDL_Window *window = NULL;  //Start creating windows
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());

    atexit(SDL_Quit); // set for clean-up on exit
    FILE *fp; //Store live cell coordinates
    FILE *fp2;//store world size

    char m;
    printf("Do you need to get the size of the world yourself?(y or n): ");
    scanf(" %c",&m); //Whether to choose a world university
    if (m=='n'){
        if ((fp2 = fopen("size.txt", "r")) == NULL){
            printf("error!!!");
            return -1 ;
        }
        char f[100];
        while (fgets(f, 128, fp2) != NULL) {
            sscanf(f,"%d %d",&height,&width); //read file
        }
    } else{
        printf("please input height and width: \n"); //user input
        printf("height: ");
        scanf("%d", &height);
        printf("width: ");
        scanf("%d", &width);
    }
    printf("define the position yourself?(Please input y or n): "); //Determine live cell coordinates
    scanf(" %c",&w);
    getchar();
    if (w=='n'){
        if ((fp = fopen("initial.txt", "r")) == NULL){
            printf("error!!!");
            return -1 ;
        }
        char s[100];
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                a[i][j]=0;
            }
        }
        while (fgets(s, 128, fp) != NULL) {
            int x,y;
            sscanf(s,"%d %d",&x,&y);  //Read live cell coordinates
            a[x][y]=1;
        }
        fclose(fp);
    } else{
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                a[i][j]=0; //Dead cells are represented by 0
            }
        }
    }

    //
    if (width!=height){ //Calculations made if the length and width of the world are not equal
        int mm;
        if (width>height){
            p=900;
            mm=width;
            dd=p/mm;
            h=dd*height;
        } else{
            h=900;
            mm=height;
            dd=h/mm;
            p=dd*width;
        }

    } else{
        h=900;
        p=900;//The maximum length and width that the computer can have
        dd=900/width;
    }

    SDL_CreateWindowAndRenderer(h, p, 0, &window, &renderer); //screen size
    SDL_SetWindowTitle( window, "The game of life"); //title
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    black_surface = SDL_LoadBMP("black.bmp");  //live cell bmp images
    white_surface = SDL_LoadBMP("white.bmp");  //dead cell bmp images
    a_surface=SDL_LoadBMP("OIP-C1.bmp");   //Play and pause buttons
    a_texture=SDL_CreateTextureFromSurface(renderer, a_surface);
    b_surface=SDL_LoadBMP("OIP-C2.bmp");
    b_texture=SDL_CreateTextureFromSurface(renderer, b_surface);
    white_texture = SDL_CreateTextureFromSurface(renderer, white_surface);
    black_texture = SDL_CreateTextureFromSurface(renderer, black_surface);
    return 0;
}
void draw_object( int x, int y, SDL_Texture *texture )
{//Determine the size of each cell and obtain its coordinates
    TILE_SIZE= dd;
    SDL_Rect rect;
    rect.h = TILE_SIZE;
    rect.w = TILE_SIZE;
    rect.x = x * TILE_SIZE;
    rect.y = y * TILE_SIZE;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}
void render(){
    SDL_Event gameEvent;
    for (int x = 0; x < height; ++x) {
        for (int y = 0; y < width; ++y) {
            draw_object(x,y,white_texture);
        }
    }
    int x,y;
    while  ( SDL_PollEvent( &gameEvent)  !=   0  ) {
        if (gameEvent.type == SDL_MOUSEBUTTONDOWN) {
            if (SDL_BUTTON_LEFT==gameEvent.button.button) {
                if (state == 1) {   //Left mouse click on dead cells to make cells alive
                    x = gameEvent.button.x / TILE_SIZE;
                    y = gameEvent.button.y / TILE_SIZE;
                    a[x][y] = 1;
                }
            }
            if (SDL_BUTTON_RIGHT==gameEvent.button.button) {
                if (state == 1) {  //Right mouse click on a dead cell makes the cell die
                    x = gameEvent.button.x / TILE_SIZE;
                    y = gameEvent.button.y / TILE_SIZE;
                    a[x][y] = 0;
                }
            }
        }
        if (gameEvent.type==SDL_KEYDOWN){
            if (gameEvent.key.keysym.sym==SDLK_SLASH){ //Type "/" to pause or start the game
                if (state==0){
                    state=1;
                    break;} else{
                    state=0;
                }
            }

        }
    }

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if (a[i][j]==1){
                draw_object(i,j,black_texture); // draw new square if required
            }
            else{
                draw_object(i,j,white_texture); // draw new square if required
            }
        }
    }
    if (state==1){
        draw_object1(0,0,a_texture);  //Pause and start image switching
    } else{
        draw_object1(0,0,b_texture);
    }
    SDL_RenderPresent(renderer);
}
void render1(){
    SDL_Event gameEvent;
    for (int x = 0; x < height; ++x) {
        for (int y = 0; y < width; ++y) {
            draw_object(x,y,white_texture);
        }
    }
    int x,y;
    while  ( SDL_PollEvent( &gameEvent)  !=   0  ) {
        if (gameEvent.type == SDL_MOUSEBUTTONDOWN) {
            if (SDL_BUTTON_LEFT==gameEvent.button.button) {
                if (state == 0) {   //Left mouse click on dead cells to make cells alive
                    x = gameEvent.button.x / TILE_SIZE;
                    y = gameEvent.button.y / TILE_SIZE;
                    a[x][y] = 1;
                }
            }
            if (SDL_BUTTON_RIGHT==gameEvent.button.button) {
                if (state == 0) {  //Right mouse click on a dead cell makes the cell die
                    x = gameEvent.button.x / TILE_SIZE;
                    y = gameEvent.button.y / TILE_SIZE;
                    a[x][y] = 0;
                }
            }
        }
        if (gameEvent.type==SDL_KEYDOWN){
            if (gameEvent.key.keysym.sym==SDLK_SLASH){ //Type "/" to pause or start the game
                if (state==0){
                state=1;
                break;} else{
                    state=0;
                }
            }

        }
    }
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {

            if (a[i][j]==1){
                draw_object(i,j,black_texture); // draw new square if required
            }
            else{
                draw_object(i,j,white_texture); // draw new square if required
            }
        }
    }
    if (state==0){
        draw_object1(0,0,a_texture); //Pause and start image switching
    } else{
        draw_object1(0,0,b_texture);
    }

    SDL_RenderPresent(renderer);

}
void draw_object1(int x, int y, SDL_Texture *texture){
    int TILE_SIZE1;
    TILE_SIZE1=dd+10;
    SDL_Rect rect;   //Determine the size of each cell and obtain its coordinates
    rect.h = TILE_SIZE1;
    rect.w = TILE_SIZE1;
    rect.x = y*30 ;
    rect.y = x*20 ;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}
void input(){
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    SDL_PumpEvents();
    if (state[SDL_SCANCODE_ESCAPE]) {  // input SDL_SCANCODE_ESCAPE and exit
        printf("Generation: %d",count); //output iteration count
        exit(0);
    }
}
void speed(){
    SDL_Event gameEvent1;
    while  ( SDL_PollEvent( & gameEvent1)  !=   0  ) {
        if (gameEvent1.type==SDL_KEYDOWN){
            if (gameEvent1.key.keysym.sym==SDLK_F10){
                delay+=100;
                break;
            }
            if (gameEvent1.key.keysym.sym==SDLK_F11){
                delay-=30;
                break;
            }
        }
    }
}


