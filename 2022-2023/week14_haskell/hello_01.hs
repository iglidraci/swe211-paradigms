main = do
    putStrLn "Hello, what's your name?"
    name <- getLine
    putStrLn $ "What's up " ++ name ++ "?"

{-
ghci> :t putStrLn
putStrLn :: String -> IO ()
ghci> :t getLine
getLine :: IO String
-}

{-
Each of these steps is an I/O action.
By putting them together with do syntax, we glued them into one I/O action.
The action that we got has a type of IO (), because that's the type of the last
I/O action inside.
The last action in a do block, cannot be bound to a name

How do you read name <- getLine?
perform the I/O action getLine and then bind its result value to name

Is it valid?
nameTag = "Hello, my name is " ++ getLine
-}