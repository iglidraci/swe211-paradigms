-- right triangle that has integers for all sides and all sides equal to or smaller 
-- than 10 and perimeter of 24

rightTriangles = [ (a,b,c) | c <- [1..10], b <- [1..10], a <- [1..10], a^2 + b^2 == c^2, a+b+c == 24]