#ifndef SecondChance_H_INCLUDED
#define SecondChance_H_INCLUDED

using namespace std;

// SecondChance function
void SecondChance(int Pages[],int  NPages,int NFrames)
{

    int *frames = new int [NFrames] ;    /* array for frames */
    bool *secondChanceBit = new bool[NFrames] ;  /*SECOND CHANCE Bit */
    bool valid[10];
    int frame = 0; /* index of the next frame to add pages in */
    bool done; /* check if page find frame */
    int totalMiss = 0;

    //initialize frames as empty
    for (int i=0; i<NFrames; i++)
    {
        frames[i]= -1;
        secondChanceBit[i] = false;
    }
    // initialize all valid with 0 for expected pages 1-10
    for (int i=0; i<10; i++)
        valid[i] = false;
    for (int readyPage=0; readyPage<NPages; readyPage++)
    {
        do
        {
            if (frames[frame]==-1 && valid[Pages[readyPage]-1]== false)
            {
                cout<<"first condition";

                frames[frame]=Pages[readyPage];
                valid[Pages[readyPage]-1] = true;
                secondChanceBit[frame] = false;
                cout<<"you are at frame "<< frame;
                frame = (frame+1)%NFrames;
            }
            else if (valid[Pages[readyPage]-1] == true)
            {
                cout<<"second condition";

                cout<<"you are at frame "<< frame;
                for (int i =0; i<NFrames; i++)
                {
                    if (Pages[readyPage]==frames[i])
                        secondChanceBit[i]=true;
                }
            }
              else if (secondChanceBit[frame]== true)
            {
                cout<<"third condition" <<"\n";
                cout<<"you are at frame "<< frame;
                secondChanceBit[frame] = false;
                frame = (frame+1)%NFrames;

            }
            else if (secondChanceBit[frame]== false)
            {
                cout<<"fourth condition";
                cout<<"you are at frame "<< frame;
                valid[frames[frame]-1] = false;
                frames[frame]=Pages[readyPage];
                secondChanceBit[frame] = false;
                frame = (frame+1)%NFrames;
                valid[Pages[readyPage]-1] = true;
                totalMiss++;
            }

        }
        while (valid[Pages[readyPage]-1] == false);


        cout << "total miss: "<<totalMiss<< "\n";
        for (int qq = 0 ; qq<NFrames; qq++)
            cout<< frames[qq]<<" ";
        cout<< "\n";
    }
}

#endif // SECONDC#ifndef SECONDCHANCE_H_INCLUDED
#define SecondChance_H_INCLUDED
