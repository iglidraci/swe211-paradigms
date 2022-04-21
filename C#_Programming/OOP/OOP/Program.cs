using System;

namespace OOP
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Person p1 = new Person("Foo", 1, -4);
            p1.IntroduceYourself();
            Employee e1 = new Employee("Bar", 2, 20, -2);
            Console.WriteLine($"{e1.Name} has {e1.Experience} years of experience");
            if (e1.IsEqual(e1)) Console.WriteLine("Equal");
        }
    }
}