from model import Car
from model import Intersection

carOne = ["KNA3573", 1.05]
carTwo = ["WSK7474", 1.15]

carOneObj = Car(carOne[0], carOne[1])
carTwoObj = Car(carTwo[0], carTwo[1])

print (carOneObj.getLicensePlate())
