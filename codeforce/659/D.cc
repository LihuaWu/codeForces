/*
 * http://codeforces.com/contest/659/problem/D
 * D. Bicycle Race
 * time limit per test1 second
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 * */

#include <iostream>

using namespace std;

int main() {
   int n; 
    cin >> n;
    int startX, startY;
    int move = -1;// move towards:east:1 west:2 north:3 south:4
    cin >> startX >> startY;
    int turn = 0;
    for (int i = 0; i < n; i++) {
        int curX, curY;
        cin >> curX >> curY;
        if (curX == startX) {
            if (curY > startY) { //north
                if (move == 1) { ++turn; }
                move = 3;
            } else if (curY < startY) { //south
                if (move == 2) { ++turn; }
                move = 4;
            } else {} //never be here
        } else if (curY == startY) {
            if (curX > startX) { //east
                if (move == 4) { ++turn; }
                move = 1;
            } else if (curX < startX) { //west
                if (move == 3) { ++turn; }
                move = 2;
            }

        } else {} //never be here
        startX = curX; startY = curY;
    }
    std::cout << turn << "\n";
    return 0;
}
