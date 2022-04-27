using System;

namespace OOP
{
    /*
     * Can be refilled with a specified amount once each month, on the last day of the month.
     */
    public sealed class GiftCardAccount : BankAccount
    {
        // A readonly field can't be assigned after the constructor exits
        private readonly decimal _monthlyDeposit;

        public GiftCardAccount(string name, decimal initialBalance, decimal monthlyDeposit)
            : base(name, initialBalance)
        {
            _monthlyDeposit = monthlyDeposit;
        }

        public override void PerformMonthEndTransactions()
        {
            if (_monthlyDeposit != 0)
                MakeDeposit(_monthlyDeposit, DateTime.Now, "Add monthly deposit");
        }
    }
}