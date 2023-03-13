package zerodha;

/**
 * The OrderExecutioner class is responsible for executing orders on an exchange
 * by calling the ExchangeConnector's placeOrder method.
 */
public class OrderExecutioner {
    /**
     * Executes the specified order on the connected exchange.
     *
     * @param order the Order object to execute
     */
    public void executeOrder(Order order) {
        var exchConnector = ExchangeConnector.getExchangeConnector();
        exchConnector.placeOrder(order);
    }
}
