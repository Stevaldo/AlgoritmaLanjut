#include <iostream>
using namespace std;

int dat[10] = {23, 31, 44, 56, 77, 3, 91, 90, 12, 81};

int minimum(int a, int b, int min1, int min2)
{
  int temp1, temp2;
 
  if(a+5==b)
  {
    if (dat[a]<min1)
      temp1 = dat[a];
    else 
      temp1 = min1;      
    if (dat[a+5]<min2)
      temp2 = dat[a+5];
    else 
      temp2 = min2;      
    if(temp1<temp2)
      return temp1;
    else
      return temp2;
  }
  if(a+5<b)
  {
    if (dat[a]<min1)
      temp1 = dat[a];
    else 
      temp1 = min1;      
    if (dat[a+5]<min2)
      temp2 = dat[a+5];
    else 
      temp2 = min2;           
    return minimum(a+1,b,temp1,temp2);
  } 
  return 0;    
}  

int main()
{
  cout<<"data: ";
  for(int i=0;i<10;i++)
    cout<<dat[i]<<" ";
    cout<<endl;
    cout<<"nilai terkecil adalah "<<minimum(0,9,999,999)<<endl;
    return 0;
}