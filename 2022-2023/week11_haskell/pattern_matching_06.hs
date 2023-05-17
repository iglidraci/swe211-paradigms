-- Pattern matching consists of specifying patterns to which some data should conform 
-- and then checking to see if it does and deconstructing the data according to those patterns


count :: Integral a => a -> String
count 1 = "One"
count 2 = "Two"
count 3 = "Three"
count x = "Not between one and three"
-- the patterns will be checked from top to bottom

-- factorial recursively
factorial :: Integral a => a -> a
factorial 0 = 1
factorial n = n * factorial (pred n)

-- Pattern matching can also fail
-- Always include a catch-all pattern
capitalOf :: String -> String
capitalOf "Albania" = "Tirana"
capitalOf "Greece" = "Athens"
-- if we call capitalOf "Germany" you will get a "Non-exhaustive patterns" error


-- Add together two vectors.
addVectors :: Num a => (a, a) -> (a, a) -> (a, a)
addVectors x y = (fst x + fst y, snd x + snd y)

-- let's use pattern matching
addVectors' :: Num a => (a, a) -> (a, a) -> (a, a)
addVectors' (x1, y1) (x2, y2) = (x1 + x2, y1 + y2)

-- extract from triples
first :: (a, b, c) -> a
first (x, _, _) = x

second :: (a, b, c) -> b
second (_, y, _) = y

third :: (a, b, c) -> c
third (_, _, z) = z

-- Lists can also be used in pattern matching as x:xs
-- it will match only against lists of length 1 or more

head' :: [a] -> a
head' [] = error "List is empty!"
head' (x:xs) = x
-- error function will raise a runtime error


-- let's build a function to describe a list

tell :: Show a => [a] -> String
tell [] = "List is empty"
tell (x:[]) = "List has one element only: " ++ show x
tell (x:y:[]) = "List has two elements: " ++ show x ++ " and " ++ show y
tell (x:y:_) = "List is long. The first two elements are " ++ show x ++ " and " ++ show y
