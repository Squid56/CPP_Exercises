#pragma once
#include <vector>
#include <memory>


struct ShippingScheduler;
class Book;

typedef std::vector<std::shared_ptr<Book>> tBooks;

class ShoppingCart {
public:
	ShoppingCart(std::shared_ptr<ShippingScheduler> shippingScheduler);

	void addBook(std::shared_ptr<Book> book);
	void checkout();

private:
	tBooks books;
	std::shared_ptr<ShippingScheduler> shippingScheduler;

};
