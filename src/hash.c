#include "main.h"

extern struct hobyni *hostbynick;

void change_nick (char *old, char *nouveau)
{
	struct hobyni *oh;
	HASH_FIND_STR(hostbynick, old, oh);
	HASH_DEL(hostbynick, oh);
	free(oh->nick);
	oh->nick = strdup(nouveau);
	HASH_ADD_KEYPTR(hh, hostbynick, hostbynick->nick, strlen(hostbynick->nick), oh);
}

void del_nick (char *old)
{
	struct hobyni *oh;
	HASH_FIND_STR(hostbynick, old, oh);
	HASH_DEL(hostbynick, oh);
	free(oh);
}

void add_nick (char *nick, char *user, char *host)
{
	struct hobyni *h;
	HASH_FIND_STR(hostbynick, nick, h);
	if (h!=NULL) {
		putlog(LOG_SERV, "*", "WARNING: attempt to add_nick() already existing nickname! %s", nick);
		HASH_DEL(hostbynick, h);
		free(h);
	}
	h = (struct hobyni *)malloc(sizeof(struct hobyni));
	h->nick = strndup(nick,  60);
	h->user = strndup(user,  30);
	h->host = strndup(host, 291);
	HASH_ADD_KEYPTR(hh, hostbynick, h->nick, strlen(h->nick), h);
	putlog(LOG_SERV, "*", "added %s to the cross reference database as %s@%s", nick, h->user, h->host);
}

char *find_host_by_nick (char *nick)
{
	struct hobyni *h;
	char outbuf[8192];
	char *out=outbuf;
	HASH_FIND_STR(hostbynick, nick, h);
	if (h==NULL) return "I@do.not.have.this.user";
	putlog(LOG_SERV, "*", "found %s in cross reference database as %s %s", nick, h->user, h->host);
	sprintf(out, "%s@%s", h->user, h->host);
	return out;
}
