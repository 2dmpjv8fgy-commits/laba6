#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include "../Account.h"
#include "../Transaction.h"

class MockAccount : public Account {
public:
    MockAccount(int id, int balance) : Account(id, balance) {}
    MOCK_METHOD(int, GetBalance, (), (const, override));
    MOCK_METHOD(void, Lock, (), (override));
    MOCK_METHOD(void, Unlock, (), (override));
    MOCK_METHOD(bool, ChangeBalance, (int diff), (override));
};

class BankingTest : public ::testing::Test {
protected:
    void SetUp() override {}
};

TEST_F(BankingTest, TransactionAppliesChanges) {
    MockAccount acc1(1, 1000);
    MockAccount acc2(2, 500);
    Transaction tr;

    EXPECT_CALL(acc1, Lock()).Times(1);
    EXPECT_CALL(acc2, Lock()).Times(1);
    EXPECT_CALL(acc1, GetBalance()).WillOnce(testing::Return(1000));
    EXPECT_CALL(acc1, ChangeBalance(-300)).WillOnce(testing::Return(true));
    EXPECT_CALL(acc2, ChangeBalance(300)).WillOnce(testing::Return(true));
    EXPECT_CALL(acc1, Unlock()).Times(1);
    EXPECT_CALL(acc2, Unlock()).Times(1);

    EXPECT_TRUE(tr.Make(acc1, acc2, 300));
}

TEST(AccountTest, RealAccountCoverage) {
    Account acc(123, 1000);
    EXPECT_EQ(acc.GetBalance(), 1000);
    
    acc.Lock();
    acc.Unlock();
    
    acc.Lock();
    EXPECT_TRUE(acc.ChangeBalance(500));
    EXPECT_EQ(acc.GetBalance(), 1500);
    
    acc.Unlock();
    EXPECT_THROW(acc.ChangeBalance(100), std::runtime_error);
}

