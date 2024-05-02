-- calculate ph once, bind it to a name 
-- and then use that name instead of the expression

phScale :: Float -> String
phScale hydronium
    | ph <= 4.5 = "all fish die"
    | ph <= 5.5 = "frog eggs, tadpoles, and crayfish die"
    | ph < 7 = "acid"
    | ph == 7 = "distilled water and human blood"
    | otherwise = "alkaline"
    where
        ph = negate (logBase 10 hydronium) 

-- The names we define in the where section of a function
-- are only visible to that function

-- let's make a function that takes a list of
-- concentration of hydrogen ions and returns a list of ph scales.

calcPhScales :: [Float] -> [Float]
calcPhScales hs = [ph h | h <- hs]
    where
        ph hydronium = negate (logBase 10 hydronium)
