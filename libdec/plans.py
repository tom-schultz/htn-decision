import random

class TaskNetwork:
    def __init__(self, actions):
        self.actions = actions

        self.plan = []
    
    def build_plan(self, state, goal):
        self.plan = list(self.actions)
        random.shuffle(self.plan)
        print("New plan: " + str(self.plan))

    def execute_plan(self, state):
        if len(self.plan) > 0 and self.plan[0].perform(state):
            self.plan.pop(0)
            return True
        
        print("Did nothing.")
        return False
