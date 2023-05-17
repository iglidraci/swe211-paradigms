double x = 2 * x

doubleUs x y = double x + double y

-- if statement in Haskell is an expression
-- else part is mandatory in Haskell
doubleSmallNumber x = if x > 100  
                        then x  
                        else x*2
