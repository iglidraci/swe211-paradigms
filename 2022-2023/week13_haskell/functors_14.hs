import Recursive_12
{-
Functor typeclass if for things that can be mapped over.
This is how Functor typeclass is implemented

class Functor f where  
    fmap :: (a -> b) -> f a -> f b


f is not a concrete type, but a type constructor that takes one type parameter.

map :: (a -> b) -> [a] -> [b]
map is just a fmap that works only on lists.

Here is how a list is instance of Functor typeclass

instance Functor [] where  
    fmap = map


Maybe is a functor

instance Functor Maybe where  
    fmap f (Just x) = Just (f x)  
    fmap f Nothing = Nothing
-}

-- our BST type can be a functor
instance Functor BST where  
    fmap f EmptyTree = EmptyTree  
    fmap f (Node x leftsub rightsub) = Node (f x) (fmap f leftsub) (fmap f rightsub)

{-
ghci> fmap (*4) (foldr treeInsert EmptyTree [5,7,3,2,1,7])
Node 28 (Node 4 EmptyTree (Node 8 EmptyTree (Node 12 EmptyTree (Node 20 EmptyTree EmptyTree)))) EmptyTree
-}

{-
Either a b can also be made a functor

instance Functor (Either a) where  
    fmap f (Right x) = Right (f x)  
    fmap f (Left x) = Left x 
-}