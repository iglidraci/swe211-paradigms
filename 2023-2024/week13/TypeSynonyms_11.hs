import qualified Data.Map as Map

{-
data Either a b = Left a | Right b deriving (Eq, Ord, Read, Show)
So we can use this type to encapsulate a value of one type or another
When we're interested in how some function failed or why, we usually use the result type of Either a b,
where a is some sort of type that can tell us something about the possible failure and b is the type of 
a successful computation.
-}

data LockerState = Taken | Free deriving (Eq)  

-- type synonym, same as: type String = [Char]
type Code = String

-- It'll map from locker numbers to a pair of whether the locker is in use or not and the locker code
type LockerMap = Map.Map Int (LockerState, Code)

{-
We're going to make a function that searches for the code in a locker map.
We're going to use an Either String Code type to represent our result.
Our lookup can fail in two ways — the locker can be taken, in which case we can't tell the code
or the locker number might not exist at all.
-}

lockerLookup :: Int -> LockerMap -> Either String Code  
lockerLookup lockerNumber map = 
    case Map.lookup lockerNumber map of   
        Nothing -> Left $ "Locker number " ++ show lockerNumber ++ " doesn't exist!"  
        Just (Taken, _) -> Left $ "Locker " ++ show lockerNumber ++ " is already taken!"
        Just (Free, code) -> Right code

lockers :: LockerMap  
lockers = Map.fromList   
    [(100,(Taken,"ZD39I"))  
    ,(101,(Free,"JAH3I"))  
    ,(103,(Free,"IQSA9"))  
    ,(105,(Free,"QOTSA"))  
    ,(109,(Taken,"893JJ"))  
    ,(110,(Taken,"99292"))  
    ]

{-
ghci> lockerLookup 101 lockers  
Right "JAH3I"  
ghci> lockerLookup 100 lockers  
Left "Locker 100 is already taken!"  
ghci> lockerLookup 102 lockers  
Left "Locker number 102 doesn't exist!"

We could have used a Maybe a to represent the result but then we wouldn't know why we couldn't get the code.
-}