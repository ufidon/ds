#include <iostream>

void moveDisk(int disk, char source, char destination) {
    std::cout << "Move disk " << disk << " from " << source << " to " << destination << std::endl;
}

void towerOfHanoi(int disks, char source, char auxiliary, char destination) {
    if (disks == 1) {
        moveDisk(disks, source, destination);
    } else {
        towerOfHanoi(disks - 1, source, destination, auxiliary);
        moveDisk(disks, source, destination);
        towerOfHanoi(disks - 1, auxiliary, source, destination);
    }
}

int main() {
    int numDisks = 3; // Change this value for a different number of disks
    char source = 'A', auxiliary = 'B', destination = 'C';

    std::cout << "Tower of Hanoi solution for " << numDisks << " disks:" << std::endl;
    towerOfHanoi(numDisks, source, auxiliary, destination);

    return 0;
}
