int a[1000][1000];
int t[1000][1000];
char w;
int state;
int count;
int delay;
int init();
void draw_object( int x, int y, SDL_Texture *texture );
void draw_object1( int x, int y, SDL_Texture *texture );
void render();
void input();
void render1();
int TILE_SIZE;

