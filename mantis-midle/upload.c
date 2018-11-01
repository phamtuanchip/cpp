#include "mongoose.h"  // Include Mongoose API definitions

struct mg_str cb(struct mg_connection *c, struct mg_str file_name) {
  // Return the same filename. Do not actually do this except in test!
  // fname is user-controlled and needs to be sanitized.
  return file_name;
}

void ev_handler(struct mg_connection *c, int ev, void *ev_data) {
  switch (ev) {   
    case MG_EV_HTTP_PART_BEGIN:
    case MG_EV_HTTP_PART_DATA:
    case MG_EV_HTTP_PART_END:
      mg_file_upload_handler(c, ev, ev_data, cb);
      break;
  }
}

int main(void) {
  struct mg_mgr mgr;

  mg_mgr_init(&mgr, NULL);  // Initialize event manager object

  // Note that many connections can be added to a single event manager
  // Connections can be created at any point, e.g. in event handler function
  mg_bind(&mgr, "8003", ev_handler);  // Create listening connection and add it to the event manager

  for (;;) {  // Start infinite event loop
    mg_mgr_poll(&mgr, 1000);
  }

  mg_mgr_free(&mgr);
  return 0;
}