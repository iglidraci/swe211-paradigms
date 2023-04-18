class ContactList(list["Contact"]):
    def search(self, name: str) -> list["Contact"]:
        matching_contacts: list["Contact"] = []
        for contact in self:
            if name in contact.name:
                matching_contacts.append(contact)
        return matching_contacts


class Contact:
    # class variable, shared by all instances of the class
    all_contacts: ContactList = ContactList()

    def __init__(self, name: str, email: str) -> None:
        self.name = name
        self.email = email
        Contact.all_contacts.append(self)

    def __repr__(self) -> str:
        return f"{self.__class__.__name__} ({self.name}, {self.email})"


class Supplier(Contact):
    def order(self, order: "Order") -> None:
        print(f"Send order to {self.name}")


class Order:
    pass


class Friend(Contact):

    def __init__(self, name: str, email: str, phone: str) -> None:
        # super() function returns the object as if it was actually an instance of the parent class
        # allowing us to call the parent method directly
        super().__init__(name, email)
        self.phone = phone


if __name__ == '__main__':
    c1 = Contact("Foo", "foo@email.com")
    c2 = Contact("Bar", "bar@email.com")
    s = Supplier("Baz", "baz@email.com")
    f = Friend("Qux", "qux@email.com", "000-111")
    print(Contact.all_contacts)
