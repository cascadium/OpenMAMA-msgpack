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

#ifndef MAMA_PAYLOAD_MSGPACK_MSG_IMPL_H__
#define MAMA_PAYLOAD_MSGPACK_MSG_IMPL_H__

#include <mama/integration/types.h>

#if defined(__cplusplus)
extern "C" {
#endif

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_init(mamaPayloadBridge bridge, char *identifier);

MAMAIgnoreDeprecatedOpen
MAMAExpBridgeDLL
mamaPayloadType
msgpackmsgPayload_getType(void);

MAMAIgnoreDeprecatedClose

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_create(msgPayload *msg);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_createForTemplate(msgPayload *msg,
                                    mamaPayloadBridge bridge,
                                    mama_u32_t templateId);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_copy(const msgPayload msg,
                       msgPayload *copy);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_clear(msgPayload msg);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_destroy(msgPayload msg);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_setParent(msgPayload msg,
                            const mamaMsg parent);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getByteSize(msgPayload msg,
                              mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getNumFields(const msgPayload msg,
                               mama_size_t *numFields);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getSendSubject(const msgPayload msg,
                                 const char **subject);

MAMAExpBridgeDLL
const char *
msgpackmsgPayload_toString(const msgPayload msg);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_iterateFields(const msgPayload msg,
                                const mamaMsg parent,
                                mamaMsgField field,
                                mamaMsgIteratorCb cb,
                                void *closure);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_serialize(const msgPayload msg,
                            const void **buffer,
                            mama_size_t *bufferLength);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_unSerialize(const msgPayload msg,
                              const void *buffer,
                              mama_size_t bufferLength);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getByteBuffer(const msgPayload msg,
                                const void **buffer,
                                mama_size_t *bufferLength);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_setByteBuffer(const msgPayload msg,
                                mamaPayloadBridge bridge,
                                const void *buffer,
                                mama_size_t bufferLength);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_createFromByteBuffer(msgPayload *msg,
                                       mamaPayloadBridge bridge,
                                       const void *buffer,
                                       mama_size_t bufferLength);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_apply(msgPayload dest,
                        const msgPayload src);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getNativeMsg(const msgPayload msg,
                               void **nativeMsg);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getFieldAsString(const msgPayload msg,
                                   const char *name,
                                   mama_fid_t fid,
                                   char *buffer,
                                   mama_size_t len);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addBool(msgPayload msg,
                          const char *name,
                          mama_fid_t fid,
                          mama_bool_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addChar(msgPayload msg,
                          const char *name,
                          mama_fid_t fid,
                          char value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addI8(msgPayload msg,
                        const char *name,
                        mama_fid_t fid,
                        mama_i8_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addU8(msgPayload msg,
                        const char *name,
                        mama_fid_t fid,
                        mama_u8_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addI16(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_i16_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addU16(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_u16_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addI32(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_i32_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addU32(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_u32_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addI64(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_i64_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addU64(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_u64_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addF32(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_f32_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addF64(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_f64_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addString(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            const char *value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addOpaque(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            const void *value,
                            mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addDateTime(msgPayload msg,
                              const char *name,
                              mama_fid_t fid,
                              const mamaDateTime value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addPrice(msgPayload msg,
                           const char *name,
                           mama_fid_t fid,
                           const mamaPrice value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addMsg(msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         const mamaMsg value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addVectorBool(msgPayload msg,
                                const char *name,
                                mama_fid_t fid,
                                const mama_bool_t value[],
                                mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addVectorChar(msgPayload msg,
                                const char *name,
                                mama_fid_t fid,
                                const char value[],
                                mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addVectorI8(msgPayload msg,
                              const char *name,
                              mama_fid_t fid,
                              const mama_i8_t value[],
                              mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addVectorU8(msgPayload msg,
                              const char *name,
                              mama_fid_t fid,
                              const mama_u8_t value[],
                              mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addVectorI16(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_i16_t value[],
                               mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addVectorU16(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_u16_t value[],
                               mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addVectorI32(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_i32_t value[],
                               mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addVectorU32(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_u32_t value[],
                               mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addVectorI64(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_i64_t value[],
                               mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addVectorU64(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_u64_t value[],
                               mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addVectorF32(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_f32_t value[],
                               mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addVectorF64(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_f64_t value[],
                               mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addVectorString(msgPayload msg,
                                  const char *name,
                                  mama_fid_t fid,
                                  const char *value[],
                                  mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addVectorMsg(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mamaMsg value[],
                               mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addVectorDateTime(msgPayload msg,
                                    const char *name,
                                    mama_fid_t fid,
                                    const mamaDateTime value[],
                                    mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_addVectorPrice(msgPayload msg,
                                 const char *name,
                                 mama_fid_t fid,
                                 const mamaPrice value[],
                                 mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateBool(msgPayload msg,
                             const char *name,
                             mama_fid_t fid,
                             mama_bool_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateChar(msgPayload msg,
                             const char *name,
                             mama_fid_t fid,
                             char value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateI8(msgPayload msg,
                           const char *name,
                           mama_fid_t fid,
                           mama_i8_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateU8(msgPayload msg,
                           const char *name,
                           mama_fid_t fid,
                           mama_u8_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateI16(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            mama_i16_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateU16(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            mama_u16_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateI32(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            mama_i32_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateU32(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            mama_u32_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateI64(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            mama_i64_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateU64(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            mama_u64_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateF32(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            mama_f32_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateF64(msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            mama_f64_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateString(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const char *value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateOpaque(msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const void *value,
                               mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateDateTime(msgPayload msg,
                                 const char *name,
                                 mama_fid_t fid,
                                 const mamaDateTime value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updatePrice(msgPayload msg,
                              const char *name,
                              mama_fid_t fid,
                              const mamaPrice value);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateSubMsg(msgPayload msg,
                               const char *fname,
                               mama_fid_t fid,
                               const mamaMsg subMsg);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateVectorMsg(msgPayload msg,
                                  const char *fname,
                                  mama_fid_t fid,
                                  const mamaMsg value[],
                                  mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateVectorString(msgPayload msg,
                                     const char *fname,
                                     mama_fid_t fid,
                                     const char *strList[],
                                     mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateVectorBool(msgPayload msg,
                                   const char *fname,
                                   mama_fid_t fid,
                                   const mama_bool_t boolList[],
                                   mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateVectorChar(msgPayload msg,
                                   const char *fname,
                                   mama_fid_t fid,
                                   const char charList[],
                                   mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateVectorI8(msgPayload msg,
                                 const char *fname,
                                 mama_fid_t fid,
                                 const mama_i8_t i8List[],
                                 mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateVectorU8(msgPayload msg,
                                 const char *fname,
                                 mama_fid_t fid,
                                 const mama_u8_t u8List[],
                                 mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateVectorI16(msgPayload msg,
                                  const char *fname,
                                  mama_fid_t fid,
                                  const mama_i16_t i16List[],
                                  mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateVectorU16(msgPayload msg,
                                  const char *fname,
                                  mama_fid_t fid,
                                  const mama_u16_t u16List[],
                                  mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateVectorI32(msgPayload msg,
                                  const char *fname,
                                  mama_fid_t fid,
                                  const mama_i32_t i32List[],
                                  mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateVectorU32(msgPayload msg,
                                  const char *fname,
                                  mama_fid_t fid,
                                  const mama_u32_t u32List[],
                                  mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateVectorI64(msgPayload msg,
                                  const char *fname,
                                  mama_fid_t fid,
                                  const mama_i64_t i64List[],
                                  mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateVectorU64(msgPayload msg,
                                  const char *fname,
                                  mama_fid_t fid,
                                  const mama_u64_t u64List[],
                                  mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateVectorF32(msgPayload msg,
                                  const char *fname,
                                  mama_fid_t fid,
                                  const mama_f32_t f32List[],
                                  mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateVectorF64(msgPayload msg,
                                  const char *fname,
                                  mama_fid_t fid,
                                  const mama_f64_t f64List[],
                                  mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateVectorPrice(msgPayload msg,
                                    const char *fname,
                                    mama_fid_t fid,
                                    const mamaPrice priceList[],
                                    mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_updateVectorTime(msgPayload msg,
                                   const char *fname,
                                   mama_fid_t fid,
                                   const mamaDateTime timeList[],
                                   mama_size_t size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getBool(const msgPayload msg,
                          const char *name,
                          mama_fid_t fid,
                          mama_bool_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getChar(const msgPayload msg,
                          const char *name,
                          mama_fid_t fid,
                          char *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getI8(const msgPayload msg,
                        const char *name,
                        mama_fid_t fid,
                        mama_i8_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getU8(const msgPayload msg,
                        const char *name,
                        mama_fid_t fid,
                        mama_u8_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getI16(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_i16_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getU16(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_u16_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getI32(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_i32_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getU32(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_u32_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getI64(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_i64_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getU64(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_u64_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getF32(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_f32_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getF64(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         mama_f64_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getString(const msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            const char **result);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getOpaque(const msgPayload msg,
                            const char *name,
                            mama_fid_t fid,
                            const void **result,
                            mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getDateTime(const msgPayload msg,
                              const char *name,
                              mama_fid_t fid,
                              mamaDateTime result);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getPrice(const msgPayload msg,
                           const char *name,
                           mama_fid_t fid,
                           mamaPrice result);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getMsg(const msgPayload msg,
                         const char *name,
                         mama_fid_t fid,
                         msgPayload *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getVectorBool(const msgPayload msg,
                                const char *name,
                                mama_fid_t fid,
                                const mama_bool_t **result,
                                mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getVectorChar(const msgPayload msg,
                                const char *name,
                                mama_fid_t fid,
                                const char **result,
                                mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getVectorI8(const msgPayload msg,
                              const char *name,
                              mama_fid_t fid,
                              const mama_i8_t **result,
                              mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getVectorU8(const msgPayload msg,
                              const char *name,
                              mama_fid_t fid,
                              const mama_u8_t **result,
                              mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getVectorI16(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_i16_t **result,
                               mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getVectorU16(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_u16_t **result,
                               mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getVectorI32(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_i32_t **result,
                               mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getVectorU32(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_u32_t **result,
                               mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getVectorI64(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_i64_t **result,
                               mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getVectorU64(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_u64_t **result,
                               mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getVectorF32(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_f32_t **result,
                               mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getVectorF64(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const mama_f64_t **result,
                               mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getVectorString(const msgPayload msg,
                                  const char *name,
                                  mama_fid_t fid,
                                  const char ***result,
                                  mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getVectorDateTime(const msgPayload msg,
                                    const char *name,
                                    mama_fid_t fid,
                                    const mamaDateTime **result,
                                    mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getVectorPrice(const msgPayload msg,
                                 const char *name,
                                 mama_fid_t fid,
                                 const mamaPrice **result,
                                 mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getVectorMsg(const msgPayload msg,
                               const char *name,
                               mama_fid_t fid,
                               const msgPayload **result,
                               mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayload_getField(const msgPayload msg,
                           const char *name,
                           mama_fid_t fid,
                           msgFieldPayload *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_create(msgFieldPayload *field);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_destroy(msgFieldPayload field);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getType(const msgFieldPayload field,
                               mamaFieldType *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getName(msgFieldPayload field,
                               mamaDictionary dict,
                               mamaFieldDescriptor desc,
                               const char **result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getFid(const msgFieldPayload field,
                              mamaDictionary dict,
                              mamaFieldDescriptor desc,
                              uint16_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getDescriptor(const msgFieldPayload field,
                                     mamaDictionary dict,
                                     mamaFieldDescriptor *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_updateBool(msgFieldPayload field,
                                  msgPayload msg,
                                  mama_bool_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_updateChar(msgFieldPayload field,
                                  msgPayload msg,
                                  char value);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_updateI8(msgFieldPayload field,
                                msgPayload msg,
                                mama_i8_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_updateU8(msgFieldPayload field,
                                msgPayload msg,
                                mama_u8_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_updateI16(msgFieldPayload field,
                                 msgPayload msg,
                                 mama_i16_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_updateU16(msgFieldPayload field,
                                 msgPayload msg,
                                 mama_u16_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_updateI32(msgFieldPayload field,
                                 msgPayload msg,
                                 mama_i32_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_updateU32(msgFieldPayload field,
                                 msgPayload msg,
                                 mama_u32_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_updateI64(msgFieldPayload field,
                                 msgPayload msg,
                                 mama_i64_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_updateU64(msgFieldPayload field,
                                 msgPayload msg,
                                 mama_u64_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_updateF32(msgFieldPayload field,
                                 msgPayload msg,
                                 mama_f32_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_updateF64(msgFieldPayload field,
                                 msgPayload msg,
                                 mama_f64_t value);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_updateString(msgFieldPayload field,
                                    msgPayload msg,
                                    const char *value);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_updateDateTime(msgFieldPayload field,
                                      msgPayload msg,
                                      const mamaDateTime value);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_updatePrice(msgFieldPayload field,
                                   msgPayload msg,
                                   const mamaPrice value);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_updateSubMsg(msgFieldPayload field,
                                    msgPayload msg,
                                    const msgPayload subMsg);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getBool(const msgFieldPayload field,
                               mama_bool_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getChar(const msgFieldPayload field,
                               char *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getI8(const msgFieldPayload field,
                             mama_i8_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getU8(const msgFieldPayload field,
                             mama_u8_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getI16(const msgFieldPayload field,
                              mama_i16_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getU16(const msgFieldPayload field,
                              mama_u16_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getI32(const msgFieldPayload field,
                              mama_i32_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getU32(const msgFieldPayload field,
                              mama_u32_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getI64(const msgFieldPayload field,
                              mama_i64_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getU64(const msgFieldPayload field,
                              mama_u64_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getF32(const msgFieldPayload field,
                              mama_f32_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getF64(const msgFieldPayload field,
                              mama_f64_t *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getString(const msgFieldPayload field,
                                 const char **result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getOpaque(const msgFieldPayload field,
                                 const void **result,
                                 mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getDateTime(const msgFieldPayload field,
                                   mamaDateTime result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getPrice(const msgFieldPayload field,
                                mamaPrice result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getMsg(const msgFieldPayload field,
                              msgPayload *result);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getVectorBool(const msgFieldPayload field,
                                     const mama_bool_t **result,
                                     mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getVectorChar(const msgFieldPayload field,
                                     const char **result,
                                     mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getVectorI8(const msgFieldPayload field,
                                   const mama_i8_t **result,
                                   mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getVectorU8(const msgFieldPayload field,
                                   const mama_u8_t **result,
                                   mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getVectorI16(const msgFieldPayload field,
                                    const mama_i16_t **result,
                                    mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getVectorU16(const msgFieldPayload field,
                                    const mama_u16_t **result,
                                    mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getVectorI32(const msgFieldPayload field,
                                    const mama_i32_t **result,
                                    mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getVectorU32(const msgFieldPayload field,
                                    const mama_u32_t **result,
                                    mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getVectorI64(const msgFieldPayload field,
                                    const mama_i64_t **result,
                                    mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getVectorU64(const msgFieldPayload field,
                                    const mama_u64_t **result,
                                    mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getVectorF32(const msgFieldPayload field,
                                    const mama_f32_t **result,
                                    mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getVectorF64(const msgFieldPayload field,
                                    const mama_f64_t **result,
                                    mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getVectorString(const msgFieldPayload field,
                                       const char ***result,
                                       mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getVectorDateTime(const msgFieldPayload field,
                                         const mamaDateTime **result,
                                         mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getVectorPrice(const msgFieldPayload field,
                                      const mamaPrice **result,
                                      mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getVectorMsg(const msgFieldPayload field,
                                    const msgPayload **result,
                                    mama_size_t *size);

MAMAExpBridgeDLL
mama_status
msgpackmsgFieldPayload_getAsString(const msgFieldPayload field,
                                   const msgPayload msg,
                                   char *buffer,
                                   mama_size_t len);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayloadIter_create(msgPayloadIter *iter,
                             msgPayload msg);

MAMAExpBridgeDLL
msgFieldPayload
msgpackmsgPayloadIter_next(msgPayloadIter iter,
                           msgFieldPayload field,
                           msgPayload msg);

MAMAExpBridgeDLL
mama_bool_t
msgpackmsgPayloadIter_hasNext(msgPayloadIter iter,
                              msgPayload msg);

MAMAExpBridgeDLL
msgFieldPayload
msgpackmsgPayloadIter_begin(msgPayloadIter iter,
                            msgFieldPayload field,
                            msgPayload msg);

MAMAExpBridgeDLL
msgFieldPayload
msgpackmsgPayloadIter_end(msgPayloadIter iter,
                          msgPayload msg);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayloadIter_associate(msgPayloadIter iter,
                                msgPayload msg);

MAMAExpBridgeDLL
mama_status
msgpackmsgPayloadIter_destroy(msgPayloadIter iter);

#if defined(__cplusplus)
}
#endif

#endif /* MAMA_PAYLOAD_MSGPACK_MSG_IMPL_H__ */
