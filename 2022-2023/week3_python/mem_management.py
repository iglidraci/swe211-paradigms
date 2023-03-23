import sys

b = list()

ref_count = sys.getrefcount(b)

print(ref_count)

b.append(b)

ref_count = sys.getrefcount(b)

print(ref_count)

