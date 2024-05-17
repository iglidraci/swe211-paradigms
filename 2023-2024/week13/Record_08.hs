data Person = Person {
    firstName :: String,
    lastName :: String,
    age :: Int,
    height :: Float,
    favBook :: String
} deriving (Show)

{-
ghci> p = Person {firstName="Winston", lastName="Smith", age=40, height=175.5, favBook="1984"}
ghci> p
Person {firstName = "Winston", lastName = "Smith", age = 40, height = 175.5, favBook = "1984"}
ghci> firstName p
"Winston"
ghci> favBook p
"1984"
-}

tellPerson :: Person -> String
tellPerson (Person {firstName=f, lastName=l, age=a, height=h, favBook=b}) = 
    "This is " ++ f ++ " " ++ l ++ ", " ++ show a ++ " year old, "
    ++ show h ++ " cms tall with " ++ b ++ " favorite book"