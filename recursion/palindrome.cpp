#include <iostream>
using namespace std;
bool checkPalindrome(string& str, int p1, int p2){
// base case
if(p1>=p2){
  return true;
}
// ek case 
if(str[p1]!=str[p2]){
  return false;
}
//RE
return checkPalindrome(str,p1+1, p2-1);


}

int main() {
  string s="shilplihs";
  int p1=0;
  int p2=s.size()-1;
 bool ans = checkPalindrome(s,p1, p2);
 cout<<ans<<endl;

  return 0;
}