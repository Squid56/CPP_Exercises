#pragma once

#include <memory>

class Book;
struct ShippingScheduler{
	virtual void schedule(std::shared_ptr<Book> book) = 0;
};