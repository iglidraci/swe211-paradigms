data Person = Person {
    firstName :: String,
    lastName :: String,
    age :: Int,
    height :: Float,
    phoneNumber :: String
} deriving (Show)

{-
ghci> p = Person {firstName="Foo", lastName="Bar", age=10, height=175.5, phoneNumber="0055-6666"}
ghci> p
Person {firstName = "Foo", lastName = "Bar", age = 10, height = 175.5, phoneNumber = "0055-6666"}
ghci> firstName p
"Foo"
ghci> lastName p
"Bar"
-}

tellPerson :: Person -> String
tellPerson (Person {firstName=f, lastName=l, age=a, height=h, phoneNumber=p}) = 
    "This is " ++ f ++ " " ++ l ++ ", " ++ show a ++ " year old, "
    ++ show h ++ " cms tall with phone number " ++ p