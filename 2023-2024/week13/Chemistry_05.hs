module Chemistry
(
    phScale,
    avgAtomicMass
) where

phScale :: Float -> String
phScale hydronium
    | ph <= horriblyAcidic = "all fish die"
    | ph <= overwhelminglyAcidic = "frog eggs, tadpoles, and crayfish die"
    | ph < neutral = "acid"
    | ph == neutral = "distilled water and human blood"
    | otherwise = "alkaline"
    where
        ph = calculatePh hydronium
        neutral = 7
        acidic = 7
        overwhelminglyAcidic = 5.5
        horriblyAcidic = 4.5

-- it is not exported therefore cannot be used outside this file
calculatePh :: Float -> Float 
calculatePh = negate . logBase 10

avgAtomicMass :: Num a => [(a, a)] -> a
avgAtomicMass [] = 0
avgAtomicMass isotopes = sum (map (\(x, y) -> x * y) isotopes)