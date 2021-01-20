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

#include "msgpackmsgpayloadfunctions.h"
#include "bridge.h"
#include <mama/integration/bridge/omnmmsgpayloadfunctions.h>
#include <mama/integration/bridge/omnmmsgpayloadimpl.h>
#include <mama/integration/msg.h>


mama_status
msgpackmsgFieldPayload_create(msgFieldPayload *field) {
    return omnmmsgFieldPayload_create(field);
}

mama_status
msgpackmsgFieldPayload_destroy(msgFieldPayload field) {
    return omnmmsgFieldPayload_destroy(field);
}

mama_status
msgpackmsgFieldPayload_getType(const msgFieldPayload field,
                               mamaFieldType *result) {
    return omnmmsgFieldPayload_getType(field, result);
}

mama_status
msgpackmsgFieldPayload_getName(msgFieldPayload field,
                               mamaDictionary dict,
                               mamaFieldDescriptor desc,
                               const char **result) {
    return omnmmsgFieldPayload_getName(field, dict, desc, result);
}

mama_status
msgpackmsgFieldPayload_getFid(const msgFieldPayload field,
                              mamaDictionary dict,
                              mamaFieldDescriptor desc,
                              uint16_t *result) {
    return omnmmsgFieldPayload_getFid(field, dict, desc, result);
}

mama_status
msgpackmsgFieldPayload_getDescriptor(const msgFieldPayload field,
                                     mamaDictionary dict,
                                     mamaFieldDescriptor *result) {
    return omnmmsgFieldPayload_getDescriptor(field, dict, result);
}

mama_status
msgpackmsgFieldPayload_updateBool(msgFieldPayload field,
                                  msgPayload msg,
                                  mama_bool_t value) {
    return omnmmsgFieldPayload_updateBool(field, msg, value);
}

mama_status
msgpackmsgFieldPayload_updateChar(msgFieldPayload field,
                                  msgPayload msg,
                                  char value) {
    return omnmmsgFieldPayload_updateChar(field, msg, value);
}

mama_status
msgpackmsgFieldPayload_updateI8(msgFieldPayload field,
                                msgPayload msg,
                                mama_i8_t value) {
    return omnmmsgFieldPayload_updateI8(field, msg, value);
}

mama_status
msgpackmsgFieldPayload_updateU8(msgFieldPayload field,
                                msgPayload msg,
                                mama_u8_t value) {
    return omnmmsgFieldPayload_updateU8(field, msg, value);
}

mama_status
msgpackmsgFieldPayload_updateI16(msgFieldPayload field,
                                 msgPayload msg,
                                 mama_i16_t value) {
    return omnmmsgFieldPayload_updateI16(field, msg, value);
}

mama_status
msgpackmsgFieldPayload_updateU16(msgFieldPayload field,
                                 msgPayload msg,
                                 mama_u16_t value) {
    return omnmmsgFieldPayload_updateU16(field, msg, value);
}

mama_status
msgpackmsgFieldPayload_updateI32(msgFieldPayload field,
                                 msgPayload msg,
                                 mama_i32_t value) {
    return omnmmsgFieldPayload_updateI32(field, msg, value);
}

mama_status
msgpackmsgFieldPayload_updateU32(msgFieldPayload field,
                                 msgPayload msg,
                                 mama_u32_t value) {
    return omnmmsgFieldPayload_updateU32(field, msg, value);
}

mama_status
msgpackmsgFieldPayload_updateI64(msgFieldPayload field,
                                 msgPayload msg,
                                 mama_i64_t value) {
    return omnmmsgFieldPayload_updateI64(field, msg, value);
}

mama_status
msgpackmsgFieldPayload_updateU64(msgFieldPayload field,
                                 msgPayload msg,
                                 mama_u64_t value) {
    return omnmmsgFieldPayload_updateU64(field, msg, value);
}

mama_status
msgpackmsgFieldPayload_updateF32(msgFieldPayload field,
                                 msgPayload msg,
                                 mama_f32_t value) {
    return omnmmsgFieldPayload_updateF32(field, msg, value);
}

mama_status
msgpackmsgFieldPayload_updateF64(msgFieldPayload field,
                                 msgPayload msg,
                                 mama_f64_t value) {
    return omnmmsgFieldPayload_updateF64(field, msg, value);
}

mama_status
msgpackmsgFieldPayload_updateString(msgFieldPayload field,
                                    msgPayload msg,
                                    const char *str) {
    return omnmmsgFieldPayload_updateString(field, msg, str);
}

mama_status
msgpackmsgFieldPayload_updateDateTime(msgFieldPayload field,
                                      msgPayload msg,
                                      const mamaDateTime value) {
    return omnmmsgFieldPayload_updateDateTime(field, msg, value);
}

mama_status
msgpackmsgFieldPayload_updatePrice(msgFieldPayload field,
                                   msgPayload msg,
                                   const mamaPrice value) {
    return omnmmsgFieldPayload_updatePrice(field, msg, value);
}

mama_status
msgpackmsgFieldPayload_updateSubMsg(msgFieldPayload field,
                                    msgPayload msg,
                                    const msgPayload subMsg) {
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status
msgpackmsgFieldPayload_getBool(const msgFieldPayload field,
                               mama_bool_t *result) {
    return omnmmsgFieldPayload_getBool(field, result);
}

mama_status
msgpackmsgFieldPayload_getChar(const msgFieldPayload field,
                               char *result) {
    return omnmmsgFieldPayload_getChar(field, result);
}

mama_status
msgpackmsgFieldPayload_getI8(const msgFieldPayload field,
                             mama_i8_t *result) {
    return omnmmsgFieldPayload_getI8(field, result);
}

mama_status
msgpackmsgFieldPayload_getU8(const msgFieldPayload field,
                             mama_u8_t *result) {
    return omnmmsgFieldPayload_getU8(field, result);
}

mama_status
msgpackmsgFieldPayload_getI16(const msgFieldPayload field,
                              mama_i16_t *result) {
    return omnmmsgFieldPayload_getI16(field, result);
}

mama_status
msgpackmsgFieldPayload_getU16(const msgFieldPayload field,
                              mama_u16_t *result) {
    return omnmmsgFieldPayload_getU16(field, result);
}

mama_status
msgpackmsgFieldPayload_getI32(const msgFieldPayload field,
                              mama_i32_t *result) {
    return omnmmsgFieldPayload_getI32(field, result);
}

mama_status
msgpackmsgFieldPayload_getU32(const msgFieldPayload field,
                              mama_u32_t *result) {
    return omnmmsgFieldPayload_getU32(field, result);
}

mama_status
msgpackmsgFieldPayload_getI64(const msgFieldPayload field,
                              mama_i64_t *result) {
    return omnmmsgFieldPayload_getI64(field, result);
}

mama_status
msgpackmsgFieldPayload_getU64(const msgFieldPayload field,
                              mama_u64_t *result) {
    return omnmmsgFieldPayload_getU64(field, result);
}

mama_status
msgpackmsgFieldPayload_getF32(const msgFieldPayload field,
                              mama_f32_t *result) {
    return omnmmsgFieldPayload_getF32(field, result);
}

mama_status
msgpackmsgFieldPayload_getF64(const msgFieldPayload field,
                              mama_f64_t *result) {
    return omnmmsgFieldPayload_getF64(field, result);
}

mama_status
msgpackmsgFieldPayload_getString(const msgFieldPayload field,
                                 const char **result) {
    return omnmmsgFieldPayload_getString(field, result);
}

mama_status
msgpackmsgFieldPayload_getOpaque(const msgFieldPayload field,
                                 const void **result,
                                 mama_size_t *size) {
    return omnmmsgFieldPayload_getOpaque(field, result, size);
}

mama_status
msgpackmsgFieldPayload_getDateTime(const msgFieldPayload field,
                                   mamaDateTime result) {
    return omnmmsgFieldPayload_getDateTime(field, result);
}

mama_status
msgpackmsgFieldPayload_getPrice(const msgFieldPayload field,
                                mamaPrice result) {
    return omnmmsgFieldPayload_getPrice(field, result);
}

mama_status
msgpackmsgFieldPayload_getMsg(const msgFieldPayload field,
                              msgPayload *result) {
    return omnmmsgFieldPayload_getMsg(field, result);
}

mama_status
msgpackmsgFieldPayload_getVectorBool(const msgFieldPayload field,
                                     const mama_bool_t **result,
                                     mama_size_t *size) {
    return omnmmsgFieldPayload_getVectorBool(field, result, size);
}

mama_status
msgpackmsgFieldPayload_getVectorChar(const msgFieldPayload field,
                                     const char **result,
                                     mama_size_t *size) {
    return omnmmsgFieldPayload_getVectorChar(field, result, size);
}

mama_status
msgpackmsgFieldPayload_getVectorI8(const msgFieldPayload field,
                                   const mama_i8_t **result,
                                   mama_size_t *size) {
    return omnmmsgFieldPayload_getVectorI8(field, result, size);
}

mama_status
msgpackmsgFieldPayload_getVectorU8(const msgFieldPayload field,
                                   const mama_u8_t **result,
                                   mama_size_t *size) {
    return omnmmsgFieldPayload_getVectorU8(field, result, size);
}

mama_status
msgpackmsgFieldPayload_getVectorI16(const msgFieldPayload field,
                                    const mama_i16_t **result,
                                    mama_size_t *size) {
    return omnmmsgFieldPayload_getVectorI16(field, result, size);
}

mama_status
msgpackmsgFieldPayload_getVectorU16(const msgFieldPayload field,
                                    const mama_u16_t **result,
                                    mama_size_t *size) {
    return omnmmsgFieldPayload_getVectorU16(field, result, size);
}

mama_status
msgpackmsgFieldPayload_getVectorI32(const msgFieldPayload field,
                                    const mama_i32_t **result,
                                    mama_size_t *size) {
    return omnmmsgFieldPayload_getVectorI32(field, result, size);
}

mama_status
msgpackmsgFieldPayload_getVectorU32(const msgFieldPayload field,
                                    const mama_u32_t **result,
                                    mama_size_t *size) {
    return omnmmsgFieldPayload_getVectorU32(field, result, size);
}

mama_status
msgpackmsgFieldPayload_getVectorI64(const msgFieldPayload field,
                                    const mama_i64_t **result,
                                    mama_size_t *size) {
    return omnmmsgFieldPayload_getVectorI64(field, result, size);
}

mama_status
msgpackmsgFieldPayload_getVectorU64(const msgFieldPayload field,
                                    const mama_u64_t **result,
                                    mama_size_t *size) {
    return omnmmsgFieldPayload_getVectorU64(field, result, size);
}

mama_status
msgpackmsgFieldPayload_getVectorF32(const msgFieldPayload field,
                                    const mama_f32_t **result,
                                    mama_size_t *size) {
    return omnmmsgFieldPayload_getVectorF32(field, result, size);
}

mama_status
msgpackmsgFieldPayload_getVectorF64(const msgFieldPayload field,
                                    const mama_f64_t **result,
                                    mama_size_t *size) {
    return omnmmsgFieldPayload_getVectorF64(field, result, size);
}

mama_status
msgpackmsgFieldPayload_getVectorString(const msgFieldPayload field,
                                       const char ***result,
                                       mama_size_t *size) {
    return omnmmsgFieldPayload_getVectorString(field, result, size);
}

mama_status
msgpackmsgFieldPayload_getVectorDateTime(const msgFieldPayload field,
                                         const mamaDateTime **result,
                                         mama_size_t *size) {
    return omnmmsgFieldPayload_getVectorDateTime(field, result, size);
}

mama_status
msgpackmsgFieldPayload_getVectorPrice(const msgFieldPayload field,
                                      const mamaPrice **result,
                                      mama_size_t *size) {
    return omnmmsgFieldPayload_getVectorPrice(field, result, size);
}


mama_status
msgpackmsgFieldPayload_getVectorMsg(const msgFieldPayload field,
                                    const msgPayload **result,
                                    mama_size_t *size) {
    return omnmmsgFieldPayload_getVectorMsg(field, result, size);
}

mama_status
msgpackmsgFieldPayload_getAsString(const msgFieldPayload field,
                                   const msgPayload msg,
                                   char *buffer,
                                   mama_size_t len) {
    return omnmmsgFieldPayload_getAsString(field, msg, buffer, len);
}

mama_status
msgpackmsgPayloadIter_create(msgPayloadIter *iter,
                             msgPayload msg) {
    return omnmmsgPayloadIter_create(iter, msg);
}

msgFieldPayload
msgpackmsgPayloadIter_next(msgPayloadIter iter,
                           msgFieldPayload field,
                           msgPayload msg) {
    return omnmmsgPayloadIter_next(iter, field, msg);
}

mama_bool_t
msgpackmsgPayloadIter_hasNext(msgPayloadIter iter,
                              msgPayload msg) {
    return omnmmsgPayloadIter_hasNext(iter, msg);
}

msgFieldPayload
msgpackmsgPayloadIter_begin(msgPayloadIter iter,
                            msgFieldPayload field,
                            msgPayload msg) {
    return omnmmsgPayloadIter_begin(iter, field, msg);
}

/*
 * Postponing implementation until this method is included or removed from the
 * implementation
 */
msgFieldPayload
msgpackmsgPayloadIter_end(msgPayloadIter iter,
                          msgPayload msg) {
    return omnmmsgPayloadIter_end(iter, msg);
}

mama_status
msgpackmsgPayloadIter_associate(msgPayloadIter iter,
                                msgPayload msg) {
    return omnmmsgPayloadIter_associate(iter, msg);
}

mama_status
msgpackmsgPayloadIter_destroy(msgPayloadIter iter) {
    return omnmmsgPayloadIter_destroy(iter);
}

mama_status
msgpackmsgPayload_createForTemplate(msgPayload *msg,
                                    mamaPayloadBridge bridge,
                                    mama_u32_t templateId) {
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

mama_status
msgpackmsgPayload_clear(msgPayload msg) {
    return omnmmsgPayload_clear(msg);
}

mama_status
msgpackmsgPayload_setParent(msgPayload msg,
                            const mamaMsg parent) {
    return omnmmsgPayload_setParent(msg, parent);
}

mama_status
msgpackmsgPayload_getNumFields(const msgPayload msg,
                               mama_size_t *numFields) {
    return omnmmsgPayload_getNumFields(msg, numFields);
}

mama_status
msgpackmsgPayload_getSendSubject(const msgPayload msg,
                                 const char **subject) {
    /*
     * Not implemented for now. Used by self describing messages and the qpid
     * payload is not self describing. We could add this capability later.
     */
    return MAMA_STATUS_NOT_IMPLEMENTED;
}

const char *
msgpackmsgPayload_toString(const msgPayload msg) {
    return omnmmsgPayload_toString(msg);
}

mama_status
msgpackmsgPayload_iterateFields(const msgPayload msg,
                                const mamaMsg parent,
                                mamaMsgField field,
                                mamaMsgIteratorCb cb,
                                void *closure) {
    return omnmmsgPayload_iterateFields(msg, parent, field, cb, closure);
}

mama_status
msgpackmsgPayload_apply(msgPayload dest,
                        const msgPayload src) {
    return omnmmsgPayload_apply(dest, src);
}

mama_status
msgpackmsgPayload_getNativeMsg(const msgPayload msg,
                               void **nativeMsg) {
    return omnmmsgPayload_getNativeMsg(msg, nativeMsg);
}

mama_status
msgpackmsgPayload_getFieldAsString(const msgPayload msg,
                                   const char *name,
                                   mama_fid_t fid,
                                   char *buffer,
                                   mama_size_t len) {
    return omnmmsgPayload_getFieldAsString(msg, name, fid, buffer, len);
}

mama_status
msgpackmsgPayload_addBool(msgPayload msg,
                          const char *name,
                          mama_fid_t fid,
                          mama_bool_t value) {
    return omnmmsgPayload_addBool(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_addChar(msgPayload msg,
                          const char *name,
                          mama_fid_t fid,
                          char value) {
    return omnmmsgPayload_addChar(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_addI8(msgPayload msg,
                        const char *name,
                        mama_fid_t fid,
                        mama_i8_t value) {
    return omnmmsgPayload_addI8(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_addU8(msgPayload msg,
                        const char *name,
                        mama_fid_t fid,
                        mama_u8_t value) {
    return omnmmsgPayload_addU8(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_addI16(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_i16_t value) {
    return omnmmsgPayload_addI16(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_addU16(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_u16_t value) {
    return omnmmsgPayload_addU16(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_addI32(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_i32_t value) {
    return omnmmsgPayload_addI32(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_addU32(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_u32_t value) {
    return omnmmsgPayload_addU32(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_addI64(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_i64_t value) {
    return omnmmsgPayload_addI64(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_addU64(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_u64_t value) {
    return omnmmsgPayload_addU64(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_addF32(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_f32_t value) {
    return omnmmsgPayload_addF32(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_addF64(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_f64_t value) {
    return omnmmsgPayload_addF64(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_addString(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            const char *str) {
    return omnmmsgPayload_addString(msg, name, fid, str);
}

mama_status
msgpackmsgPayload_addOpaque(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            const void *opaque,
                            mama_size_t size) {
    return omnmmsgPayload_addOpaque(msg, name, fid, opaque, size);
}

mama_status
msgpackmsgPayload_addDateTime(msgPayload msg,
                              const char *name,
                              mama_fid_t fid,
                              const mamaDateTime value) {
    return omnmmsgPayload_addDateTime(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_addPrice(msgPayload msg,
                           const char *name,
                           mama_fid_t fid,
                           const mamaPrice value) {
    return omnmmsgPayload_addPrice(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_addMsg(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         const mamaMsg value) {
    return omnmmsgPayload_addMsg(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_addVectorBool(msgPayload msg,
                                const char *name,
                                mama_fid_t fid,
                                const mama_bool_t value[],
                                mama_size_t size) {
    return omnmmsgPayload_addVectorBool(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_addVectorChar(msgPayload msg,
                                const char *name,
                                mama_fid_t fid,
                                const char value[],
                                mama_size_t size) {
    return omnmmsgPayload_addVectorChar(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_addVectorI8(msgPayload msg,
                              const char *name,
                              mama_fid_t fid,
                              const mama_i8_t value[],
                              mama_size_t size) {
    return omnmmsgPayload_addVectorI8(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_addVectorU8(msgPayload msg,
                              const char *name,
                              mama_fid_t fid,
                              const mama_u8_t value[],
                              mama_size_t size) {
    return omnmmsgPayload_addVectorU8(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_addVectorI16(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_i16_t value[],
                               mama_size_t size) {
    return omnmmsgPayload_addVectorI16(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_addVectorU16(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_u16_t* value,
                               mama_size_t size) {
    return omnmmsgPayload_addVectorU16(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_addVectorI32(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_i32_t value[],
                               mama_size_t size) {
    return omnmmsgPayload_addVectorI32(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_addVectorU32(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_u32_t value[],
                               mama_size_t size) {
    return omnmmsgPayload_addVectorU32(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_addVectorI64(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_i64_t value[],
                               mama_size_t size) {
    return omnmmsgPayload_addVectorI64(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_addVectorU64(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_u64_t value[],
                               mama_size_t size) {
    return omnmmsgPayload_addVectorU64(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_addVectorF32(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_f32_t value[],
                               mama_size_t size) {
    return omnmmsgPayload_addVectorF32(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_addVectorF64(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_f64_t value[],
                               mama_size_t size) {
    return omnmmsgPayload_addVectorF64(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_addVectorString(msgPayload msg,
                                  const char *name,
                                  mama_fid_t fid,
                                  const char *value[],
                                  mama_size_t size) {
    return omnmmsgPayload_addVectorString(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_addVectorDateTime(msgPayload msg,
                                    const char *name,
                                    mama_fid_t fid,
                                    const mamaDateTime value[],
                                    mama_size_t size) {
    return omnmmsgPayload_addVectorDateTime(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_addVectorPrice(msgPayload msg,
                                 const char *name,
                                 mama_fid_t fid,
                                 const mamaPrice value[],
                                 mama_size_t size) {
    return omnmmsgPayload_addVectorPrice(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_updateBool(msgPayload msg,
                             const char *name,
                             mama_fid_t fid,
                             mama_bool_t value) {
    return omnmmsgPayload_updateBool(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_updateChar(msgPayload msg,
                             const char *name,
                             mama_fid_t fid,
                             char value) {
    return omnmmsgPayload_updateChar(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_updateI8(msgPayload msg,
                           const char *name,
                           mama_fid_t fid,
                           mama_i8_t value) {
    return omnmmsgPayload_updateI8(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_updateU8(msgPayload msg,
                           const char *name,
                           mama_fid_t fid,
                           mama_u8_t value) {
    return omnmmsgPayload_updateU8(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_updateI16(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            mama_i16_t value) {
    return omnmmsgPayload_updateI16(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_updateU16(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            mama_u16_t value) {
    return omnmmsgPayload_updateU16(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_updateI32(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            mama_i32_t value) {
    return omnmmsgPayload_updateI32(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_updateU32(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            mama_u32_t value) {
    return omnmmsgPayload_updateU32(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_updateI64(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            mama_i64_t value) {
    return omnmmsgPayload_updateI64(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_updateU64(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            mama_u64_t value) {
    return omnmmsgPayload_updateU64(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_updateF32(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            mama_f32_t value) {
    return omnmmsgPayload_updateF32(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_updateF64(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            mama_f64_t value) {
    return omnmmsgPayload_updateF64(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_updateString(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const char *str) {
    return omnmmsgPayload_updateString(msg, name, fid, str);
}

mama_status
msgpackmsgPayload_updateOpaque(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const void *opaque,
                               mama_size_t size) {
    return omnmmsgPayload_updateOpaque(msg, name, fid, opaque, size);
}

mama_status
msgpackmsgPayload_updateDateTime(msgPayload msg,
                                 const char *name,
                                 mama_fid_t fid,
                                 const mamaDateTime value) {
    return omnmmsgPayload_updateDateTime(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_updatePrice(msgPayload msg,
                              const char *name,
                              mama_fid_t fid,
                              const mamaPrice value) {
    return omnmmsgPayload_updatePrice(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_updateSubMsg(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mamaMsg value) {
    return omnmmsgPayload_updateSubMsg(msg, name, fid, value);
}

mama_status
msgpackmsgPayload_updateVectorString(msgPayload msg,
                                     const char *name,
                                     mama_fid_t fid,
                                     const char *value[],
                                     mama_size_t size) {
    return omnmmsgPayload_updateVectorString(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_updateVectorBool(msgPayload msg,
                                   const char *name,
                                   mama_fid_t fid,
                                   const mama_bool_t value[],
                                   mama_size_t size) {
    return omnmmsgPayload_updateVectorBool(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_updateVectorChar(msgPayload msg,
                                   const char *name,
                                   mama_fid_t fid,
                                   const char value[],
                                   mama_size_t size) {
    return omnmmsgPayload_updateVectorChar(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_updateVectorI8(msgPayload msg,
                                 const char *name,
                                 mama_fid_t fid,
                                 const mama_i8_t value[],
                                 mama_size_t size) {
    return omnmmsgPayload_updateVectorI8(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_updateVectorU8(msgPayload msg,
                                 const char *name,
                                 mama_fid_t fid,
                                 const mama_u8_t value[],
                                 mama_size_t size) {
    return omnmmsgPayload_updateVectorU8(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_updateVectorI16(msgPayload msg,
                                  const char *name,
                                  mama_fid_t fid,
                                  const mama_i16_t value[],
                                  mama_size_t size) {
    return omnmmsgPayload_updateVectorI16(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_updateVectorU16(msgPayload msg,
                                  const char *name,
                                  mama_fid_t fid,
                                  const mama_u16_t value[],
                                  mama_size_t size) {
    return omnmmsgPayload_updateVectorU16(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_updateVectorI32(msgPayload msg,
                                  const char *name,
                                  mama_fid_t fid,
                                  const mama_i32_t value[],
                                  mama_size_t size) {
    return omnmmsgPayload_updateVectorI32(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_updateVectorU32(msgPayload msg,
                                  const char *name,
                                  mama_fid_t fid,
                                  const mama_u32_t value[],
                                  mama_size_t size) {
    return omnmmsgPayload_updateVectorU32(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_updateVectorI64(msgPayload msg,
                                  const char *name,
                                  mama_fid_t fid,
                                  const mama_i64_t value[],
                                  mama_size_t size) {
    return omnmmsgPayload_updateVectorI64(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_updateVectorU64(msgPayload msg,
                                  const char *name,
                                  mama_fid_t fid,
                                  const mama_u64_t value[],
                                  mama_size_t size) {
    return omnmmsgPayload_updateVectorU64(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_updateVectorF32(msgPayload msg,
                                  const char *name,
                                  mama_fid_t fid,
                                  const mama_f32_t value[],
                                  mama_size_t size) {
    return omnmmsgPayload_updateVectorF32(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_updateVectorF64(msgPayload msg,
                                  const char *name,
                                  mama_fid_t fid,
                                  const mama_f64_t value[],
                                  mama_size_t size) {
    return omnmmsgPayload_updateVectorF64(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_updateVectorPrice(msgPayload msg,
                                    const char *name,
                                    mama_fid_t fid,
                                    const mamaPrice value[],
                                    mama_size_t size) {
    return omnmmsgPayload_updateVectorPrice(msg, name, fid, value, size);
}

mama_status
msgpackmsgPayload_updateVectorTime(msgPayload msg,
                                   const char *name,
                                   mama_fid_t fid,
                                   const mamaDateTime value[],
                                   mama_size_t size) {
    return omnmmsgPayload_updateVectorTime(msg, name, fid, value, size);
}


mama_status
msgpackmsgPayload_getBool(const msgPayload msg,
                          const char *name,
                          mama_fid_t fid,
                          mama_bool_t *result) {
    return omnmmsgPayload_getBool(msg, name, fid, result);
}

mama_status
msgpackmsgPayload_getChar(const msgPayload msg,
                          const char *name,
                          mama_fid_t fid,
                          char *result) {
    return omnmmsgPayload_getChar(msg, name, fid, result);
}

mama_status
msgpackmsgPayload_getI8(const msgPayload msg,
                        const char *name,
                        mama_fid_t fid,
                        mama_i8_t *result) {
    return omnmmsgPayload_getI8(msg, name, fid, result);
}

mama_status
msgpackmsgPayload_getU8(const msgPayload msg,
                        const char *name,
                        mama_fid_t fid,
                        mama_u8_t *result) {
    return omnmmsgPayload_getU8(msg, name, fid, result);
}

mama_status
msgpackmsgPayload_getI16(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_i16_t *result) {
    return omnmmsgPayload_getI16(msg, name, fid, result);
}

mama_status
msgpackmsgPayload_getU16(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_u16_t *result) {
    return omnmmsgPayload_getU16(msg, name, fid, result);
}

mama_status
msgpackmsgPayload_getI32(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_i32_t *result) {
    return omnmmsgPayload_getI32(msg, name, fid, result);
}

mama_status
msgpackmsgPayload_getU32(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_u32_t *result) {
    return omnmmsgPayload_getU32(msg, name, fid, result);
}

mama_status
msgpackmsgPayload_getI64(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_i64_t *result) {
    return omnmmsgPayload_getI64(msg, name, fid, result);
}

mama_status
msgpackmsgPayload_getU64(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_u64_t *result) {
    return omnmmsgPayload_getU64(msg, name, fid, result);
}

mama_status
msgpackmsgPayload_getF32(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_f32_t *result) {
    return omnmmsgPayload_getF32(msg, name, fid, result);
}

mama_status
msgpackmsgPayload_getF64(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_f64_t *result) {
    return omnmmsgPayload_getF64(msg, name, fid, result);
}

mama_status
msgpackmsgPayload_getString(const msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            const char **result) {
    return omnmmsgPayload_getString(msg, name, fid, result);
}

mama_status
msgpackmsgPayload_getOpaque(const msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            const void **result,
                            mama_size_t *size) {
    return omnmmsgPayload_getOpaque(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getDateTime(const msgPayload msg,
                              const char *name,
                              mama_fid_t fid,
                              mamaDateTime result) {
    return omnmmsgPayload_getDateTime(msg, name, fid, result);
}

mama_status
msgpackmsgPayload_getPrice(const msgPayload msg,
                           const char *name,
                           mama_fid_t fid,
                           mamaPrice result) {
    return omnmmsgPayload_getPrice(msg, name, fid, result);
}

mama_status
msgpackmsgPayload_getMsg(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         msgPayload *result) {
    return omnmmsgPayload_getMsg(msg, name, fid, result);
}

mama_status
msgpackmsgPayload_getVectorBool(const msgPayload msg,
                                const char *name,
                                mama_fid_t fid,
                                const mama_bool_t **result,
                                mama_size_t *size) {
    return omnmmsgPayload_getVectorBool(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getVectorChar(const msgPayload msg,
                                const char *name,
                                mama_fid_t fid,
                                const char **result,
                                mama_size_t *size) {
    return omnmmsgPayload_getVectorChar(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getVectorI8(const msgPayload msg,
                              const char *name,
                              mama_fid_t fid,
                              const mama_i8_t **result,
                              mama_size_t *size) {
    return omnmmsgPayload_getVectorI8(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getVectorU8(const msgPayload msg,
                              const char *name,
                              mama_fid_t fid,
                              const mama_u8_t **result,
                              mama_size_t *size) {
    return omnmmsgPayload_getVectorU8(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getVectorI16(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_i16_t **result,
                               mama_size_t *size) {
    return omnmmsgPayload_getVectorI16(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getVectorU16(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_u16_t **result,
                               mama_size_t *size) {
    return omnmmsgPayload_getVectorU16(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getVectorI32(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_i32_t **result,
                               mama_size_t *size) {
    return omnmmsgPayload_getVectorI32(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getVectorU32(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_u32_t **result,
                               mama_size_t *size) {
    return omnmmsgPayload_getVectorU32(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getVectorI64(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_i64_t **result,
                               mama_size_t *size) {
    return omnmmsgPayload_getVectorI64(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getVectorU64(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_u64_t **result,
                               mama_size_t *size) {
    return omnmmsgPayload_getVectorU64(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getVectorF32(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_f32_t **result,
                               mama_size_t *size) {
    return omnmmsgPayload_getVectorF32(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getVectorF64(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_f64_t **result,
                               mama_size_t *size) {
    return omnmmsgPayload_getVectorF64(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getVectorString(const msgPayload msg,
                                  const char *name,
                                  mama_fid_t fid,
                                  const char ***result,
                                  mama_size_t *size) {
    return omnmmsgPayload_getVectorString(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getVectorDateTime(const msgPayload msg,
                                    const char *name,
                                    mama_fid_t fid,
                                    const mamaDateTime **result,
                                    mama_size_t *size) {
    return omnmmsgPayload_getVectorDateTime(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getVectorPrice(const msgPayload msg,
                                 const char *name,
                                 mama_fid_t fid,
                                 const mamaPrice **result,
                                 mama_size_t *size) {
    return omnmmsgPayload_getVectorPrice(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getVectorMsg(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const msgPayload **result,
                               mama_size_t *size) {
    return omnmmsgPayload_getVectorMsg(msg, name, fid, result, size);
}

mama_status
msgpackmsgPayload_getField(const msgPayload msg,
                           const char *name,
                           mama_fid_t fid,
                           msgFieldPayload *result) {
    return omnmmsgPayload_getField(msg, name, fid, result);
}
