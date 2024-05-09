{-
Folds are functions that reduce a list to a single value
A fold takes a binary function, a starting value (or accumulator) and a list.
The binary function is called with the starting value (or accumulator) and
the first (or last) element of the list and produces another starting value.
-}

{-
foldl aka the left fold
It folds the list up from the left side
The binary function is applied between the starting value and the head of the list.
-}

-- sum function
sum' :: Num a => [a] -> a
sum' xs = foldl (\acc x -> acc + x) 0 xs
-- \acc x -> acc + x is the binary function
-- 0 is the starting value
-- xs is the list to be folded up

-- shorter implementation sum' = foldl (+) 0
-- Why does this work?

elem' :: Eq a => a -> [a] -> Bool
elem' y ys = foldl (\acc x -> if x == y then True else acc) False ys

{-
foldr aka the right fold
Works in similar way to left fold.
The accumulator consumes values from the right
The right fold's binary function has the current value as the first parameter 
and the accumulator as the second one (so \x acc -> ...)
-}
map' :: (a -> b) -> [a] -> [b]
map' f xs = foldr (\x acc -> f x : acc) [] xs

{-
The foldl1 and foldr1 functions work much like foldl and foldr but
you don't need to provide them with an explicit starting value.
They assume the first (or last) element of the list to be the starting value
sum = foldl1 (+)
-}
maximum' :: (Ord a) => [a] -> a  
maximum' = foldr1 (\x acc -> if x > acc then x else acc)