{-
case expression of pattern -> result  
                   pattern -> result  
                   pattern -> result 
-}

head' :: [a] -> a
head' xs = case xs of
    [] -> error "List is empty!"
    (x:_) -> x


count :: (Eq a, Num a) => a -> String
count x = case x of
    1 -> "One"
    2 -> "Two"
    3 -> "Three"
    _ -> "Anything else from 1 to 3"
