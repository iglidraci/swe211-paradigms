{-
High-order functions are functions that take functions as parameters
or return functions as return values
-}

-- a function that takes a function and applies it twice to something
applyTwice :: (a -> a) -> a -> a
applyTwice f x = f (f x)
{-
Guess the result
applyTwice (+3) 10
applyTwice (2^) 3
applyTwice (3:) [1]
-}

{-
zipWith
It takes a function and two lists as parameters and then joins the two lists 
by applying the function between corresponding elements 
-}

zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (x:xs) (y:ys) = (f x y) : zipWith' f xs ys

{-
Guess the result
zipWith' (+) [4,2,5,6] [2,6,2,3]
zipWith' (*) (replicate 5 2) [1..]
zipWith' (zipWith' (*)) [[1,2,3],[3,5,6],[2,3,4]] [[3,2,2],[3,4,5],[5,4,3]]
-}


{-
map
takes a function and a list and applies that function to every element in the list
Let's see what its type signature is and how it's defined.
map :: (a -> b) -> [a] -> [b]  
map _ [] = []  
map f (x:xs) = f x : map f xs

Guess the result
map (+3) [1,5,3,1,6]
map (replicate 3) [3..6]
map (map (^2)) [[1,2],[3,4,5,6],[7,8]]
-}

{-
filter
takes a predicate and a list and then returns the list of elements that satisfy the predicate
filter :: (a -> Bool) -> [a] -> [a]  
filter _ [] = []  
filter p (x:xs)   
    | p x       = x : filter p xs  
    | otherwise = filter p xs

Guess the result
filter (>3) [1,5,3,2,1,6,4,3,2,1]
filter even [1..10]
-}


-- Let's find the largest number under 100,000 that's divisible by 3829
largestDivisible :: Integral a => a
largestDivisible = head (filter pred [100000, 99999 ..])
    where pred x = x `mod` 3829 == 0


{-
sum of all odd squares that are smaller than 10,000
takeWhile function takes a predicate and a list and then goes from the beginning 
of the list and returns its elements while the predicate holds true.
sum (takeWhile (<10000) (filter odd (map (^2) [1..])))
-}

{-
Collatz sequence
We take a natural number.
If that number is even, we divide it by two.
If it's odd, we multiply it by 3 and then add 1 to that.
We take the resulting number and apply the same thing to it.
It is thought that for all starting numbers, the chains finish at the number 1.
Starting number 13, we get this sequence: 13, 40, 20, 10, 5, 16, 8, 4, 2, 1
-}
collatzChain :: Integral a => a -> [a]
collatzChain 1 = [1]
collatzChain n
    | even n = n : collatzChain (n `div` 2)
    | otherwise = n : collatzChain (n*3 + 1)

-- for all starting numbers between 1 and 100, 
-- how many chains have a length greater than 15?
numLongChains :: Int
numLongChains = length (filter isLong (map collatzChain [1..100]))
    where isLong chain = (length chain) > 15


{-
Guess the output
listOfFuncs = map (*) [0..]
(listOfFuncs !! 4) 5
-}