class BaseClass:
    num_base_calls: int = 0

    def call_me(self) -> None:
        print("Calling method on BaseClass")
        self.num_base_calls += 1


class LeftSubclass(BaseClass):
    num_left_calls: int = 0

    def call_me(self) -> None:
        super().call_me()
        print("Calling method on LeftSubclass")
        self.num_left_calls += 1


class RightSubclass(BaseClass):
    num_right_calls: int = 0

    def call_me(self) -> None:
        super().call_me()
        print("Calling method on RightSubclass")
        self.num_right_calls += 1


class Subclass(LeftSubclass, RightSubclass):
    num_sub_calls: int = 0

    def call_me(self) -> None:
        super().call_me()
        print("Calling method on Subclass")
        self.num_sub_calls += 1


if __name__ == '__main__':
    '''
    Python's Method Resolution Order (MRO) algorithm transforms the diamond into a flat, linear tuple.
    The linear version of this diamond is the sequence Subclass, LeftSubclass, RightSubClass, BaseClass, object.
    With multiple inheritance we want to call the next method in the MRO sequence,
    not necessarily a method of the parent class.
    '''
    s = Subclass()
    s.call_me()
    print(s.num_sub_calls, s.num_left_calls, s.num_right_calls, s.num_base_calls)