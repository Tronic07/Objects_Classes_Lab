# Objects_Classes_Lab

A C++ class for representing a book in a library system.

## Data Dictionary

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
| `getTitle() const`           | `std::string` | Gets the book's title.    |
| `getAuthor() const`          | `std::string` | Gets the book's author.   |
| `isAvailable() const`        | `bool`        | Checks if available.      |
| `checkOut()`                 | `void`        | Checks out the book.      |
| `returnBook()`               | `void`        | Returns the book.         |
