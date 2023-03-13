package zerodha;

import zerodha.Common.*;

/**
 * An Order class that defines the properties and behavior of an order for a
 * stock.
 */
public class Order {
    private TRANSACTION_TYPE m_txnType;
    private ORDER_TYPE m_orderType;
    private EXCHANGE m_exchange;
    private double m_price;
    private int m_qty;
    private Stock m_stock;
    // more ...

    /**
     * Constructor that takes in all properties as parameters and initializes
     * them.
     * 
     * @param txnType   type of transaction
     * @param orderType type of order
     * @param exchange  exchange of order
     * @param price     price for order
     * @param qty       quantity of order
     * @param stock     stock that will be part of order
     */
    public Order(TRANSACTION_TYPE txnType, ORDER_TYPE orderType, EXCHANGE exchange, double price, int qty,
            Stock stock) {
        this.m_txnType = txnType;
        this.m_orderType = orderType;
        this.m_exchange = exchange;
        this.m_price = price;
        this.m_qty = qty;
        this.m_stock = stock;
    }

    /**
     * This method returns the transaction type of the order.
     * 
     * @return transaction type is returned
     */
    public TRANSACTION_TYPE getTransactionType() {
        return this.m_txnType;
    }

    /**
     * This method returns the exchange of the order.
     * 
     * @return exchange for current order is returned
     */
    public EXCHANGE getExchange() {
        return this.m_exchange;
    }
}
