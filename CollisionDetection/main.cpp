#include <SFML/Graphics.hpp>

#include "application\Application.h"
#include <vld.h>

int main()
{
	std::shared_ptr<Application> application(new Application());

	application->build();
    application->run();

    return 0;
}