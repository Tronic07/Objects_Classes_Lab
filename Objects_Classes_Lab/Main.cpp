#include <iostream>
#include <vector>
#include <string>

class BankAccount {
private:
	std::string accountNumber;
	std::string accountHolderName;
	double balance;
public:
	BankAccount() : accountNumber(""), accountHolderName(""), balance(0.0) {}

	BankAccount(std::string accNum, std::string holderName, double initialBalance)
		: accountNumber(accNum), accountHolderName(holderName), balance(initialBalance) {}

	std::string getAccountNumber() const { return accountNumber; }
	std::string getAccountHolderName() const { return accountHolderName; }
	double getBalance() const { return balance; }

	void setAccountHolderName(std::string holderName) { accountHolderName = holderName; }

	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			std::cout << "Deposited $" << amount << ". New balance: $" << balance << std::endl;
		}
		else {
			std::cout << "Invalid deposit amount.\n";
		}
	}

	void withdraw(double amount) {
		if (amount > 0 && amount <= balance) {
			balance -= amount;
			std::cout << "Withdrew $" << amount << ". New balance: $" << balance << std::endl;
		}
		else if (amount > balance) {
			std::cout << "Insufficient funds.\n";
		}
		else {
			std::cout << "Invalid withdrawal amount.\n";
		}
	}
};

BankAccount* findAccount(std::vector<BankAccount>& accounts, const std::string& accNum) {
	for (auto& acc : accounts) {
		if (acc.getAccountNumber() == accNum) {
			return &acc;
		}
	}
	return nullptr;
}

int main() {
	std::vector<BankAccount> accounts;
	int choice;
	std::string accNum, holderName;
	double amount;

	while (true) {
		std::cout << "Bank Account Management System Menu:\n"
			<< "1. Create New Account\n"
			<< "2. Deposit Funds\n"
			<< "3. Withdraw Funds\n"
			<< "4. View All Accounts\n"
			<< "5. Exit\n"
			<< "Enter your choice: ";
		std::cin >> choice;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number.\n";
		}

		switch (choice) {
		case 1: {
			std::cout << "\nEnter account number: ";
			std::cin >> accNum;
			std::cout << "Enter account holder name (use underscores for space, e.g., John_Doe): ";
			std::cin >> holderName;
			accounts.emplace_back(accNum, holderName, 0.0);
			std::cout << "Account created successfully!\n";
			break;
		}
		case 2: {
			std::cout << "\nEnter account number to deposit into: ";
			std::cin >> accNum;
			BankAccount* account = findAccount(accounts, accNum);
			if (account) {
				std::cout << "Enter amount to deposit: $";
				std::cin >> amount;
				account->deposit(amount);
			}
			else {
				std::cout << "Account not found.\n";
			}
			break;
		}
		case 3: {
			std::cout << "\nEnter account number to withdraw from: ";
			std::cin >> accNum;
			BankAccount* account = findAccount(accounts, accNum);
			if (account) {
				std::cout << "Enter amount to withdraw: $";
				std::cin >> amount;
				account->withdraw(amount);
			}
			break;
		}
		case 4: {
			std::cout << "\n--- All Accounts ---\n";
			for (const auto& acc : accounts) {
				std::cout << "Acc Number: " << acc.getAccountNumber()
					<< ", Holder: " << acc.getAccountHolderName()
					<< ", Balance: $" << acc.getBalance() << std::endl;
			}
			std::cout << "-------------------\n";
			break;
		}
		case 5:
			std::cout << "\nExit program. Goodbye!\n";
			return 0;
		default:
			std::cout << "\nInvalid choice. Please try again.\n";
		}
	}
}