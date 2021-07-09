/* Include header C++ */
#include <iostream>
#include <string>
#include <vector>

/* Include FGame Library */
#include <FGame.hpp>

int main(int argc, const char* argv[]) {
	FGameV2 Manager = FGameV2({ 0 }, "Just like this");

	for(auto& listFile : Manager.Run.File.List(".", 
				FG_THIS_DEFAULT(Manager))) {
		std::cout << listFile << std::endl;
	}
	/*
	 * Because i don't using parameter
	 * I make parameter into void
	 * Why, Because i see compiler
	 * If progammer using parameter like them
	 * But not in using, The compiler give
	 * Warning. Becuase that i made like this
	 */
	{
		(void)argc;
		(void)argv;
	}
	return 0;
}
