package zerodha;

import zerodha.Common.*;

/**
 * The purpose of this class is to represent a stock, which has a name, a price,
 * and an exchange it is traded on. This class can be used to create objects
 * that represent individual stocks, and these objects can be used by other
 * classes or modules in the program.
 */
public class Stock {
    private String m_name;
    private double m_price;
    private EXCHANGE m_exchange;
    // more ...

    /**
     * This constructor initializes the member variables with the values passed as
     * arguments.
     * 
     * @param name     name of stock
     * @param price    price for stock
     * @param exchange specify exchange (NSE, BSE)
     */
    public Stock(String name, double price, EXCHANGE exchange) {
        this.m_name = name;
        this.m_price = price;
        this.m_exchange = exchange;
    }
}
