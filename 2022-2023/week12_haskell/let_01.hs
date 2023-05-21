-- Where bindings are a syntactic construct that let you bind 
-- to variables at the end of a function and the whole function can see them,
-- including all the guards.

-- Let bindings let you bind to variables anywhere and are expressions 
-- themselves, but are very local, so they don't span across guards.

-- cylinder's surface area based on its height and radius
cylinder :: RealFloat a => a -> a -> a
cylinder r h =
    let sideArea = 2 * pi * r * h
        topArea = pi * (r ^ 2)
    in  sideArea + 2 * topArea

-- The names that you define in the let part are accessible 
-- to the expression after the in part.
-- Let bindings are expressions.
-- [let double x = 2 * x in (double 5, 'a')]


-- You can also put let bindings inside list comprehensions
calcPhScales :: [Float] -> [Float]
calcPhScales hs = [ph h | h <- hs, let ph hydronium = negate (logBase 10 hydronium)]
