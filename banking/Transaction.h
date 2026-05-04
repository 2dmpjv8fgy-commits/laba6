#pragma once
#include "Account.h"

class Transaction {
public:
    Transaction();
    virtual ~Transaction();
    virtual bool Make(Account& from, Account& to, int sum);
};
