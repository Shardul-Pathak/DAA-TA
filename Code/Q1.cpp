/* Problem Statement: Given a row X cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area. */ 
#include<iostream>
#include<vector>
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

int maxArea(int n,int height[]) {
    int max=0;
    for(int i=0;i<n;i++) {
        int prevHistogram=prevIndex(i,height);
        int nextHistogram=nextIndex(n,i,height);
        if(height[i]*(nextHistogram-prevHistogram-1)>max) {
            max=height[i]*(nextHistogram-prevHistogram-1);
        }
    }
    return max;
}

int main() {
    int row,col;
    cin>>row>>col;
    int matrix[row][col];
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cin>>matrix[i][j];
        }
    }
    int prefix[row][col];
    for(int i=0;i<col;i++) {
        int sum=0;
        for(int j=0;j<row;j++) {
            if(matrix[j][i]==0) {
                prefix[j][i]=0;
                sum=0;
            }
            else {
                sum+=1;
                prefix[j][i]=sum;
            }
        }
    }
    int max=0;
    for(int i=0;i<row;i++) {
        int height[col];
        for(int j=0;j<col;j++) {
            height[j]=prefix[i][j];
        }
        int area=maxArea(col,height);
        if(area>max) {
            max=area;
        }
    }
    cout<<max<<endl;
}
