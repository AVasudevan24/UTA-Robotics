#include <iostream>
using namespace std;

class BankAccount {
  public:
    float getAccountBalance() {
      return accountBalance;
    }

    void deposit(float amount) {
      accountBalance += amount;
    }

    void withdraw(float request) {
      double newBalance = accountBalance - request;

      if (newBalance <= 0){
        return; // Don't withdraw anything, because the balance would be invalid
        cout <<"your balance is too low to withdraw this ammount!"<< endl;
      }
      else if(newBalance < minBalance) {

        if(newBalance <= fee) { // They can't afford the fee
          return; // Don't withdraw anything, because the balance would be negative
          cout<<"you cannot afford the minimum balance fee on this withdrawa"<< endl;
        }
        else {
          accountBalance = newBalance - fee; // Update the balance, but subtract a fee
        }
      }
      else{
        accountBalance = newBalance; // Update the balance
      }

    }

    BankAccount() {
      accountNumber = 0;
      accountBalance = 0.0;
      fee = 50.0;
      minBalance = 100.0;
      name = "";
      address = "";
    }

  private:
    int accountNumber;
    float accountBalance;
    string name;
    string address;
    float minBalance;
    float fee;

};

int main(){

    float withdrawRequest;
    BankAccount myAccount;
    myAccount.deposit(1000.00);

    cout << "Hello customer, please enter the amount you would like to withdraw: ";
    cin >> withdrawRequest;

    myAccount.withdraw(withdrawRequest);

    cout << "Your remaining balance is : " << myAccount.getAccountBalance() << endl;
    return 0;
}