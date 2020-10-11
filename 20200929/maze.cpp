#include <stdio.h>
#include <stdlib.h>

#define MAX_MAZE_SIZE 20
#define MAZE_ENTRY_X 0
#define MAZE_ENTRY_Y 0

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

bool isDirectionWalkable(int currentX, int currentY, char direction, char poppedStep,
                         bool mazeArray[MAX_MAZE_SIZE][MAX_MAZE_SIZE], MazeStepStack *mazeStepStack) {
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
    return mazeArray[currentY + yDelta][currentX + xDelta] // loop up the map if the direction is walkable
           && poppedStep != direction // check if the direction already walked before and went back because no more ways to go
           && peek(mazeStepStack) != reversedDirection; // prevent going back
}

void solveMaze(int mazeSize, bool mazeArray[MAX_MAZE_SIZE][MAX_MAZE_SIZE], MazeStepStack *mazeStepStack) {
    int mazeExitX = mazeSize - 1;
    int mazeExitY = mazeSize - 1;
    int currentX = MAZE_ENTRY_X;
    int currentY = MAZE_ENTRY_Y;
    char poppedStep = '\0';
    while (currentX != mazeExitX || currentY != mazeExitY) {
        if (isDirectionWalkable(currentX, currentY, 'E', poppedStep, mazeArray, mazeStepStack)) {
            push(mazeStepStack, 'E');
            poppedStep = '\0'; // the new step should mind the previous popped step
            currentX++;
        } else if (isDirectionWalkable(currentX, currentY, 'S', poppedStep, mazeArray, mazeStepStack)) {
            push(mazeStepStack, 'S');
            poppedStep = '\0';
            currentY++;
        } else if (isDirectionWalkable(currentX, currentY, 'W', poppedStep, mazeArray, mazeStepStack)) {
            push(mazeStepStack, 'W');
            poppedStep = '\0';
            currentX--;
        } else if (isDirectionWalkable(currentX, currentY, 'N', poppedStep, mazeArray, mazeStepStack)) {
            push(mazeStepStack, 'N');
            poppedStep = '\0';
            currentY--;
        } else {
            poppedStep = pop(mazeStepStack);
            switch (poppedStep) {
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
        }
    }

    printStepSymbols(mazeStepStack);
}

int main() {
    // variable declaration and initialization
    int mazeSize = 0;
    int intTempBooleanValue = 0; // there is no scanf conversion specifier for boolean, use integer to read 1 and 0.
    bool mazeArray[MAX_MAZE_SIZE][MAX_MAZE_SIZE] = {false};
    // read inputs
    scanf("%d", &mazeSize);
    for (int i = 0; i < mazeSize; ++i) {
        for (int j = 0; j < mazeSize; ++j) {
            scanf("%d", &intTempBooleanValue);
            mazeArray[i][j] = intTempBooleanValue;
        }
    }
    // initialize stack to save steps
    MazeStepStack *mazeStepStack = createStack(mazeSize * mazeSize);
    // solve the maze
    solveMaze(mazeSize, mazeArray, mazeStepStack);
    return 0;
}
