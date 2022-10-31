#include<bits/stdc++.h>

using namespace std;
int main(){

/* 
    //array-----
    int basic[3]= {1,2,3};
    array<int,4> a= {1,2,3,4};
    int size= a.size();
    for(int i=0; i<size; i++){
        cout<<a[i]<<endl;
    }
*/
/*
   // vector-----
    vector<int>v;
    cout<<"size: " <<v.size()<<endl;
    v.push_back(1);
    cout<<"size: " <<v.capacity()<<endl;
    v.push_back(10);
    cout<<"size: " <<v.capacity()<<endl;
    cout<<"front"<< v.front()<<endl;
    v.clear();
    cout<<"new size" <<v.size()<<endl;
*/


/*
    //deque------
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_front(3);
    cout<<"front"<<d.front()<<endl;
    cout<<"back"<<d.back()<<endl;

    cout<<"before erase"<<d.size()<<endl;
    d.erase(d.begin(), d.begin()+1);
    cout<<"after erase"<<d.size()<<endl;
    for(int i:d){
        cout<<i<<endl;
    }
*/
     priority_queue<int> maxi;  //max-heap h ye
     priority_queue<int, vector<int>, greater<int>>mini;  //ye wali h min-heap
     maxi.push(10);
     maxi.push(60);
     maxi.push(80);
     maxi.push(20);
     cout<<"size: "<<maxi.size()<<endl;
    for(int i=0; i<maxi.size(); i++){
        cout<<maxi.top()<<" ";
        maxi.top();
    }
     mini.push(10);
     mini.push(60);
     mini.push(80);
     mini.push(20);
     cout<<"size: "<<mini.size()<<endl;
    for(int i=0; i<mini.size(); i++){
        cout<<mini.top()<<" ";
        mini.top();
    }
}
