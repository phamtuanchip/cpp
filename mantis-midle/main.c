#include <string.h>
#include <stdio.h>

#include "mongoose.h"
//#include "mxml.h"
//#include "sqlite3.h"

/***Sqlite initialization stuff***/
//comment out everything sqlite related if you don't want sqlite, including the callback function and the include "sqlite3.h"
static int callback(void *custom, int argc, char **argv, char **azColName);
char *zErrMsg = 0;
//sqlite3 *db;
int rc;

/***Just some laziness shortcut functions I made***/
//typedef mxml_node_t *dom;                     //type "dom" instead of "mxml_node_t *"
#define c mxmlNewElement                      //type "c" instead of "mxmlNewElement"
// inline void t(dom parent, const char *string) //etc
// {
//     mxmlNewText(parent, 0, string);
// }

// //type "sa" instead of "mxmlElementSetAttr"
// inline void sa(dom element, const char *attribute, const char *value)
// {
//     mxmlElementSetAttr(element, attribute, value);
// }

//The only non boilerplate code around in this program is this function
void serve_hello_page(struct mg_connection *conn)
{
    // char output[1000];
    // mg_send_header(conn, "Content-Type", "text/html; charset=utf-8");
    // mg_printf_data(conn, "%s", "<!DOCTYPE html>");
    // //This literally prints into the html document

    // /*Let's generate some html, we could have avoided the
    //  * xml parser and just spat out pure html with mg_printf_data
    //  * e.g. mg_printF_data(conn,"%s", "<html>hello</html>") */

    // //...But xml is cleaner, here we go:
    // dom html = mxmlNewElement(MXML_NO_PARENT, "html");
    // dom head = c(html, "head");
    // dom meta = c(head, "meta");
    // sa(meta, "charset", "utf-8");
    // dom body = c(html, "body");
    // t(body, "Hello, world<<"); //The < is auto escaped, neat!
    // c(body, "br");
    // t(body, "Fred ate bred");
    // dom table = c(body, "table");
    // sa(table, "border", "1");

    // //populate the table via sqlite
    // rc = sqlite3_exec(db, "SELECT * from myCoolTable", callback, table, &zErrMsg);
    // if (rc != SQLITE_OK)
    // {
    //     fprintf(stderr, "SQL error: %s\n", zErrMsg);
    //     sqlite3_free(zErrMsg);
    // }

    // mxmlSaveString(html, output, 1000, MXML_NO_CALLBACK);
    // mg_printf_data(conn, "%s", output);
    // mxmlDelete(html);
}

//sqlite callback
static int callback(void *custom, int argc, char **argv, char **azColName)
{
    // //this function is executed for each row
    // dom table = (dom)custom;

    // dom tr = c(table, "tr");
    // dom td;
    // int i;
    // for (i = 0; i < argc; i++)
    // {
    //     td = c(tr, "td");
    //     if (argv[i])
    //         t(td, argv[i]);
    //     else
    //         t(td, "NULL");

    //     printf("%s == %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    // }
    // printf("\n");
    return 0;
}

static int event_handler(struct mg_connection *conn, enum mg_event ev)
{
     serve_hello_page(conn);

    // if (ev == MG_AUTH)
    // {
    //     return MG_TRUE; // Authorize all requests
    // }
    // else if (ev == MG_REQUEST)
    // {
    //     if (!strcmp(conn->uri, "/hello"))
    //     {
    //         serve_hello_page(conn);
    //         return MG_TRUE; // Mark as processed
    //     }
    // }
    // return MG_FALSE; // Rest of the events are not processed
}

int main(void)
{
    struct mg_server *server = mg_create_server(NULL, event_handler);
    //mg_set_option(server, "document_root", "."); //prevent dir listing and auto file serving
    //TODO can I allow file listing without dir listing in a specified directory?
    mg_set_option(server, "listening_port", "8080");

    //rc = sqlite3_open("db.sqlite3", &db);

    // if (rc)
    // {
    //     fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    //     sqlite3_close(db);
    //     return (1);
    // }

    printf("Server is running on port 8080!\n");
    for (;;)
    {
        mg_poll_server(server, 1000); // Infinite loop, Ctrl-C to stop
    }
    mg_destroy_server(&server);
   // sqlite3_close(db);

    return 0;
}