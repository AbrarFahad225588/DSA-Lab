#include<iostream>
using namespace std;

 int main() {
    int n,cap;
    cin>>n>>cap;
    float p[n],wt[n];
    for(int i=0;i<n;i++) cin>>wt[i]>>p[i];
    float rat[n];
    for (int i=0 ;i<n;i++)
    {
        rat[i]=(float)p[i]/wt[i];
    }
    // sort 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(rat[i]<rat[j])
            {
                swap(rat[i],rat[j]);
                swap(p[i],p[j]);
                swap(wt[i],wt[j]);
            }
        }
    }

    // maximum profit 
    float max_profit=0;
    int i;
    for(i=0;i<n;i++)
    {
        if(wt[i]>cap)
        {
            break;
        }else
        {
            max_profit+=p[i];
            cap-=wt[i];
        }
    }
   if(i<n)
   {
     max_profit+=rat[i]*cap;
   }
    cout<<max_profit<<endl;
    return 0;
}