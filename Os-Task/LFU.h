#ifndef LFU_H_INCLUDED
#define LFU_H_INCLUDED

using namespace std;

// LFU function
void LFU(int arr[], int nPages, int nFrames)
{


    int p;
    bool done;
    int totalMiss = 0;
    int *frames = new int [nFrames] ;   /* array for frames */
    int *frequency =new int [nFrames];                 /* array to check frequency for each page */
    int *check = new int [nPages];      /* array to be checked if page leave memory or not */
    int totalHlt = 0;


    //initialize frames as empty
    for (int i=0; i<nFrames; i++)
    {
        frames[i]= -1;
    }
    // initialize all frequency with 0 for expected pages 1-10
    for (int i=0; i<nFrames; i++)
    {
        frequency[i]=0;
    }
    // initialize check bit for each page
    for (int i=0; i<nPages; i++ )
    {
        check[i]= -1;
    }


    for (int readyPage=0; readyPage<nPages; readyPage++)
    {

        done = false; // to check if page finds a frame
        for (int i=0 ; i<nFrames; i++)
        {

            // check if page is already exist
            if (arr[readyPage]==frames[i])
            {
                totalHlt ++;
                // increase frequency of the page
                frequency[i]++;
                done = true;
                break;
            }
            // you find empty frame
            else if (frames[i]== -1)
            {
                totalMiss++;
                frames[i] = arr[readyPage];
                frequency[i]++;
                done = true;
                break;
            }

        }


        // you have to swap with another page
        if (done==false)
        {
            int least= frequency[0]; /* least as value */
            int leastFrequentlyUsed = 0;/* least as frame index */

            // find frequency of current pages in the memory
            for (int k=0 ; k<nFrames; k++)
            {
                // you find the least
                if(frequency[k]<least)
                {
                    least = frequency[k];
                    leastFrequentlyUsed = k ;
                    p = k;
                }
                // you find more than one page has the same frequency
                else if (frequency[k]==least )
                {
                    // check if the page leave the memory before
                    for (int j = 0; j<readyPage; j++)
                    {
                        // find first in
                        if(arr[j] == frames[leastFrequentlyUsed] && check[j]!=0)
                        {
                            p = j; // save swapped page
                            break;
                        }
                        else if (arr[j]==frames[k] &&  check[j]!=0)
                        {
                            least = frequency[k];
                            leastFrequentlyUsed = k ;
                            p = j; // save swapped page
                            break;
                        }

                    }

                }
            }


            // swap with the least or first in
            frames[leastFrequentlyUsed] = arr[readyPage];
            done = true;
            frequency[leastFrequentlyUsed] = 1;
            check[p] = 0;   //page leaved memory
            totalMiss++;

        }
        for (int qq = 0 ; qq<nFrames; qq++)
                cout<< frames[qq]<<" ";
            cout<< "\n";

 // end of if statment
    }// end of for loop
    cout << "total miss: "<<totalMiss<< "\n";
    cout << "total HLT: "<<totalHlt<< "\n";

} // end of function







#endif // LFU_H_INCLUDED

