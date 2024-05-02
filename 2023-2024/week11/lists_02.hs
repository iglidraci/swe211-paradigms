{-
ghci> [1,2,3,4] ++ [9,10,11,12]
[1,2,3,4,9,10,11,12]
ghci> "hello" ++ " " ++ "world"
ghci> 5:[1,2,3,4,5]
[5,1,2,3,4,5]
ghci> [1, 2, 3, 4] !! 1
2


Some common list operations

ghci> head [5,4,3,2,1]
5
ghci> head []
*** Exception: Prelude.head: empty list
ghci> tail [5,4,3,2,1]
[4,3,2,1]
ghci> last [5,4,3,2,1]
1 
ghci> init [5,4,3,2,1]
[5,4,3,2]
ghci> length [5,4,3,2,1]
5
ghci> null [1,2,3]
False
ghci> null []
True
ghci> reverse [5,4,3,2,1]
[1,2,3,4,5]
ghci> take 3 [5,4,3,2,1]
[5,4,3]
ghci> take 1 [3,9,3]
[3]
ghci> drop 3 [8,4,2,1,5,6]
[1,5,6]
ghci> drop 100 [1,2,3,4]
[]
ghci> minimum [8,4,2,1,5,6]
1
ghci> maximum [1,9,2,3,4]
9
ghci> sum [5,2,1,6,3,2,5,7]
31
ghci> product [6,2,1,2]
24
ghci> 4 `elem` [3,4,5,6]
True
ghci> [1..20]
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
ghci> ['a'..'z']
"abcdefghijklmnopqrstuvwxyz"
ghci> [2,4..20]
[2,4,6,8,10,12,14,16,18,20]
ghci> take 24 [13,26..]
ghci> take 10 (cycle [1,2,3])
[1,2,3,1,2,3,1,2,3,1]
-}

-- we want a comprehension that replaces each odd number greater than 10 with "BANG!" 
-- and each odd number that's less than 10 with "BOOM!"

boomBang xs = [if x > 10 then "BANG!" else "BOOM!" | x <- xs, odd x]

-- wanted all numbers that are not 13, 15 or 19

-- we can have multiple predicates in list comprehensions, you have to pass all predicates
notSomeNumbers xs = [x | x <- xs, x /= 13, x /= 15, x /= 19]

-- We can also draw from several lists
-- When drawing from several lists, comprehensions produce all combinations of the given lists 
-- and then join them by the output function we supply.

-- products of all the possible combinations between numbers in those lists
allProducts xs ys = [x * y | x <- xs, y <- ys]
-- more than 50
allProductsMore50 xs ys = [x * y | x <- xs, y <- ys, x * y >= 50]

-- combine a list of adjectives and nouns
combine adjectives nouns = [adjective ++ " " ++ noun | adjective <- adjectives, noun <- nouns]

-- our own version of length!
length' xs = sum [1 | _ <- xs]

-- function that takes a string and removes everything except uppercase letters from it
removeNonUpperCase st = [c | c <- st, c `elem` ['A' .. 'Z']]

-- Nested list comprehensions are also possible if you're operating on lists that contain lists
-- remove all odd numbers without flattening the list

removeOdd xxs = [ [x | x <- xs, even x] | xs <- xxs]