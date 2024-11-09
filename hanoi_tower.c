/*A fundamental exercise that taught me how to implement RECURSIONS */

#include <stdio.h>

int number_of_disks = 2;
char start = 'A';
char end = 'C';
char temp = 'B';
int counter = 0;
void tower_of_hanoi(int number_of_disks, char start, char end, char temp){

    counter++;

    printf("This is depth %d\n", counter);
    printf("Number of disks: %d\n", number_of_disks);
    if(number_of_disks == 1) {
        printf("Start is %c : End is %c : Temp is %c\n", start, end, temp);
        printf("One disk left. Move disk %d from %c to %c \n", number_of_disks, start, end);
        printf("Going up...\n");
        counter--;
        return;
    }

    //printf("Number of disks: %d\n", number_of_disks);
    printf("Start is %c : End is %c : Temp is %c\n", start, end, temp);
    printf("Going down...\n");

    tower_of_hanoi(number_of_disks - 1, start, temp, end); 
    printf("This is depth %d\n", counter);
    printf("Start is %c : End is %c : Temp is %c\n", start, end, temp);
    printf("Move disk %d from %c to %c \n", number_of_disks, start, end);
    printf("Going down...\n");

    tower_of_hanoi(number_of_disks - 1, temp, end, start);
    printf("This recursion is done!\n");
    printf("Going up....\n");
    counter--;
}
int main() {
    tower_of_hanoi(number_of_disks, start, end, temp);

    return 0;
}
