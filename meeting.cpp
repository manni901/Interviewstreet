#include<iostream>
using namespace std;

void bub(int*,int*,int);

int main()
{
    int M,K;
    cin>>M>>K;
    int i;
    int SH,SM,EH,EM;
    int *arr=new int[2*M];
    int *ar=new int[2*M];
    for(i=0;i<(2*M);i+=2)
    {
        cin>>SH>>SM>>EH>>EM;
        arr[i]=(60*SH)+SM;ar[i]=0;
        if(EH==0 && EM==0){arr[i+1]=1440;}
        else{arr[i+1]=(60*EH)+EM;}ar[i+1]=1;
    }

    bub(arr,ar,2*M);
    if((arr[0]-0)>=K)
    {
       cout<<"00 "<<"00 ";
       cout.width(2);cout.fill('0');
        cout<<right<<arr[0]/60;
        cout<<" ";
        cout.width(2);cout.fill('0');
        cout<<right<<arr[0]%60;
        cout<<"\n";
    }
    int count=1;

    for(i=1;i<((2*M)-1);i++)
    {
        if(ar[i]==0){count++;}else{count--;}
        if(count==0 && ar[i+1]==0 && (arr[i+1]-arr[i])>=K){
        cout.width(2);cout.fill('0');
        cout<<right<<arr[i]/60;
        cout<<" ";
        cout.width(2);cout.fill('0');
        cout<<right<<arr[i]%60;
        cout<<" ";
        cout.width(2);cout.fill('0');
        cout<<right<<arr[i+1]/60;
        cout<<" ";
        cout.width(2);cout.fill('0');
        cout<<right<<arr[i+1]%60;
        cout<<"\n";}
    }
    if((1440-arr[i])>=K){
       cout.width(2);cout.fill('0');
        cout<<right<<arr[i]/60;
        cout<<" ";
        cout.width(2);cout.fill('0');
        cout<<right<<arr[i]%60;
        cout<<" 00 "<<"00";
        cout<<"\n";
    }
}

void bub(int *arr,int *ar,int M)
{
    int temp;
    for(int i=0;i<(M-1);i++)
    {
        for(int j=0;j<(M-i-1);j++)
        {
            if(arr[j]>arr[j+1])
            {
             temp=arr[j];
             arr[j]=arr[j+1];
             arr[j+1]=temp;
             temp=ar[j];
             ar[j]=ar[j+1];
             ar[j+1]=temp;
            }
            else if(arr[j]==arr[j+1] && ar[j]==0 && ar[j+1]==1)
            {
                ar[j]=1;ar[j+1]=0;
            }
        }
    }
}
