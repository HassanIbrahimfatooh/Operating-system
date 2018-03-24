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
    int NPages;   /* TO Set The Number Of Pages */
    int Algorithm;  /* To Chooses memory management algorithm*/
    int NFrames;    /* To Set The Number Of Frames */

    // Taking The Numbers Of Pages and Frames
    cout << "Enter The Number of Pages :  ";
    cin >> NPages ;
    cout << "Enter The Number of Frames :  ";
    cin >> NFrames ;
    system("CLS");      /* Clearing the output screen */

    // Pages Array
    int *Pages;
    Pages = new int [NPages];

    // Pushing Random Numbers into the array from (1) to (10)
    cout << "Array : "<<endl;
    for (int i=0 ; i < NPages ;i++){
        Pages[i] = rand() % 10 + 1;
        cout << Pages[i]<<"   ";
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
    cin >> Algorithm;
    system("CLS");      /* Clearing the output screen */

    // Checking the input for executing the certain function
    if (Algorithm == 1){
        /* Headers/FIFO.h */
        FIFO(Pages , NPages, NFrames);
    }
    else if (Algorithm == 2){
        /* Headers/LRU.h */
        LRU(Pages , NPages, NFrames);
    }
    else if (Algorithm == 3){
        /* Headers/LFU.h */
        LFU(Pages , NPages, NFrames);
    }
    else if (Algorithm == 4){
        /* Headers/MFU.h */
        MFU(Pages , NPages, NFrames);
    }
    else if (Algorithm == 5){
        /* Headers/Optimum.h */
        Optimum(Pages , NPages, NFrames);
    }
    else if (Algorithm == 6){
        /* Headers/SecondChance.h */
        SecondChance(Pages, NPages, NFrames);
    }else{
        cout << "Please Choose a valid Number"<<endl;
    }

    return 0;
}
