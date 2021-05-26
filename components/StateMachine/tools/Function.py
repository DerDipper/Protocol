class Function:
    def __init__(self, name) -> None:
        self.name = name
        self.isStatic = False
        self.parameters = []

    def setStatic(self) -> None:
        self.isStatic = True

    def setReturnType(self, type):
        self.returnType = type

    def addParameter(self, parameter):
        self.parameters.append(parameter)

    def getDeclaration(self) -> str:
        text = str()
        firstParameter = False
        if self.isStatic:
            text = text + "static "
        else:
            text = text + "extern "
        text = text + self.returnType + " "
        text = text + self.name
        text = text + "("
        for param in self.parameters:
            if firstParameter:
                text = text + ", "
            text = text + param[0] + " " + param[1] 
            firstParameter = True
        text = text + ")"
        return text

if __name__ == "__main__":
    f = Function("add")
    f.setReturnType("int")
    f.addParameter(("const int", "lhs"))
    f.addParameter(("const int", "rhs"))
    
    print(f.getDeclaration())

    f.setStatic()
    print(f.getDeclaration())
    