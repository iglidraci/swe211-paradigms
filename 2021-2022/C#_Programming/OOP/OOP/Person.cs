using System;
namespace OOP
{
    public class Person
    {
        public string Name { get; set; }
        public int Id { get; set; }
        private int _age;  // Backing store
        public int Age
        {
            get { return _age;}
            set { _age = _age > 0 ? value : 1; }
        }
        public Person(){}

        public Person(string name, int id, int age)
        {
            Name = name;
            Id = id;
            Age = age;
        }

        public void IntroduceYourself()
        {
            Console.WriteLine($"My name is {Name}, {Age} years old");
        }
    }
}