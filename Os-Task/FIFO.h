#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED

using namespace std;

int getReplaceposition(int counter[],int n)
{
    int max = counter[0];
    int pos=0;
    for(int i=0; i<n; i++)
    {
        if(counter[i]>max)
        {
            pos=i;
            max = counter[i];
        }
    }

    return pos;
}

// FIFO function
void FIFO(int pages[], int nPages, int  nFrames)
{
    // Complete this function

    int flag, hlt,Totalhlt=0;
    int pageFault=0;
//    int *pages = new int[nPages];
    int *frames = new int[nFrames];
    int *counter = new int[nFrames];

    for(int i=0; i<nFrames; i++)
    {
        frames[i] = 0;
        counter[i] = 0; //here 0 referes an empty space in frame
    }

    for(int i=0; i<nPages; i++)
    {
        flag =0;
        hlt = 0 ;
        for(int j=0; j<nFrames; j++)
        {
            if(frames[j] == pages[i])
            {
                flag=1;  //if page is present in frame (flag=1)
                hlt = 1;
                Totalhlt++;
                break;
            }
        }

        //if page is not present in frame (flag=0)
        if(flag == 0)
        {
            pageFault++;
            for(int j=0; j<nFrames; j++)
            {
                if(frames[j] == 0)
                {
                    frames[j] = pages[i];
                    flag=1;
                    hlt = 0 ;
                    counter[j]++;
                    break;
                }

            }
        }


        //if there is no empty frame
        if(flag == 0)
        {
            int pos = getReplaceposition(counter,nFrames);
            frames[pos] = pages[i];
            counter[pos] = 1;
            for(int k=0; k<nFrames; k++)
            {
                if(k!=pos)
                    counter[k]++;
            }
        }

        cout<<endl;
        for(int j=0; j<nFrames; j++)
        {
            if (hlt == 1)
            {
                cout << "  ";
            }
            else
            {
                cout<<frames[j]<<" ";
            }
        }
    }

    cout<<"\nTotal Hlt: "<< Totalhlt;
    cout<<"\nTotal Miss: "<<pageFault;


}

#endif // FIFO_H_INCLUDED
