from pathlib import Path


class AudioFile:
    ext: str

    def __init__(self, filepath: Path) -> None:
        if not filepath.suffix == self.ext:
            raise ValueError("Invalid file format")
        self.filepath = filepath


class MP3File(AudioFile):
    ext = ".mp3"

    def play(self) -> None:
        print(f"playing {self.filepath} as mp3")


class WavFile(AudioFile):
    ext = ".wav"

    def play(self) -> None:
        print(f"playing {self.filepath} as wav")


class OggFile(AudioFile):
    ext = ".ogg"

    def play(self) -> None:
        print(f"playing {self.filepath} as ogg")


if __name__ == '__main__':
    '''
    AudioFile.__init__() can check the file type without actually knowing which subclass it is referring to
    '''
    p1 = MP3File(Path("foo.mp3"))
    p2 = WavFile(Path("bar.wav"))
    p1.play()
    p2.play()
    p3 = OggFile(Path("baz.mp3"))
    p3.play()
