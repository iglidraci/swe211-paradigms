-- guards are a way of testing whether some property 
-- of a value (or several of them) are true or false
phScale :: Float -> String

phScale x
    | x <= 4.3 = "all fish die"
    | x <= 5.5 = "frog eggs, tadpoles, and crayfish die"
    | x < 7 = "acid"
    | x == 7 = "distilled water and human blood"
    | otherwise = "alkaline"

-- otherwise is defined simply as otherwise = True and catches everything
-- If no suitable guards or patterns are found, an error is thrown


-- let's implement our own max function
max' :: Ord a => a -> a -> a
max' x y
    | x > y = x
    | otherwise = y


-- let's implement our own compare by using guards
compare' :: Ord a => a -> a -> Ordering
compare' x y
    | x > y = GT
    | x == y = EQ
    | otherwise = LT