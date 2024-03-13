#include <stdio.h>

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    float sideA;
    float sideB;
} Rectangle;

void definePointCoordinates(Point *p) {
    printf("[Point]\nDefine coordinate X: ");
    scanf("%f", &((*p).x));
    printf("Define coordinate Y: ");
    scanf("%f", &((*p).y));
}

void movePoint(Point *p) {
    float moveXby;
    float moveYby;

    printf("Move coordinate X by: ");
    scanf("%f", &moveXby);
    printf("Move coordinate Y by: ");
    scanf("%f", &moveYby);

    (*p).x += moveXby;
    (*p).y += moveYby;
}

void defineRectangleSides(Rectangle *r) {
    printf("\n[Rectangle]\nDefine side A: ");
    scanf("%f", &((*r).sideA));
    printf("Define side B: ");
    scanf("%f", &((*r).sideB));
}

float calculateRectangleCircumference(Rectangle *r) {
    return ((*r).sideA * 2) + ((*r).sideB * 2);
}

float calculateAreaOfRectangle(Rectangle *r) {
    return (*r).sideA * (*r).sideB;
}

int main() {
    Point point;
    Rectangle rectangle;

    definePointCoordinates(&point);
    printf("Coordinates of point: X = %.2f Y = %.2f\n", point.x, point.y);
    movePoint(&point);
    printf("Updated coordinates of point: X = %.2f Y = %.2f\n", point.x, point.y);

    defineRectangleSides(&rectangle);
    printf("Rectangle sides: A = %.2f B = %.2f", rectangle.sideA, rectangle.sideB);
    printf("\nRectangle circumference: %.2f", calculateRectangleCircumference(&rectangle));
    printf("\nArea of rectangle: %.2f\n", calculateAreaOfRectangle(&rectangle));

    return 0;
}
