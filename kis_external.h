/*
    This file is part of Kismet

    Kismet is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Kismet is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Kismet; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __KIS_EXTERNAL_H__
#define __KIS_EXTERNAL_H__

/* Kismet External Tool API
 *
 * This superclass marshals the external tool API and implements the kismet-level
 * commands and options; It should be subclassed by specific tool implementations,
 * such as data sources or plugins.
 *
 * More docs on the external tool api are in:
 * docs/dev/helper_interface.md
 *
 */

#include "config.h"

#include <functional>

#include "globalregistry.h"
#include "buffer_handler.h"
#include "ipc_remote2.h"

#include "protobuf_cpp/kismet.pb.h"

class KisExternalInterface : public BufferInterface {
public:
    KisExternalInterface(GlobalRegistry *in_globalreg);
    virtual ~KisExternalInterface();

    // Connect an existing buffer, such as a TCP socket or IPC pipe
    virtual void connect_buffer(std::shared_ptr<BufferHandlerGeneric> in_ringbuf);

    // Trigger an error condition and call all the related functions
    virtual void trigger_error(std::string reason);

    // Buffer interface - called when the attached ringbuffer has data available.
    virtual void BufferAvailable(size_t in_amt);

    // Buffer interface - handles error on IPC or TCP, called when there is a 
    // low-level error on the communications stack (process death, etc).
    // Passes error to the the internal source_error function
    virtual void BufferError(std::string in_error);

    // Launch the external binary and connect the IPC channel to our buffer
    // interface; most tools will use this unless they support network; 
    // datasources are the primary exception
    virtual bool launch_ipc();

    // Close the external interface
    virtual void close_external();

protected:
    // Wrap a protobuf'd packet in our network framing and send it
    virtual bool send_packet(std::shared_ptr<KismetExternal::Command> c);

    // Central packet dispatch handler
    virtual void dispatch_rx_packet(std::shared_ptr<KismetExternal::Command> c);

    // Packet handlers
    virtual void handle_packet_message(uint32_t in_seqno, std::string in_content);
    virtual void handle_packet_ping(uint32_t in_seqno, std::string in_content);
    virtual void handle_packet_pong(uint32_t in_seqno, std::string in_content);
    virtual void handle_packet_shutdown(uint32_t in_seqno, std::string in_content);

    void send_ping();
    void send_pong(uint32_t ping_seqno);
    void send_shutdown(std::string reason);


    kis_recursive_timed_mutex ext_mutex;

    // Communications API.  We implement a buffer interface and listen to the
    // incoming read buffer, we're agnostic if it's a network or IPC buffer.
    std::shared_ptr<BufferHandlerGeneric> ringbuf_handler;

    // If we're an IPC instance, the IPC control.  The ringbuf_handler is associated
    // with the IPC instance.
    std::shared_ptr<IPCRemoteV2> ipc_remote;

    GlobalRegistry *globalreg;

    std::shared_ptr<Timetracker> timetracker;

    uint32_t seqno;

    time_t last_pong;

    std::string external_binary;

    int ping_timer_id;
};


#endif

