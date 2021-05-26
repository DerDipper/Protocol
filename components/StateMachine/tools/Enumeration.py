class Enumeration:
    def __init__(self, name) -> None:
        self.name = name
        self.identifier = []

    def addIdentifier(self, id) -> None:
        self.identifier.append(id)
    
    def getDeclaration(self) -> str:
        text = str()
        text = text + "typedef enum " + self.name + "_e" + "\n"
        text = text + "{" + "\n"
        for id in self.identifier:
            text = text + "   " + self.name.upper() + "_" + id.upper() + "," + "\n"
        text = text + "}" + self.name

        return text

if __name__ == "__main__":
    enum = Enumeration("Machine_State")
    enum.addIdentifier("Init")
    enum.addIdentifier("Idle")
    enum.addIdentifier("Operational")
    enum.addIdentifier("Error")
    print(enum.getDeclaration())