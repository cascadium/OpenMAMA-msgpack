/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Cascadium Ltd (http://cascadium.io)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*=========================================================================
  =                             Includes                                  =
  =========================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS
#endif

#include <mama/mama.h>
#include <mama/price.h>

#include "msgpackmsgpayloadfunctions.h"
#include <wombat/strutils.h>
#include <mama/integration/types.h>
#include <mama/integration/mama.h>
#include <mama/integration/bridge/omnmmsgpayloadfunctions.h>
#include <mama/integration/bridge/omnmmsgpayloadimpl.h>
#include "bridge.h"


mama_status
msgpackmsgPayload_init(mamaPayloadBridge bridge, char *identifier) {
    *identifier = (char) MAMA_PAYLOAD_ID_MSGPACK;

    /* Will set the bridge's compile time MAMA version */
    MAMA_SET_BRIDGE_COMPILE_TIME_VERSION("msgpackmsg");

    return MAMA_STATUS_OK;
}

MAMAIgnoreDeprecatedOpen

mamaPayloadType
msgpackmsgPayload_getType(void) {
    return (mamaPayloadType) MAMA_PAYLOAD_ID_MSGPACK;
}

MAMAIgnoreDeprecatedClose

mama_status
msgpackmsgPayload_create(msgPayload *msg) {
    if (NULL == msg) return MAMA_STATUS_NULL_ARG;
    msgpackPayloadImpl *impl = (msgpackPayloadImpl *) calloc(1, sizeof(msgpackPayloadImpl));
    mama_status status = omnmmsgPayload_create(&impl->mOmnmPayload);
    if (status != MAMA_STATUS_OK) return status;

    msgpack_sbuffer_init(&impl->mBuffer);

    /* serialize values into the buffer using msgpack_sbuffer_write callback function. */
    msgpack_packer_init(&impl->mPacker, &impl->mBuffer, msgpack_sbuffer_write);

//    msgpack_pack_array(&impl->mPacker, 3);
//    msgpack_pack_int(&impl->mPacker, 1);

    /* deserialize the buffer into msgpack_object instance. */
    /* deserialized object is valid during the msgpack_zone instance alive. */
    msgpack_zone_init(&impl->mDeserializationZone, MSGPACK_CHUNK_SIZE);

    status = omnmmsgPayloadImpl_setExtenderClosure(impl->mOmnmPayload, impl);
    if (status != MAMA_STATUS_OK) return status;
    *msg = impl->mOmnmPayload;
    return MAMA_STATUS_OK;
}

mama_status
msgpackmsgPayload_destroy(msgPayload msg) {
    if (NULL == msg) return MAMA_STATUS_NULL_ARG;
    msgpackPayloadImpl *impl = NULL;
    mama_status status = omnmmsgPayloadImpl_getExtenderClosure(msg, (const void **) &impl);
    if (status != MAMA_STATUS_OK) return status;
    msgpack_zone_destroy(&impl->mDeserializationZone);
    msgpack_sbuffer_destroy(&impl->mBuffer);
    free(impl);
    return omnmmsgPayload_destroy(msg);
}

mama_status
msgpackmsgPayload_copy(const msgPayload msg,
                       msgPayload *copy) {
    if (NULL == msg || NULL == copy) return MAMA_STATUS_NULL_ARG;
    mama_status status = omnmmsgPayload_copy(msg, copy);
    if (status != MAMA_STATUS_OK) return status;
    msgpackPayloadImpl *impl = (msgpackPayloadImpl *) calloc(1, sizeof(msgpackPayloadImpl));
    impl->mOmnmPayload = copy;
    omnmmsgPayloadImpl_setExtenderClosure(copy, (void *) impl);
    return MAMA_STATUS_OK;
}

#pragma pack(push, 1)
typedef struct omMsgpackMamaDateTime {
    int64_t mSeconds;
    uint32_t mNanoseconds;
    uint8_t mPrecision;
    uint8_t mHints;
} serializedMamaDateTime;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct omMsgpackPrice {
    double mValue;
    uint8_t mPrecision;
    uint8_t mHints;
} serializedPrice;
#pragma pack(pop)

mama_status
msgpackmsgPayloadImpl_serialize_field(msgpackPayloadImpl *impl,
                                      msgFieldPayload field) {

    // MAMA Types

    //mama_bool_t       true / false
    //char              uint 8
    //mama_u8_t         uint 8
    //mama_i8_t         int 8
    //mama_u16_t        uint 16
    //mama_i16_t        int 16
    //mama_u32_t        uint 32
    //mama_i32_t        int 32
    //mama_u64_t        uint 64
    //mama_i64_t        int 64
    //mama_f32_t        float 32
    //mama_f64_t        float 64
    //string            str 32
    //msg               map 16
    //opaque            bin 32
    //datetime          fixext 16
    //price             fixext 16
    //I8 vector         array 16 (arrays can be lists)
    //U8 vector         array 16
    //bool vector       array 16
    //char vector       array 16
    //u16 vector        array 16
    //i16 vector        array 16
    //u32 vector        array 16
    //i32 vector        array 16
    //u64 vector        array 16
    //i64 vector        array 16
    //f32 vector        array 16
    //f64 vector        array 16
    //string vector     array 16
    //msg vector        array 16
    //price vector      array 16
    //datetime vector   array 16

    mamaFieldType type;
    omnmmsgFieldPayload_getType(field, &type);
    mama_fid_t fid;
    mama_status status = msgpackmsgFieldPayload_getFid(field, NULL, NULL, &fid);
    const char* name = NULL;
    msgpackmsgFieldPayload_getName(field, NULL, NULL, &name);

    // 2 values = fid and name
    if (name != NULL && fid > 0) {
        msgpack_pack_array(&impl->mPacker, 2);
    }
    if (fid > 0) {
        msgpack_pack_uint16(&impl->mPacker, fid);
    }
    if (name != NULL) {
        size_t strlen = strlenEx(name);
        msgpack_pack_str(&impl->mPacker, strlen);
        msgpack_pack_str_body(&impl->mPacker, name, strlen);
    }

    switch(type) {
        case MAMA_FIELD_TYPE_OPAQUE: {
            const void* value;
            mama_size_t valueLen;
            omnmmsgFieldPayload_getOpaque(field, &value, &valueLen);
            msgpack_pack_bin(&impl->mPacker, valueLen);
            msgpack_pack_bin_body(&impl->mPacker, value, valueLen);
            break;
        }
        case MAMA_FIELD_TYPE_STRING: {
            const char* value;
            omnmmsgFieldPayload_getString(field, &value);
            size_t valueLen = strlenEx(value);
            msgpack_pack_str(&impl->mPacker, valueLen);
            msgpack_pack_str_body(&impl->mPacker, value, valueLen);
            break;
        }
        case MAMA_FIELD_TYPE_BOOL: {
            mama_bool_t value;
            omnmmsgFieldPayload_getBool(field, &value);
            if (value) {
                msgpack_pack_true(&impl->mPacker);
            } else {
                msgpack_pack_false(&impl->mPacker);
            }
            break;
        }
        case MAMA_FIELD_TYPE_I8: {
            mama_i8_t value;
            omnmmsgFieldPayload_getI8(field, &value);
            msgpack_pack_int8(&impl->mPacker, value);
            break;
        }
        case MAMA_FIELD_TYPE_U8: {
            mama_u8_t value;
            omnmmsgFieldPayload_getU8(field, &value);
            msgpack_pack_uint8(&impl->mPacker, value);
            break;
        }
        case MAMA_FIELD_TYPE_I16: {
            mama_i16_t value;
            omnmmsgFieldPayload_getI16(field, &value);
            msgpack_pack_int16(&impl->mPacker, value);
            break;
        }
        case MAMA_FIELD_TYPE_U16: {
            mama_u16_t value;
            omnmmsgFieldPayload_getU16(field, &value);
            msgpack_pack_uint16(&impl->mPacker, value);
            break;
        }
        case MAMA_FIELD_TYPE_I32: {
            mama_i32_t value;
            omnmmsgFieldPayload_getI32(field, &value);
            msgpack_pack_int32(&impl->mPacker, value);
            break;
        }
        case MAMA_FIELD_TYPE_U32: {
            mama_u32_t value;
            omnmmsgFieldPayload_getU32(field, &value);
            msgpack_pack_uint32(&impl->mPacker, value);
            break;
        }
        case MAMA_FIELD_TYPE_I64: {
            mama_i64_t value;
            omnmmsgFieldPayload_getI64(field, &value);
            msgpack_pack_int64(&impl->mPacker, value);
            break;
        }
        case MAMA_FIELD_TYPE_U64: {
            mama_u64_t value;
            omnmmsgFieldPayload_getU64(field, &value);
            msgpack_pack_uint64(&impl->mPacker, value);
            break;
        }
        case MAMA_FIELD_TYPE_F32: {
            mama_f32_t value;
            omnmmsgFieldPayload_getF32(field, &value);
            msgpack_pack_float(&impl->mPacker, value);
            break;
        }
        case MAMA_FIELD_TYPE_F64: {
            mama_f64_t value;
            omnmmsgFieldPayload_getF64(field, &value);
            msgpack_pack_double(&impl->mPacker, value);
            break;
        }
        case MAMA_FIELD_TYPE_CHAR: {
            char value;
            omnmmsgFieldPayload_getChar(field, &value);
            msgpack_pack_char(&impl->mPacker, value);
            break;
        }
        case MAMA_FIELD_TYPE_TIME: {
            mamaDateTime value;
            mamaDateTimeHints hints;
            mamaDateTimePrecision precision;
            struct omMsgpackMamaDateTime mpdt;
            struct timespec ts;
            mamaDateTime_create(&value);
            omnmmsgFieldPayload_getDateTime(field, value);
            mamaDateTime_getStructTimeSpec(value, &ts);
            mamaDateTime_getHints(value, &hints);
            mamaDateTime_getPrecision(value, &precision);

            mpdt.mSeconds = htonll(ts.tv_sec);
            mpdt.mNanoseconds = htonl(ts.tv_nsec);
            mpdt.mHints = hints;
            mpdt.mPrecision = precision;

            msgpack_pack_ext(&impl->mPacker, sizeof(mpdt), MAMA_FIELD_TYPE_TIME);
            msgpack_pack_ext_body(&impl->mPacker, &mpdt, sizeof(mpdt));
            mamaDateTime_destroy(value);
            break;
        }
        case MAMA_FIELD_TYPE_PRICE: {
            mamaPrice value;
            mamaPricePrecision precision;
            struct omMsgpackPrice mpp;

            mamaPrice_create(&value);
            omnmmsgFieldPayload_getPrice(field, value);
            mamaPrice_getValue(value, &mpp.mValue);
            mamaPrice_getHints(value, &mpp.mHints);
            mamaPrice_getPrecision(value, &precision);
            mpp.mPrecision = (uint8_t)precision;

            msgpack_pack_ext(&impl->mPacker, sizeof(mpp), MAMA_FIELD_TYPE_PRICE);
            msgpack_pack_ext_body(&impl->mPacker, &mpp, sizeof(mpp));
            mamaPrice_destroy(value);
            break;
        }
        case MAMA_FIELD_TYPE_VECTOR_BOOL: {
            break;
        }
        case MAMA_FIELD_TYPE_VECTOR_CHAR: {
            break;
        }
        case MAMA_FIELD_TYPE_VECTOR_I8: {
            break;
        }
        case MAMA_FIELD_TYPE_VECTOR_U8: {
            break;
        }
        case MAMA_FIELD_TYPE_VECTOR_I16: {
            break;
        }
        case MAMA_FIELD_TYPE_VECTOR_U16: {
            break;
        }
        case MAMA_FIELD_TYPE_VECTOR_I32: {
            break;
        }
        case MAMA_FIELD_TYPE_VECTOR_U32: {
            break;
        }
        case MAMA_FIELD_TYPE_VECTOR_I64: {
            break;
        }
        case MAMA_FIELD_TYPE_VECTOR_U64: {
            break;
        }
        case MAMA_FIELD_TYPE_VECTOR_F32: {
            break;
        }
        case MAMA_FIELD_TYPE_VECTOR_F64: {
            break;
        }
        case MAMA_FIELD_TYPE_VECTOR_STRING: {
            break;
        }
        case MAMA_FIELD_TYPE_MSG: {
            break;
        }
        case MAMA_FIELD_TYPE_VECTOR_MSG: {
            break;
        }
        case MAMA_FIELD_TYPE_VECTOR_TIME:
        case MAMA_FIELD_TYPE_VECTOR_PRICE:
        case MAMA_FIELD_TYPE_QUANTITY:
        case MAMA_FIELD_TYPE_COLLECTION:
        case MAMA_FIELD_TYPE_UNKNOWN:
        default:
            break;
    }
}

mama_status
msgpackmsgPayload_serialize(const msgPayload msg,
                            const void **buffer,
                            mama_size_t *bufferLength) {
    mama_status status;
    msgPayloadIter iter = NULL;
    status = omnmmsgPayloadIter_create(&iter, msg);
    if (status != MAMA_STATUS_OK) return status;
    status = omnmmsgPayloadIter_associate(iter, msg);
    if (status != MAMA_STATUS_OK) return status;
    msgpackPayloadImpl *impl = NULL;
    status = omnmmsgPayloadImpl_getExtenderClosure(msg, (const void **) &impl);
    if (status != MAMA_STATUS_OK) return status;

    msgFieldPayload field;

    // Add the map - all will be added to this since a MAMA Message is effectively a composite-key map
    mama_size_t numFields = 0;
    msgpackmsgPayload_getNumFields(msg, &numFields);
    msgpack_pack_map(&impl->mPacker, numFields);
    while (NULL != (field = omnmmsgPayloadIter_next(iter, NULL, msg))) {
        msgpackmsgPayloadImpl_serialize_field(impl, field);
    }
    *buffer = (const void *)impl->mBuffer.data;
    *bufferLength = (mama_size_t)impl->mBuffer.size;

    return MAMA_STATUS_OK;
}



mama_status
msgpackmsgPayloadImpl_deserialize_field(msgpackPayloadImpl *impl,
                                        msgpack_object* key,
                                        msgpack_object* value) {
    mama_fid_t fid = 0;
    const char* name = NULL;
    switch (key->type) {
        case MSGPACK_OBJECT_POSITIVE_INTEGER:
            fid = key->via.i64;
            break;
        case MSGPACK_OBJECT_STR:
            name = key->via.str.ptr;
            break;
        case MSGPACK_OBJECT_ARRAY:
            fid = key->via.array.ptr[0].via.u64;
            name = key->via.array.ptr[0].via.str.ptr;
            break;
        default:
            break;
    }
    switch(value->type) {
        case MSGPACK_OBJECT_NIL:
            break;
        case MSGPACK_OBJECT_BOOLEAN: {
            mama_bool_t val = value->via.boolean;
            msgpackmsgPayload_addBool(impl->mOmnmPayload, name, fid, val);
            break;
        }
        case MSGPACK_OBJECT_POSITIVE_INTEGER: {
            uint64_t val = value->via.u64;
            // Attempt to use smallest field type possible... OMNM complains if a call to getIX is made where
            // the underlying data type may overflow, so err on the side of caution.
            if (val <= UINT8_MAX) {
                msgpackmsgPayload_addU8(impl->mOmnmPayload, name, fid, (mama_u8_t) val);
            } else if (val <= UINT16_MAX) {
                msgpackmsgPayload_addU16(impl->mOmnmPayload, name, fid, (mama_u16_t) val);
            } else if (val <= UINT32_MAX) {
                msgpackmsgPayload_addU32(impl->mOmnmPayload, name, fid, (mama_u32_t) val);
            } else {
                msgpackmsgPayload_addU64(impl->mOmnmPayload, name, fid, (mama_u64_t) val);
            }
            break;
        }
        case MSGPACK_OBJECT_NEGATIVE_INTEGER: {
            int64_t val = value->via.i64;
            // Attempt to use smallest field type possible... OMNM complains if a call to getIX is made where
            // the underlying data type may overflow, so err on the side of caution.
            if (val >= INT8_MIN) {
                msgpackmsgPayload_addI8(impl->mOmnmPayload, name, fid, (mama_i8_t) val);
            } else if (val >= INT16_MIN) {
                msgpackmsgPayload_addI16(impl->mOmnmPayload, name, fid, (mama_i16_t) val);
            } else if (val >= INT32_MIN) {
                msgpackmsgPayload_addI32(impl->mOmnmPayload, name, fid, (mama_i32_t) val);
            } else {
                msgpackmsgPayload_addI64(impl->mOmnmPayload, name, fid, (mama_i64_t) val);
            }
            break;
        }
        case MSGPACK_OBJECT_FLOAT32: {
            mama_f32_t val = (mama_f32_t)value->via.f64;
            msgpackmsgPayload_addF32(impl->mOmnmPayload, name, fid, val);
            break;
        }
        case MSGPACK_OBJECT_FLOAT64: {
            mama_f64_t val = value->via.f64;
            msgpackmsgPayload_addF64(impl->mOmnmPayload, name, fid, val);
            break;
        }
        case MSGPACK_OBJECT_STR: {
            char* val = (char*) value->via.str.ptr;
            val[value->via.str.size] = '\0';
            msgpackmsgPayload_addString(impl->mOmnmPayload, name, fid, (const char*)val);
            break;
        }
        case MSGPACK_OBJECT_ARRAY:
            // This is a vector
            break;
        case MSGPACK_OBJECT_MAP:
            // This is a nested message
            break;
        case MSGPACK_OBJECT_BIN: {
            const void* val = value->via.bin.ptr;
            mama_size_t valLen = value->via.bin.size;
            msgpackmsgPayload_addOpaque(impl->mOmnmPayload, name, fid, val, valLen);
            break;
        }
        case MSGPACK_OBJECT_EXT:
            // This may be a price or a datetime object
            switch (value->via.ext.type) {
                case MAMA_FIELD_TYPE_TIME:
                    // Only proceed if this is a message length that we understand
                    if (value->via.ext.size == sizeof(struct omMsgpackMamaDateTime)) {
                        struct omMsgpackMamaDateTime* omdt = (struct omMsgpackMamaDateTime*)value->via.ext.ptr;
                        mamaDateTime val;
                        mamaDateTime_create(&val);
                        struct timespec ts;
                        ts.tv_sec = ntohll(omdt->mSeconds);
                        ts.tv_nsec = ntohl(omdt->mNanoseconds);

                        mamaDateTime_setFromStructTimeSpec(val, &ts);
                        mamaDateTime_setHints(val, omdt->mHints);
                        mamaDateTime_setPrecision(val, omdt->mPrecision);
                        msgpackmsgPayload_addDateTime(impl->mOmnmPayload, name, fid, val);
                        mamaDateTime_destroy(val);
                    }
                    break;
                case MAMA_FIELD_TYPE_PRICE:
                    // Only proceed if this is a message length that we understand
                    if (value->via.ext.size == sizeof(struct omMsgpackPrice)) {
                        struct omMsgpackPrice* omp = (struct omMsgpackPrice*)value->via.ext.ptr;
                        mamaPrice val;
                        mamaPrice_create(&val);

                        mamaPrice_setValue(val, omp->mValue);
                        mamaPrice_setHints(val, omp->mHints);
                        mamaPrice_setPrecision(val, omp->mPrecision);
                        msgpackmsgPayload_addPrice(impl->mOmnmPayload, name, fid, val);
                        mamaPrice_destroy(val);
                    }
                    break;
                default:
                    break;
            }
            break;
    }
    return MAMA_STATUS_OK;
}

mama_status
msgpackmsgPayload_unSerialize(const msgPayload msg,
                              const void *buffer,
                              mama_size_t bufferLength) {
    // Reading from msgpack

    //positive fixint	0xxxxxxx	0x00 - 0x7f [< 128]             mama_i8_t
    //negative fixint	111xxxxx	0xe0 - 0xff [> -32]             mama_i8_t
    //fixmap	        1000xxxx	0x80 - 0x8f [< 16 elements]     mamaMsg
    //fixarray	        1001xxxx	0x90 - 0x9f [< 16 elements]     vector<type>
    //fixstr	        101xxxxx	0xa0 - 0xbf [< 16 elements]     string
    //false	            11000010	0xc2                            mama_bool_t
    //true	            11000011	0xc3                            mama_bool_t
    //bin 8	            11000100	0xc4                            opaque
    //bin 16	        11000101	0xc5                            opaque
    //bin 32	        11000110	0xc6                            opaque
    //float 32	        11001010	0xca                            mama_f32_t
    //float 64	        11001011	0xcb                            mama_f64_t
    //uint 8	        11001100	0xcc                            mama_u8_t
    //uint 16	        11001101	0xcd                            mama_u16_t
    //uint 32	        11001110	0xce                            mama_u32_t
    //uint 64	        11001111	0xcf                            mama_u64_t
    //int 8	            11010000	0xd0                            mama_i8_t
    //int 16	        11010001	0xd1                            mama_i16_t
    //int 32	        11010010	0xd2                            mama_i32_t
    //int 64	        11010011	0xd3                            mama_i64_t
    //str 8	            11011001	0xd9                            string
    //str 16	        11011010	0xda                            string
    //str 32	        11011011	0xdb                            string
    //array 16	        11011110	0xde                            vector<type from first element>
    //map 16	        11011110	0xde                            mamaMsg

    // Not mapped:
    //   - nil
    //   - (never used)
    //   - ext8
    //   - ext16
    //   - ext32
    //   - fixext 1
    //   - fixext 2
    //   - fixext 4
    //   - fixext 8
    //   - fixext 16 (except price and datetime)
    //   - array 32
    //   - map 32

    // Create iterator

    msgpackPayloadImpl *impl = NULL;
    mama_status status = omnmmsgPayloadImpl_getExtenderClosure(msg, (const void **) &impl);
    if (status != MAMA_STATUS_OK) return status;
    msgpackmsgPayload_clear(msg);

    msgpack_object deserialized;
    msgpack_zone_clear(&impl->mDeserializationZone);
    msgpack_unpack(buffer, bufferLength, NULL, &impl->mDeserializationZone, &deserialized);
    // This will return a MAP
    if (deserialized.type == MSGPACK_OBJECT_MAP) {
        msgpack_object_map* map = &deserialized.via.map;
        for (int i = 0; i < map->size; i++) {
            msgpack_object_kv* kv = &map->ptr[0];
            msgpackmsgPayloadImpl_deserialize_field(impl, &kv->key, &kv->val);
        }
    }
    return MAMA_STATUS_OK;
}

mama_status
msgpackmsgPayload_getByteBuffer(const msgPayload msg,
                                const void **buffer,
                                mama_size_t *bufferLength) {
    return msgpackmsgPayload_serialize(msg, buffer, bufferLength);
}

/*
 * Note this function sets an underlying implementation handle - not
 * necessarily a serialized version of the message.
 */
mama_status
msgpackmsgPayload_setByteBuffer(const msgPayload msg,
                                mamaPayloadBridge bridge,
                                const void *buffer,
                                mama_size_t bufferLength) {
    return msgpackmsgPayload_unSerialize(msg, buffer, bufferLength);
}

mama_status
msgpackmsgPayload_createFromByteBuffer(msgPayload *msg,
                                       mamaPayloadBridge bridge,
                                       const void *buffer,
                                       mama_size_t bufferLength) {
    mama_status status = msgpackmsgPayload_create(msg);
    if (status != MAMA_STATUS_OK) return status;
    return msgpackmsgPayload_unSerialize(msg, buffer, bufferLength);
}