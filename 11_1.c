#include <stdio.h>
#include <stdlib.h>
#define ON 1
#define OFF 0

void initializeRobots(int* robotPointer, int size) {
    int* end = robotPointer + size;
    while(robotPointer < end) {
        *robotPointer = ON;
        robotPointer++;
    }
}

void turnOffRobot(int* robot) {
    *robot = 0;
}

int skipRobots(int* robots, int size, int index, int k) {
    int skippedOnRobotCount = 0;
    while(skippedOnRobotCount < k) {
        index = (index + 1) % size;
        if (*(robots + index) == ON) {
            skippedOnRobotCount++;
        }
    }
    return index;
}

int main() {
    int *robots;
    int size, k;
    scanf("%d %d", &size, &k);
    robots = (int *) malloc(size * sizeof(int));

    initializeRobots(robots, size);

    int offRobotCount = 0;
    int index = 0;
    while (offRobotCount < (size - 1)) {
        printf("%d ", index + 1);
        turnOffRobot(robots + index);
        offRobotCount++;

        index = skipRobots(robots, size, index, k);
    }

    free(robots);
}
