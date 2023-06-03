main = do
    line <- getLine
    if null line
        then return ()
        else do
            putStrLn $ reverseWords line
            main

reverseWords :: String -> String
reverseWords = unwords . map reverse . words

{-
return makes an I/O action out of a pure value
What's the point of just transforming a pure value into an I/O action that doesn't do anything?
We needed some I/O action to carry out in the case of an empty input line.
return is sort of the opposite to <-
-}