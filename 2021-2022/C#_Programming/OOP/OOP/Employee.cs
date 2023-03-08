namespace OOP
{
    public class Employee : Person, IEquatable<Employee>
    {
        private int _experience;

        public int Experience
        {
            get => _experience;
            set => _experience = value > 0 ? value : 0;
        }
        public Employee() {}

        public Employee(string name, int id, int age, int experience) : base(name, id, age)
        {
            Experience = experience;
        }

        public bool IsEqual(Employee other)
        {
            return Id == other.Id;
        }
    }
}