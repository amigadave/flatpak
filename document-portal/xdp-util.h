#ifndef XDP_UTIL_H
#define XDP_UTIL_H

#include <gio/gio.h>
#include "xdg-app-db.h"
#include "xdp-enums.h"

G_BEGIN_DECLS

const char **      xdg_unparse_permissions (XdpPermissionFlags   permissions);
XdpPermissionFlags xdp_parse_permissions   (const char         **permissions);

XdpPermissionFlags xdp_entry_get_permissions (XdgAppDbEntry      *entry,
                                              const char         *app_id);
gboolean           xdp_entry_has_permissions (XdgAppDbEntry      *entry,
                                              const char         *app_id,
                                              XdpPermissionFlags  perms);
const char *       xdp_entry_get_path        (XdgAppDbEntry      *entry);
char *             xdp_entry_dup_basename    (XdgAppDbEntry      *entry);
char *             xdp_entry_dup_dirname     (XdgAppDbEntry      *entry);
guint64            xdp_entry_get_device      (XdgAppDbEntry      *entry);
guint64            xdp_entry_get_inode       (XdgAppDbEntry      *entry);
int                xdp_entry_open_dir        (XdgAppDbEntry      *entry);
int                xdp_entry_stat            (XdgAppDbEntry      *entry,
                                              struct stat        *buf,
                                              int                 flags);

guint32 xdp_id_from_name (const char *name);
char *  xdp_name_from_id (guint32     doc_id);


void  xdp_invocation_lookup_app_id        (GDBusMethodInvocation  *invocation,
                                           GCancellable           *cancellable,
                                           GAsyncReadyCallback     callback,
                                           gpointer                user_data);

char *xdp_invocation_lookup_app_id_finish (GDBusMethodInvocation  *invocation,
                                           GAsyncResult           *result,
                                           GError                **error);

void  xdp_connection_track_name_owners    (GDBusConnection        *connection);

G_END_DECLS

#endif /* XDP_UTIL_H */