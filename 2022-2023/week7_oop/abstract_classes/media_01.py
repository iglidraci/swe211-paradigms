import abc


class MediaLoader(abc.ABC):
    @abc.abstractmethod
    def play(self) -> None:
        ...

    @property
    @abc.abstractmethod
    def ext(self) -> str:
        ...


class Ogg(MediaLoader):
    ext = '.ogg'

    def play(self) -> None:
        pass


if __name__ == '__main__':
    ogg = Ogg()
    