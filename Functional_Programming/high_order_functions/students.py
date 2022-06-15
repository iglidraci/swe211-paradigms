'''
The weight of the midterm exam is 30%, the weight of the project is 20% and the weight of the final exam is 50%.
Print the list of students sorted according to their average, 
but excluding the students whose final exam score is less than 50 points.
'''


students = [ ("Alice", 90, 100, 85), ("Bob", 100, 80, 90), 
             ("Catherine", 80, 50, 75), ("Daniel", 95, 40, 60),
             ("Elvis", 100, 100, 48), ("Fred", 90, 80, 45),
             ("Juliet",80, 75, 65), ("Kane", 40, 90, 80)]

name = lambda x: x[0]
midterm = lambda x: x[1]
project = lambda x: x[2]
final = lambda x: x[3]
average = lambda x: midterm(x)*0.3 + project(x)*0.2 + final(x)*0.5

filtered = filter(lambda x: final(x) > 50, students)
sorted_avg = sorted(filtered, key=average, reverse=True)
result = list(map(lambda x: f'{name(x)}({average(x)})', sorted_avg))
print(result)
