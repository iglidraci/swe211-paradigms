using System;

namespace OOP
{
    /*
     * Will get a credit of 5% of the month-ending-balance.
     */
    public class InterestEarningAccount : BankAccount
    {
        public InterestEarningAccount(string name, decimal initialBalance) : base(name, initialBalance)
        { }

        public override void PerformMonthEndTransactions()
        {
            if (Balance > 500m)
                MakeDeposit(Balance*0.05m, DateTime.Now, "Apply monthly interest");
        }
    }
}