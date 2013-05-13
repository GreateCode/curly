#include <boost/asio.hpp>

#include <fstream>
#include <curly.hh>
#include <service.hh>
#include <asio_request.hh>

namespace asio = boost::asio;

int
main(int, const char *[])
{
  asio::io_service io;
  std::ofstream null("/dev/null");

  auto get0 = curly::make_get();
  get0.url("http://fabien.le.boute-en-tra.in");
  get0.output(null);
  curly::asio_request r0(io, get0);

  auto get1 = curly::make_get();
  get1.url("http://fabien.le.boute-en-tra.in");
  get1.output(null);
  curly::asio_request r1(io, get1);

  auto get2 = curly::make_get();
  get2.url("http://fabien.le.boute-en-tra.in");
  get2.output(null);
  curly::asio_request r2(io, get2);

  auto get3 = curly::make_get();
  get3.url("http://fabien.le.boute-en-tra.in");
  get3.output(null);
  curly::asio_request r3(io, get3);

  auto get4 = curly::make_get();
  get4.url("http://fabien.le.boute-en-tra.in");
  get4.output(null);
  curly::asio_request r4(io, get4);

  auto get5 = curly::make_get();
  get5.url("http://fabien.le.boute-en-tra.in");
  get5.output(null);
  curly::asio_request r5(io, get5);

  auto get6 = curly::make_get();
  get6.url("http://fabien.le.boute-en-tra.in");
  get6.output(null);
  curly::asio_request r6(io, get6);

  auto get7 = curly::make_get();
  get7.url("http://fabien.le.boute-en-tra.in");
  get7.output(null);
  curly::asio_request r7(io, get7);

  auto get8 = curly::make_get();
  get8.url("http://fabien.le.boute-en-tra.in");
  get8.output(null);
  curly::asio_request r8(io, get8);

  auto get9 = curly::make_get();
  get9.url("http://fabien.le.boute-en-tra.in");
  get9.output(null);
  curly::asio_request r9(io, get9);

  auto get10 = curly::make_get();
  get10.url("http://fabien.le.boute-en-tra.in");
  get10.output(null);
  curly::asio_request r10(io, get10);

  auto fn = [&] (int code)
  {
    if (code == CURLE_OK)
      std::cout << "Request succeeded\n";
  };
  r0.async_perform(fn);
  r1.async_perform(fn);
  r2.async_perform(fn);
  r3.async_perform(fn);
  r4.async_perform(fn);
  r5.async_perform(fn);
  r6.async_perform(fn);
  r7.async_perform(fn);
  r8.async_perform(fn);
  r9.async_perform(fn);
  r10.async_perform(fn);

  io.run();
  return 0;
}
