import math


class Point:
    """
    Represents a point in 2D geometric coordinates
    """

    def __init__(self, x: float = 0, y: float = 0) -> None:
        """
        Initialize the position of a new point. Default is the origin
        :param x: float x-coordinates
        :param y: float y-coordinates
        """
        self.move(x, y)

    def move(self, x: float, y: float) -> None:
        """
        Move your point to a new location
        :param x: float x-coordinates
        :param y: float y-coordinates
        :return: void
        """
        self.x = x
        self.y = y

    def reset(self) -> None:
        """
        Reset the point back to origin
        :return:
        """
        self.move(0, 0)

    def calculate_distance(self, other: "Point") -> float:
        """
        Calculate the Euclidean distance from this point to a second point passed as a parameter
        :param other: Point instance
        :return: float distance
        """
        return math.hypot(self.x - other.x, self.y - other.y)


if __name__ == '__main__':
    p = Point()
    p2 = Point(5, 0)
    print(p.calculate_distance(p2))
    assert p2.calculate_distance(p) == p.calculate_distance(p2)
