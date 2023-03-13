package zerodha;

import java.lang.System;

/**
 * The ExchangeConnector class provides a singleton instance that can be used to
 * connect to an exchange and place orders.
 */
public class ExchangeConnector {
    private static ExchangeConnector m_ExchangeConnectorInstance = null;

    private ExchangeConnector() {
    }

    /**
     * Returns the singleton instance of the ExchangeConnector class. If the
     * instance does not yet exist, it is created.
     *
     * @return the singleton instance of the ExchangeConnector class
     */
    public static ExchangeConnector getExchangeConnector() {
        if (m_ExchangeConnectorInstance == null) {
            ExchangeConnector.m_ExchangeConnectorInstance = new ExchangeConnector();
        }
        return ExchangeConnector.m_ExchangeConnectorInstance;
    }

    /**
     * Places an order on the connected exchange.
     *
     * @param order the Order object to place
     */
    public void placeOrder(Order order) {
        System.out.println("Order has been send to exchange");
    }
}
