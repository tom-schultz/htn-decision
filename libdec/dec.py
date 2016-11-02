#!/usr/bin/env python

import time
from actions import MoveAction
from components import PositionComponent
from decisions import DumbWeightedOption, UtilitySystem
from plans import TaskNetwork, Actions

class Agent:
    def __init__(self, decider, planner):
        self.state = "start"
        self.goal_state = "start"
        self.decider = decider
        self.planner = planner
        self.position = PositionComponent(0, 0, 0)
        self.speed = SpeedComponent(200)
    
    def act(self):
        if self.state == self.goal_state:
            self.goal_state = self.decider.decide().desc
            print("New goal: " + self.goal_state)
            self.planner.build_plan(self, self.goal_state)
        
        if not self.planner.execute_plan(self):
            self.planner.build_plan(self, self.goal_state)

def main():
    planner = TaskNetwork([
        Action(, None, "move"),
        Action("tired", None, "rest")
    ])

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
