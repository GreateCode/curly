#include <curly.hh>

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

void
test()
{
  auto get = curly::make_get();
  std::ofstream dev_null("/dev/null");

  get.url("http://fabien.le.boute-en-tra.in/");

  {
    curly::request req(get);

    std::cout << req.url() << " " << req.code() << std::endl;
    std::cout << req.time().count() << std::endl;
  }

  {
    get.url("http://127.0.0.1:8000");
    curly::request req(get);

    std::cout << req.url() << " " << req.code() << std::endl;
    std::cout << req.time().count() << std::endl;
  }
}

int
main(int argc, const char *argv[])
{
  //std::cout << curly::get("http://fabien.le.boute-en-tra.in") << "\n";
  //std::stringstream ss;
  //curly::get("http://fabien.le.boute-en-tra.in", ss);
  //std::cout << ss.str() << std::endl;
  test();
  return 0;
}
