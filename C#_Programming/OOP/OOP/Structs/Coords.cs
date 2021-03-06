namespace OOP.Structs
{
    public struct Coords
    {
        public Coords(double x, double y)
        {
            X = x;
            Y = y;
        }

        public double X { get; set; }
        public double Y { get; set; }

        public override string ToString() => $"({X}, {Y})";
    }
}