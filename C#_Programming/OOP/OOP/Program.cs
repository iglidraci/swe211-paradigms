using System;
using OOP.Structs;

namespace OOP
{
    internal class Program
    {
        private static T[] MapArray<T>(T[] arr, Func<T, T> mappingFunc) where T : IComparable<T>
        {
            T[] newArray = new T[arr.Length];
            for (int i = 0; i < arr.Length; i++)
            {
                newArray[i] = mappingFunc(arr[i]);
            }

            return newArray;
        }

        private static int ReduceArray(int[] arr, Func<int, int, int> reduceFunc)
        {
            if (arr.Length == 0)
                return 0;
            int finalResult = arr[0];
            for (int i = 1; i < arr.Length; i++)
            {
                finalResult = reduceFunc(finalResult, arr[i]);
            }

            return finalResult;
        }

        private static int Cube(int a) => a * a * a;

        public static void Main(string[] args)
        {
            var arr = new[] { 1, 2, 3 };
            var cubic = MapArray(arr, Cube);
            var product = ReduceArray(cubic, (x, y) => x * y);
            Array.ForEach(cubic, Console.WriteLine);
            Console.WriteLine($"Product is {product}");
            var account = new BankAccount("Gosha", 1000);
            account.MakeWithdrawal(200, DateTime.Now, "Rent payment");
            account.ReportBalance();
            account.MakeDeposit(300, DateTime.Now, "Salary for March");
            account.ReportBalance();
            // let's test exceptions
            try
            {
                var invalidAccount = new BankAccount("Sogga", -10);
                invalidAccount.ReportBalance();
            }
            catch (ArgumentException e)
            {
                Console.WriteLine("Exception thrown creating an account with negative initial balance");
                Console.WriteLine(e);
            }

            try
            {
                account.MakeWithdrawal(-500, DateTime.Now, "Attempt to withdraw negative amount");
            }
            catch (ArgumentException e)
            {
                Console.WriteLine(e);
            }
            account.ReportBalance();
            Console.WriteLine(account.GetAccountHistory());
            var giftCard = new GiftCardAccount("Plinka", 100, 20);
            giftCard.MakeWithdrawal(50, DateTime.Now, "Buy expensive jewellery");
            giftCard.MakeWithdrawal(50, DateTime.Now, "Buy food");
            giftCard.PerformMonthEndTransactions();
            Console.WriteLine(giftCard.GetAccountHistory());

            var piggyBank = new InterestEarningAccount("Floppa", 500);
            piggyBank.MakeDeposit(110, DateTime.Now, "Save some money");
            piggyBank.MakeWithdrawal(100, DateTime.Now, "Buying cement");
            piggyBank.PerformMonthEndTransactions();
            Console.WriteLine(piggyBank.GetAccountHistory());
            TestStructs();
            int a = 1;
            // An argument that is passed to a ref
            // parameter must be initialized before it is passed
            // This requirement differs from out parameters, whose arguments
            // don't have to be explicitly initialized before they are passed.
            MutateInt(ref a);
            Console.WriteLine(a);
            TestTuples();
        }

        private static void TestTuples()
        {
            (int, int) t1 = (1, 2);
            Console.WriteLine($"Tuple with elements {t1.Item1} and {t1.Item2}");
            (int X, int Y) point = (1, 2);
            Console.WriteLine($"Tuple with elements {point.X} and {point.Y}");
            var minMax = FindMinMax(new[] { 10, 20, 1, 40 });
            Console.WriteLine($"Min {minMax.min} and max {minMax.max}");
        }

        private static (int min, int max) FindMinMax(int[] arr)
        {
            int min = Int32.MaxValue;
            int max = Int32.MinValue;
            foreach (var nr in arr)
            {
                if (nr > max)
                    max = nr;
                if (nr < min)
                    min = nr;
            }

            return (min, max);
        }

        private static void MutateInt(ref int b)
        {
            b++;
        }

        private static void TestStructs()
        {
            var p1 = new Coords(0, 0);
            var p2 = p1;
            p2.Y = 1;
            Console.WriteLine(p1);
            Console.WriteLine(p2);
            Console.WriteLine(p1 is Coords);
        }
    }
}