isPalindrome :: Eq a => [a] -> Bool
isPalindrome x = x == reverse x

abs' :: (Ord a, Num a) => a -> a
abs' x = if x >= 0 then x else negate x

initials :: String -> String -> String
initials first last = (head first) : '.' : (head last) : "" 

length' :: Num b => [a] -> b
length' [] = 0
length' (_:xs) = 1 + length' xs


square :: Num a => [a] -> [a]
square xs = [x^2 | x <- xs]

sum' :: Num a => [a] -> a
sum' [] = 0
sum' (x:xs) = x + sum' xs

