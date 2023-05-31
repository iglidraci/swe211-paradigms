{-
This is how Eq class is defined
class Eq a where  
    (==) :: a -> a -> Bool  
    (/=) :: a -> a -> Bool  
    x == y = not (x /= y)  
    x /= y = not (x == y)


a is the type variable and it means that a will play the role of the type that we will soon
be making an instance of Eq.
It's not mandatory to implement the function bodies themselves
-}

-- let's make types instances of this class

data TrafficLight = Red | Yellow | Green 

instance Eq TrafficLight where  
    Red == Red = True  
    Green == Green = True  
    Yellow == Yellow = True  
    _ == _ = False

-- this is the minimal complete definition for the typeclass

instance Show TrafficLight where  
    show Red = "Red light"  
    show Yellow = "Yellow light"
    show Green = "Green light"


-- let's define a typeclass for truthy/falsy values

class YesNo a where  
    yesno :: a -> Bool

-- let's define some instances

instance YesNo Int where  
    yesno 0 = False  
    yesno _ = True

instance YesNo [a] where  
    yesno [] = False
    yesno _ = True

instance YesNo Bool where  
    yesno = id

instance YesNo (Maybe a) where  
    yesno (Just _) = True  
    yesno Nothing = False

instance YesNo TrafficLight where  
    yesno Green = True  
    yesno _ = False


-- Let's make a function that mimics the if statement, but it works with YesNo values.
yesnoIf :: (YesNo y) => y -> a -> a -> a  
yesnoIf val yesResult noResult = if yesno val then yesResult else noResult