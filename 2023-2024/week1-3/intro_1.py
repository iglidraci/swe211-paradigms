earth_is_flat = False

if earth_is_flat:
    print("be careful not to fall off!")
else:
    name = input("enter your name: ")
    lat = float(input("enter your latitude: "))
    if lat > 90 or lat < -90:
        print("incorrect latitude")
    else:
        print(type(name))
        print(type(lat))
        hemisphere = "northern" if lat > 0 else "southern"
        print(f'{name} lives in the {hemisphere} hemisphere')
