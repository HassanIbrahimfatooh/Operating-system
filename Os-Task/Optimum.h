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
        bool isFrameEmpty = False;
        bool isPageAlreadyPresent = False;
        for(int j=0; j< NFrames; j++)
        {
            // Check if the Page is aleardy presented
            if(Frames[j] == Pages[i])
            {
                isPageAlreadyPresent = True;
                break;
            }
            // Check if there is Empty Frame
            else if(Frames[j] == -1)
            {
                Frames[j] = Pages[i];
                isFrameEmpty = True;
                break;
            }
        } //Loop on Frames
        if(!isFrameEmpty && !isPageAlreadyPresent)
        {
            int minCount = -1;
            int minIndex = -1;
            for(int j=0; j< NFrames; j++)
            {
                int counter = 0;
                for(int k=i+1; k<NPages; k++)
                    if(Frames[j] == Pages[k])
                        counter++;
                if(counter < minCount)
                {
                    minCount = counter;
                    minIndex = j;
                }
            }
            Frames[minIndex] = Page[i];
        }
        
        for(j=0;j<nFrames;j++)
        {
            cout<<frames[j]<<" ";
        }
         
    cout<<endl;  
        
    }
}

#endif // OPTIMUM_H_INCLUDED
