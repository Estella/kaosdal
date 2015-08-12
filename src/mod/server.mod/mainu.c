// Created by janicez for the sake of whatchama
struct hobyni {
	char nick[60];
	char user[30];
	char host[291];
	UT_hash_handle hh;
};

struct hobyni *hostbynick = NULL;

void change_nick (char *old, char *nouveau)
{
	struct hobyni *oh;
	HASH_FIND_STR(hostbynick, &old, oh);
	HASH_DEL_STR(hostbynick, oh);
	oh->nick = strndup(nouveau, 60);
	HASH_ADD_STR(hostbynick, nick, oh);
}

void del_nick (char *old)
{
	struct hobyni *oh;
	HASH_FIND_STR(hostbynick, &old, oh);
	HASH_DEL_STR(hostbynick, oh);
	free(oh);
}

void add_nick (char *nick, char *user, char *host)
{
	struct hobyni *h;
	HASH_FIND_STR(hostbynick, &old, h);
	if (h!=NULL) {
		putlog(LOG_SERV, "*", "WARNING: attempt to add_nick() already existing nickname! %s", nick);
		HASH_DEL_STR(hostbynick, h);
		free(h);
	}
	h = (struct hobyni *)malloc(sizeof(struct hobyni));
	h->nick = strndup(nick,  60);
	h->user = strndup(user,  30);
	h->host = strndup(host, 291);
	HASH_ADD_STR(hostbynick, nick, h);
}

static hobyni *find_host_by_nick (char *nick)
{
	struct hobyni *h;
	HASH_FIND_STR(hostbynick, &nick, h);
	return h;
}

