class State:
    def __init__(self, name) -> None:
        self.name = name
        self.entry = str()
        self.do = str()
        self.exit = str()

    def __str__(self) -> str:
        return self.name

    def __eq__(self, o: object) -> bool:
        return o.name == self.name

