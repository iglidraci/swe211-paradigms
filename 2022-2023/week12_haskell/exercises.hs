applyTimes :: (Eq a, Num a) => a -> (b -> b) -> b -> b
applyTimes 0 _ x = x
applyTimes n f b = f (applyTimes (n-1) f b)

incTimes :: (Eq a, Num a) => a -> a -> a
incTimes times n = applyTimes times (+1) n


mult :: Integral a => a -> a -> a
mult 0 _ = 0
mult _ 0 = 0
mult x y
    | y < 0 = - mult x (-y)
    | otherwise = x + mult x (y-1)


mc91 :: Integral a => a -> a
mc91 n
    | n > 100 = n - 10
    | otherwise = applyTimes 2 mc91 (n + 11)


myAnd :: [Bool] -> Bool
myAnd = foldr (&&) True

myAny :: (a -> Bool) -> [a] -> Bool
myAny _ [] = False
myAny f (x:xs)
    | f x = True
    | otherwise = myAny f xs


myFilter :: (a -> Bool) -> [a] -> [a]
myFilter f xs = foldr (\x acc -> if f x then x:acc else acc) [] xs


squish :: [[a]] -> [a]
squish [] = []
squish (x:xs) = x ++ squish xs

foldr' :: (a -> b -> b) -> b -> [a] -> b
foldr' f acc [] = acc
foldr' f acc (x:xs) = f x (foldr f acc xs)


foldl' :: (b -> a -> b) -> b -> [a] -> b
foldl' f acc [] = acc
foldl' f acc (x:xs) = foldl f (f acc x) xs
