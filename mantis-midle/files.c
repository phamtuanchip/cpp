#include "mongoose.h"

static const char *s_http_port = "8001";

static void ev_handler(struct mg_connection *c, int ev, void *ev_data) {
  if (ev == MG_EV_HTTP_REQUEST) {
    struct mg_serve_http_opts opts;

    memset(&opts, 0, sizeof(opts));  // Reset all options to defaults
    opts.document_root = ".";       // Serve files from the current directory
	opts.enable_directory_listing = "yes";

    mg_serve_http(c, (struct http_message *) ev_data, opts);
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