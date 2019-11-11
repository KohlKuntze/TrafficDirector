
from model import Orders

def createBuyOrder(ticker, price, quantity):

    return Orders.BuyOrder.init(ticker, price, quantity)


