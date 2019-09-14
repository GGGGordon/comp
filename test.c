// Assignment 1 Mandelbrot: Mandelbrot generation functions
// mandelbrot.c
//
// Completed by
//  Jianan Ge (z5191407)
//
// Modified on 2018-09-04
// Peter Kerr (dayHH-lab)
//
// Version 1.0.2: Fix minor typos in comments.
// Version 1.0.1: Fix issues with spacing and indentation.
// Version 1.0.0: Assignment released.

#include <stdio.h>

// Add your own #includes here

#include <math.h> 
#include "mandelbrot.h"
#include "pixelColor.h"

// Add your own #defines here
#define MAX_STEPS 256
#define TILE_SIZE 512


// Add your own function prototypes here
int escapeSteps(struct complex c);

void drawMandelbrot(
    struct pixel pixels[TILE_SIZE][TILE_SIZE],
    struct complex center,
    int z
    );


// Take a pixel grid and and the path from the web browser used to
// request the 'tile'.
//
// The requestPath will be in the form "/mandelbrot/2/{zoom}/{x}/{y}.bmp".
// In the query, 'x' and 'y' are decimals and describe the 'center' of the
// tile and need to be converted into a complex number.
// 'zoom' is an integer representing the zoom level for the tile.
void serveMandelbrot(
    struct pixel pixels[TILE_SIZE][TILE_SIZE],
    char *requestPath
) {
    struct complex center = {0.0, 0.0};
    int z = 7;

    sscanf(
        requestPath,
        "/mandelbrot/2/%d/%lf/%lf.bmp",
        &z, &center.re, &center.im
    );

    // Use drawMandelbrot to draw the image.
    drawMandelbrot(pixels, center, z);
}

int main (void){
    /*double real;
    double imaginary;
    scanf("%d",&real);
    scanf("%d",&imaginary);
     
    struct complex input;
    input.re = real;
    input.im = imaginary;
    
    int steps;
    steps =  escapeSteps(input);
    printf("%d\n",steps);*/
    
    double x = -2;
    double y = -1;
    
    while (y < 1){
       x = -2;
        while(x < 1){
            struct complex abc;
            abc.re = x;
            abc.im = y;
            int steps;
            steps = escapeSteps(abc);
            
            if (steps!= -1){
                printf(" ");
            }
            else{
                printf("*");
            }
            x = x + 0.05;
        }
        printf("\n");
        y= y + 0.1;
    }    
        
    
    
    return 0;
}


// Draw a single Mandelbrot tile, by calculating and colouring each of
// the pixels in the tile.
//
// Your function "returns" this tile by filling in the `pixels` 2D array
// that is passed in to your function.
//
// The `pixels` array is TILE_SIZE high and TILE_SIZE wide.
// The bottom left corner of the image is pixels[0][0].
//
// `center` is a complex number, representing the center of the tile.
// `z` is used to calculate the distance between each pixel in the image.
// Each pixel is 2^(-z) apart from each other.
void drawMandelbrot(
    struct pixel pixels[TILE_SIZE][TILE_SIZE],
    struct complex center,
    int z
    
    
) {
    double d;
    d = pow(2,-z);
    
    int re = 0;
    int im = 0;
    
    struct complex curr;
      
     // TODO: COMPLETE THIS FUNCTION
     
     // 1: find the re and im offset for the bottom left corner ([0][0])
     
     // 2: within two while loops, go through the whole 2d array, incremending the index as well as the re and im parts, like:
        //re = re + 1;
        //curr.re = curr.re + d;
        
     // 3: within the two loops, check the escapeSteps, if -1 make all the colours in the pixel white, else make them black 
}

// Determine the number of steps required to escape the Mandelbrot set,
// for the given complex number `c`.
int escapeSteps(struct complex c) {
    int steps = 0;
    struct complex w;
    w.re = 0;
    w.im = 0;
    double moduluSquare = (w.re * w.re + w.im * w.im);
    double temp = w.re ;
    while(steps < MAX_STEPS && moduluSquare < 4){
    temp = w.re;
    w.re = (w.re * w.re - w.im * w.im) + c.re ;
    w.im = 2 * temp * w.im + c.im ;
    moduluSquare = (w.re * w.re + w.im * w.im);
    steps++;
    }
    
    if( steps == MAX_STEPS) {
    steps = NO_ESCAPE;
    }
       
    

    // TODO: COMPLETE THIS FUNCTION

    return steps;
}

// Add your own functions here.
// Remember to make them static.
