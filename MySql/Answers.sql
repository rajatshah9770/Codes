-- Basic Level
-- List all customers.
SELECT * FROM Customers;
-- Get all orders placed by customer with CustomerID = 1.
select * from Customers where CustomerId = 1;
select * from Orders where CustomerID = 1; -- Answer
Select * from Orders join Customers on Orders.CustomerId = Customers.CustomerId where Orders.CustomerId = 1;


Find the email address of 'Diana Prince'.

List all products ordered in OrderID = 101.

Show all orders placed after '2024-03-01'.

Count how many orders each customer has placed.

Get all order items where quantity is greater than 1.

List all distinct products ordered.

Find the total number of customers.

List customers who haven't placed any orders.

⚙️ Intermediate Level
Get a list of customers and their total number of orders (include customers with 0 orders).

List all orders along with the customer name who placed them.

Show each order with total quantity of items in that order.

Find all orders that contain the product 'Laptop'.

Find the top 3 customers who placed the most orders.

Get all customers whose name starts with 'A'.

List the names of customers who placed orders in April 2024.

Retrieve the most recently placed order.

For each customer, show the total quantity of items they have ordered across all their orders.

List all orders with more than 2 products in them.

🔍 Advanced Level
Get the average quantity of each product ordered.

Find the order with the highest number of items.

List orders and total items, sorted by most items first.

List customers who ordered more than 5 items in total.

Find customers who ordered both 'Laptop' and 'Mouse'.

Get all products that were ordered more than once (across different orders).

For each month, find the total number of orders placed.

List orders that include more than one type of product.

Generate a report with: Customer Name, Order Date, Total Quantity in that order.

Find customers who have not ordered after March 2024.

