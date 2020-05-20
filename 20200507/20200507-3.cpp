#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct data {
    int value;
    data *next;
};

void input(data *n, int num) {
    data *newdata = new data();     //create new memory size for data
    newdata->value = num;           //put num into int value from struct data
    newdata->next = NULL;           //define the next element is NULL
    data *now = n;
    data *pas = NULL;
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

void printnum(data *n) {

    data *now = n;
    while (now != NULL) {
        printf("%d ", now->value);
        now = now->next;
    }
    puts("");
}

int counter(data *n) {
    int counter = 0;
    while (n != NULL) {
        counter++;
        n = n->next;
    }
    return counter;
}

int sum(data *n) {

    int sum = 0;

    while (n != NULL) {
        sum += n->value;
        n = n->next;
    }
    return sum;

}

float average(data *n) {
    return (float) sum(n) / (float) counter(n);
}

int main() {

    data *Ptr = new data();
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



