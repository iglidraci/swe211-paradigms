import qualified Data.Set as Set

-- We have two strings
-- We want to find out which characters were used in both of them

common :: String -> String -> Set.Set Char
common s1 s2 = Set.intersection (Set.fromList s1) (Set.fromList s2)

{-
intersection function returns elements both sets share

difference function reports which letters are in the first set but aren't in the second one

union returns all the unique elements in both sets

The null, size, member, empty, insert and delete functions all work like you'd expect them to
-}

removeDuplicates :: Ord a => [a] -> [a]
removeDuplicates = Set.toList . Set.fromList