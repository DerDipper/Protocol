class Event:
    def __init__(self, name) -> None:
        self.name = name

    def __str__(self) -> str:
        return self.name

    def __eq__(self, o: object) -> bool:
        return o.name == self.name