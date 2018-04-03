#include<stdio.h>
#include<stdlib.h>

struct transitionTable{

}

struct nfa{
    int initialState;
    int states[];
    int finalStates[];
    char inputSymbols[];
    struct transitionTable nfaTransitionTable;
}

int main(void){



    return 0;
}