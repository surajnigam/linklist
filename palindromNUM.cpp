#include<bits/stdc++.h>
using namespace std;
int main()
{
  int x;
  cin>>x;
 vector<int> arr;
 int r,count=0;
 while(x!=0)
 {
    r=x%10;
    arr.push_back(r);
    x=x/10;
    count++;
 }
 for(int i=0; i<arr.size(); i++)
 {
    cout<<arr[i]<<" ";
 }
  return 0;
}