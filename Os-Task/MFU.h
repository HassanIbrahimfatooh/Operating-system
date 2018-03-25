#ifndef MFU_H_INCLUDED
#define MFU_H_INCLUDED

using namespace std;

// LFU function
void MFU(int arr[], int nPages, int nFrames)
{


    int p;
    int counter=1 ; /* for check who come first */


    int totalMiss = 0;

    int *frames = new int [nFrames] ;    /* array for frames */

    int *frequency = new int [nPages];  /* array to check frequency for each page */

    /* array to be checked if page leave memory or not */
    int *check = new int [nPages];
    bool done;
    //initialize frames as empty
    for (int i=0; i<nFrames; i++)
        frames[i]= -1;
    // initialize all frequency with 0 for expected pages 1-10
    for (int i=0; i<10; i++)
        frequency[i]=0;
    // initialize check bit for each page
    for (int i=0; i<nPages; i++ )
        check[i]= -1;




    for (int readyPage=0; readyPage<nPages; readyPage++)
    {

        done = false; // to check if page finds a frame
        for (int i=0 ; i<nFrames; i++)
        {

            // check if page is already exist
            if (arr[readyPage]==frames[i])
            {
                cout <<"page is already here";
                // increase frequency of the page
                frequency[arr[readyPage]-1]++;
                done = true;
                break;
            }
            // you find empty frame
            else if (frames[i]== -1)
            {
                frames[i] = arr[readyPage];
                frequency[arr[readyPage]-1]++;
                done = true;
                break;
            }

        }


        // you have to swap with another page
        if (done==false)
        {
            int Most= frames[0]; /* Most as value */
            int MostFrequentlyUsed = 0;/* Most as frame index */
            // find frequency of current pages in the memory
            for (int k=0 ; k<nFrames; k++)
            {
                // you find the Most
                if(frequency[frames[k]-1]>Most)
                {
                    Most = frequency[frames[k]-1];
                    MostFrequentlyUsed = k ;
                    p = k;
                }
                // you find more than one page has the same frequency
                else if (frequency[frames[k]-1]==Most )
                {
                    // check if the page leave the memory before

                    for (int j = 0; j<readyPage; j++)
                    {

                        // find first in
                        if(arr[j] == frames[MostFrequentlyUsed] && check[j]!=0)
                        {
                            p = j; // save swapped page
                            break;
                        }
                        else if (arr[j]==frames[k] &&  check[j]!=0)
                        {
                            Most = frequency[frames[k]-1];
                            MostFrequentlyUsed = k ;
                            p = j; // save swapped page
                            break;
                        }

                    }

                }
            }


            // swap with the Most or first in
            frames[MostFrequentlyUsed] = arr[readyPage];
            done = true;
            frequency[arr[readyPage]-1]++;
            frequency[arr[p]-1] = 0; // frequency return to 0 of swapped page
            check[p] = 0;   //page leaved memory
            totalMiss++;
            cout << "total miss: "<<totalMiss<< "\n";
            for (int qq = 0 ; qq<nFrames; qq++)
                cout<< frames[qq]<<" ";
            cout<< "\n";
        }
    }




}

#endif // MFU_H_INCLUDED
