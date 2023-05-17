removeNonUppercase :: String -> String
removeNonUppercase st = [c | c <- st, c `elem` ['A' .. 'Z']]

-- function that takes several parameters
addThree :: Int -> Int -> Int -> Int
addThree x y z = x + y + z
