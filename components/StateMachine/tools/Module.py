from Enumeration import Enumeration
from Function import Function

class Module:
    def __init__(self, name) -> None:
        self.name = name
        self.enumerations = []
        self.functions = []
        self.structs = []

    def printToFiles(self):
        implementation = open(self.name + ".c", "w")
        for func in self.functions:
            if func.isStatic:
                implementation.write(func.getDeclaration() + ";\n")

        implementation.close()


        interface = open(self.name + ".h", "w")
        for func in self.functions:
            if False == func.isStatic:
                interface.write(func.getDeclaration() + ";\n")
        interface.close()


if __name__ == "__main__":
    m = Module("StateMachine")
    f = Function("add")
    f.setReturnType("int")
    f.addParameter(("const int", "lhs"))
    f.addParameter(("const int", "rhs"))
    m.functions.append(f)
    f = Function("sub")
    f.setReturnType("int")
    f.addParameter(("const int", "lhs"))
    f.addParameter(("const int", "rhs"))
    f.setStatic()
    m.functions.append(f)
    m.printToFiles()
