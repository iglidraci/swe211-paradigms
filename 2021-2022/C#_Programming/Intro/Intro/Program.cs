using System;
using System.Collections.Generic;

namespace Intro
{
    public class Program
    {
        public static void Main(string[] args)
        {
            // HelloWorld(args.Length);
            // TestNumbers()
            // TestDateTime();
            // DataCollections();
            // TestDictionary();
            // TestHashSet();
        }

        private static void TestDateTime()
        {
            // DateTime is a struct that represents an instant in time
            // typically expressed as a date and time of day.
            var now = DateTime.Now;
            var past = new DateTime(2010, 5, 22, 23, 0, 0);
            var dateString = "10/1/2022 10:30:30 AM";
            var future = DateTime.Parse(dateString,
                System.Globalization.CultureInfo.InvariantCulture);
            Console.WriteLine(now);
            Console.WriteLine(past);
            Console.WriteLine(future);
            Console.WriteLine(past.ToString("dd/MM/yyyy"));
            Console.WriteLine(now.ToString("F", new System.Globalization.CultureInfo("de-DE")));
            Console.WriteLine(future.ToString("F", new System.Globalization.CultureInfo("sq-AL")));
        }

        private static void TestHashSet()
        {
            void PrintHashSet(HashSet<int> hashSet)
            {
                foreach (var nr in hashSet)
                {
                    Console.Write($"{nr} ");
                }

                Console.WriteLine();
            }

            HashSet<int> numbers = new HashSet<int>();
            int i = 0;
            while (i++ <= 10)
            {
                numbers.Add(i);
            }
            numbers.Add(1);
            if (numbers.Contains(11)) Console.WriteLine("Found 11 in the hash set");
            if (numbers.Remove(0)) Console.WriteLine("Removed 0 from the hash set");
            // lets try to remove all even numbers with one line
            int removedEven = numbers.RemoveWhere(IsEven);
            Console.WriteLine($"Removed {removedEven} even numbers from hash set");
            PrintHashSet(numbers);
            // UnionWith modifies the current hash set object to contain all elements that are present in itself,
            // the specified collection or both
            var evenNumbers = new HashSet<int>();
            for (int j = 1; j <= 5; j++)
            {
                evenNumbers.Add(j * 2);
            }
            Console.WriteLine("Even numbers are");
            PrintHashSet(evenNumbers);
            numbers.UnionWith(evenNumbers);
            Console.WriteLine("After union");
            PrintHashSet(numbers);
            // IntersectWith modifies the current hash set object to contain only elements that are present in that
            // object and in the specified collection
            numbers.IntersectWith(evenNumbers);
            Console.WriteLine("After intersect");
            PrintHashSet(numbers);
            // ExceptWith removes all elements in the specified collection from the current object
            numbers.ExceptWith(evenNumbers);
            Console.WriteLine("After ExceptWith");
            PrintHashSet(numbers);
        }

        private static bool IsEven(int nr)
        {
            return nr % 2 == 0;
        }
        

        private static void TestDictionary()
        {
            var dict = new Dictionary<string, string>();
            Console.WriteLine("Enter id name and age separated by comma");
            var data = Console.ReadLine()?.Split(',');
            if (data?.Length != 3)
            {
                Console.WriteLine("Wrong input values");
                Environment.Exit(1);
            }
            dict.Add("id", data[0].Trim());
            dict.Add("name", data[1].Trim());
            dict.Add("age", data[2].Trim());
            if (!dict.ContainsKey("nationality"))
            {
                Console.Write("Enter your nationality: ");
                dict.Add("nationality", Console.ReadLine());
            }

            dict.Remove("age");
            foreach (KeyValuePair<string, string> kvp in dict)
            {
                Console.WriteLine($"Key: {kvp.Key}, Value: {kvp.Value}");
            }
            Console.WriteLine($"Your nationality is {dict["nationality"]}");
            // we know for sure we do not have a key named 'age', let us try to get age from dict
            string age;
            // the out keyword causes arguments to be passed by reference
            if (dict.TryGetValue("age", out age)) Console.WriteLine($"Age is {age}");
            else Console.WriteLine("There is no key age in the dictionary");
        }

        private static void HelloWorld(int argsLength)
        {
            Console.WriteLine("Hello C#");
            Console.WriteLine($"Nr of arguments is {argsLength}");
            string input = Console.ReadLine();
            int nr = int.Parse(input ?? "0");
            Console.WriteLine($"Input is {nr}");
        }

        private static void TestNumbers()
        {
            int max = int.MaxValue;
            var min = int.MinValue;
            int what = max + 2;
            Console.WriteLine($"Range of integers is {min} to {max}");
            if (what == min + 1)
            {
                Console.WriteLine($"what = {what}");
            }

            double doubleMax = double.MaxValue;
            double doubleMin = Double.MinValue;
            Console.WriteLine($"Range of double type is {doubleMin} to {doubleMax}");
            decimal decimalMax = decimal.MaxValue;
            decimal decimalMin = Decimal.MinValue;
            Console.WriteLine($"Range of decimal type is {decimalMin} to {decimalMax}");
            // decimal type has a smaller range but greater precision
            double a = 1.0;
            double b = 3.0;
            Console.WriteLine(a/b);
            var c = 1.0M;
            var d = 3.0M;
            Console.WriteLine(c/d);
            Console.WriteLine($"Area of circle with radius 2.50 cm is {Math.PI * Math.Pow(2.5, 2)}");
        }

        private static void DataCollections()
        {
            var sports = new List<string> {"football", "basketball", "volleyball", "rugby"};
            int i = 0;
            while (i++ < 3)
            {
                Console.Write("Enter a sport: ");
                string newSport = Console.ReadLine();
                if (!sports.Contains(newSport))
                    sports.Add(newSport);
            }
            Console.WriteLine($"Total number of sports is {sports.Count}");
            // sort them alphabetically
            sports.Sort();
            foreach (string sport in sports) Console.Write($"{sport.ToUpper()} ");
            Console.WriteLine();
            Console.Write("Search for a sport: ");
            int index = sports.IndexOf(Console.ReadLine());
            Console.WriteLine(index != -1 ? $"{sports[index]} found at index {index}" : "Not found!");
            int[] numbers = {1, 2, 3, 4};
            for (int j = 0; j < numbers.Length; j++)
            {
                numbers[j] *= numbers[j];
            }

            foreach (var number in numbers)
            {
                Console.Write($"{number} ");
            }
        }
    }
}