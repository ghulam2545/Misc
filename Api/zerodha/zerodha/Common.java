package zerodha;

/**
 * This class contains commonly used enums/types in application.
 */
public class Common {
    /**
     * This enum contains the various order statuses that a trading order can have,
     */
    public enum ORDER_STATUS {
        /** Specty that this is new order that has to fulfill */
        OPEN,
        /** Specify that this order is partially fulfilled */
        PARTIALLY_DONE,
        /** Specify that this order is completely fulfilled */
        DONE,
        /** Specify that this order anyhow cancelled */
        CANCELLED
    }

    /**
     * This enum defines the various types of trading orders that can be placed,
     * including LIMIT and MARKET.
     */
    public enum ORDER_TYPE {
        /** Some additional specification for type */
        LIMIT,
        /** Some additional specification for type */
        MARKET
    }

    /**
     * This enum contains the two transaction types that can occur in a trading
     * order,
     */
    public enum TRANSACTION_TYPE {
        /** Specify that ask is to buy stock */
        BUY,
        /** Specify that ask is to sell stock */
        SELL
    }

    /**
     * This enum contains the exchanges where a trading order can be executed,
     * including NSE and BSE.
     */
    public enum EXCHANGE {
        /** National Stock Exchange */
        NSE,
        /** Bombay Stock Exchange */
        BSE
    }
}