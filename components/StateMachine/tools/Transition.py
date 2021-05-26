import re


class Transition:
    def addSourceState(self, state):
        self.source = state

    def addDestinationState(self, state):
        self.dest = state

    def addEvent(self, event):
        self.event = event

    def __str__(self) -> str:
        return self.source.name + " --> " + self.dest.name + " : " + self.event.name

