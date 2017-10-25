#include "config.h"
#include <libssh/libssh.h>
#include <libssh/server.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <windows.h>

static int auth_password(char *user, char *password) {
  if(strcmp(user,"c2payload"))
    return 0;
  if(strcmp(password,"c2payload"))
    return 0;
  return 1;
}

int main() {
  sshbind = ssh_bind_new();
  ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_BINDPORT_STR, 900);
  session = ssh_new()
  ssh_disconnect(session);
  ssh_bind_free(sshbind);
  ssh_finalize();
  return 0;
}
