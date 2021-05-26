from State import State
from Event import Event
from Transition import Transition
import re
import os

REGEX_FOR_TRANSITIONS = r"(\w+) *-*> *(\w+) *:* *(\w+)*"
REGEX_FOR_INITIAL_STATE = r"\[\*\] *-*> *(\w+)"
REGEX_FOR_FINDING_ENTRY = r"(\w*) *: *\(entry\) *(\w+)"
REGEX_FOR_FINDING_do = r"(\w*) *: *\(do\) *(\w+)"
REGEX_FOR_FINDING_EXIT = r"(\w*) *: *\(exit\) *(\w+)"

class StateMachine:
    def __init__(self, name) -> None:
        self.name = os.path.splitext(name)[0]
        self.events = []
        self.states = []
        self.transitions = []
        file = open(name, "r")
        text = file.readlines()
        for txt in text:
            matches = re.finditer(REGEX_FOR_TRANSITIONS, txt, re.MULTILINE)
            for matchNum, match in enumerate(matches, start=1):
                if State(match.group(1)) not in self.states:
                    self.states.append(State(match.group(1)))
                if State(match.group(2)) not in self.states:
                    self.states.append(State(match.group(2)))
                if Event(match.group(3)) not in self.events:
                    self.events.append(Event(match.group(3)))
        for txt in text:
            matches = re.finditer(REGEX_FOR_TRANSITIONS, txt, re.MULTILINE)
            for matchNum, match in enumerate(matches, start=1):            
                tr = Transition()
                for state in self.states:
                    if State(match.group(1)) == state:
                        tr.addSourceState(state)
                    if State(match.group(2)) == state:
                        tr.addDestinationState(state)
                for event in self.events:
                    if Event(match.group(3)) == event:
                        tr.addEvent(event)
                self.transitions.append(tr)        
        for txt in text:
            matches = re.finditer(REGEX_FOR_INITIAL_STATE, txt, re.MULTILINE)
            for matchNum, match in enumerate(matches, start=1):
                for state in self.states:
                    if State(match.group(1)) == state:
                        self.initial = state
        file.close()

    def __str__(self) -> str:
        text = str()
        text = text + "--------------------------------------------------------\n"
        text = text + "Name: " +  self.name + "\n"
        text = text + "--------------------------------------------------------\n"
        text = text + "States:" + "\n"
        for state in self.states:
            text = text + "\t" + str(state) + "\n"
        text = text + "--------------------------------------------------------\n"
        text = text + "Events:" + "\n"
        for event in self.events:
            text = text + "\t" + str(event) + "\n"
        text = text + "--------------------------------------------------------\n"
        text = text + "Transitions:" + "\n"
        for transition in self.transitions:
            text = text + "\t" + str(transition) + "\n"
        text = text + "--------------------------------------------------------\n"
        text = text + "Inital State: " + str(self.initial) + "\n"
        text = text + "--------------------------------------------------------\n"
        return text
        
