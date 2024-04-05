from abc import ABC, abstractmethod


class MediaLoader(ABC):
    @abstractmethod
    def play(self) -> None:
        pass

    @property
    @abstractmethod
    def ext(self) -> str:
        pass


class Ogg(MediaLoader):
    ext = '.ogg'

    def play(self) -> None:
        pass


if __name__ == '__main__':
    ogg = Ogg()
