import zerodha.Common.*;
import zerodha.User;
import zerodha.Stock;
import zerodha.Order;
import zerodha.OrderManager;
import zerodha.Controller;
import zerodha.ExchangeConnector;

public class Main {
    public static void main(String[] args) {
        
        // just to check every thing is working (no compilation error)
        
        User maggie = new User("maggie");
        Controller.addUser("maggie", maggie);
        Stock stock = new Stock("Tesla", 3000, EXCHANGE.BSE);
        Order order = new Order(TRANSACTION_TYPE.BUY, ORDER_TYPE.MARKET, EXCHANGE.BSE, 2000, 11, stock);

        OrderManager orderManager = new OrderManager();
        orderManager.placeOrder("maggie", order);

        // You can't do this
        // ExchangeConnector conn = new ExchangeConnector();
    }
}
