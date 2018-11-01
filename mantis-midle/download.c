#include "mongoose.h"

static const char *s_http_port = "8002";

static void ev_handler(struct mg_connection *c, int ev, void *ev_data) {
   switch (ev) {
     case MG_EV_HTTP_REQUEST: {
       struct http_message *hm = (struct http_message *) ev_data;
       mg_http_serve_file(c, hm, "file.txt",
                          mg_mk_str("text/plain"), mg_mk_str(""));
       break;
     }     
   }
  }
int main(void) {
  struct mg_mgr mgr;
  struct mg_connection *c;

  mg_mgr_init(&mgr, NULL);
  c = mg_bind(&mgr, s_http_port, ev_handler);
  mg_set_protocol_http_websocket(c);

  for (;;) {
    mg_mgr_poll(&mgr, 1000);
  }
  mg_mgr_free(&mgr);

  return 0;
}