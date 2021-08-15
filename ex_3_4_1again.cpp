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
      BankAccount() {
          accountNumber = 0;
          accountBalance = 0.0;
          name = "";
          address = "";
      }
      void withdraw(float amount) {
          if (amount>accountBalance) {
              cout << "YOU DONT HAVE ENOUGH MONEY" << endl;
          }
          else {accountBalance -= amount;}

    
          
      }

  private:
     int accountNumber;
     float accountBalance;
     string name;
     string address;
};
int main() {
    BankAccount alisonBankAccount;
    BankAccount bobBankAccount;
    BankAccount joeBankAccount;
    bobBankAccount.deposit (300);
    cout << bobBankAccount.getAccountBalance() << " is Bobs account balance" <<endl;
    alisonBankAccount.deposit (500);
    cout << alisonBankAccount.getAccountBalance() << " is Alisons account balance" <<endl;
    bobBankAccount.withdraw (200);
    cout << bobBankAccount.getAccountBalance() << " is Bobs account balance" <<endl;
    joeBankAccount.deposit (200);
    cout << alisonBankAccount.getAccountBalance() << " is Alisons account balance" <<endl;
    cout << bobBankAccount.getAccountBalance() << " is Bobs account balance" <<endl;
    cout << joeBankAccount.getAccountBalance() << " is Joes account balance" <<endl;


}
