#ifndef OPTIMUM_H_INCLUDED
#define OPTIMUM_H_INCLUDED

using namespace std;

// Optimum function
void Optimum(int Pages[], int NPages, int  NFrames){
   
    // Frames Array
    int *Frames;
    Frames = new int [NFrames];
    for(int i=0; i< NFrames; i++)
        Frames[i] = -1;
    
    for(int i=0; i< NPages; i++)
    {
        bool isFrameEmpty = false;
        bool isPageAlreadyPresent = false;
        for(int j=0; j< NFrames; j++)
        {
            // Check if the Page is aleardy presented
            if(Frames[j] == Pages[i])
            {
                isPageAlreadyPresent = true;
                break;
            }
            // Check if there is Empty Frame
            else if(Frames[j] == -1)
            {
                Frames[j] = Pages[i];
                isFrameEmpty = true;
                break;
            }
        } //Loop on Frames
        
        if((!isFrameEmpty) && (!isPageAlreadyPresent))
        {
            int MaxCount = 0;
            int Index = -1;
            for(int j=0; j< NFrames; j++)
            {
                bool found = false;
                for(int k=i+1; k<NPages; k++)
                    if(Frames[j] == Pages[k])
                    {
                        found = true;
                        if((k - i) > MaxCount)
                        {
                            MaxCount = k - i;
                            Index = j;
                        }
                        break;
                    }
                if(!found)
                {
                    MaxCount = NPages;
                    Index = j;
                }
            }
            Frames[Index] = Pages[i];
        }
        
        for(int j=0;j<NFrames;j++)
        {
            cout<<Frames[j]<<" ";
        }
         
    cout<<endl;  
        
    }
}

#endif // OPTIMUM_H_INCLUDED
