import Data.Char
{-
Data.Char exports a bunch of predicates over characters.

isLower checks whether a character is lower-cased.

isUpper checks whether a character is upper-cased.

isAlpha checks whether a character is a letter.

isAlphaNum checks whether a character is a letter or a number.

isDigit checks whether a character is a digit.

isLetter checks whether a character is a letter.
-}

allAlphaNum :: String -> Bool

allAlphaNum = all isAlphaNum

{-
toUpper converts a character to upper-case.

toLower converts a character to lower-case.

The ord and chr functions convert characters to their corresponding numbers
and vice versa.
ghci> ord 'a'
97
ghci> chr 97
'a'
-}

-- The Caesar cipher 
encode :: Int -> String -> String
encode shift = map (chr . (+shift) . ord)

decode :: Int -> String -> String
decode shift = encode (negate shift)