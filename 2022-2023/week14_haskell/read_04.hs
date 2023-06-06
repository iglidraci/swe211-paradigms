import Data.Char

main = do
    contents <- getContents
    putStrLn $ map toUpper contents

{-
getContents is an I/O action that reads everything from the standard input until it
encounters an end-of-file character.
-}