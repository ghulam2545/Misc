package zerodha;

import java.lang.System;
import zerodha.Common.*;

/**
 * The OrderValidator class is responsible for validating orders for a user.
 * It checks if the user has enough funds to buy or enough stocks to sell in
 * their portfolio.
 */
public class OrderValidator {
    /**
     * This method validates an order for a user.
     * 
     * @param userId the user ID of the user placing the order
     * @param order  the order to be validated
     * @return true if the order is valid,
     */
    public boolean validateOrder(String userId, Order order) {
        var currUser = Controller.getUser(userId);

        if (order.getTransactionType() == TRANSACTION_TYPE.BUY) {
            System.out.println("Checking if user " + currUser.getUserId() + " has enough funds to buy.");
            System.out.println("For now, let's assume user is a good person and return true");
        } else {
            System.out.println("Checking if user " + userId + " has enough stocks to sell in portfolio.");
            System.out.println("For now, let's assume user is a good person and return true");
        }
        return true;
    }
}
