module Chemistry
(
    phScale,
    avgAtomicMass
) where

phScale :: Float -> String
phScale hydronium
    | ph <= 4.5 = "all fish die"
    | ph <= 5.5 = "frog eggs, tadpoles, and crayfish die"
    | ph < 7 = "acid"
    | ph == 7 = "distilled water and human blood"
    | otherwise = "alkaline"
    where
        ph = calculatePh hydronium

-- it is not exported therefore cannot be used outside this file
calculatePh :: Float -> Float 
calculatePh = negate . logBase 10

avgAtomicMass :: Num a => [(a, a)] -> a
avgAtomicMass [] = 0
avgAtomicMass isotopes = sum (map (\(x, y) -> x * y) isotopes)