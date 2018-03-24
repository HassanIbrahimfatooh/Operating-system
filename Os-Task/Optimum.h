#ifndef OPTIMUM_H_INCLUDED
#define OPTIMUM_H_INCLUDED

using namespace std;

// Optimum function
void Optimum(int Pages[], int NPages, int  NFrames){
   
    // Frames Array
    int *Frames;
    Frames = new int [NFrames];
    for(int i=0; i< NFrames; i++)
        Frames[i] = -1; // Empty Frame
    
    int TotalMiss = 0; // Total Miss Counter
    
    // Loop on Pages
    for(int i=0; i<NPages; i++)
    {
        bool isThereEmptyFrame = false;
        bool isPageAlreadyPresented = false;
        
        // Loop on Frames
        for(int j=0; j<NFrames; j++)
        {
            
            // Check if the Page is aleardy presented
            if(Frames[j] == Pages[i])
            {
                isPageAlreadyPresented = true;
                break;
            }
            
            // Check if there is Empty Frame
            else if(Frames[j] == -1)
            {
                TotalMiss++;
                Frames[j] = Pages[i];
                isThereEmptyFrame = true;
                break;
            }
        } // End of Loop on Frames
        
        // Need to Replace
        if((!isThereEmptyFrame) && (!isPageAlreadyPresented))
        {
            TotalMiss++;
            int MaxDistance = 0;
            int Index = -1;
            
            // Loop on Frames
            for(int j=0; j< NFrames; j++)
            {
                bool isPageUsedInFuture = false;
                
                // Loop on Future use Pages
                for(int k=i+1; k<NPages; k++)
                {
                    // is Page Used In Future
                    if(Frames[j] == Pages[k])
                    {
                        isPageUsedInFuture = true;
                        
                        if((k - i) > MaxDistance)
                        {
                            MaxDistance = k - i;
                            Index = j;
                        }
                        break;
                    }
                } // End Loop on Future use Pages
                
                if(!isPageUsedInFuture)
                {
                    MaxDistance = NPages; // The Biggest Value forever
                    Index = j;
                    break;
                }
            } // End of Loop on Frames
            
            // Replace The Frame's Page 
            Frames[Index] = Pages[i];
        }
        
        // Show Frames 
        for(int j=0;j<NFrames;j++)
        {
            cout<<Frames[j]<<" ";
        }
        cout<<endl;  
        
    } // End of Loop on Pages
    
    // Show Tota Miss
    cout<<"Total Miss = "<<TotalMiss<<endl;
}

#endif // OPTIMUM_H_INCLUDED
