/* SPDX-License-Identifier: Apache-2.0 */

/*
 * Copyright 2018-2023 Joel E. Anderson
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/** @file
 * Socket targets allow logs to be sent to a Unix domain socket.
 *
 * The most common use for socket targets is to send logs to /dev/log,
 * /var/run/syslog, or whatever socket the syslog daemon is listening on.
 *
 * **Thread Safety: MT-Safe**
 * Logging to socket targets is thread safe by virtue of using the `sendto`
 * function, which is thread safe itself.
 *
 * **Async Signal Safety: AS-Unsafe lock**
 * Logging to socket targets is not signal safe, as a non-reentrant lock is used
 * to coordinate the read of the entry with other potential accesses.
 *
 * **Async Cancel Safety: AC-Unsafe lock**
 * Logging to socket targets is not safe to call from threads that may be
 * asynchronously cancelled, as the cleanup of the lock used for entries may not
 * be completed.
 */

#ifndef __STUMPLESS_TARGET_SOCKET_H
#  define __STUMPLESS_TARGET_SOCKET_H

#  include <stumpless/config.h>
#  include <stumpless/target.h>

#  ifdef __cplusplus
extern "C" {
#  endif

/**
 * Closes a socket target.
 *
 * This function closes the socket target, as well as the connection to the
 * target socket.
 *
 * **Thread Safety: MT-Unsafe**
 * This function is not thread safe as it destroys resources that other threads
 * would use if they tried to reference this target.
 *
 * **Async Signal Safety: AS-Unsafe lock heap**
 * This function is not safe to call from signal handlers due to the destruction
 * of a lock that may be in use as well as the use of the memory deallocation
 * function to release memory.
 *
 * **Async Cancel Safety: AC-Unsafe lock heap**
 * This function is not safe to call from threads that may be asynchronously
 * cancelled, as the cleanup of the lock may not be completed, and the memory
 * deallocation function may not be AC-Safe itself.
 *
 * @param target The socket target to close.
 */
STUMPLESS_PUBLIC_FUNCTION
void
stumpless_close_socket_target( const struct stumpless_target *target );

/**
 * Opens a socket target.
 *
 * **Thread Safety: MT-Safe race:name race:local_socket**
 * This function is thread safe, of course assuming that the target name and
 * socket name are not modified by any other threads during execution.
 *
 * **Async Signal Safety: AS-Unsafe heap**
 * This function is not safe to call from signal handlers due to the use of
 * memory allocation functions.
 *
 * **Async Cancel Safety: AC-Unsafe heap**
 * This function is not safe to call from threads that may be asynchronously
 * cancelled, as the memory allocation function may not be AC-Safe itself.
 *
 * @param name The name of the socket target, and the socket to send logs to.
 *
 * @param local_socket The name of the Unix domain socket to connect from. This
 * can be set to NULL if you'd like to use the default name of stumpless-socket.
 * If abstract socket names are supported, then this name will be abstract and
 * therefore not appear in the filesystem.
 *
 * @return The opened target if no error is encountered. In the event of an
 * error, NULL is returned and an error code is set appropriately.
 */
STUMPLESS_PUBLIC_FUNCTION
struct stumpless_target *
stumpless_open_socket_target( const char *name, const char *local_socket );

#  ifdef __cplusplus
}                               /* extern "C" */
#  endif
#endif                          /* __STUMPLESS_TARGET_SOCKET_H */
