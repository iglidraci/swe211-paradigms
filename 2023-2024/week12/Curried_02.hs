multThree :: Num a => a -> a -> a -> a
multThree x y z = x * y * z
-- multThree 3 5 9 same as ((multThree 3) 5) 9

compareHundredTo :: (Num a, Ord a) => a -> Ordering
compareHundredTo = compare 100

-- infix operators can be partially applied
compareToHundred :: (Num a, Ord a) => a -> Ordering
compareToHundred = (`compare` 100)

-- A function that checks if a character supplied to it is an uppercase letter
isUpperAlphaNum :: Char -> Bool
isUpperAlphaNum = (`elem` ['A' .. 'Z'])