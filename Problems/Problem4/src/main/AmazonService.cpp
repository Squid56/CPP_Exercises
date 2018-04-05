#include <AmazonService.h>
#include <windows.h>
#include <iostream>

AmazonService* AmazonService::amazonService = nullptr;


AmazonService* AmazonService::getInstance()
{
	if (amazonService == nullptr){
		amazonService = new AmazonService();
	}
	return amazonService;
}

bool AmazonService::checkout( std::shared_ptr<Book> book ){
	std::cout << "Checking out book started..." << std::endl;
	::Sleep(60000);
	std::cout << "Checking out book done..." << std::endl;
	return true;
}
