#pragma once

class Account {
public:
    Account(int id, int balance);
    virtual ~Account();
    virtual int GetBalance() const;
    virtual void Lock();
    virtual void Unlock();
    virtual bool ChangeBalance(int diff);
private:
    int id_;
    int balance_;
    bool locked_;
};
