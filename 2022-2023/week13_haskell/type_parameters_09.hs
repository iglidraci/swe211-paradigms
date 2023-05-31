{-
A value constructor can take some values parameters and then produce a new value.
In a similar manner, type constructors can take types as parameters to produce new types.

data Maybe a = Nothing | Just a
No value can have a type of just Maybe, because that's not a type per se,
it's a type constructor.
Maybe Int, Maybe Car, Maybe String

ghci> Just "Hello"
Just "Hello"
ghci> Just 84
Just 84
ghci> :t Just "Hello"
Just "Hello" :: Maybe String
ghci> :t Nothing
Nothing :: Maybe a
-}

data Car a b = Car { company :: a  
                     , model :: b  
                     , year :: Int   
                     } deriving (Show)

-- Don't do: data (Ord k) => Map k v = ...

-- Let's implement a 3D vector
data Vector a = Vector a a a deriving (Show)

vplus :: Num t => Vector t -> Vector t -> Vector t
(Vector x1 y1 z1) `vplus` (Vector x2 y2 z2) = Vector (x1+x2) (y1+y2) (z1+z2)

vMult :: Num t => Vector t -> t -> Vector t
(Vector x y z) `vMult` a = Vector (x*a) (y*a) (z*a)

vScalarMult :: Num t => Vector t -> Vector t -> t
(Vector x1 y1 z1) `vScalarMult` (Vector x2 y2 z2) = x1*x2 + y1*y2 + z1*z2
{-
ghci> Vector 3 5 8 `vplus` Vector 9 2 8
Vector 12 7 16
ghci> Vector 3 5 8 `vplus` Vector 9 2 8 `vplus` Vector 0 2 3
Vector 12 9 19
ghci> Vector 3 9 7 `vMult` 10
Vector 30 90 70
ghci> Vector 4 9 5 `vScalarMult` Vector 9.0 2.0 4.0
74.0
-}