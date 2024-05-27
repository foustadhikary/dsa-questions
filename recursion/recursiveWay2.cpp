#include <iostream>
using namespace std;


void findLastOcc(string& s, int i,int& ans, char ch){

    if (i<0){
        return ;
    }
    if(s[i]==ch){
        ans =i;
        return;
    }
    //recursive call 
    findLastOcc(s, i-1,ans,ch);


}
int main(){

    string s;
    cin>>s;
    char ch;
    cin>>ch;

    int ans=-1;
    findLastOcc(s,s.size()-1,ans,ch);
    cout<< ans<<endl;




    return 0;
}