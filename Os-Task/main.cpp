#include <iostream>      /* Input & Output  */
#include <time.h>        /* time */
#include <stdlib.h>      /* Standard Library */
#include "FIFO.h"        /* Headers/FIFO.h */
#include "LFU.h"         /* Headers/LFU.h */
#include "LRU.h"         /* Headers/LRU.h */
#include "MFU.h"         /* Headers/MFU.h */
#include "Optimum.h"     /* Headers/Optimum.h */
#include "SecondChance.h"    /* Headers/SecondChance.h */

using namespace std;


// Main function
int main()
{
    // Function to change time for Random function
    srand (time(NULL));

    // Variables
    int ArraySize;   /* Describes Memory size */
    int MemoryType;  /* Chooses memory management type*/

    // Taking memory size variable
    cout << "Choose Memory Size :  ";
    cin >> ArraySize ;
    system("CLS");      /* Clearing the output screen */

    // Array has the same size
    int arr[ArraySize];

    // Pushing Random Numbers into the array from (1) to (10)
    cout << "Array : "<<endl;
    for (int i=0 ; i<ArraySize ;i++){
        arr[i] = rand() % 10 + 1;
        cout << arr[i]<<"   ";
    }

    // For Choosing a Number
    cout <<endl<<endl;
    cout << "1- First In First Out(FIFO)"<<endl;
    cout << "2- Least Recently used(LRU)"<<endl;
    cout << "3- Least Frequently used(LFU)"<<endl;
    cout << "4- Most Frequently used(MFU)"<<endl;
    cout << "5- Optimum "<<endl;
    cout << "6- Second Chance"<<endl<<endl;
    cout << "Choose a Number :  ";

    // Taking an input
    cin >> MemoryType;
    system("CLS");      /* Clearing the output screen */

    // Checking the input for executing the certain function
    if (MemoryType == 1){
        FIFO(arr , ArraySize);
    }
    else if (MemoryType == 2){
        LRU(arr , ArraySize);
    }
    else if (MemoryType == 3){
        LFU(arr , ArraySize);
    }
    else if (MemoryType == 4){
        MFU(arr , ArraySize);
    }
    else if (MemoryType == 5){
        Optimum(arr , ArraySize);
    }
    else if (MemoryType == 6){
        SecondChance(arr , ArraySize);
    }

    return 0;
}
