#include "Account.h"
#include <stdexcept>

Account::Account(int id, int balance) : id_(id), balance_(balance), locked_(false) {}
Account::~Account() {}
int Account::GetBalance() const { return balance_; }
void Account::Lock() { locked_ = true; }
void Account::Unlock() { locked_ = false; }
bool Account::ChangeBalance(int diff) {
    if (!locked_) throw std::runtime_error("Account is not locked");
    balance_ += diff;
    return true;
}
