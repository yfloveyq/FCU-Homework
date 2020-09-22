#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Data {
    int value;
    Data *next;
};

void input(Data *n, int num) {
    Data *newdata = new Data();     //create new memory size for data
    newdata->value = num;           //put num into int value from struct data
    newdata->next = NULL;           //define the next element is NULL
    Data *now = n;
    Data *pas = NULL;
    while (now != NULL && num > now->value) {
        pas = now;              //change numbers
        now = now->next;
    }
    if (pas != NULL) {
        pas->next = newdata;
        newdata->next = now;
    } else {
        newdata->next = n;
    }
}

void printnum(Data *n) {

    Data *now = n;
    while (now != NULL) {
        printf("%d ", now->value);
        now = now->next;
    }
    puts("");
}

int counter(Data *n) {
    int counter = 0;
    while (n != NULL) {
        counter++;
        n = n->next;
    }
    return counter;
}

int sum(Data *n) {

    int sum = 0;

    while (n != NULL) {
        sum += n->value;
        n = n->next;
    }
    return sum;

}

float average(Data *n) {
    return (float) sum(n) / (float) move(n);
}

int main() {

    Data *Ptr = new Data();
    srand(time(NULL));
    Ptr->value = 0;
    Ptr->next = NULL;
    for (int i = 0; i < 25; ++i) {
        input(Ptr, (int) rand() % 100);
    }
    Ptr = Ptr->next;

    printnum(Ptr);
    printf("The sum is : %d\n", sum(Ptr));
    printf("The average is : %f\n", average(Ptr));


    return 0;
}



