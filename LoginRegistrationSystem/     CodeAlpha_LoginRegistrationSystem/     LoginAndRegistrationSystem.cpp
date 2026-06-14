#include <iostream>
#include <string>
#include <system_error>
#include <fstream>
#define ALPHA(c) (((c)>='A' && (c)<='Z') || ((c)>='a' && (c)<='z'))
#define NUM(c) ((c)>='0' && (c)<='9')
#define SPECIAL(c) (!(ALPHA(c) || NUM(c)))

using namespace std;

class SecureSystem {
  protected :
  string username;
  string password;
  };
  
  class Register : protected SecureSystem {
    public :
    bool InputValidation( string s);
    void Registration();
    unsigned int Hash(string s)
{
    unsigned int hash = 0;

    for (int i = 0; i < s.length(); i++)
    {
        hash ^= ((unsigned int)s[i] << (i % 16));
        hash += (i + 1);
    }

    return hash;
}
  };
  
  class Login : protected SecureSystem
{
public:
    Login()
    {
        Register Obj3;

        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;

        unsigned int h = Obj3.Hash(password);

        ifstream file("users.txt");

        string user;
        unsigned int pass;

        while(file >> user >> pass)
        {
            if(user == username && pass == h)
            {
                cout << "Login successful\n";
                file.close();
                return;
            }
        }

        file.close();
        cout << "Invalid username or password\n";
    }
};




    
  
bool RegisterUser(string username, unsigned int passwordHash)
{
    string user;
    unsigned int pass;

    fstream file("users.txt", ios::in);

    while(file >> user >> pass)
    {
        if(user == username)
        {
            file.close();
            return false;
        }
    }

    file.close();

    file.open("users.txt", ios::app);

    file << username << " " << passwordHash << endl;

    file.close();

    return true;
}

  
  bool  Register :: InputValidation(string s){
    
    if(s.length()>12  || s.length()<8)  
    {
      cout<<"Error:\nOnly 8 to 12 characters allowed."<<endl;
    return 0;
    }
    else cout<<"✅ 8 to 12 Characters allowed"<<endl;
    int alpha=0 , num= 0 , special =0;
    for (int i = 0; i < s.length(); i++)
{
    if (ALPHA(s[i])) alpha++;
    if (NUM(s[i])) num++;
    if (SPECIAL(s[i])) special++;
}

if (alpha)
    cout << "✅ Alphabets are present" << endl;
else
    cout << "❌ Alphabets are not present" << endl;

if (num)
    cout << "✅ Numbers are present" << endl;
else
    cout << "❌ Numbers are absent" << endl;

if (special)
    cout << "✅ Special characters are present" << endl;
else
    cout << "❌ Special characters are absent" << endl;
    
    if(alpha && num && special)
    return true ;
    else  return false;
  }

void Register :: Registration()
{
  auto count=0;
  registeration:
  cout<<"#Registration"<<endl;
  cout<<"Enter username"<<endl;
  cin>> username;
  cout<<"Enter password : "<<endl;
  cin>>password;
  if(InputValidation(password)  && RegisterUser( username,  Hash(password)))
  cout<<"Registered successfully"<<endl;
  else
  {
    cout<<" Invalid password"<<endl;
    count++;
    if(count==3) {
      cout<<"Try next time\n";
     }
     else goto registeration;
     
     
     }
}






int main() 
{
  Register Obj1;
  cout<<"=============================" <<endl;
  cout<<"Registration and Login System"<<endl;
  cout<<"=============================" <<endl;
  cout<<"Hi user,\n\tThis is a safe and secure system for you to register and get logged in.\n"<<endl<<endl<<endl;
  
  int Command=1;
  do{
    cout<<"------------" <<endl<<"MenuBar"<<endl<<"------------"<<endl;
    cout<<"1 Register yourself"<<endl;
    cout<<"2 Login"<<endl;
    cout<<"3 Exit"<<endl<<endl;
    
    cout<<"Enter Command : "<<endl;
    cin>>Command;
    
    switch(Command){
    case 1:
    {
      Obj1.Registration();
      
      break;
    }
    case 2 :
    {
      Login Obj2;
      break;
    }
    case 3 :
    {
      cout<<"Exiting...........\n";
      break;
      }
    default: 
    cout<<" Error : \n\tInvalid command \n";
  }
 }while(Command != 3);
  return 0;
  
  }
  
