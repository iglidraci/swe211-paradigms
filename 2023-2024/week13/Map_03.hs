import qualified Data.Map as Map

-- The most obvious way to represent maps in Haskell would be by having a list of pairs

findKey :: Eq k => k -> [(k, v)] -> v
findKey key dict = (snd . head . filter (\(k, _) ->  key == k)) dict
-- What if a key isn't in the map?

-- Let's use the Maybe data type. If we don't find the key, we'll return a Nothing.
-- If we find it, we'll return Just something.
findKey' :: Eq k => k -> [(k, v)] -> Maybe v
findKey' _ [] = Nothing
findKey' key ((k, v) : xs)
    | key == k = Just v
    | otherwise = findKey' key xs


-- be pragmatic
findKey'' :: Eq k => k -> [(k, v)] -> Maybe v
findKey'' key = foldr (\(k,v) acc -> if k == key then Just v else acc) Nothing


{-
Data.Map module offers much faster maps

The fromList function takes an association list (in the form of a list)
and returns a map with the same associations.
ghci> Map.fromList [("name", "Ishmael"), ("mother", "Hagar")]
fromList [("name","Ishmael"), ("mother","Hagar")]

empty represents an empty map. It takes no arguments, it just returns an empty map

insert takes a key, a value and a map and returns a new map
ghci> Map.insert 3 100 Map.empty
fromList [(3,100)]
-}

-- We are initiated now, we can implement our own fromList
fromList' :: Ord k => [(k, v)] -> Map.Map k v
fromList' = foldr (\ (k, v) acc -> Map.insert k v acc) Map.empty

{-
null checks if a map is empty

size reports the size of a map

lookup returns Just something if it finds something for the key and Nothing if it doesn't

member takes a key and a map and reports whether the key is in the map or not

map and filter work much like their list equivalents
ghci> Map.filter isUpper $ Map.fromList [(1,'a'),(2,'A'),(3,'b'),(4,'B')]  
fromList [(2,'A'),(4,'B')] 

toList is the inverse of fromList

keys and elems return lists of keys and values respectively
-}