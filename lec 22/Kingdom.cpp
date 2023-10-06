// In this mystical kingdom, there were three enchanted pegs: the Source Peg, the Destination Peg, and the Helper Peg. Each peg had unique magical properties essential for saving the kingdom from an evil sorceress's destructive curse.



// To counter this spell and protect the kingdom, they had to transfer magical disks of varying sizes, represented by positive integers, from the Source Peg to the Destination Peg using the Helper Peg. Notably, each disk was smaller than the one beneath it.



// According to the ancient legends, the Sorceress' curse could be broken only if the disks were transferred from the Source Peg to the Destination Peg following these rules:

// Only one disk could be moved at a time.
// A larger disk could never be placed on top of a smaller disk.
// The Helper Peg could be used temporarily for disk movements.


// The kingdom's wise sage had devised a solution using the Tower of Hanoi algorithm, a mysterious ritual that required the minimum number of moves to transfer all the magical disks from the Source Peg to the Destination Peg.



// Write a program to calculate the minimum number of moves required to solve the Tower of Hanoi problem for n magical disks, thus breaking the Sorceress' curse and saving the kingdom from impending doom.



// Note: This kind of question will be helpful in clearing Capgemini recruitment.

// Input format :
// The input consists of an integer denoting the number of disks n.

// Output format :
// The output displays the minimum number of moves required to solve the Tower of Hanoi problem for n disks.

// Code constraints :
// 0 < n <= 8
// You are using GCC
#include <stdio.h>

int towerOfHanoiMoves(int n) {
    
    //Type your code here
    if(n==1){
        return 1;
    }
    else{
        int moves = towerOfHanoiMoves(n-1);
        return 2*moves+1;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int moves = towerOfHanoiMoves(n);
    printf("%d", moves);

    return 0;
}