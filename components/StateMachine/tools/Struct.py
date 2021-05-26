class Struct:
    def __init__(self, object) -> None:
        self.object = object

    def getInitialization(self) -> str:
        text = str()

        attrs = vars(self.object)
        text = str()
        text = "{"
        text = text + ', '.join(".%s = %s" % item for item in attrs.items())
        text = text + "}"
        return text

class TransitionImplementation:
    def __init__(self, source, destination, event) -> None:
        self.source = source
        self.destination = destination
        self.event = event

if __name__ == "__main__":
    v = TransitionImplementation("Init", "Idle", "Initialization_Done")
    struct = Struct(v)
    print(struct.getInitialization())
