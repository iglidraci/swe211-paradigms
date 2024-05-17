module Recursive_12 where
{-
A constructor in an algebraic data type can have several fields.
We can make types whose constructors have fields that are of the same type.
3:(4:(5:(6:[])))
Let's implement our own List
-}

-- data List a = Empty | Cons a (List a) deriving (Show, Read, Eq, Ord)

{-
ghci> 5 `Cons` Empty
Cons 5 Empty
ghci> 5 `Cons` (6 `Cons` Empty)
Cons 5 (Cons 6 Empty)
ghci> 
-}

{-
We can define functions to be automatically infix by making them comprised of only special characters.
We can also do the same with constructors.
-}

infixr 5 :-:  
data List a = Empty | a :-: (List a) deriving (Show, Read, Eq, Ord)
{-
A fixity declaration, states how tightly the operator binds and whether it's left-associative or
right-associative. *'s fixity is infixl 7 * and +'s fixity is infixl 6

ghci> 1 :-: 2 :-: 3 :-: Empty
1 :-: (2 :-: (3 :-: Empty))
-}

-- Let's make a function that adds two of our lists together
infixr 5  .++ 
(.++) :: List a -> List a -> List a   
Empty .++ ys = ys  
(x :-: xs) .++ ys = x :-: (xs .++ ys)
{-
ghci> a = 3 :-: 4 :-: 5 :-: Empty
ghci> b = 6 :-: 7 :-: Empty
ghci> a .++ b
3 :-: (4 :-: (5 :-: (6 :-: (7 :-: Empty))))
-}


data BinaryTree a = EmptyTree | Node a (BinaryTree a) (BinaryTree a) deriving (Show, Read, Eq)

-- tree with just one node
singleton :: a -> BinaryTree a  
singleton x = Node x EmptyTree EmptyTree

-- insert in a binary search tree
treeInsert :: (Ord a) => a -> BinaryTree a -> BinaryTree a  
treeInsert x EmptyTree = singleton x  
treeInsert x (Node a left right)  
    | x < a  = Node a (treeInsert x left) right  
    | x > a  = Node a left (treeInsert x right)
    | otherwise = Node a left right

-- search for element in BST

treeElem :: (Ord a) => a -> BinaryTree a -> Bool  
treeElem x EmptyTree = False  
treeElem x (Node a left right)  
    | x == a = True  
    | x < a  = treeElem x left  
    | x > a  = treeElem x right


-- pre-order traversal
preorder :: BinaryTree a -> [a]
preorder EmptyTree = []
preorder (Node x left right) = (x : (preorder left)) ++ (preorder right)

-- inorder traversal of BST
inorder :: BinaryTree a -> [a]
inorder EmptyTree = []
inorder (Node x left right) = (inorder left) ++ [x] ++ (inorder right) 