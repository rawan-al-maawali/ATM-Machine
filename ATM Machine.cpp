#include <iostream>
using namespace std;
#define size 5 //To be used in arrays; static arrays can't accept size that is given as a variable. This way preprocessor will replace size with the given value at compile time.(Feel free to change the value).
int index = 0;  // Helps in counting up the index of arrays and adding elements to arrays.
int account_num =0; //Helps in identifying the number of accounts.
int position;  // Helps in identifyig the exact index of each user; changes according to login information. This way each user has a special same index in all arrays.
string username[size]; //Array of users' names.
string password[size]; //Array of users' passwords.
double balance[size]; //Array of users account balances.


void createAccount() {
  cout<<"Please enter your user name: ";
  cin>>username[index]; //Initiating username and store it in the specified array.
  cout<<"Please enter your password: ";
  cin>>password[index]; //Initiating password and store it in the specified array.
  balance[index] = 0.000;  //Initiating balance as zero and store it in the specified array.
  index +=1; //Content of current index are stored; this moves index one unit up preparing for next registeration.
  account_num +=1; //One more account has been created.
  cout<<endl<<"Thank you! Your account has been created!"<<endl<<endl;
}

void deposit() {
  double deposit; //To store the money the user willing to deposit.
  cout<<endl<<"Amount of deposit: OMR ";
  cin>>deposit; 
  balance[position] +=deposit; //deposit money into balance array at user's special index.
  cout<<endl;
}

void withdraw(){
  double moneyWithdraw;  //to store the money the user willing to withdraw
  cout<<endl<<"Amount of withdrawal: OMR ";
  cin>> moneyWithdraw; 
  cout<<endl;
  if (moneyWithdraw>balance[position]) {    //Withdrawed money can't be bigger the the user's balance.
    cout<<"You don't have sufficent funds.\nPlease check your account balance."<<endl<<endl;
  }
  else if ((moneyWithdraw<=balance[position]) && (moneyWithdraw>0)) { //Withdrawed money has to be a positive number and less or equal to the user's balance.
    balance[position] -= moneyWithdraw; 
  }
  else { //User can't input a negative number.
    cout<<"Invalid input, please re-enter the money you would like to withdraw."<<endl;
    withdraw();
  }
}

void displayBalance() {
  cout<<endl<<"Your Balance is  "<<balance[position]<< " OMR"<<endl<<endl;
}

void mainMenu(){
  while (true) { //While loop is used because we don't know how many times the user wants to log in. Main menu is accessable as many times to the user as long as the user is registered in the ATM.
    char entry2; // To store user option from the menu.
    cout<<"d-> Deposit Money \n"<<"w -> Withdraw Money\n"<<"r -> Request Balance\n"<< "q -> Introduction Menu\n"<<endl;
    cin>> entry2;
    switch (entry2) { //Each option entered has its own case/ takes us to a different funcion.
      case 'd':
        deposit();
        break;
      case 'D': //Note that the user can enter both small or capital letter.
        deposit();
        break;
      case 'w':
        withdraw();
        break;
      case 'W':
        withdraw();
        break;
      case 'r':
        displayBalance();
        break;
      case 'R':
        displayBalance();
        break;
      case 'q':
        break; //Breaks from the switch statement.
      case 'Q':
        break; //Breaks from the switch statement.
      default:
        cout<<"Please enter a valid option."<<endl<<endl; //In case the user inputs an unlisted option.
    }
    if ((entry2 == 'q') || (entry2 == 'Q')) { //After breaking from the switch statement, we need to break from the while loop. That is how this function ends until recalled again.
      break;
    }
  }    
}

void login(){
  string name; //To store username entered temporaryly.
  string pass; //To store user password entered temporarily.
  bool access = false; //Used for validating user login information.
  cout<<"Please enter your user id: ";
  cin>> name;
  cout<< "Please enter your password: ";
  cin>> pass;
  for (int i=0; i<=index;++i) { //This loops through all existing indexes in the arrays.
    if(name == username[i] && pass == password[i] ) {//Since every user has the same index in all arrays, name and password pair has to match the one registered.
      cout<<endl<<"Access Granted!"<<endl<<endl;
      access = true; //If the login information are correct, access is granted.
      position = i; //This is the special index number of the user. The index number will be saved here temporary as long as the user logged in. This number can be used in the main menu.
      break;
    }
  }
  if (access != true) { // In other words, false.
    cout <<endl<<"******** LOGIN FAILED ********"<<endl<<endl;
  }
  else { //If access is true.
    mainMenu();
  }
}

void introMenu() {
  while (true) { //While loop is used because we don't know how many times registered users want to use the ATM/ or get back to the intro menu as many times as they want.
    char entry; //To store the intro menu selected option.
    cout<<endl<<"Please select an option from the menu below:"<<endl<<endl<<"1 -> Login\n"<<"c -> Create New Account\n"<<"q -> Quit"<<endl<<endl;
    cin>> entry;
    switch(entry) { //Each option entered has its own case.
      case 'l':
        cout<<endl;
        login();
        break;
      case 'L':
        cout<<endl;
        login();
        break;
      case 'c':
        cout<<endl;
        if (account_num >= size) { //the number of accounts created can't exceed the array size.
          cout<<"Sorry, we have reached the maximum number of users. PLease contact manufacturer."<<endl<<endl;
          break;
        }
        else { //If number of accounts created is less than the array size, then there is place for more accounts.
          createAccount();
          break;
        }
      case 'C':
        cout<<endl;
        if (account_num >= size) {
          cout<<"Sorry, we have reached the maximum number of users. PLease contact manufacturer."<<endl<<endl;
          break;
        }
        else {
          createAccount();
          break;
        };
      case 'q':
        cout<<endl<<"Thanks for stopping by!"<<endl<<endl;
        break; //Breaks from the switch statement.
      case 'Q':
        cout<<endl<<"Thanks for stopping by!"<<endl<<endl;
        break; //Breaks from the switch statement.
      default:
        cout<<"Please enter a valid option."<<endl<<endl;
    }
    if ((entry=='q') || (entry == 'Q')){ //After breaking from the switch statement, we need to break from the while loop. That is how this function ends until recalled again.
      break;
    }
  }
}

int main() { 
  cout<<endl<<"Hi! Welcome to the ATM Machine!"<<endl<<endl;
  introMenu();
  string start;
  cout<<"Enter 'o' to turn on the ATM machine.  "<<endl<<endl;
  cin>>start;
  if ((start =="o") or (start == "O")) {
    main(); //This takes us back again to the beginning of the main function. In other words, it turns on the ATM machine at user's signal (entering the letter o). 
  }
  return 0; //Exit status of the function main. In other words, the program worked fine.
}
