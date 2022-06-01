# wrap-process-unwrap pattern
# unwrap(process(wrap(structure)))
years = [(2000, 29.87), (2001, 30.12), (2002, 30.6), (2003, 30.66),(2004, 31.33), 
        (2005, 32.62), (2006, 32.73), (2007, 33.5),
        (2008, 32.84), (2009, 33.02), (2010, 32.92)]
print(max(map(lambda x: (x[0], x), years))[1])
fst = lambda x: x[0]
snd = lambda x: x[1]
print(snd(max(map(lambda x: (x[0], x), years))))