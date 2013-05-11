#include <boost/asio.hpp>
#include <curly.hh>

#include "service.hh"
#include "asio_request.hh"

#define DEBUG std::cout << __PRETTY_FUNCTION__ <<": " << __LINE__ << std::endl;
#define FDEBUG(X) std::cout << X << " " << __PRETTY_FUNCTION__ <<": " << __LINE__ << std::endl;

namespace asio = boost::asio;

int
main(int, const char *[])
{
  asio::io_service io;

  auto get = curly::make_get();
  get.url("http://fabien.le.boute-en-tra.in");
  get.output(std::clog);

  curly::asio_request r(io, get);
  auto fn = [&] (int code)
  {
    if (code == CURLE_OK)
      std::cout << "Request succeeded\n";
  };
  r.async_perform(fn);

  io.run();
  return 0;
}
