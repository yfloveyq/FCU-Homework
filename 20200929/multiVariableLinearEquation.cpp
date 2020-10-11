#include <stdio.h>

#define MAX_EQUATION_NUMBER 100

void makeTheRowthCoefficientToOne(int row, int variableNumber, float equations[MAX_EQUATION_NUMBER][MAX_EQUATION_NUMBER]) {
    float coefficientOfTheRowthVariable = equations[row][row];
    for (int i = 0; i <= variableNumber; ++i) {
        equations[row][i] /= coefficientOfTheRowthVariable;
    }
}

void eraseTheRowthCoefficientInOtherRows(int row, int variableNumber, float equations[MAX_EQUATION_NUMBER][MAX_EQUATION_NUMBER]) {
    for (int i = 0; i < variableNumber; ++i) {
        if (i != row) {
            float coefficientToBeErase = equations[i][row];
            for (int j = 0; j <= variableNumber; ++j) {
                equations[i][j] -= equations[row][j] * coefficientToBeErase;
            }
        }
    }
}

void performGaussianElimination(int variableNumber, float equations[MAX_EQUATION_NUMBER][MAX_EQUATION_NUMBER]) {
    for (int i = 0; i < variableNumber; ++i) {
        if (equations[i][i] != 0) { // prevent divided by zero(results in infinite)
            makeTheRowthCoefficientToOne(i, variableNumber, equations);
            eraseTheRowthCoefficientInOtherRows(i, variableNumber, equations);
        }
    }
}

const char* judgeResult(int variableNumber, float equations[MAX_EQUATION_NUMBER][MAX_EQUATION_NUMBER]) {

    for (int i = 0; i < variableNumber - 1; ++i) { // check the previous variable's coefficient before the last variable
        if (equations[variableNumber - 1][i] != 0) {
            return "computation error, non-zero coefficient found, please check your code.";
        }
    }
    if (equations[variableNumber - 1][variableNumber - 1] == 0) {
        if (equations[variableNumber - 1][variableNumber] == 0) { // infinite
            return "Infinite solutions";
        } else {
            return "No solution";
        }
    } else if (equations[variableNumber - 1][variableNumber - 1] == 1) {
        return "The only solution";
    }
    return "computation error, the last coefficient not equals to 1 or 0, please check your code.";
}

int main() {
    // variable declaration and initialization
    int variableNumber = 0;
    float equations[MAX_EQUATION_NUMBER][MAX_EQUATION_NUMBER] = {0};
    // read inputs
    scanf("%d", &variableNumber);
    bool inputEnded = false;
    int rowNumber = 0;
    int variableCountInRow = 0;
    while (!inputEnded) {
        if (variableCountInRow <= variableNumber) { // read right hand side value(i.e. variable count + 1)
            scanf("%f", &equations[rowNumber][variableCountInRow]);
        }
        if (equations[rowNumber][variableCountInRow++] == -999) {
            inputEnded = true;
        } else if (variableCountInRow > variableNumber) {
            rowNumber++;
            variableCountInRow = 0;
        }
    }

    performGaussianElimination(variableNumber, equations);

    printf("%s", judgeResult(variableNumber, equations));
    return 0;
}