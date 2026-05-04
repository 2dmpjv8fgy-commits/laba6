#include "Transaction.h"

Transaction::Transaction() {}
Transaction::~Transaction() {}
bool Transaction::Make(Account& from, Account& to, int sum) {
    if (from.GetBalance() < sum) return false;
    from.Lock();
    to.Lock();
    from.ChangeBalance(-sum);
    to.ChangeBalance(sum);
    from.Unlock();
    to.Unlock();
    return true;
}
