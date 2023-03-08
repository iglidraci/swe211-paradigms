from funcs import my_map, my_reduce

'''
https://crocoder.dev/blog/map-filter-reduce-exercises/
Devs like to abbreviate everything: k8s means Kubernetes, 
a11y means accessibility, l10n means localization. 
You get the Dev numeronyms by taking the first and the last letter and counting the number of letters 
in between. Words that have less than 4 letters aren't abbreviated, because that would just be odd.
The input is a sentence, and you should abbreviate every word that is 4 letters long or longer.
There won't be any punctuation in the sentence. g2d l2k e6e
'''

first = lambda x: x[0]
last = lambda x: x[-1]


def numeronyms(s: str) -> str:
    words = s.split(' ')
    mapped = my_map(words, lambda x: f'{first(x)}{len(x[1:-1])}{last(x)}' if len(x) > 4 else x)
    return my_reduce(mapped, lambda x, y: f'{x} {y}')


inp = 'Every developer likes to mix kubernetes and javascript'
result = numeronyms(inp)
assert result == 'E3y d7r l3s to mix k8s and j8t'
print(result)