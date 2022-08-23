defaultFavs = { animal = 'gru', food = 'donuts' }
myFavs = { food = 'pizza' }
setmetatable(myFavs, { __index = defaultFavs })
print(myFavs.animal)  -- works! thanks, metatable
print(myFavs.food)

function printObj(o)
    print(o)
    for x, v in pairs(o) do
        print(x, "==", v)
    end
end
printObj(myFavs)

Dog = {
    innerID = "xxx"
}

function Dog:new()
    newObj = { sound = 'woof' }
    self.__index = self
    return setmetatable(newObj, self)
end

function Dog:makeSound()
    -- 6.
    print('I say ' .. self.sound)
end

d = Dog:new()
printObj(d)
d:makeSound()

LoudDog = Dog:new()

function LoudDog:new(level)
    newObj = { ['level'] = level }
    self.__index = self
    return setmetatable(newObj, self)
end

function LoudDog:makeSound()
    s = self.sound .. '...'
    for i = 1, self.level do
        s = s .. ' ' .. self.sound
    end
    print(s)
end

l = LoudDog:new(3)
l:makeSound()