#include <ShoppingCart.h>
#include <algorithm>
#include "AmazonService.h"
#include "ShippingScheduler.h"
#include "Book.h"

ShoppingCart::ShoppingCart( std::shared_ptr<ShippingScheduler> shippingScheduler ):shippingScheduler(shippingScheduler) {
}

void ShoppingCart::addBook( std::shared_ptr<Book> book ) {
	books.push_back(book);
}

void ShoppingCart::checkout() {
	std::shared_ptr<ShippingScheduler> scheduler(shippingScheduler);
	std::for_each(books.begin(), books.end(), [&scheduler](std::shared_ptr<Book> book){
		if (AmazonService::getInstance()->checkout(book)){
			scheduler->schedule(book);
		}
	});
}

