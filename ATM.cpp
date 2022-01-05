#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

/* Mini Project - ATM
-->Check Balence
-->Cash Withraw
-->User Details
-->Update Mobile No
*/

class atm
{ //class atm
private:
    long int account_No;
    string name; //private member variable
    int PIN;
    double balence;
    string mobile_No;

public:
    //setdata function is setting the data into the private member variables
    void setData(long int account_No_a, string name_a, int PIN_a, double balence_a, string mobile_No_a)
    {
        //assigning the formal arguments to the private member variables
        account_No = account_No_a;
        name = name_a;
        PIN = PIN_a;
        balence = balence_a;
        mobile_No = mobile_No_a;
    }
    //getAccount No function is returning the user's account no.
    long int getAccountNo()
    {
        return account_No;
    }
    //getName function is returning user's name
    string getName()
    {
        return name;
    }
    int getPIN()
    {
        return PIN;
    }
    double getBalence()
    {
        return balence;
    }
    string getMobileNo()
    {
        return mobile_No;
    }

    //setMobile no function is updating the user mobile no
    void setMobile(string mob_prev, string mob_new)
    {
        if (mob_prev == mobile_No)
        {                        //it will check old mobile no
            mobile_No = mob_new; //and update with new mobile no if old match
            cout << "Sucessfully Update Mobile no." << endl;
            _getch(); //getch is to fold the screen(untill user press any key)
        }
        else
        {
            cout << "Incorrect !!! Old Mobile No" << endl;
            _getch();
        }
    }

    //cash withDraw function is used to withraw money from ATM
    void cashWithDraw(int amount_a)
    {
        if (amount_a > 0 && amount_a < balence) ////check enter amount validity
        {
            balence -= amount_a; //balence = balence - amount_a
            cout << "Please Collect your Cash" << endl;
            cout << "Avaible Balence : " << balence << endl;
            _getch();
        }
        else
        {
            cout << "Invalid Input Or Insufficent Balence" << endl;
            _getch();
        }
    }
};

///////////////////////////////////////////////////////////////////

int main()
{
    int choice = 0, enterPIN; //enteePin and enterAccountNO-->user authentication
    long int enterAccoutNo;

    system("cls");

    //creat user object

    atm user1;
    //Set user details(into object)     (Setting Default Data)
    user1.setData(1234567, "Akash", 6699, 45000.90, "6287971210");

    do
    {
        system("cls");

        cout << endl
             << "WELCOME TO ATM" << endl;
        cout << "Enter your Account No" << endl;
        cin >> enterAccoutNo;

        cout << "Enter PIN" << endl;
        cin >> enterPIN;

        //check whether enter value match with user details
        if ((enterAccoutNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system("cls");

                //user Interface

                cout << endl
                     << "Welcome to ATM" << endl;
                cout << endl
                     << "Select Options ";
                cout << endl
                     << "1. Check Balence";
                cout << endl
                     << "2. Cash Withraw";
                cout << endl
                     << "3. Show User Details";
                cout << endl
                     << "4. Update Mobile No";
                cout << endl
                     << "5. Exit" << endl;

                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "Your Balence is : " << user1.getBalence();
                    _getch();
                    break;
                case 2:
                    cout << "Enter the amount : " << endl;
                    cin >> amount;
                    user1.cashWithDraw(amount);
                    // _getch();
                    break;
                case 3:
                    cout << endl
                         << "User Details are : " << endl;
                    cout << endl
                         << "-> Account No " << user1.getAccountNo();
                    cout << endl
                         << "-> Name       " << user1.getName();
                    cout << endl
                         << "-> Balence    " << user1.getBalence();
                    cout << endl
                         << "-> Mobile No  " << user1.getMobileNo();
                    _getch();
                    break;
                case 4:
                    cout << "Enter Old Mobile No " << endl;
                    cin >> oldMobileNo;

                    cout << "Enter New Mobile No " << endl;
                    cin >> newMobileNo;

                    user1.setMobile(oldMobileNo, newMobileNo);

                    break;
                case 5:
                    exit(0);

                default:
                    cout << " Enter Valid Data !!!" << endl;
                }

            } while (1);
        }

    } while (1);

    return 0;
}