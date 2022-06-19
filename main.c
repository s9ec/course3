#include <stdio.h>
#include <SDL.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"
#include "initial.h"
#include "store.h"
#include "arithmetic.h"


int main(int argc, char *argv[]) {
    delay = 150;//Delay time per iteration
    count=0; //Calculate the number of iterations
    char s; //Whether the user chooses the number of iterations
    state=0;
    printf("finite or not?(Please input y or n): ");
    scanf("%c",&s);
    if (s=='y') {
        printf("times:");//input the number of iterations
        scanf("%d", &times);
        init();
        FILE *fp;
        if (w=='n'){
            render();
            while (count < times) {      // game loop
                input();
                if (state==0){
                    next();
                }
                render();           // render new state
                speed();   //Make iterations faster or slower
                SDL_Delay(delay); // time between frames (ms)
                int x = store(fp);
                if (x == 1) {
                    count++;  //The number of iterations increases
                } else {
                    return 0;
                }
            }
        } else{
            render1();
            while (count < times) {      // game loop
                input();
                if (state==1){
                    next();
                }
                render1();           // render new state
                speed();
                SDL_Delay(delay); // time between frames (ms)
                int x = store(fp);
                if (x == 1 &&state==1) {
                    count++;
                }
            }
        }
//            printf("%d",count);

    } else{
        init();
        FILE *fp;
        if (w=='n'){
            render();
            while (true) {      // game loop
                input();
                if (state==0){
                    next();
                    count++;
                }

                render();           // render new state
                speed();
                SDL_Delay(delay); // time between frames (ms)
                store(fp);
//                printf("%d",count);
            }
        } else{
            render1();
            while (true) {      // game loop
                input();
                if (state==1){
                    next();
                    count++;
                }
                render1();           // render new state
                speed();
                SDL_Delay(delay);

                 store(fp);
            }
        }

    }
    printf("Generation %d",count);
}


