{-
An algebraic data type is a structured type that’s formed by composing other types.
Let's see how the Bool type is defined in the standard library
data Bool = False | True
data means that we're defining a new data type
The part before the = denotes the type, which is Bool
The parts after the = are value constructors. They specify the different values that this type can have.
So we can read this as: the Bool type can have a value of True or False.
Both the type name and the value constructors have to be capital cased.
-}

{-
Let's say that a shape can be a circle or a rectangle
-}

data Shape = Circle Float Float Float | Rectangle Float Float Float Float
{-
Value constructors are actually functions that ultimately return a value of a data type
ghci> :t Circle 
Circle :: Float -> Float -> Float -> Shape
-}

surface :: Shape -> Float
surface (Circle _ _ r) = pi * r^2
surface (Rectangle x1 y1 x2 y2) = (abs $ x2 - x1) * (abs $ y2 - y1)

c = Circle 10 20 10
r = Rectangle 0 0 10 10
{-
What do you think will happen if you try to print c in the prompt?
deriving (...)

What's the result?
map (surface . Circle 10 20) [4,5,6,6]
-}