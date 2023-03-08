using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace OOP
{
    public class BankAccount
    {
        private static int accountNumberSeed = 1;
        private List<Transaction> allTransactions = new List<Transaction>();
        public string Number { get; }
        public string Owner { get; set; }
        public decimal Balance
        {
            get => allTransactions.Sum(x => x.Amount);
        }

        public BankAccount(string owner, decimal initialBalance)
        {
            Owner = owner;
            Number = accountNumberSeed.ToString();
            accountNumberSeed++;
            MakeDeposit(initialBalance, DateTime.Now, "Initial balance");
        }
        

        public void MakeDeposit(decimal amount, DateTime date, string note)
        {
            if (amount <= 0)
                throw new ArgumentException(nameof(amount), "Amount of deposit should positive");
            allTransactions.Add(new Transaction(amount, date, note));
        }

        public void MakeWithdrawal(decimal amount, DateTime date, string note)
        {
            if (amount <= 0)
                throw new ArgumentException(nameof(amount), "Amount of withdrawal cannot be negative");
            if (Balance - amount < 0)
                throw new InvalidOperationException("Not enough balance to withdraw");
            allTransactions.Add(new Transaction(-amount, date, note));
        }

        public void ReportBalance()
        {
            Console.WriteLine($"{Owner}'s current balance is {Balance}");
        }

        public string GetAccountHistory()
        {
            var report = new StringBuilder();
            report.AppendLine("Date\t\tAmount\tBalance\tNote");
            decimal balance = 0;
            foreach (var transaction in allTransactions)
            {
                balance += transaction.Amount;
                report.AppendLine($"{transaction.Date.ToShortDateString()}\t{transaction.Amount}" +
                                  $"\t{balance}\t{transaction.Notes}");
            }

            return report.ToString();
        }

        public virtual void PerformMonthEndTransactions()
        {
            // use the virtual keyword to declare a method in the base class that a
            // derived class may provide a different implementation for
        }
        private struct Transaction
        {
            public decimal Amount { get; }
            public DateTime Date { get; }
            public string Notes { get; }
            public Transaction(decimal amount, DateTime date, string note)
            {
                Amount = amount;
                Date = date;
                Notes = note;
            }
        }
    }
}