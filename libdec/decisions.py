import random

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
