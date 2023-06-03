import System.IO
import System.Directory
import Data.Char
import Data.List

main = removeTodo


{-
openFile :: FilePath -> IOMode -> IO Handle
type FilePath = String
data IOMode = ReadMode | WriteMode | AppendMode | ReadWriteMode  
-}
readPoem :: IO ()
readPoem = do
    handle <- openFile "quote.txt" ReadMode
    contents <- hGetContents handle
    putStr $ contents ++ "\n"
    hClose handle


{-
withFile :: FilePath -> IOMode -> (Handle -> IO a) -> IO a
-}
readPoem' :: IO ()
readPoem' = do
    withFile "quote.txt" ReadMode (\h -> do
        contents <- hGetContents h
        putStr $ contents ++ "\n")

-- let's make our own withFile function
withFile' :: FilePath -> IOMode -> (Handle -> IO a) -> IO a
withFile' path mode func = do
    handle <- openFile path mode
    result <- func handle
    hClose handle
    return result


readPoem'' :: IO ()
readPoem'' = do
    contents <- readFile "quote.txt"
    putStrLn contents


{-
writeFile :: FilePath -> String -> IO ()
If the file exists, it will be overwritten
-}
writePoem :: IO ()
writePoem = do
    contents <- readFile "quote.txt"
    writeFile "quote_capitalized.txt" $ map toUpper contents


writeTODOs :: IO ()
writeTODOs = do
    todoItem <- getLine
    appendFile "todo.txt" $ todoItem ++ "\n"


-- program for removing an item from todo list
removeTodo :: IO ()
removeTodo = do
    handle <- openFile "todo.txt" ReadMode
    (tempName, tempHandle) <- openTempFile "." "temp"
    contents <- hGetContents handle
    let
        todoTasks = lines contents
        numberedTasks = zipWith (\n todo -> show n ++ " - " ++ todo) [1..] todoTasks
    putStrLn "These are your TODO items:"
    putStrLn $ unlines numberedTasks
    putStrLn "Which one do you want to delete?"
    nrStr <- getLine
    let
        nr = read nrStr
        newTodoItems = delete (todoTasks !! (nr - 1)) todoTasks
    hPutStr tempHandle $ unlines newTodoItems
    hClose handle
    hClose tempHandle
    removeFile "todo.txt"
    renameFile tempName "todo.txt"