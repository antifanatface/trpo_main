#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define AMOUNT_LIMIT 256

typedef struct {
    int16_t x;
    int16_t y;
    float r;
} createCircleStruct;

typedef struct {
    //uint8_t amount;
    bool alive[AMOUNT_LIMIT];
    int32_t addressList[AMOUNT_LIMIT];
} createGeomListStruct;

uint16_t charToDigitF(uint16_t charTmp) {
    if (charTmp >= 48 && charTmp <= 57) {
        return charTmp - 48;
    }
    return NULL;
}

int32_t geommgr(createGeomListStruct geomlist) {
    bool running = 1;
    while (running) {
        int16_t xValue = 0;
        int16_t yValue = 0;
        float rValue = 0.0;
        bool typing = 1;
        //createCircleStruct circle_prot;
        //int32_t *circleAddress_tmp = NULL;
        uint16_t freeCounter = 0;
        uint16_t id_tmp = 0;
        int32_t alive_list[AMOUNT_LIMIT];
        uint8_t alive_counter = 0;
        int32_t *circle_tmp1;
        int32_t *circle_tmp2;
        printf("What do you want?\n");
        printf("1. Create a circle.\n2. Delete a circle.\n3. Get the list of circles.\n4. Intersects list.\n0 Quit.\n");
        //printf("What do you want?\n/*1. Create a circle.\n2. Delete a circle.\n"
            //"3. Get the list of circles.\n4. Intersects list.\nq Quit.\n*\");
        //sleep(3);
        //getchar();
        //getchar();
        uint16_t choice;
        scanf("%d", &choice);
        //switch (getchar()) {
        //printf("%d\n", choice);
        //printf("%d\n", charToDigitF(choice));
        switch (choice) {
        case 1 :
            while (freeCounter < AMOUNT_LIMIT) {
                if (geomlist.alive[freeCounter] == 0) {
                    break;
                }
                freeCounter++;
            }
            if (freeCounter >= 256) {
                printf("Sorry but I have no free space!\n");
                break;
            }
            xValue = 0;
            yValue = 0;
            rValue = 0;
            while (typing) {
                printf("Enter the circle's x cord. (The module of value mustn't be more 30'000 and it must be integer)\n");
                scanf("%d", &xValue);
                if (abs(xValue) > 30000) {
                    printf("Wrong value.\n");
                    continue;
                } typing = 0;
            }
            typing = 1;
            while (typing) {
                printf("Enter the circle's y cord. (The module of value mustn't be more 30'000 and it must be integer)\n");
                scanf("%d", &yValue);
                if (abs(xValue) > 30000) {
                    printf("Wrong value.\n");
                    continue;
                } typing = 0;
            }
            typing = 1;
            while (typing) {
                printf("Enter the circle's radius. (The module of value must be more than 0 and 1.234 format (e.g. 10.0, 0.5, 3.48))\n");
                scanf("%f", &rValue);
                if (rValue <= 0) {
                    printf("Wrong value.\n");
                    continue;
                } typing = 0;
            }
            createCircleStruct circle;
            circle.x = xValue;
            circle.y = yValue;
            circle.r = rValue;
            geomlist.addressList[freeCounter] = &circle;
            geomlist.alive[freeCounter] = 1;
            printf("%d\n", &circle);
            //geomlist.amount++;
            break;
        case 2 :
            printf("Enter the id of circle that you want to delete:\n");
            typing = 1;
            while (typing) {
                scanf("%d", &id_tmp);
                printf("%d\n", id_tmp);
                if (id_tmp == 'q') {
                    break;
                }
                if (geomlist.alive[id_tmp] == 1) {
                    geomlist.alive[id_tmp] = 0;
                    //free(geomlist.addressList[id_tmp]);
                    typing = 0;
                } else {
                    printf("Invalid value!\n");
                    break;
                }
            }
            break;
        case 3 :/*
            circle_tmp1 = NULL;
            printf("List of available circes:\n");
            for (uint16_t counter_tmp = 0; counter_tmp < AMOUNT_LIMIT; counter_tmp++) {
                if (geomlist.alive[counter_tmp] == 1) {
                printf("garash %d\n", geomlist.alive[counter_tmp]);
                //circle_tmp1 = geomlist.addressList[counter_tmp];
                if (circle_tmp1 == NULL) {
                    printf("Pointer error!\n");
                    break;
                }
                circle_tmp1 = geomlist.addressList[counter_tmp];
                printf("before before: %d\n", circle_tmp1);
                createCircleStruct *circle_tmp1;
                printf("before: %d\n", circle_tmp1);
                circle_tmp1 = geomlist.addressList[counter_tmp];
                printf("after: %d\n", circle_tmp1);
                //printf("%d\n", circle_tmp1);
                //printf("%d\n", counter_tmp);
                printf("%d\n", circle_tmp1->x);
                printf("id: %hu, x cord: %hu, y cord: %hu, radius: %f\n",
                        counter_tmp, circle_tmp1.x,
                        circle_tmp1.y, circle_tmp1.r);
                } else {
                    //printf("Invalid value!\n");
                    //break;
                }
            }*/
            break;
        case 4 :
            /*alive_counter = 0;
            for (uint16_t counter_tmp = 0; counter_tmp < AMOUNT_LIMIT; counter_tmp++) {
                alive_list[counter_tmp] = 0;
            }

            for (uint16_t counter_tmp = 0; counter_tmp < AMOUNT_LIMIT; counter_tmp++) {
                if (geomlist.alive[counter_tmp] == 1) {
                    alive_list[counter_tmp] = geomlist.addressList[counter_tmp];
                    alive_counter++;
                }
            }*/
            circle_tmp1 = NULL;
            circle_tmp2 = NULL;
            for (uint16_t counter_tmp1 = 0; counter_tmp1 < AMOUNT_LIMIT; counter_tmp1++) {
                if (geomlist.alive[counter_tmp1] == 1) {
                    for (uint8_t counter_tmp2 = 0; counter_tmp2 < AMOUNT_LIMIT; counter_tmp2++) {
                        if (geomlist.alive[counter_tmp2] == 1 && counter_tmp1 != counter_tmp2) {
                            //int32_t *circle_tmp1 = geomlist.addressList[counter_tmp1];
                            //int32_t *circle_tmp2 = geomlist.addressList[counter_tmp2];
                            circle_tmp1 = geomlist.addressList[counter_tmp1];
                            circle_tmp2 = geomlist.addressList[counter_tmp2];
                            createCircleStruct *circle_tmp1;
                            createCircleStruct *circle_tmp2;
                            float destination = sqrt((circle_tmp2->x - circle_tmp1->x^2)
                                + ((circle_tmp2->y - circle_tmp1->y)^2));
                            if (circle_tmp1->r + circle_tmp2->r >= destination) {
                                printf("%d intersects %d\n", counter_tmp1, counter_tmp2);
                            }
                        }
                    }
                }
            }
            break;
        case 0 :
            printf("Quiting...\n");
            running = 0;
            break;
        default:
            printf("invalid value\n");
            break;
        }
    }
    return 0;
}

int main()
{
    createGeomListStruct geomlist;
    for (uint16_t counter_tmp = 0; counter_tmp < AMOUNT_LIMIT; counter_tmp++) {
        geomlist.alive[counter_tmp] = 0;
        //printf("4e");
    }
    geommgr(geomlist);
    return 0;
}
