class Polar:
    def __init__(self, radius: float, theta: float):
        self._radius = radius
        self._theta = theta

    @property
    def radius(self) -> float:
        return self._radius

    @radius.setter
    def radius(self, r) -> None:
        self._radius = r


if __name__ == '__main__':
    p = Polar(160.5, 2)
    print(p.radius)
    p.radius = 180
    print(p.radius)
