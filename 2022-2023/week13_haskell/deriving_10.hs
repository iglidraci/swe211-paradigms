data Person = Person { firstName :: String  
                     , lastName :: String  
                     , age :: Int  
                     } deriving (Eq, Show, Read)

{-
Haskell will see if the value constructors match (there's only one value constructor here
though) and then it will check if all the data contained inside matches by testing each 
pair of fields with ==.

ghci> foo = Person{firstName="Foo", lastName="Bar", age=10}
ghci> baz = Person{firstName="Baz", lastName="Bar", age=12}
ghci> foo == baz
False
ghci> foo == foo
True
ghci> "Foo is:" ++ show foo
"Foo is:Person {firstName = \"Foo\", lastName = \"Bar\", age = 10}"
ghci> read "Person {firstName = \"Foo\", lastName = \"Bar\", age = 10}" :: Person
Person {firstName = "Foo", lastName = "Bar", age = 10}
-}

data Day = Monday | Tuesday | Wednesday | Thursday | Friday | Saturday | Sunday   
           deriving (Eq, Ord, Show, Read, Bounded, Enum)

{-
ghci> Monday `compare` Wednesday
LT
ghci> Monday < Wednesday
True
ghci> minBound :: Day
Monday
ghci> succ Monday
Tuesday
ghci> pred Tuesday
Monday
ghci> [Monday .. Thursday]
[Monday,Tuesday,Wednesday,Thursday]
-}