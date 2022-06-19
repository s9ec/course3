#include <stdio.h>
#include <SDL.h>
#include <stdlib.h>
#include <stdbool.h>
#include "store.h"

int height;
int width;



int store(FILE *fp){
    fp = fopen("initial.txt", "w+");  //Save the updated live cell coordinates to a file
    if (!fp) {
        fprintf(stderr, "Failed in opening %s\n", fp);
        return -1 ;
    }
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if (a[i][j]==1){
                fprintf(fp,"%d %d\n",i,j);
            }
        }
    }
    fclose(fp);
    return 1;
}
