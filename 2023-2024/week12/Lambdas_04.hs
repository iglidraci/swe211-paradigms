{-
Lambdas are basically anonymous functions
To make a lambda, we write a \  and then we write the parameters, separated by spaces
After that comes a -> and then the function body.
-}

longLists :: [[a]] -> [[a]]
longLists lists = filter (\list -> length list > 5) lists

{-
ME: Can we get a (+3)?
MOM: We have (+3) at home
(+3) AT HOME: (\x -> x + 3)



Guess the result
map (\x -> x + 3) [1,6,3,2]
zipWith (\a b -> a * 2 * b) [5,4,3,2,1] [1,2,3,4,5]
map (\(a,b) -> a + b) [(1,2),(3,5),(6,3),(2,6),(2,5)]
-}