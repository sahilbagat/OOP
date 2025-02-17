#include <iostream>
#include<string.h>
using namespace std;

class Bank{
    private:
         string accountHolder;
         int accountNumber;
         string accountType;
         double balance;
         
   public:
        Bank(){
            accountHolder=":sahil bagat";
            accountNumber= 123446789;
            accountType=":saving";
            balance= 1000;
        }
        Bank(string a,int n,string t,double b){
            accountHolder=a;
            accountNumber=n;
            accountType=t;
              balance=b;
        }
        
        void getaccountHolder(){
            cout<<"account Holder :"<<accountHolder<<endl;
        }
        void getaccountNumber(){
            cout<<"account number :"<<accountNumber<<endl;
        
        }
        void getaccountType(){
            cout<<"account Type :"<<accountType<<endl;
        }
        void getbalance(){
            cout<<"balance :"<<balance<<endl;
        }
        void setAccountType(string x){
            accountType=x;
        }
        void setDeposit(){
            int depositamount;
            cout<<"enter amount to deposit:"<<endl;
            cin>>depositamount;
            balance=balance+depositamount;
            cout<<"deposited :"<<depositamount<<endl;
            cout<<"New balance"<<balance<<endl;
        }
        void setWithdrawl(){
            int withdrawlamount;
            cout<<"enter amount to withdrawl:"<<endl;
            cin>>withdrawlamount;
            balance=balance-withdrawlamount;
            cout<<"withdrawl :"<<withdrawlamount<<endl;
            cout<<"New balance"<<balance<<endl;
        }
        void getDisplayaccountdetails(){
            cout<<"account details : "<<endl;
            getaccountHolder();
            getaccountNumber();
            getaccountType();
            getbalance();
     }
        ~Bank(){
        	cout<<"destructor is called"<<endl;
		}    
            
        
};

int main() {
  Bank b1;
  Bank b2("haris",789456123,"saving",5000);
  b1.getaccountHolder();
  b1.getaccountNumber();
  b1.getaccountType();
  b1.getbalance();
  b1.setAccountType("current");
  b1.setDeposit();
  b1.setWithdrawl();
  b1.getDisplayaccountdetails();
  cout<<"\n"<<endl;
  b2.getaccountHolder();
  b2.getaccountNumber();
  b2.getaccountType();
  b2.getbalance();
  

    return 0;
}
