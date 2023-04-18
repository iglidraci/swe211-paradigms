from typing import Dict, Hashable, Any


class NoDuplicateDict(Dict[Hashable, Any]):
    def __setitem__(self, key, value) -> None:
        if key in self:
            raise ValueError(f"duplicate key {key}")
        else:
            super().__setitem__(key, value)


if __name__ == '__main__':
    d = NoDuplicateDict()
    d['id'] = 1
    # d['id'] = 2