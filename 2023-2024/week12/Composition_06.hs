{-
Function application with $
function application with $ is right-associative
sum (map sqrt [1..130]) can be rewritten as sum $ map sqrt [1..130]
You can imagine a $ being sort of the equivalent of writing an opening parentheses
and then writing a closing one on the far right side of the expression

Guess the result
sum $ filter (> 10) $ map (*2) [2..10]
-}

{-
Function composition as in mathematics (f o g)(x) = f(g(x))
In Haskell we do function composition with the . function
(.) :: (b -> c) -> (a -> b) -> a -> c  
f . g = \x -> f (g x)

Guess the output
(negate . (* 3)) 3
map (negate . abs) [5,-3,-6,7,-3,2,-19,24]
map (negate . sum . tail) [[1..5],[3..6],[1..7]]
-}

fn = ceiling . negate . tan . cos . max 50