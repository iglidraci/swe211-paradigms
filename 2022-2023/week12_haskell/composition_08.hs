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
-- fn x = ceiling (negate (tan (cos (max 50 x))))