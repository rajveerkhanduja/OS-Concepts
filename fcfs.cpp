#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    vector<int> at(n), bt(n), ct(n), tat(n), wt(n);
    float totaltat=0, totalwt=0;
    cout<<"Enter the arrival time and burst time for each process: \n";
    for(int i=0;i<n;i++){
        cout<<"Enter AT of Process ["<<i+1<<"]: ";
        cin>>at[i];
        cout<<"Enter BT of Process ["<<i+1<<"]: ";
        cin>>bt[i];
    }
    int currTime = at[0];
    for(int i=0;i<n;i++){
        currTime = max(currTime, at[i]) + bt[i];
        ct[i] = currTime;
    }

    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        totaltat+=tat[i];
        totalwt+=wt[i];
    }
    cout<<"Process\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++){
        cout<<"P"<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\n";
    }
    cout<<fixed<<setprecision(2);
    cout<<"\nAverage Turn Around Time: "<<totaltat/n<<"\n";
    cout<<"\nAverage Waiting Time: "<<totalwt/n<<"\n";
    return 0;
}