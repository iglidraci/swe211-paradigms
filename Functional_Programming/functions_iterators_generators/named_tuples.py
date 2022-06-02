from collections import namedtuple

white_color = (255, 255, 255, "white")

red = lambda x: x[0]
green = lambda x: x[1]
blue = lambda x: x[2]

print(red(white_color))

Color = namedtuple("Color", ("red", "green", "blue", "name"))

white = Color(255, 255, 255, "white")
black = Color(0, 0, 0, "black")
print(white.red, white.green, white.blue)