
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace pplx;
using namespace utility;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;
 
int main(int argc, char *args[]){
    auto fileStream = std::make_shared<ostream>();
    printf("test");
     http_client client(U("http://www.bing.com/"));
    return 0;
}