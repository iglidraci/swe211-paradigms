class Color:
    def __init__(self, rgb: int, name: str) -> None:
        self._rgb = rgb
        if not name:
            raise ValueError("Invalid color name")
        self._name = name

    def _get_name(self):
        return self._name

    def _set_name(self, name: str):
        if not name:
            raise ValueError("Invalid color name")
        self._name = name

    def _del_name(self):
        # delete is very rarely used
        print('deleting name property')
        del self._name

    name = property(_get_name, _set_name, _del_name)

    @staticmethod
    def rgb_to_hex(r, g, b):
        """
        R/16 = x + y/16
        G/16 = x' + y'/16
        B/16 = x" + y"/16
        """
        color = [f'{hex(x//16)[-1].upper()}{hex(x % 16)[-1].upper()}' for x in [r, g, b]]
        return "".join(color)


if __name__ == '__main__':
    c = Color(0xff0000, "bright red")
    print(c.name)
    c.name = 'red'
    print(c.name)
    del c.name
    print(Color.rgb_to_hex(182, 0, 35))
