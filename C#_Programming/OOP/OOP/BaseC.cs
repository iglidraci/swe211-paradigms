using System;

namespace OOP
{
    public class BaseC
    {
        public void Invoke() { }
        // virtual keyword: allow for it to be overridden in a derived class
        public virtual void Foo()
        {
            Console.WriteLine("BaseC.Foo");
        }
    }

    public class DerivedC : BaseC
    {
        //  the new keyword explicitly hides a member that is inherited from a base class
        public new void Invoke() {}
        public override void Foo()
        {
            base.Foo();
            Console.WriteLine("DerivedC.Foo");
        }
    }
}