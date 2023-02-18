#include "../inc/header.h"

int dist(int **matrix, int start_x, int start_y, int stovp, int ryad)  {

    int max;
    int direction_x[4] = {1, 0, -1, 0}; // 0 - right, 1 - down, 2 - left, 3 - up
    int direction_y[4] = {0, 1, 0, -1}; // 0 - right, 1 - down, 2 - left, 3 - up
    bool stop = false;
    int flag = 0;

    int d = 0;
    if (matrix[start_y][start_x] == -2 ) 
    {
        mx_printerr("entry point cannot be an obstacle\n");
        exit(0);
    }

    matrix[start_y][start_x] = 0; 

    while (!stop | flag) {
        stop = true;

        for (int y = 0; y < ryad; y++) {
            for (int x = 0; x < stovp; x++) {
                if (matrix[y][x] == d) {
                    for (int k = 0; k < 4; k++)  {

                        int iy = y + direction_y[k]; 
                        int ix = x + direction_x[k];

                        if (iy >= 0 && iy < ryad && ix >= 0 && ix < stovp && matrix[iy][ix] == -1) {
                            stop = false;  
                            matrix[iy][ix] = d + 1;
                        }
                    }
                }
            }   
        }
            
        d++;
        flag = 0;
    }

    max = matrix[0][0];
    
    for (int i = 0; i < ryad; i++) {
        for (int j = 0; j < stovp; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }      
        }
    }

    
    return max;
}

