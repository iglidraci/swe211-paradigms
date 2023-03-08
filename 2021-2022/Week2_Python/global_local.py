def foo():
    print(f"hello {name}")


# is defined as global but can be used inside the function
# todo what if we initialize a variable with the same name inside the function?
# todo what if we try to assign the global variable inside the function?
# global keyword will tell python that we want to change the global variable
name = 'Bar'
foo()
print(name)