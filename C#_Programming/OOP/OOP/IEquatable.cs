using System;

namespace OOP
{
    public interface IEquatable<T>
    {
        bool IsEqual(T other);
    }
}