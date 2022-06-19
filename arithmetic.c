#include <stdio.h>
#include <SDL.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arithmetic.h"
#include "main.h"
int height;
int width;

void next(){
        for (int i = 0; i < height; ++i) { //Determine the next survival based on the surrounding cell inventory
            for (int j = 0; j < width; ++j) {
                if (i==0&&j==0){//Determine the number of living cells around
                    t[i][j]=a[i][j + 1]+ a[i + 1][j] + a[i + 1][j + 1];
                }
                else if (i==0&&1<=j&&j<=width-2){//different situations
                    t[i][j] =a[i][j - 1] + a[i][j + 1] + a[i + 1][j - 1] + a[i + 1][j]
                                         + a[i + 1][j + 1];
                }
                else if(1<=i&&i<=height-2&&j==0){
                    t[i][j]=a[i-1][j]+a[i-1][j+1]+a[i][j+1]+a[i+1][j]+a[i+1][j+1];
                }
                else if(i==height-1&&j==width-1){
                    t[i][j]=a[i][j-1]+a[i-1][j-1]+a[i-1][j];
                }
                else if(1<=i+1&&i+1<=height-2&&j==width-1){
                    t[i][j]=a[i - 1][j - 1] + a[i - 1][j]+ a[i][j - 1]+ a[i + 1][j - 1] + a[i + 1][j];
                }
                else if(i==height-1&&1<=j&&j<=width-2){
                    t[i][j]=a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j - 1] + a[i][ j + 1];
                }
                else if(i==0&&j==width-1){
                    t[i][j] = a[i][j - 1] + a[i + 1][j - 1] + a[i + 1][j];
                }
                else if(i==height-1&&j==0){
                    t[i][j] = a[i - 1][j] + a[i - 1][j + 1] + a[i][j + 1];
                }
                else{
                    t[i][j]=a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j - 1] + a[i][j + 1]
                            + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];
                }
            }
        }
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int m = check(t[i][j]);
                if (m==3){
                    a[i][j]=1;//Next Generation Cell Survival
                }
                if (m==0){
                    a[i][j]=0;//Next Generation Cell dead
                }
            }
        }
    }

int check(int d){
    if (d==3){ //a function of the number of detections
        return 3;
    }
    if (d!=3&&d!=2){
        return 0;
    } else{
        return -1;
    }
}


