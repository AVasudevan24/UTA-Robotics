

include <iostream>
using namespace std;

class BankAccount {
    public:
    float getAccountBalance () {
        return accountBalance;
    }
    void deposit (float amount) {
        accountBalance += amount;
    }
     BankAccount() {
          accountNumber = 0;
          accountBalance = 0.0;
          name = "";
          address = "";
      }
    }
  private:
     int accountNumber;
     float accountBalance;
     string name;
     string address;

      

int main() {
     BankAccount alisonBankAccount; //make a bankAccount for Alison
     alisonBankAccount.accountNumber = 14538;  //assign the account a number
     alisonBankAccount.accountBalance = 1000000.01;  //give Alison some money
     alisonBankAccount.name = "Alison Norman";  //assign name and address
     alisonBankAccount.address = "1600 Pennsylvania Avenue NW Washington, DC 20500";
     return 0;
}
int main(){

   BankAccount alisonBankAccount;
   BankAccount bobBankAccount;
   bobBankAccount.deposit(300.95);
   return 0;
}
int main() {
    cout alisonBankAccount.address
}