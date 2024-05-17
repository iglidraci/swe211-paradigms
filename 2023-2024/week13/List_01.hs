import Data.List
import qualified Data.Map as M

-- The nub function removes duplicate elements from a list
numUniques :: Eq a => [a] -> Int
numUniques = length . nub

{-
Useful functions from Data.List

intersperse takes an element and a list and then puts that element in between 
each pair of elements in the list
ghci> intersperse '.' "Hello"
"H.e.l.l.o"

transpose transposes a list of lists
ghci> transpose [[1, 2], [3, 4, 5]]
[[1,3],[2,4],[5]]

concat flattens a list of lists into just a list of elements
ghci> concat [[3,4,5],[2,3,4],[2,1,1]]
[3,4,5,2,3,4,2,1,1]

and takes a list of boolean values and returns True only if all the values 
in the list are True
ghci> and $ map (>4) [5,6,7,8]

or returns True if any of the boolean values in a list is True.
ghci> or $ map (>4) [1,2,3]

any and all take a predicate and then check if any or all the elements 
in a list satisfy the predicate.
ghci> all (`elem` ['A'..'Z']) "ABCDa"

iterate takes a function and a starting value. It applies the function
to the starting value, then it applies that function to the result,
then it applies the function to that result again, etc (infinite list).
ghci> take 10 $ iterate (*2) 1

splitAt takes a number and a list. It then splits the list at that many elements,
returning the resulting two lists in a tuple.
ghci> splitAt 2 [2..8]
([2,3],[4,5,6,7,8])

takeWhile takes elements from a list while the predicate holds
ghci> sum $ takeWhile (<10000) $ map (^3) [1..]  
53361

dropWhile is similar, only it drops all the elements while the predicate is true
ghci> dropWhile (<3) [1,2,2,2,3,4,5,4,3,2,1]
[3,4,5,4,3,2,1]

sort simply sorts a list
ghci> sort [8,5,3,2,1,6,4,2]  
[1,2,2,3,4,5,6,8]

group takes a list and groups adjacent elements into sublists if they are equal
ghci> group [1, 1, 2, 2]
[[1,1],[2,2]]
ghci> group [1, 1, 2, 3, 2]
[[1,1],[2],[3],[2]]

isInfixOf searches for a sublist within a list and returns True
ghci> "tom" `isInfixOf` "atoms"
True

isPrefixOf and isSuffixOf search for a sublist at the beginning and at the
end of a list, respectively.
ghci> "at" `isPrefixOf` "atoms"
True
ghci> "oms" `isSuffixOf` "atoms"
True

find takes a predicate and a list and returns the first element 
that satisfies the predicate.

elemIndex maybe returns the index of the element we're looking for.


Guess the result
ghci> sortBy (\x y -> length x `compare` length y) [[5,4,5,4,4],[1,2,3],[3,5,4,3],[],[2],[2,2]]
ghci> sortBy (compare `on` length) [[5,4,5,4,4],[1,2,3],[3,5,4,3],[],[2],[2,2]]
Function `on` is defined as:
on :: (b -> b -> c) -> (a -> b) -> a -> a -> c
f `on` g = \x y -> f (g x) (g y)
-}