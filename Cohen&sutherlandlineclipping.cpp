#include <stdio.h>
#include <graphics.h>

#define INSIDE 0 // 0000
#define LEFT 1   // 0001
#define RIGHT 2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000

// Define the window coordinates
#define X_MIN 100
#define X_MAX 300
#define Y_MIN 100
#define Y_MAX 300

int computeOutCode(int x, int y) {
    int code = INSIDE;

    if (x < X_MIN)
        code |= LEFT;
    else if (x > X_MAX)
        code |= RIGHT;

    if (y < Y_MIN)
        code |= BOTTOM;
    else if (y > Y_MAX)
        code |= TOP;

    return code;
}

void drawLine(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y2);
}

void cohenSutherland(int x1, int y1, int x2, int y2) {
    int outcode1, outcode2, outcode;
    int accept = 0, done = 0;

    while (!done) {
        outcode1 = computeOutCode(x1, y1);
        outcode2 = computeOutCode(x2, y2);

        if (!(outcode1 | outcode2)) {
            accept = 1;
            done = 1;
        } else if (outcode1 & outcode2) {
            done = 1;
        } else {
            int x, y;

            outcode = outcode1 ? outcode1 : outcode2;

            if (outcode & TOP) {
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            } else if (outcode & BOTTOM) {
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            } else if (outcode & RIGHT) {
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            } else {
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            if (outcode == outcode1) {
                x1 = x;
                y1 = y;
            } else {
                x2 = x;
                y2 = y;
            }
        }
    }

    if (accept) {
        drawLine(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    printf("Enter coordinates of line (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    initgraph(&gd, &gm, NULL);

    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX); // Drawing the clipping window

    drawLine(x1, y1, x2, y2); // Drawing the original line

    cohenSutherland(x1, y1, x2, y2); // Applying line clipping

    getch();
    closegraph();
    return 0;
}
