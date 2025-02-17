#include <iostream>
#include<string.h>
using namespace std;

class Book{
    private:
        char* Title;
        char* Author_Name;
        int Page_Count;
        bool Format_Type;
        float* Chapter_p;
        int Chapter_no;
    public:
        Book(){
        	cout<<"Default Constructor"<<endl;
            Title=new char[1];
            Title[0]='\0';
            Author_Name=new char[1];
            Author_Name[0]='\0';
            Page_Count=0;
            Format_Type=false;
            Chapter_p=NULL;
            Chapter_no = 0;
        }
        Book(const char* tit,const char* aut,int p_c,bool f_t,float* c_p,int c_n)
        {
        	cout<<"Parameterised constructor"<<endl;
            Title=new char[strlen(tit)+1];
            strcpy(Title,tit);
            Author_Name=new char[strlen(aut)+1];
            strcpy(Author_Name,aut);
            Page_Count=p_c;
            Format_Type=f_t;
            Chapter_p=new float[c_n];
            for(int i = 0; i < c_n; i++){
            Chapter_p[i]=c_p[i];
            
            }
            Chapter_no=c_n;
        }
        Book(const Book &obj){
        	cout<<"Copy constructor"<<endl;
            Title=obj.Title;
            Author_Name=obj.Author_Name;
            Page_Count=obj.Page_Count;
            Format_Type=obj. Format_Type;
            Chapter_p=obj.Chapter_p;
            Chapter_no=obj.Chapter_no;
        }
        void setChapterpagecount(int x){
            Page_Count=x;
        }
        void getinfo(){
            cout<<"Book Name :"<<Title<<endl;
            cout<<"Author Name :"<< Author_Name<<endl;
            cout<<"Page Count :"<<Page_Count<<endl;
            cout<<"IS It Hardcover :" ;
            if(Format_Type==1){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"Yes"<<endl;
            }
            cout<<"Chapter Pages :";
            for(int i=0;i<Chapter_no;i++){
                cout<<Chapter_p[i];
                cout<<" ";
            }
            cout<<"\nNumber of Chapter :"<<Chapter_no<<endl;
            cout<<endl<<endl;
        }
        ~Book(){
        	delete Title;
        	delete Author_Name;
        	delete Chapter_p;
		}
    
};

int main() {
   Book b1;
   b1.getinfo();
   float arr[10]={10,20,30,10,50,5,6,88,4,45};
   Book b3("AGNI","APJ Abdul Kalam",50,true,arr,10);
   b3.getinfo();
   Book b2=b3;
   b2.setChapterpagecount(200);
   b2.getinfo();
   

    return 0;
}

