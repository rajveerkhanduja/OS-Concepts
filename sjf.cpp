#include<bits/stdc++.h>
using namespace std;

struct Process{
    int id;
    int bt;
    int wt;
    int tat;
};

int main(){
    int n;
    cout<<"Enter the no. of processes: ";
    cin>>n;

    vector<Process>p(n);
    cout<<"Enter Burst Time:\n";
    for(int i=0;i<n;i++){
        p[i].id=i+1;
        cout<<"p"<<p[i].id<<":";
        cin>>p[i].bt;
    }

    sort(p.begin(),p.end(),[](const Process&a, const Process&b){
        return a.bt<b.bt;
    });

    int totalwt=0, totaltat=0;
    p[0].wt=0;

    for(int i=1;i<n;i++){
        p[i].wt=p[i-1].wt+p[i-1].bt;
        totalwt+=p[i].wt;
    }

    for(int i=0;i<n;i++){
        p[i].tat=p[i].wt+p[i].bt;
        totaltat+=p[i].tat;
    }

    float avgwt=static_cast<float>(totalwt)/n;
    float avgtat=static_cast<float>(totaltat)/n;

    cout<<"\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(int i=0;i<n;i++){
        cout<<"p"<<p[i].id<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].tat<<"\n";
    }
    cout<<fixed<<setprecision(2);
    cout<<"\nAverage Waiting Time: "<<avgwt;
    cout<<"\nAverage Turnaround Time: "<<avgtat;
    return 0;
}