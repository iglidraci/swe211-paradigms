{-
The maximum faction recursively
Max is either head or max of tail
-}

maximum' :: Ord a => [a] -> a
maximum' [] = error "empty list"
maximum' (x:[]) = x
maximum' (x:xs)
    | x > maxTail = x
    | otherwise = maxTail
    where maxTail = maximum' xs


{-
replicate takes an Int and some element and returns a list
that has several repetitions of the same element.
-}
replicate' :: Int -> a -> [a]
replicate' n x
    | n <= 0 = []
    | otherwise = x:replicate' (n-1) x

{-
Function take. It takes a certain number of elements from a list
-}

take' :: Int -> [a] -> [a]
take' n _
    | n <= 0 = []
take' _ [] = []
take' n (x:xs) = x : take' (n-1) xs

-- reverse
reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x]

-- repeat
repeat' :: a -> [a]
repeat' x = x : repeat' x

-- zip
zip' :: [a] -> [b] -> [(a, b)]
zip' _ [] = []
zip' [] _ = []
zip' (x:xs) (y:ys) = (x, y) : zip' xs ys

-- elem
elem' :: Eq a => a -> [a] -> Bool
elem' a [] = False
elem' a (x:xs)
    | a == x = True
    | otherwise = elem' a xs


-- quicksort
quicksort :: Ord a => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = 
    let smallerThan = quicksort [a | a <- xs, a <= x]
        biggerThan = quicksort [a | a <- xs, a > x]
    in smallerThan ++ [x] ++ biggerThan