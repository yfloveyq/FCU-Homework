#include <stdio.h>
#include <stdlib.h>

#define MAX_MAZE_SIZE 20
#define MAZE_ENTRY_X 0
#define MAZE_ENTRY_Y 0
#define MAX_POPPED_DIRECTION_SIZE 3

typedef struct t_stack {
    int top;
    unsigned capacity;
    char *stepSymbols;
} MazeStepStack;

struct t_stack *createStack(unsigned capacity) {
    struct t_stack *stack = (struct t_stack *) malloc(sizeof(struct t_stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->stepSymbols = (char *) malloc(stack->capacity * sizeof(char));
    return stack;
}


bool isFull(struct t_stack *stack) {
    return stack->top == stack->capacity - 1;
}

bool isEmpty(struct t_stack *stack) {
    return stack->top == -1;
}

void push(struct t_stack *stack, char stepSymbol) {
    if (isFull(stack))
        return;
    stack->stepSymbols[++stack->top] = stepSymbol;
}

char pop(struct t_stack *stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->stepSymbols[stack->top--];
}

char peek(struct t_stack *stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->stepSymbols[stack->top];
}

void printStepSymbols(struct t_stack *stack) {
    if (!isEmpty(stack)) {
        char *stepSymbols = stack->stepSymbols;
        for (int i = 0; i <= stack->top; ++i) {
            printf("%c", *(stepSymbols + i));
        }
    }
}

void addPoppedDirections(int currentX, int currentY, char poppedDirection, char poppedDirections[MAX_MAZE_SIZE][MAX_MAZE_SIZE][MAX_POPPED_DIRECTION_SIZE]) {
    for (int i = MAX_POPPED_DIRECTION_SIZE - 1; i > 0; --i) {
        if (poppedDirections[currentX][currentY][i] == '\0') {
            poppedDirections[currentX][currentY][i] = poppedDirection;
            break;
        }
    }
}

int isDirectionAlreadyWalkedBefore(int currentX, int currentY, char direction, char poppedDirections[MAX_MAZE_SIZE][MAX_MAZE_SIZE][MAX_POPPED_DIRECTION_SIZE]) {
    int isWaled = 0;
    for (int i = 0; i < MAX_POPPED_DIRECTION_SIZE; ++i) {
        if (direction == poppedDirections[currentX][currentY][i]) {
            isWaled = 1;
            break;
        }
    }
    return isWaled;
}

int isDirectionWalkable(int mazeSize, int currentX, int currentY, char direction, char poppedDirections[MAX_MAZE_SIZE][MAX_MAZE_SIZE][MAX_POPPED_DIRECTION_SIZE],
                         int mazeArray[MAX_MAZE_SIZE][MAX_MAZE_SIZE], MazeStepStack *mazeStepStack) {
    char reversedDirection;
    int xDelta = 0;
    int yDelta = 0;
    switch (direction) {
        case 'E':
            reversedDirection = 'W';
            xDelta = 1;
            break;
        case 'S':
            reversedDirection = 'N';
            yDelta = 1;
            break;
        case 'W':
            reversedDirection = 'E';
            xDelta = -1;
            break;
        default: // 'N'
            reversedDirection = 'S';
            yDelta = -1;
            break;
    }
    return (currentX + xDelta) >= 0
           && (currentY + yDelta) >= 0
           && (currentX + xDelta) <= mazeSize
           && (currentY + yDelta) <= mazeSize
           && mazeArray[currentY + yDelta][currentX + xDelta] // loop up the map if the direction is walkable. note: 1 = true, 0 = false by default in C language.
           && !isDirectionAlreadyWalkedBefore(currentX, currentY, direction, poppedDirections) // check if the direction already walked before and went back because no more ways to go
           && peek(mazeStepStack) != reversedDirection; // prevent going back
}

void solveMaze(int mazeSize, int mazeArray[MAX_MAZE_SIZE][MAX_MAZE_SIZE], MazeStepStack *mazeStepStack) {
    int mazeExitX = mazeSize - 1;
    int mazeExitY = mazeSize - 1;
    int currentX = MAZE_ENTRY_X;
    int currentY = MAZE_ENTRY_Y;
    char poppedDirections[MAX_MAZE_SIZE][MAX_MAZE_SIZE][MAX_POPPED_DIRECTION_SIZE] = {'\0'};
    while (currentX != mazeExitX || currentY != mazeExitY) {
        if (isDirectionWalkable(mazeSize, currentX, currentY, 'E', poppedDirections, mazeArray, mazeStepStack)) {
            push(mazeStepStack, 'E');
            currentX++;
        } else if (isDirectionWalkable(mazeSize, currentX, currentY, 'S', poppedDirections, mazeArray, mazeStepStack)) {
            push(mazeStepStack, 'S');
            currentY++;
        } else if (isDirectionWalkable(mazeSize, currentX, currentY, 'W', poppedDirections, mazeArray, mazeStepStack)) {
            push(mazeStepStack, 'W');
            currentX--;
        } else if (isDirectionWalkable(mazeSize, currentX, currentY, 'N', poppedDirections, mazeArray, mazeStepStack)) {
            push(mazeStepStack, 'N');
            currentY--;
        } else {
            char poppedDirection = pop(mazeStepStack);
            switch (poppedDirection) {
                case 'E':
                    currentX--;
                    break;
                case 'S':
                    currentY--;
                    break;
                case 'W':
                    currentX++;
                    break;
                default: // 'N'
                    currentY++;
                    break;
            }
            addPoppedDirections(currentX, currentY, poppedDirection, poppedDirections);
        }
    }

    printStepSymbols(mazeStepStack);
}

int main() {
    // variable declaration and initialization
    int mazeSize = 0;
    int mazeArray[MAX_MAZE_SIZE][MAX_MAZE_SIZE] = {false};
    // read inputs
    scanf("%d", &mazeSize);
    for (int i = 0; i < mazeSize; ++i) {
        for (int j = 0; j < mazeSize; ++j) {
            scanf("%d", &mazeArray[i][j]);
        }
    }
    // initialize stack to save steps
    MazeStepStack *mazeStepStack = createStack(mazeSize * mazeSize);
    // solve the maze
    solveMaze(mazeSize, mazeArray, mazeStepStack);
    return 0;
}
