# Objects_Classes_Lab

| Attribute          | Data Type     | Description                    |
|--------------------|---------------|--------------------------------|
| `accountNumber`    | `std::string` | The account number.            |
| `accountHolderName`| `std::string` | The account holder's name.     |
| `balance`          | `double`      | The account balance.           |

## Methods List

| Method Signature                                                                  | Return Type   | Description               |
|-----------------------------------------------------------------------------------|---------------|---------------------------|
| `BankAccount()`                                                                   | (Constructor) | Default constructor.      |
| `BankAccount(std::string accNum, std::string holderName, double initialBalance)`  | (Constructor) | Parameterized constructor.|
| `getAccountNumber() const`           | `std::string` | Gets the account number.    |
| `getAccountHolderName() const`          | `std::string` | Gets the account holder's name.   |
| `getBalance() const`        | `double`        | gets the account balance.      |
| `deposit()`                 | `void`        | Deposits into the account.      |
| `withdraw()`               | `void`        | Withdraws from the account.         |
