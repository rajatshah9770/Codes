
-- Insert Customers
INSERT INTO Customers (CustomerID, Name, Email) VALUES
(1, 'Alice Johnson', 'alice@example.com'),
(2, 'Bob Smith', 'bob@example.com'),
(3, 'Charlie Brown', 'charlie@example.com'),
(4, 'Diana Prince', 'diana@example.com'),
(5, 'Ethan Hunt', 'ethan@example.com'),
(6, 'Fiona Glenanne', 'fiona@example.com'),
(7, 'George Costanza', 'george@example.com'),
(8, 'Hannah Baker', 'hannah@example.com'),
(9, 'Ian Malcolm', 'ian@example.com'),
(10, 'Jane Eyre', 'jane@example.com');

-- Insert Orders
INSERT INTO Orders (OrderID, CustomerID, OrderDate) VALUES
(101, 1, '2024-01-15'),
(102, 2, '2024-01-20'),
(103, 3, '2024-02-01'),
(104, 1, '2024-02-10'),
(105, 5, '2024-03-05'),
(106, 6, '2024-03-15'),
(107, 7, '2024-04-01'),
(108, 8, '2024-04-12'),
(109, 9, '2024-05-01'),
(110, 10, '2024-05-10');

-- Insert OrderItems
INSERT INTO OrderItems (ItemID, OrderID, Product, Quantity) VALUES
(1001, 101, 'Laptop', 1),
(1002, 101, 'Mouse', 2),
(1003, 102, 'Keyboard', 1),
(1004, 103, 'Monitor', 1),
(1005, 104, 'Desk Lamp', 1),
(1006, 105, 'Notebook', 3),
(1007, 106, 'Pen Set', 2),
(1008, 107, 'Chair', 1),
(1009, 108, 'Desk', 1),
(1010, 109, 'USB Drive', 5);
