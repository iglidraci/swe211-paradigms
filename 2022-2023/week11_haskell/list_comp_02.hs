-- we want a comprehension that replaces each odd number greater than 10 with "BANG!" 
-- and each odd number that's less than 10 with "BOOM!"

boomBang xs = [if x > 10 then "BANG!" else "BOOM!" | x <- xs, odd x]

-- wanted all numbers that are not 13, 15 or 19

-- we can have multiple predicates in list comprehensions
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

-- flatten list of lists

flatten xxs = [x | xs<- xxs, x <- xs]