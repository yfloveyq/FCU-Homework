#include <stdio.h>
#include <string.h>

struct inventory {
    char temp[30];
    char toolname[30];
    char quantity[30];
    char cost[30];
};

void clean();

int main() {

    inventory a = {"","", "", ""};

    FILE *cfPtr;

    cfPtr = fopen("hardware.txt", "w+");

    if (cfPtr == NULL) {
        printf("File cannot be opened.");
    } else {
        fprintf(cfPtr, "3\tElectricsander\t7\t\t57.98\n");
        fprintf(cfPtr, "17\tHammer\t\t76\t\t11.99\n");
        fprintf(cfPtr, "24\tJigsaw\t\t21\t\t11.00\n");
        fprintf(cfPtr, "39\tLawnmower\t3\t\t79.50\n");
        fprintf(cfPtr, "56\tPowersaw\t21\t\t99.99\n");
        fprintf(cfPtr, "68\tScrewdriver\t106\t\t6.99\n");
        fprintf(cfPtr, "77\tSledgehammer\t11\t\t21.50\n");
        fprintf(cfPtr, "83\tWrench\t\t34\t\t7.50\n");

        fclose(cfPtr);
        clean();
    }
    return 0;
}

void clean() {
    FILE *cfPtr;
    cfPtr = fopen("hardware.txt", "r");
    inventory p[8];
    for (int i = 0; i < 8; ++i) {
        fscanf(cfPtr, "%s%s%s%s", p[i].temp, p[i].toolname, p[i].quantity, p[i].cost);
    }
    fclose(cfPtr);

    for (int j = 0; j < 5; ++j) {
        printf("Enter person you want to search for delete : ");
        char s1[5];
        scanf("%s", s1);
        int i;
        for (i = 0; i < 8; ++i) {
            if ((strcmp(p[i].temp, s1)) == 0) {
                printf("Find info\n%s\t%s\t%s\n", p[i].toolname, p[i].quantity, p[i].cost);
                strcpy(p[i].toolname, " ");
                strcpy(p[i].quantity, " ");
                strcpy(p[i].cost, " ");
                printf("Data clean complete.\n");
                break;
            }
        }
        if (i == 8) {
            printf("No info.\n");
        }
    }

    cfPtr = fopen("hardware.txt", "w+");

    for (int k = 0; k < 8; ++k) {
        fprintf(cfPtr, "%s\t%s\t%s\t%s\n", p[k].temp, p[k].toolname, p[k].quantity, p[k].cost);
    }
    fclose(cfPtr);

}
