import Data.Char

main = do
    putStrLn "What's your name?"
    name <- getLine
    putStrLn "When were you born?"
    year <- getLine
    let
        capitalName = map toUpper name
        age = 2023 - (read year :: Int)
    putStrLn $ capitalName ++ " is " ++ show age ++ " year young"

{-
use <- when you want to bind results of I/O actions to names and you can use let bindings
to bind pure expressions to names.
-}