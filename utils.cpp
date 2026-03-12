#include "utils.h"
using namespace std;
int getIntInput(const std::string& prompt){
   int n;
   while(true){
       cout<<prompt<<'\n';
       cin>>n; 
       if (cin.fail()){
        cin.clear();
cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
cout<<"input failed try again\n";
    }
    else{
        break;
    }
   }
   return n;
}
double getDoubleInput(const std::string& prompt){
      double n;
   while(true){
       cout<<prompt<<'\n';
       cin>>n; 
       if (cin.fail()){
        cin.clear();
cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
cout<<"input failed try again\n";
    }
    else{
        break;
    }
   }
   return n;
}
std::string getStringInput(const std::string& prompt){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
     string n;
   while(true){
       cout<<prompt<<'\n';
       getline(cin,n);
       if (n.empty()){
cout<<"input cannot be empty\n";
    }
    else{
        break;
    }
   }
   return n;
}
template <typename T>
T findMax(const std::vector<T>& items){
    T mx=items[0];
    for(int i=1;i<items.size();i++){
        if(mx<items[i]){
            mx=items[i];
        }
    }
    return mx;
}