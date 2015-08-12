/* src/mod/static.h -- header file for static compiles.
 *
 * NOTE: Do not edit directly. Instead, re-run `make config'.
 */

#ifndef _EGG_MOD_STATIC_H
#define _EGG_MOD_STATIC_H

char *assoc_start();
char *blowfish_start();
char *channels_start();
char *compress_start();
char *console_start();
char *ctcp_start();
char *dns_start();
char *filesys_start();
char *irc_start();
char *notes_start();
char *seen_start();
char *server_start();
char *share_start();
char *transfer_start();
char *uptime_start();

static void link_statics()
{
  check_static("assoc", assoc_start);
  check_static("blowfish", blowfish_start);
  check_static("channels", channels_start);
  check_static("compress", compress_start);
  check_static("console", console_start);
  check_static("ctcp", ctcp_start);
  check_static("dns", dns_start);
  check_static("filesys", filesys_start);
  check_static("irc", irc_start);
  check_static("notes", notes_start);
  check_static("seen", seen_start);
  check_static("server", server_start);
  check_static("share", share_start);
  check_static("transfer", transfer_start);
  check_static("uptime", uptime_start);
}

#endif /* _EGG_MOD_STATIC_H */
