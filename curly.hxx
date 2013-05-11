#ifndef CURLY_HXX
# define CURLY_HXX

# include <curly.hh> // will never include, usefull for static analysis
# include <sstream>

namespace curly
{
  template <typename T>
  int
  request_configuration::option(CURLoption opt, T&& param)
  {
    auto ec = curl_easy_setopt(_easy_handle.get(),
                               opt, std::forward<T>(param));
    throw_if_ecode(ec);
    return ec;
  }
  template <typename T>
  int
  request::info(CURLINFO info, T&& param)
  {
    auto ec = curl_easy_getinfo(this->_config.native_handle(), info,
                                std::forward<T>(param));
    throw_if_ecode(ec);
    return ec;
  }

  template <CURLoption Opt>
  curly::request_configuration
  make_method()
  {
    curly::request_configuration c;
    
    c.option(Opt, 1);
    c.option(CURLOPT_VERBOSE, 1);
    return c;
  }

  template <CURLoption Opt>
  std::string
  method_in(std::string const& url, std::istream& in)
  {
    std::stringstream ss;
    curly::request_configuration c = make_method<Opt>();
    
    c.url(url);
    c.input(in);
    c.output(ss);
    curly::request req(std::move(c));
    return ss.str();
  }

  template <CURLoption Opt>
  void
  method_out(std::string const& url, std::ostream& out)
  {
    curly::request_configuration c = make_method<Opt>();
    
    c.url(url);
    c.output(out);
    curly::request req(std::move(c));
  }

  template <CURLoption Opt>
  void
  method_inout(std::string const& url, std::istream& in, std::ostream& out)
  {
    curly::request_configuration c = make_method<Opt>();
    
    c.url(url);
    c.input(in);
    c.output(out);
    curly::request req(std::move(c));
  }

  template <CURLoption Opt>
  std::string
  method_simple(std::string const& url)
  {
    std::stringstream ss;
    curly::request_configuration c = make_method<Opt>();

    c.url(url);
    c.output(ss);
    curly::request req(std::move(c));
    return ss.str();
  }
} /* curly */

#endif /* end of include guard: CURLY_HXX */
