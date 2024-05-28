// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
void printReverese(string&str,int i,string& ans){
  if (i<0){
    return;
  }
  ans.push_back(str[i]);

  printReverese(str,i-1,ans);


  
}
int main() {
    string str;
    cin>>str;
    // int size=str.size();
    string ans="";
    int iterator=str.size()-1;
    printReverese(str,iterator,ans);
    cout<<ans;

    return 0;
}