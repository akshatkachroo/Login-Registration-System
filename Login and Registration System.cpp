
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main();


bool IsLoggedIn()
{
    string username;
    string password;
    string user_check;
    string pass_check;

    cout << "Enter username"; 
    cin >> username;
    cout << "Enter password"; 
    cin >> password;

    ifstream myFile;
    myFile.open("data\\" + username + ".txt");
    getline(myFile, user_check);
    getline(myFile, pass_check);

    if ((user_check == username) && (pass_check == password))
    {
        return true;
    }
    else 
    {
        return false;
    }
  }       
int main(){

    int choice;

    cout << "1:Register"<<endl<<"2: Login"<<endl<<"Your choice: "; 
    cin>> choice;
        if (choice == 1)
        {
            string username;
            string password;

            cout << "Select a username:";
            cin >> username;
            cout << "Select a password:"; 
            cin >> password;

            ofstream myFile;
            myFile.open("data\\" + username + ".txt");
            myFile << username << endl << password;
            myFile.close();

            main();
        }
        else if (choice == 2)
        {
            bool status = IsLoggedIn();


            if (!status) 
            {
                cout << "Login Failed!" << endl;
                return 0;
            }
            else 
            {
                cout <<"Successfully logged in!" << endl;
                return 1;
            }
        }
}