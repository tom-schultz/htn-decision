import abc

class Action:
    __metaclass__ = abc.ABCMeta

    def __init__(self, desc):
        self.desc = desc

    @abc.abstractmethod
    def perform(self):
        return True 
    
    @abc.abstractmethod
    def __repr__(self):
        return self.desc

class MoveAction(Action):
    def __init__(self, desc, actor, dest):
        super.__init__(desc)
        self.actor = actor 

    def perform(self):
        if arrived():
            return True
        
        dist_x = self.actor.dest.x - self.actor.pos.x
        dist_y = self.actor.dest.y - self.actor.pos.y

        if abs(dist_x) > abs(dist_y):
            self.actor.pos.x += copysign(1, dist_x)
        else:
            self.actor.pos.y += copysign(1, dist_y)

        return arrived()

    def arrived(self):
        return (self.actor.pos.x == self.actor.dest.x
                and self.actor.pos.y == self.actor.dest.y)

