#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string username,password;
    string searchuser,searchpass,searchemail;
    fstream file;
    public:
    void login();
    void signup();
    void forget();
}obj;

int main(){
    char choice;
    do{
    cout<<"\n1 - login";
    cout<<"\n2 - signup";
    cout<<"\n3 - forget password";
    cout<<"\n4 - exit";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    
    switch (choice){
        case '1':
        obj.login();
        break;
        case '2':
        obj.signup();
        break;
        case '3':
        obj.forget();
        break;
        case '4':
        cout << "Exiting the system..." << endl;
        break;
        default:
        cout<< "Invalid Selection"<<endl;
    }
    }while (choice != '4' );
    return 0;
}

void temp :: signup(){
    cout<<"Enter your Username :: ";
    cin.ignore();
    getline(cin,username);
    cout<<"Enter your Password :: ";
    getline(cin,password);

    file.open("loginData.txt",ios :: out | ios :: app);
    file<<username<<"*"<<password<<endl;
    file.close();
}

void temp :: login(){
    cout<<"........login........"<<endl;
    cout<<"Enter your username :: ";
    cin.ignore();
    getline(cin,searchuser);
    cout<<"\nEnter your password :: ";
    getline(cin,searchpass);

    file.open("loginData.txt",ios :: in);
    getline(file,username,'*');
    getline(file,password,'\n');

    while(!file.eof()){
        if(username == searchuser && password == searchpass){
                cout<<"\n Login successfull !";
                cout<<"\nusername :: "<<username;
                cout<<"\npassword :: "<<password;
                break;
          }
    getline(file,username,'*');
    getline(file,password,'\n');
    }
    file.close();
}

void temp :: forget(){
    cout<<"Enter your username :: ";
    cin.ignore();
    getline(cin,searchuser);

    file.open("loginData.txt",ios :: in);
    getline(file,username,'*');
    getline(file,password,'\n');

    while(!file.eof()){
        if(username == searchuser){
            cout<<"Password :: "<<password<<endl;
            break;
        }
        getline(file,username,'*');
    getline(file,password,'\n');
    }
    file.close();
}

