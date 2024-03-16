#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void plotPixel(int x, int y) {
    putpixel(x, y, RED);
}

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps, k;
    float xIncrement, yIncrement, x = x1, y = y1;

    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    xIncrement = (float)dx / steps;
    yIncrement = (float)dy / steps;

    plotPixel(x,y);

    for (k = 0; k < steps; k++) {
        if (abs(dx) > abs(dy)) {
            x += xIncrement;
            if (dy < 0) {
                y -= 1;
            } else {
                y += 1;
            }
        } else {
            y += yIncrement;
            if (dx < 0) {
                x -= 1;
            } else {
                x += 1;
            }
        }
        plotPixel(x, y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1, y1, x2, y2;

    printf("Enter the starting point (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the ending point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    drawLineDDA(x1, y1, x2, y2);

    delay(5000);
    closegraph();

    return 0;
}
