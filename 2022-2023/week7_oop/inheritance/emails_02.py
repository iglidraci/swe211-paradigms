from typing import Protocol

from inheritance.contact_01 import Contact


class Emailable(Protocol):
    """
    Protocols generally have methods, and can also have class-level attribute names with type hints,
    but not full assignment statements
    """
    email: str


class MailSender(Emailable):
    def send_mail(self, message: str) -> None:
        print(f"Sending mail to {self.email}, body: {message}")


class EmailableContact(Contact, MailSender):
    pass


if __name__ == '__main__':
    e = EmailableContact("Foo", "foo@email.com")
    print(Contact.all_contacts)
    e.send_mail("Test email")
