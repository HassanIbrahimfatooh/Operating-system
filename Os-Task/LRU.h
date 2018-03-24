#ifndef LRU_H_INCLUDED
#define LRU_H_INCLUDED

using namespace std;

// minimum Freq.
int min(int counter[],int nFrames)
{
    int minimum = counter[0];
    int pos = 0;
    for(int i=1;i<nFrames;i++) { if(minimum > counter[i])
           {   minimum = counter[i];
               pos = i;
           }
    }
 return pos;


// LRU function
void LRU(int Pages[], int NPages, int  NFrames){
    // Complete this function
    int Frames[NFrames]; /* The Array Of Frames That We have */

    int counter[ArraySize],recent = 0;

    int pageFault = 0;

    int PageHLT =0;
    for(int i=0;i<NFrames;i++)
    {
        Frames[i] = 0;
        counter[i] = 0;//here 0 referes an empty space in frame
    }
    for(int i=0;i<ArraySize;i++)

    {  int flag =0, HLTflag=0;
        for(int j=0;j<NFrames;j++)
        {
         if(Frames[j] == arr[i])
           {flag=1;
            counter[j] = recent++; //counter holds which frame is recently used,
                                 //recently used page in frame will have a bigger number
                                  //and least recently used page in frame will have a lower number
            HLTflag =1 ;
            break;
           }
        }

        if(flag == 0)
        {
            for(int j=0;j<NFrames;j++)
            {if(Frames[j] == 0)
                {   Frames[j] = arr[i];
                    counter[j] = recent++;
                    flag=1;
                    pageFault++;
                    break;
                }

            }
        }

        if(flag == 0){
            int PositionToreplace = min(counter,NFrames);
            Frames[PositionToreplace] = arr[i];
            counter[PositionToreplace] = recent++;
            pageFault++;
        }

        //print frames
      cout<<endl;
      for(int j=0;j<NFrames;j++)
      {
          if(HLTflag == 1){
            PageHLT++;
            break;
          }
          cout<<Frames[j]<<" ";
      }

    }
    cout<<"\nNumber Of Page HLT: "<<PageHLT;
    cout<<"\nTotal Miss: "<<pageFault;
}

#endif // LRU_H_INCLUDED
