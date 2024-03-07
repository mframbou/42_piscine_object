#include <iostream>
#include <vector>
#include <algorithm>

// struct Account
// {
//     private:
//         static int idCounter;
//         const int id;
//         double value;

//         void setValue(double value)
//         {
//             this->value = value;
//         }

//         void addValue(double value)
//         {
//             if (value < 0)
//                 throw std::invalid_argument("Value must be positive");
//             this->value += value;
//         }

//         void removeValue(double value)
//         {
//             if (value < 0)
//                 throw std::invalid_argument("Value must be positive");
//             if (this->value - value < 0)
//                 throw std::invalid_argument("Not enough money in account");
//             this->value -= value;
//         }

//         Account() :
//             id(idCounter++),
//             value(0.0)
//         {

//         }

//         Account(double initialDeposit) :
//             id(idCounter++),
//             value(initialDeposit)
//         {

//         }

//         friend class Bank;

//     public:
//         int getValue() const
//         {
//             return value;
//         }

//         int getId() const
//         {
//             return id;
//         }

//         friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
//         {
//             p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
//             return (p_os);
//         }
// };
// int Account::idCounter; // static member initialization, otherwise it will be undefined so it will not compile

struct Bank
{
    struct Account {
        private:
            static int idCounter;
            const int id;
            double value;

            Account() :
                id(idCounter++),
                value(0.0)
            {

            }

            Account(double initialDeposit) :
                id(idCounter++),
                value(initialDeposit)
            {

            }

        public:
            double getValue() const
            {
                return value;
            }

            int getId() const
            {
                return id;
            }

            friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
            {
                p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
                return (p_os);
            }

            friend struct Bank;
    };

    private:
        double liquidity;
        std::vector<Account *> clientAccounts;

        void setLiquidity(double liquidity)
        {
            this->liquidity = liquidity;
        }

        void addLiquidity(double liquidity)
        {
            if (liquidity < 0.0)
                throw std::invalid_argument("Value must be positive");
            this->liquidity += liquidity;
        }

        void removeLiquidity(double liquidity)
        {
            if (liquidity < 0.0)
                throw std::invalid_argument("Value must be positive");
            if (this->liquidity - liquidity < 0.0)
                throw std::invalid_argument("Not enough liquidity in bank");
            this->liquidity -= liquidity;
        }

    public:
        Bank() :
            liquidity(0.0)
        {

        }

        double getLiquidity() const
        {
            return liquidity;
        }

        void deposit(Account &account, double value)
        {
            if (value < 0.0)
                throw std::invalid_argument("Value must be positive");
            // bank takes 5% of all deposits
            addLiquidity(value * 0.05);
            account.value += value * 0.95;
        }

        void withdraw(Account &account, double value)
        {
            if (value < 0.0)
                throw std::invalid_argument("Value must be positive");
            if (account.value - value < 0.0)
                throw std::invalid_argument("Not enough money in account");
            account.value -= value;
        }

        Account &createAccount(double initialDeposit = 0.0)
        {
            Account *account = new Account(initialDeposit);
            clientAccounts.push_back(account);
            return *account;
        }

        void loan(Account &account, double value)
        {
            if (value < 0.0)
                throw std::invalid_argument("Value must be positive");
            if (value > getLiquidity())
                throw std::invalid_argument("Not enough liquidity in bank");
            account.value += value;
            removeLiquidity(value);
        }

        void removeAccount(Account &account)
        {
            std::vector<Account *>::iterator it = std::find(clientAccounts.begin(), clientAccounts.end(), &account);
            if (it != clientAccounts.end())
            {
                // replace account with NULL, so we keep the same indexes
                *it = NULL;
                delete &account;
            }
        }

        Account &operator[](int index)
        {
            if (index < 0 || index >= static_cast<int>(clientAccounts.size()))
                throw std::out_of_range("Index out of range");
            Account *account = clientAccounts[index];
            if (account == NULL)
                throw std::invalid_argument("Account does not exist anymore");
            return *clientAccounts[index];
        }

        friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
        {
            p_os << "Bank informations : " << std::endl;
            p_os << "Liquidity : " << p_bank.liquidity << std::endl;
            for (std::vector<Account *>::const_iterator it = p_bank.clientAccounts.begin(); it != p_bank.clientAccounts.end(); it++)
            {
                if (*it == NULL)
                    continue;
                p_os << **it << std::endl;
            }
            return (p_os);
        }

        ~Bank()
        {
            for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end(); it++)
                delete *it;
        }
};
int Bank::Account::idCounter; // static member initialization, otherwise it will be undefined so it will not compile

int main()
{
    Bank bank = Bank();
    Bank::Account &accountA = bank.createAccount(100);
    Bank::Account &accountB = bank.createAccount(100);

    // accountA->addValue(100);
    // accountA->id = 5;
    // accountA->value = 100;
    // bank.liquidity = 999;

	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

    try {
        bank.withdraw(accountA, 150);
    } catch (std::invalid_argument &e) {
        std::cerr << "Cannot withdraw: " << e.what() << std::endl;
    }

    bank.withdraw(accountA, 100);
    bank.deposit(accountB, 500); // 5% goes to bank so 25

    Bank::Account &accountC = bank.createAccount(1000);

    std::cout << " --------------------- " << std::endl;

    std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

    bank.deposit(accountB, 9500); // 5% goes to bank so 475, bank now has 500 liquidity
    try {
        bank.loan(accountA, 1000);
    } catch (std::invalid_argument &e) {
        std::cerr << "Cannot loan: " << e.what() << std::endl;
    }
    bank.loan(accountA, 300);
    bank.removeAccount(accountC);
    bank.removeAccount(accountC); // should not crash

    Bank::Account &accountD = bank.createAccount(999);
    (void) accountD;

    std::cout << " --------------------- " << std::endl;

    std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;


    std::cout << " --------------------- " << std::endl;

    std::cout << "Account A id and value: " << accountA.getId() << " " << accountA.getValue() << std::endl;
    std::cout << "Bank liquidity: " << bank.getLiquidity() << std::endl;

    try {
        std::cout << bank[0] << std::endl;
        std::cout << bank[1] << std::endl;
        std::cout << bank[2] << std::endl;
    } catch (std::out_of_range &e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    } catch (std::invalid_argument &e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }

    try {
        std::cout << bank[3] << std::endl;
        std::cout << bank[4] << std::endl;
    } catch (std::out_of_range &e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    } catch (std::invalid_argument &e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }

	return (0);
}
