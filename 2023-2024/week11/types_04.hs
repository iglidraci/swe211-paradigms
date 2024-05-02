{-
ghci> :t 'a'
'a' :: Char
ghci> :t True
True :: Bool
ghci> :t "HELLO!"
"HELLO!" :: String
ghci> :t (True, 'a')
(True, 'a') :: (Bool, Char)
ghci> :t 4 == 5
4 == 5 :: Bool
-}

removeNonUppercase :: String -> String
removeNonUppercase st = [c | c <- st, c `elem` ['A' .. 'Z']]

-- function that takes several parameters
addThree :: Int -> (Int -> (Int -> Int))
addThree x y z = x + y + z

factorial :: Integer -> Integer
factorial n = product [1 .. n]

circumference :: Float -> Float  
circumference r = 2 * pi * r

circumference' :: Double -> Double  
circumference' r = 2 * pi * r


{-
ghci> :t head
head :: [a] -> a
a is a type variable. It can be of any type, like generics in Java.
ghci> :t fst
fst :: (a, b) -> a


A typeclass is a sort of interface that defines some behavior.
If a type is a part of a typeclass,
that means that it supports and implements the behavior the typeclass describes.

ghci> :t (==)
(==) :: (Eq a) => a -> a -> Bool
Everything before the => symbol is called a class constraint.
We can read the previous type declaration like this: the equality function takes any two values that are of the 
same type and returns a Bool. The type of those two values must be a member of the Eq class.

Some basic typeclasses:
Eq is used for types that support equality testing.
Ord is for types that have an ordering.
ghci> :t (>)
(>) :: (Ord a) => a -> a -> Bool
Members of Show can be presented as strings. 
Read is sort of the opposite typeclass of Show.
The read function takes a string and returns a type which is a member of Read.
ghci> read "True" || False
True
ghci> read "8.2" + 3.8
12.0
ghci> read "5" - 2
3
ghci> read "[1,2,3,4]" ++ [3]
[1,2,3,4,3]
ghci> read "5" :: Int
5
ghci> read "5" :: Float
5.0
ghci> read "[1,2,3,4]" :: [Int]
[1,2,3,4]
ghci> read "(3, 'a')" :: (Int, Char)
(3, 'a')
Num is a numeric typeclass. Its members have the property of being able to act like numbers.
Let's examine the type of a number.
ghci> :t 1
1 :: (Num t) => t
ghci> :t (*)
(*) :: (Num a) => a -> a -> a
Integral is also a numeric typeclass. In this typeclass are Int and Integer.
Floating includes only floating point numbers, so Float and Double.
-}