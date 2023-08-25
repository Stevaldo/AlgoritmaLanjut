#include <iostream>
#include <cmath>
using namespace std;

int panjang;
int dat[40] = {61, 42, 53, 74, 55, 86, 27, 38, 89, 10,
               44, 60, 77, 82, 45, 12, 51, 71, 66, 90,
               14, 16, 73, 18, 15, 32, 31, 87, 62, 99,
               40, 20, 33, 92, 91, 21, 13, 11, 17, 22};

void mergeSort(int awal,int akhir)
{
  
  if (awal < akhir)
  {
    int tengah = awal + (akhir - awal)/2;
    mergeSort(awal,tengah);
    mergeSort(tengah+1,akhir);
    int temp;
    int i=awal;
    int j=tengah+1;
    int x[panjang];
    int k=0;
    while((i<=tengah) && (j<=akhir))
    {
      if(dat[i]<dat[j]) 
      {
        x[k] = dat[i];
        temp=dat[j];
        i++;
      } else
      {
        x[k] = dat[j];
        temp=dat[i];
        j++;
      }
      k++;
    }
    /**/
    if(i<=tengah)
    {
        for(int l=i;l<=tengah;l++)
        {
            x[k]=dat[l];
            k++;
        }
    }/**/
    if(j<=akhir)
    {
        for(int l=j;l<=akhir;l++)
        {
            x[k]=dat[l];
            k++;
        }
    }/**/
    for(int l=0;l<k;l++)
    {
        dat[awal+l]=x[l];
    }
  }
  
}

int main()
{
  panjang = round(sizeof(dat)/4);
  mergeSort(0,panjang-1);
  for(int i=0;i<panjang;i++)
    cout<<dat[i]<<endl;
  return 0;
}
