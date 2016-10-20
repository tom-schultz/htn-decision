#!/usr/bin/env python

import random
import time

class Agent:
    def __init__(self, decider, planner):
        self.state = "start"
        self.goal_state = "start"
        self.decider = decider
        self.planner = planner
    
    def check_state(self, precons):
        return self.state == precons
    
    def apply_state(self, postcons):
        self.state = postcons

    def act(self):
        if self.state == self.goal_state:
            self.goal_state = self.decider.decide().desc
            print("New goal: " + self.goal_state)
            self.planner.build_plan(self, self.goal_state)
        
        if not self.planner.execute_plan(self):
            self.planner.build_plan(self, self.goal_state)

class Action:
    def __init__(self, precons, postcons, desc):
        self.precons = precons
        self.postcons = postcons
        self.desc = desc

    def perform(self, state):
        if state.check_state(self.precons):
            state.apply_state(self.postcons)
            print("Performed: " + self.desc)
            return True

        return False
    
    def __repr__(self):
        return self.desc

class TaskNetwork:
    def __init__(self):
        self.actions = [
            Action("start", "end", "finish"),
            Action("end", "start", "restart")
        ]

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

class DumbWeightedOption:
    def __init__(self, weight, desc):
        self.weight = weight
        self.desc = desc

class UtilitySystem:
    def __init__(self):
        self.options = {}
        random.seed()

    def decide(self):
        sum_weight = 0

        for key, option in self.options.items():
            sum_weight += option.weight

        num = random.uniform(0, sum_weight)
        for key, option in self.options.items():
            if num < option.weight:
                return option

            num -= option.weight

def main():
    planner = TaskNetwork()
    decider = UtilitySystem()

    decider.options = {
        "cat": DumbWeightedOption(1, "start"),
        "dog": DumbWeightedOption(1, "end"),
    }

    agent = Agent(decider, planner)
   
    for i in range(1, 20):
        agent.act()

if __name__ == "__main__":
    main()
