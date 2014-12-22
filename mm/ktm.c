/*
 * Transparent Kernel Transactional Memory
 *
 * Author:  Steven M. Doyle <sdoyle@rent.com>
 *
 * This is just a nasty stub toy so I can do my development in
 * a loadable module.  It'll probably fall apart at some point,
 * but for now this is more convenient.
 */

#include <linux/linkage.h>
#include <linux/errno.h>
#include <linux/syscalls.h>

#include <asm/unistd.h>


typedef long (*txctl_handler_t)(int);

// Yup, this is unprotected.  It's just a hack, ma!  I swear!
static txctl_handler_t txctl_handler = NULL;

SYSCALL_DEFINE1(txctl, int, cmd) {
  if (!txctl_handler)
    return -ENOSYS;

  return txctl_handler(cmd);
}


void set_txctl_handler(txctl_handler_t which) {
  txctl_handler = which;
}

EXPORT_SYMBOL(set_txctl_handler);
