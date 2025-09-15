/* Problem Statement: Given an array of integers heights representing the histogram's bar height where the width of each bar is 1 return the area of the largest rectangle in histogram. */
#include<iostream>
using namespace std;

int prevIndex(int curr,int height[]) {
    for(int i=curr;i>=0;i--) {
        if(height[i]<height[curr]) {
            return i;
        }
    }
    return 0;
}

int nextIndex(int n,int curr,int height[]) {
    for(int i=curr;i<n;i++) {
        if(height[i]<height[curr]) {
            return i;
        }
    }
    return n;
}

int main() {
    int n;
    cin>>n;
    int height[n];
    int max=0;
    for(int i=0;i<n;i++) {
        cin>>height[i];
    }
    for(int i=0;i<n;i++) {
        int prevHistogram=prevIndex(i,height);
        int nextHistogram=nextIndex(n,i,height);
        if(height[i]*(nextHistogram-prevHistogram-1)>max) {
            max=height[i]*(nextHistogram-prevHistogram-1);
        }
    }
    cout<<max<<endl;
}