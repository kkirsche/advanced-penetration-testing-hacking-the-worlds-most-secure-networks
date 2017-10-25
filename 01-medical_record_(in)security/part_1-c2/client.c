#include <libssh/libssh.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main()
{
  ssh_session my_ssh_session;
  int rc;
  char *password;

  my_ssh_session = ssh_new();
  if (my_ssh_session == NULL)
    exit(-1);

  ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, "c2host");
  ssh_options_set(my_ssh_session, SSH_OPTIONS_PORT, 443);
  ssh_options_set(my_ssh_session, SSH_OPTIONS_USER, "c2user");

  rc = ssh_connect(my_ssh_session);
  if (verify_knownhost(my_ssh_session) < 0)
  {
    ssh_disconnect(my_ssh_session);
    ssh_free(my_ssh_session);
    exit(-1);
  }

  password = ("Password");
  rc = ssh_userauth_password(my_ssh_session, NULL, password);
  ssh_disconnect(my_ssh_session);
  ssh_free(my_ssh_session);
}
