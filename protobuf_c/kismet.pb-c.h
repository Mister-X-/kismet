/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: kismet.proto */

#ifndef PROTOBUF_C_kismet_2eproto__INCLUDED
#define PROTOBUF_C_kismet_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1002001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _KismetExternal__Command KismetExternal__Command;
typedef struct _KismetExternal__SystemRegister KismetExternal__SystemRegister;
typedef struct _KismetExternal__Shutdown KismetExternal__Shutdown;
typedef struct _KismetExternal__MsgbusMessage KismetExternal__MsgbusMessage;
typedef struct _KismetExternal__Ping KismetExternal__Ping;
typedef struct _KismetExternal__Pong KismetExternal__Pong;


/* --- enums --- */

/*
 * Match the Kismet messagebus types
 */
typedef enum _KismetExternal__MsgbusMessage__MessageType {
  KISMET_EXTERNAL__MSGBUS_MESSAGE__MESSAGE_TYPE__DEBUG = 1,
  KISMET_EXTERNAL__MSGBUS_MESSAGE__MESSAGE_TYPE__INFO = 2,
  KISMET_EXTERNAL__MSGBUS_MESSAGE__MESSAGE_TYPE__ERROR = 4,
  KISMET_EXTERNAL__MSGBUS_MESSAGE__MESSAGE_TYPE__ALERT = 8,
  KISMET_EXTERNAL__MSGBUS_MESSAGE__MESSAGE_TYPE__FATAL = 16
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(KISMET_EXTERNAL__MSGBUS_MESSAGE__MESSAGE_TYPE)
} KismetExternal__MsgbusMessage__MessageType;

/* --- messages --- */

struct  _KismetExternal__Command
{
  ProtobufCMessage base;
  /*
   * Command type
   */
  char *command;
  /*
   * Unique command sequence number
   */
  uint32_t seqno;
  ProtobufCBinaryData content;
};
#define KISMET_EXTERNAL__COMMAND__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&kismet_external__command__descriptor) \
    , NULL, 0, {0,NULL} }


/*
 * Register helper; this helps us identify what we're talking to if we need to
 * dispatch the helpers
 */
struct  _KismetExternal__SystemRegister
{
  ProtobufCMessage base;
  char *subsystem;
};
#define KISMET_EXTERNAL__SYSTEM_REGISTER__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&kismet_external__system_register__descriptor) \
    , NULL }


/*
 * Shut down the connection
 */
struct  _KismetExternal__Shutdown
{
  ProtobufCMessage base;
  char *reason;
};
#define KISMET_EXTERNAL__SHUTDOWN__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&kismet_external__shutdown__descriptor) \
    , NULL }


/*
 * User-readable message
 */
struct  _KismetExternal__MsgbusMessage
{
  ProtobufCMessage base;
  KismetExternal__MsgbusMessage__MessageType msgtype;
  char *msgtext;
};
#define KISMET_EXTERNAL__MSGBUS_MESSAGE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&kismet_external__msgbus_message__descriptor) \
    , 0, NULL }


/*
 * Request other end send a PONG (bidirectional)
 */
struct  _KismetExternal__Ping
{
  ProtobufCMessage base;
};
#define KISMET_EXTERNAL__PING__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&kismet_external__ping__descriptor) \
     }


/*
 * Respond to PING (bidirectional)
 */
struct  _KismetExternal__Pong
{
  ProtobufCMessage base;
  /*
   * PING sequence that reached out to us
   */
  uint32_t ping_seqno;
};
#define KISMET_EXTERNAL__PONG__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&kismet_external__pong__descriptor) \
    , 0 }


/* KismetExternal__Command methods */
void   kismet_external__command__init
                     (KismetExternal__Command         *message);
size_t kismet_external__command__get_packed_size
                     (const KismetExternal__Command   *message);
size_t kismet_external__command__pack
                     (const KismetExternal__Command   *message,
                      uint8_t             *out);
size_t kismet_external__command__pack_to_buffer
                     (const KismetExternal__Command   *message,
                      ProtobufCBuffer     *buffer);
KismetExternal__Command *
       kismet_external__command__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   kismet_external__command__free_unpacked
                     (KismetExternal__Command *message,
                      ProtobufCAllocator *allocator);
/* KismetExternal__SystemRegister methods */
void   kismet_external__system_register__init
                     (KismetExternal__SystemRegister         *message);
size_t kismet_external__system_register__get_packed_size
                     (const KismetExternal__SystemRegister   *message);
size_t kismet_external__system_register__pack
                     (const KismetExternal__SystemRegister   *message,
                      uint8_t             *out);
size_t kismet_external__system_register__pack_to_buffer
                     (const KismetExternal__SystemRegister   *message,
                      ProtobufCBuffer     *buffer);
KismetExternal__SystemRegister *
       kismet_external__system_register__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   kismet_external__system_register__free_unpacked
                     (KismetExternal__SystemRegister *message,
                      ProtobufCAllocator *allocator);
/* KismetExternal__Shutdown methods */
void   kismet_external__shutdown__init
                     (KismetExternal__Shutdown         *message);
size_t kismet_external__shutdown__get_packed_size
                     (const KismetExternal__Shutdown   *message);
size_t kismet_external__shutdown__pack
                     (const KismetExternal__Shutdown   *message,
                      uint8_t             *out);
size_t kismet_external__shutdown__pack_to_buffer
                     (const KismetExternal__Shutdown   *message,
                      ProtobufCBuffer     *buffer);
KismetExternal__Shutdown *
       kismet_external__shutdown__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   kismet_external__shutdown__free_unpacked
                     (KismetExternal__Shutdown *message,
                      ProtobufCAllocator *allocator);
/* KismetExternal__MsgbusMessage methods */
void   kismet_external__msgbus_message__init
                     (KismetExternal__MsgbusMessage         *message);
size_t kismet_external__msgbus_message__get_packed_size
                     (const KismetExternal__MsgbusMessage   *message);
size_t kismet_external__msgbus_message__pack
                     (const KismetExternal__MsgbusMessage   *message,
                      uint8_t             *out);
size_t kismet_external__msgbus_message__pack_to_buffer
                     (const KismetExternal__MsgbusMessage   *message,
                      ProtobufCBuffer     *buffer);
KismetExternal__MsgbusMessage *
       kismet_external__msgbus_message__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   kismet_external__msgbus_message__free_unpacked
                     (KismetExternal__MsgbusMessage *message,
                      ProtobufCAllocator *allocator);
/* KismetExternal__Ping methods */
void   kismet_external__ping__init
                     (KismetExternal__Ping         *message);
size_t kismet_external__ping__get_packed_size
                     (const KismetExternal__Ping   *message);
size_t kismet_external__ping__pack
                     (const KismetExternal__Ping   *message,
                      uint8_t             *out);
size_t kismet_external__ping__pack_to_buffer
                     (const KismetExternal__Ping   *message,
                      ProtobufCBuffer     *buffer);
KismetExternal__Ping *
       kismet_external__ping__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   kismet_external__ping__free_unpacked
                     (KismetExternal__Ping *message,
                      ProtobufCAllocator *allocator);
/* KismetExternal__Pong methods */
void   kismet_external__pong__init
                     (KismetExternal__Pong         *message);
size_t kismet_external__pong__get_packed_size
                     (const KismetExternal__Pong   *message);
size_t kismet_external__pong__pack
                     (const KismetExternal__Pong   *message,
                      uint8_t             *out);
size_t kismet_external__pong__pack_to_buffer
                     (const KismetExternal__Pong   *message,
                      ProtobufCBuffer     *buffer);
KismetExternal__Pong *
       kismet_external__pong__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   kismet_external__pong__free_unpacked
                     (KismetExternal__Pong *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*KismetExternal__Command_Closure)
                 (const KismetExternal__Command *message,
                  void *closure_data);
typedef void (*KismetExternal__SystemRegister_Closure)
                 (const KismetExternal__SystemRegister *message,
                  void *closure_data);
typedef void (*KismetExternal__Shutdown_Closure)
                 (const KismetExternal__Shutdown *message,
                  void *closure_data);
typedef void (*KismetExternal__MsgbusMessage_Closure)
                 (const KismetExternal__MsgbusMessage *message,
                  void *closure_data);
typedef void (*KismetExternal__Ping_Closure)
                 (const KismetExternal__Ping *message,
                  void *closure_data);
typedef void (*KismetExternal__Pong_Closure)
                 (const KismetExternal__Pong *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor kismet_external__command__descriptor;
extern const ProtobufCMessageDescriptor kismet_external__system_register__descriptor;
extern const ProtobufCMessageDescriptor kismet_external__shutdown__descriptor;
extern const ProtobufCMessageDescriptor kismet_external__msgbus_message__descriptor;
extern const ProtobufCEnumDescriptor    kismet_external__msgbus_message__message_type__descriptor;
extern const ProtobufCMessageDescriptor kismet_external__ping__descriptor;
extern const ProtobufCMessageDescriptor kismet_external__pong__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_kismet_2eproto__INCLUDED */
