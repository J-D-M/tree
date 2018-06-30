#include <algorithm>
#include <experimental/filesystem>
#include <getopt.h>
#include <iostream>
#include <iterator>
#include <optional>

namespace fs = std::experimental::filesystem;

auto
dirToString(fs::directory_entry dir) -> std::string
{
	return static_cast<std::string>(dir.path().filename());
}

auto
printDir(fs::directory_entry dir, int depth) -> void
{
	std::cout << dirToString(dir) << '\n';

	for (auto &d : fs::directory_iterator(dir)) {
		for (int i = 1; i < depth; i++)
			std::cout << "|   ";
		std::cout << "↳ ";

		if (fs::is_directory(d))
			printDir(d, depth + 1);
		else
			std::cout << dirToString(d) << '\n';
	}
}

auto
main(int argc, char **argv) -> int
{
	fs::directory_entry root{argc > 1 ? argv[1] : "."};
	if (fs::exists(root) && fs::is_directory(root))
		printDir(root, 1);
	else
		std::cout << "invalid directory: " << root << std::endl;
}
