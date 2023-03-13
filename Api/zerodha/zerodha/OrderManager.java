package zerodha;

/**
 * This class is responsible for managing the placement and
 * execution of orders on an exchange. It uses an OrderValidator to check the
 * validity of orders before they are executed, and an OrderExecutioner to
 * actually execute valid orders.
 */
public class OrderManager {
    private OrderExecutioner m_orderExecutioner;
    private OrderValidator m_orderValidator;

    /**
     * Constructs a new OrderManager instance, initializing the OrderExecutioner and
     * OrderValidator.
     */
    public OrderManager() {
        this.m_orderExecutioner = new OrderExecutioner();
        this.m_orderValidator = new OrderValidator();
    }

    /**
     * Places the specified order on the connected exchange if it is valid.
     *
     * @param userId the ID of the user placing the order
     * @param order  the Order object to place
     */
    public void placeOrder(String userId, Order order) {
        if (m_orderValidator.validateOrder(userId, order)) {
            m_orderExecutioner.executeOrder(order);
        } else {
            System.out.println("Can't execute order.");
        }
    }
}
