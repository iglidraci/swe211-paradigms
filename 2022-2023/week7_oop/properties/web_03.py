"""
A common need for custom behavior is caching a value that is difficult to calculate or expensive to look up.
The goal is to store the value locally to avoid repeated calls to the expensive calculation
"""
import time
from typing import Optional
from urllib.request import urlopen


class WebPage:
    def __init__(self, url: str):
        self.url = url
        self._content: Optional[bytes] = None

    @property
    def content(self):
        if not self._content:
            print('retrieving new page')
            with urlopen(self.url) as response:
                self._content = response.read()
        return self._content


if __name__ == '__main__':
    webpage = WebPage("http://www.google.com/")
    now = time.perf_counter()
    content1 = webpage.content
    first_fetch = time.perf_counter() - now
    now = time.perf_counter()
    content2 = webpage.content
    second_fetch = time.perf_counter() - now
    assert content2 == content1, "Problem: Pages were different"
    print(f"Initial Request     {first_fetch:.5f}")
    print(f"Subsequent Requests {second_fetch:.5f}")